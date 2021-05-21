
/* C++ implementação QuickSort */
#include <bits/stdc++.h>
using namespace std;

//  troca dois elementos
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
       //põe o elemento em sua posição correta na classificação
       // array. Colocando todos elementos menores que o pivô)
        //à esquerda e todos os elementos maiores à direita
        //de pivô
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivô
    int i = (low - 1); //  indica a posição correta do pivô encontrado até agora

    for (int j = low; j <= high - 1; j++)
    {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot)
        {
            i++; // índice de incremento de elemento menor
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


// * A função principal que implementa QuickSort
//arr [] -> Array a ser classificado,
//     baixo -> Índice inicial,
//   alto -> Índice final * /


void quickSort(int arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
       //índice de particionamento, arr [p]
        int pi = partition(arr, baixo, alto);

        // Classifica os elementos separadamente antes
        // partição e depois da partição
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}


void imprimeArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    int arr[] = {9, 8, 7, 6, 2, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Array ordenado: \n";
    imprimeArray(arr, n);
    return 0;
}









