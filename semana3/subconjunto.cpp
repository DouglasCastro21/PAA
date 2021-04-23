/*
    Implemente um algoritmo que, dado um conjunto de elementos, gere todos seus subconjuntos.


    complexidade de tempo de execução 𝑂(𝑁 · 𝑁!)


*/
#include <iostream>

using namespace std;

void subConjunto(int *conjunto, bool *verifica, int i, int tamanho)
{
    if (i == tamanho)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (verifica[j] == 1)
                cout << conjunto[j] << " ";
        }
        cout << endl;
    }
    else
    {
        verifica[i] = true;
        subConjunto(conjunto, verifica, i + 1, tamanho);
        verifica[i] = false;
        subConjunto(conjunto, verifica, i + 1, tamanho);
    }
}

int main()
{
    int elemento[] = {1, 2, 3, 4};
    int tamanho = sizeof(elemento) / sizeof(int);
    bool verifica_e[tamanho];

    for (int i = 0; i < tamanho; i++)
        verifica_e[i] = false;

    subConjunto(elemento, verifica_e, 0, tamanho);

    return 0;
}
