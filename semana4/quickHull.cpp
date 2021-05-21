#include <iostream>
#include <set>

using namespace std;

// iPair pares inteiros
#define iPair pair<int, int>

// Armazena o resultado (pontos do casco convexo)
set <iPair> hull;

// junta pontos1 e ponto2
int encontrarLado(iPair ponto1, iPair ponto2, iPair ponto)
{
    int qtd = (ponto.second - ponto1.second) * (ponto2.first - ponto1.first) -
              (ponto2.second - ponto1.second) * (ponto.first - ponto1.first);

    if (qtd > 0)
        return 1;
    if (qtd < 0)
        return -1;
    return 0;
}

//retorna um valor proporcional entre ponto1 e ponto2
int linhaDist(iPair ponto1, iPair ponto2, iPair ponto)
{
    return abs ((ponto.second - ponto1.second) * (ponto2.first - ponto1.first) -
                (ponto2.second - ponto1.second) * (ponto.first - ponto1.first));
}

//Os pontos finais  são ponto1 e ponto2
void quickHull(iPair pPair[], int n, iPair ponto1, iPair ponto2, int side)
{
    int indice = -1;
    int distriMax = 0;

     //encontra o ponto com distância máxima do lado
    for (int i=0; i<n; i++)
    {
        int temp = linhaDist(ponto1, ponto2, pPair[i]);
        if (encontrarLado(ponto1, ponto2, pPair[i]) == side && temp > distriMax)
        {
            indice = i;
            distriMax = temp;
        }
    }

    //Se nenhum ponto for encontrado, adicione os pontos finais
    if (indice == -1)
    {
        hull.insert(ponto1);
        hull.insert(ponto2);
        return;
    }

    // Recorrencia para as duas partes divididas
    quickHull(pPair, n, pPair[indice], ponto1, -encontrarLado(pPair[indice], ponto1, ponto2));
    quickHull(pPair, n, pPair[indice], ponto2, -encontrarLado(pPair[indice], ponto2, ponto1));
}

void imprimetHull(pair<int, int> *p, int num)
{
    if (num < 3)
    {
        cout << "Casco convexo não é possíveln";
        return;
    }

     // Encontra o ponto com mínimo e coordenada x máxima
    int pontoMin = 0, pontoMax = 0;
    for (int i=1; i < num; i++)
    {
        if (p[i].first < p[pontoMin].first)
            pontoMin = i;
        if (p[i].first > p[pontoMax].first)
            pontoMax = i;
    }

//Encontra recursivamente pontos de casco convexo em
//   um lado da linha unindo  pontoMin pontoMax
    quickHull(p, num, p[pontoMin], p[pontoMax], 1);

   // Encontra recursivamente pontos de casco convexo em
    //OUTRO (-1)lado da linha juntando pontoMin e pontoMax
    quickHull(p, num, p[pontoMin], p[pontoMax], -1);

    cout << "Os pontos em Convex Hull são:\n";
    while (!hull.empty())
    {
        cout << "(" <<( *hull.begin()).first << ", "
             << (*hull.begin()).second << ") ";
        hull.erase(hull.begin());
    }
}

// Driver code
int main()
{
    iPair p[] = {{4, 3}, {3, 7}, {5, 3}, {9, 5},
                 {5, 0}, {3, 8}, {4, 1}, {6, 6}};
    int tam = sizeof(p) / sizeof(p[0]);
    imprimetHull(p, tam);
    return 0;
}
