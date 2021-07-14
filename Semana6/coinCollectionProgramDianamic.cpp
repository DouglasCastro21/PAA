#include<bits/stdc++.h>
using namespace std;
#define A 7
#define B 7

//verifica se a célula atual está fora da grade ou não
bool Valido(int i, int j)
{
    return (i >=0 && i < A && j >= 0 && j < B);
}

//Esta função retorna
// número máximo de moedas que podem ser coletadas a partir de (i, j).
int maxCoinsRec(char array[A][B], int i, int j, int Direction)
{
    // é uma célula inválida ou se a célula é uma célula de bloqueio
    if (Valido(i, j) == false || array[i][j] == '#')
        return 0;

    // Verifique se esta célula contém a moeda 'C' ou se está vazia 'E'.
    int resultado = (array[i][j] == 'B') ? 1 : 0;

    // Obtenha no máximo dois casos quando você estiver voltado para a direita nesta célula
    if (Direction == 1)
        return resultado + max(maxCoinsRec(array, i + 1, j, 0),	 // baixa
                            maxCoinsRec(array, i, j + 1, 1)); // direita


    // Obtenha no máximo dois casos quando você estiver voltado para a esquerda nesta célula
    return resultado + max(maxCoinsRec(array, i + 1, j, 1), // baixa
                        maxCoinsRec(array, i, j - 1, 0)); // esquerda
}


int main()
{
    char array[A][B] = {{'E', 'B', 'B', 'B', 'B'},
                        {'B', '#', 'B', '#', 'E'},
                        {'#', 'B', 'B', '#', 'B'},
                        {'B', 'E', 'E', 'B', 'E'},
                        {'B', 'E', '#', 'B', 'E'}


    };

   // célula inicial é (0, 0) e a direção é direito
    cout << "O número máximo de moedas coletadas é "
         << maxCoinsRec(array, 0, 0, 1);

    return 0;
}
