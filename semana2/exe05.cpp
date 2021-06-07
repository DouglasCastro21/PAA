#//Algoritmo brute force maisProxima pair
#include <iostream>
#include <cfloat>
#include <cstdlib>
#include <cmath>
using namespace std;

// divisão e conquista
// encontra a menor distância entre dois pontos


struct Posicao
{
    int x, y;
};
//  matriz de coordenada X
int classificarX(const void *a, const void *b)
{
    auto *p1 = (Posicao *)a, *p2 = (Posicao *)b;
    return (p1->x - p2->x);
}
//matriz de coordenada y
int classificarY(const void *a, const void *b)
{
    auto *p1 = (Posicao *)a, *p2 = (Posicao *)b;
    return (p1->y - p2->y);
}

// encontra a distância entre dois pontos
float distancia(Posicao p1, Posicao p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// força bruta para encontra a distância entre dois pontos(a menor)

float forcaBruta(Posicao P[], int n)
{
    float menor = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distancia(P[i], P[j]) < menor)
                menor = distancia(P[i], P[j]);
    return menor;
}

//encontra um valor menor entre dois valores flutuantes
float menor(float x, float y)
{
    return (x < y) ? x : y;
}

float indiceMaisProximo(Posicao *indice, int tamanho, float m)
{
    float menor = m;


    for (int i = 0; i < tamanho; ++i)
        for (int j = i + 1; j < tamanho && (indice[j].y - indice[i].y) < menor; ++j)
            if (distancia(indice[i], indice[j]) < menor)
                menor = distancia(indice[i], indice[j]);

    return menor;
}


float utilMaisProximo(Posicao *Px, Posicao *Py, int n)
{

    if (n <= 3)
        return forcaBruta(Px, n);


    int medio = n / 2;
    Posicao pontoMedio = Px[medio];


    Posicao PosicaoEsquerda[medio];
    Posicao PosicaoDireita[n - medio];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= pontoMedio.x && li < medio)
            PosicaoEsquerda[li++] = Py[i];
        else
            PosicaoDireita[ri++] = Py[i];
    }


    float esquerdo = utilMaisProximo(Px, PosicaoEsquerda, medio);
    float direito = utilMaisProximo(Px + medio, PosicaoDireita, n - medio);

    // Encontre a menor das duas distâncias
    float m = menor(esquerdo, direito);

    Posicao indice[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - pontoMedio.x) < m)
            indice[j] = Py[i], j++;


    // a distância é indice []
    return indiceMaisProximo(indice, j, m);
}

float maisProxima(Posicao *P, int n)
{
    Posicao Posicaox[n];
    Posicao Posicaoy[n];
    for (int i = 0; i < n; i++)
    {
        Posicaox[i] = P[i];
        Posicaoy[i] = P[i];
    }

    qsort(Posicaox, n, sizeof(Posicao), classificarX);
    qsort(Posicaoy, n, sizeof(Posicao), classificarY);


    return utilMaisProximo(Posicaox, Posicaoy, n);
}





int main()
{
    Posicao p[] = {{3, 5}, {8, 10}, {12, 20}, {7, 18}, {14, 10}, {4, 12}};
    int n = sizeof(p) / sizeof(p[0]);
    cout << "A menor distancia " << maisProxima(p, n);
    return 0;
}
