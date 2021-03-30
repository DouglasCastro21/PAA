#include <iostream>
using namespace std;
//Implemente uma solu¸c˜ao baseada em busca exaustiva para o problema da Mochila (Knapsack
//Problem)

int knapsack(int capacidade_mochi, int pesos[], int beneficios[], int elementos)
{
    // tabela que será preenchida
    int V[elementos + 1][capacidade_mochi + 1];

    // inicializando a primeira linha e primeira coluna com 0
    for(int j = 0; j <= capacidade_mochi; j++)
        V[0][j] = 0;
    for(int i = 1; i <= elementos; i++)
        V[i][0] = 0;

    for(int i = 1; i <= elementos; i++)
    {
        for(int j = 1; j <= capacidade_mochi; j++)
        {
            // elemento pode fazer parte da solução
            if(pesos[i - 1] <= j)
            {
                // max...
                if((beneficios[i - 1] + V[i - 1][j - pesos[i - 1]]) > V[i - 1][j])
                    V[i][j] = beneficios[i - 1] + V[i - 1][j - pesos[i - 1]];
                else
                    V[i][j] = V[i - 1][j];
            }
            else
                V[i][j] = V[i - 1][j]; //capacidadeMochi > j
        }
    }

    // retorna o valor máximo colocado na mochila
    return V[elementos][capacidade_mochi];
}

int main(int argc, char *argv[])
{
    // capacidade máxima da mochila: capacidadeMochi
    int capacidadeMochi = 15;

    // número de elementos
    int elementos = 5;

    // vetor com os valores (benefício) de cada elemento
    int beneficios[] = {2, 5, 6, 4, 7};

    // vetor com os pesos de cada elemento
    int pesos[] = {7, 2, 5, 3, 3};

    // obtém o máximo valor que pode ser colocado na mochila
    int max_valor = knapsack(capacidadeMochi, pesos, beneficios, elementos);

    cout << "Valor maximo: " << max_valor << endl;

    return 0;
}