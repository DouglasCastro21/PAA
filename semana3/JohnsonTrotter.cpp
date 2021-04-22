/*  
    Algoritmo de Johnson e Trotter.
    Equação transporta de complexidade O(n²)

*/
#include <iostream>
#include <vector>

using namespace std;

bool esquerdaParaDireita = true;
bool direitaParaEsquerda = false;


// Encontra a posição do maior número em um vector.
int searchArr(int vector[], int n, int num_inverso)
{
    for (int i = 0; i < n; i++)
        if (vector[i] == num_inverso)
            return i + 1;
}


// encontra o maior número inteiro inverso.
int obterInverso(int *vector, bool *dir, int n)
{
    int inverso_prev = 0, num_inverso = 0;
    for (int i = 0; i < n; i++)
    {
        // direita para esquerda
        if (dir[vector[i] - 1] == direitaParaEsquerda && i != 0)
        {
            if (vector[i] > vector[i - 1] && vector[i] > inverso_prev)
            {
                num_inverso = vector[i];
                inverso_prev = num_inverso;
            }
        }

        // esquerda para direita
        if (dir[vector[i] - 1] == esquerdaParaDireita && i != n - 1)
        {
            if (vector[i] > vector[i + 1] && vector[i] > inverso_prev)
            {
                num_inverso = vector[i];
                inverso_prev = num_inverso;
            }
        }
    }

    if (num_inverso == 0 && inverso_prev == 0)
        return 0;
    else
        return num_inverso;
}

//  única permutação
int printUnicaPermutacao(int *vector, bool *dir, int n)
{
    int numInverso = obterInverso(vector, dir, n);
    int pos = searchArr(vector, n, numInverso);

    // trocando os elementos na direção dir [].
    if (dir[vector[pos - 1] - 1] == direitaParaEsquerda)
        swap(vector[pos - 1], vector[pos - 2]); //executa  troca por elemento.

    else if (dir[vector[pos - 1] - 1] == esquerdaParaDireita)
        swap(vector[pos], vector[pos - 1]); // executa u troca por elemento.

    // altera a  direção dos elementos

    for (int i = 0; i < n; i++)
    {
        if (vector[i] > numInverso)
        {
            if (dir[vector[i] - 1] == esquerdaParaDireita)
                dir[vector[i] - 1] = direitaParaEsquerda;
            else if (dir[vector[i] - 1] == direitaParaEsquerda)
                dir[vector[i] - 1] = esquerdaParaDireita;
        }
    }

    for (int i = 0; i < n; i++)
        cout << vector[i];
    cout << " ";
}

// Fianliza o algoritmo no fatorial de n   n!

int fatorial(int n)
{
    int resp = 1;
    for (int i = 1; i <= n; i++)
        resp = resp * i;
    return resp;
}

//função printUnicaPermutacao ()

void printPermutacao(int n)
{
    // Armazena  permutação atual
    int vector[n];

    //Armazena direções atuais
    bool dir[n];

    // Armazena os elementos do vector n

    for (int i = 0; i < n; i++)
    {
        vector[i] = i + 1;
        cout << vector[i];
    }
    cout << endl;

    // no inicio todas as direções são  da direita para esquerda

    for (int i = 0; i < n; i++)
        dir[i] =  direitaParaEsquerda;

    // gera permutações
    for (int i = 1; i < fatorial(n); i++)
        printUnicaPermutacao(vector, dir, n);
}

int main()
{
    std::cout << "\n Permutações " << std::endl;
    int n = 3;
    printPermutacao(n);
    return 0;
}
