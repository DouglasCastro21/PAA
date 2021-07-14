//coleta de moedas (Coin-collecting problem sem utilizar programação dinamica.
#include <bits/stdc++.h>
using namespace std;
int coletaMoedaRecur(int *altura, int esq, int direita, int h)
{

    if (esq >= direita)
        return 0;

    //faz um loop nas alturas para obter a altura mínima
    int m = esq;
    for (int i = esq; i < direita; i++)
        if (altura[i] < altura[m])
            m = i;

    //coleta de moedas usando todas as verticais
    //coleta de moedas usando a horizontal inferior linhas e recursivamente à esquerda e à direita
    //segmentos
    return min(direita - esq,
               coletaMoedaRecur(altura, esq, m, altura[m]) +
               coletaMoedaRecur(altura, m + 1, direita, altura[m]) +
               altura[m] - h);
}


//coleta a moeda da pilha, com altura em height[] array
int passosMinimos(int *altura, int num)
{
    return coletaMoedaRecur(altura, 0, num, 0);
}


int main()
{
    int altura[] = {5, 6, 5, 7, 8,2 };
    int TamN = sizeof(altura) / sizeof(int);

    cout << passosMinimos(altura, TamN) << endl;
    return 0;
}
