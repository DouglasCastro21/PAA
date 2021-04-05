// *Implemente uma solu¸c˜ao baseada em busca exaustiva para o problema do Caixeiro Viajante
//(Traveling Salesman Problem).

#include<iostream>
using namespace std;
int c = 0,cost = 500;
int graph[4][4] = { {3, 16, 35, 25},
                    {19, 5, 35, 15},
                    {12, 35, 7, 23},
                    {22, 15, 50, 1}
};
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void copiaArray(int *a, int n)
{
    int i, sum = 0;
    for(i = 0; i <= n; i++)
    {
        sum += graph[a[i % 4]][a[(i + 1) % 4]];
    }
    if (cost > sum)
    {
        cost = sum;
    }
}
void trocar(int *a, int i, int n)
{
    int j, k;
    if (i == n)
    {
        copiaArray(a, n);
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            trocar(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
}
int main()
{
    int i, j;
    int a[] = {0, 1, 2, 3};
    trocar(a, 0, 3);
    cout<<"Menor percuso:"<<cost<<endl;
  //  getch();
}