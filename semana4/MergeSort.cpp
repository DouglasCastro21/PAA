#include <iostream>
#include <vector>

void copiaVolume(std::vector<char> &elementos);
// Mescla dois  vetor vetor1 e vetor2

void merge(std::vector<char> &elementos, int vetor1, int num, int vetor2)
{
    int v1 = num - vetor1 + 1;
    int v2 = vetor2 - num;

    // vetor temporario
    std::vector<int> vetorEsquerdo(v1, 0), vetorDireito(v2, 0);

    // vetor Esquerdo  vetor Direito  recebe dados
    for (int i = 0; i < v1; i++)
        vetorEsquerdo[i] = elementos[vetor1 + i];
    for (int j = 0; j < v2; j++)
        vetorDireito[j] = elementos[num + 1 + j];


    // Índice inicial vetor1
    int i = 0;

    // Índice inicial vetor2
    int j = 0;

    // Índice vetor mesclado
    int l = vetor1;

    while (i < v1 && j < v2)
    {
        if (vetorEsquerdo[i] <= vetorDireito[j])
        {
            elementos[l] = vetorEsquerdo[i];
            i++;
        }
        else
        {
            elementos[l] = vetorDireito[j];
            j++;
        }
        l++;
    }
    //passa os elementos para a esquerda
    while (i < v1)
    {
        elementos[l] = vetorEsquerdo[i];
        i++;
        l++;
    }

    //passa os elementos para a direita
    while (j < v2)
    {
        elementos[l] = vetorDireito[j];
        j++;
        l++;
    }
}
// classificação * /
void mergeSort(std::vector<char> &elementos, int a, int b)
{

    copiaVolume(elementos);

    if (a >= b) // condição de parada
    {
        return; // retorna recursivamente
    }
    int numV = a + (b - a) / 2;
    mergeSort(elementos, a, numV);
    mergeSort(elementos, numV + 1, b);
    merge(elementos, a, numV, b);
}



void copiaVolume(std::vector<char> &elementos)
{
    std::cout << "[";
    for (auto i = 0; i < elementos.size() - 1; i++)
    {
        std::cout << elementos[i] << " ";
    }
    std::cout << elementos.back() << "]\n";
}

int main()
{
    std::vector<char> elementos = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};

    std::cout << "vetor com a palavra:\n";
    copiaVolume(elementos);
    std::cout << "\n";

    std::cout << " Ordenando ...:\n";

    mergeSort(elementos, 0, elementos.size() - 1);

    std::cout << "\nPalavra ordenada:\n";
    copiaVolume(elementos);

    return 0;
}