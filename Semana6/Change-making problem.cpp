#include <iostream>
//Implemente um algoritmo para o problema do troco (Change-making problem (Seção 8.1))
//utilizando programação dinâmica.


using namespace std;

int count(int Moedas[], int a, int b )
{
    int i, j, x, y;

    // Precisamos de b + 1 linhas como a tabela
    // valor caso baso (b = 0)
    int tabela[b + 1][a];

    for (i = 0; i < a; i++)
        tabela[0][i] = 1;

    // Preenche  a tabela
    for (i = 1; i < b + 1; i++)
    {
        for (j = 0; j < a; j++)
        {
            // Incluindo Moedas [j]
            x = (i - Moedas[j] >= 0) ? tabela[i - Moedas[j]][j] : 0;

            // excluindo Moedas[j]
            y = (j >= 1) ? tabela[i][j - 1] : 0;

            // total count
            tabela[i][j] = x + y;
        }
    }
    return tabela[b][a - 1];
}


int main()
{
    int array[] = {1, 2, 3,4,5,8,12};
    int x1 = sizeof(array) / sizeof(array[0]);
    int x2 = 5;
    cout << count(array, x1, x2);
    return 0;
}



