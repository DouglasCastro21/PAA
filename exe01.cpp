#include <iostream>
//Implementar o algoritmo Bubble Sort
using namespace std;

int main()
{
     int TAM;
     int i, aux, contador;

     cout << "Entre com o tamanho do vetor \n";
     cin >> TAM;

     int numeros[TAM];

    cout << "Entre com os " << TAM << " números e pressione enter, após digitar cada um:\n";
    for (i = 0; i < TAM; i++) {
        cin >> numeros[i];
    }
    printf("Ordem atual do array:\n");
    for (i = 0; i < TAM; i++) {
        cout <<numeros[i]<<" ";
    }
// Bubblesort:
    for (contador = 1; contador < TAM; contador++) {
        for (i = 0; i < TAM - 1; i++) {
            if (numeros[i] > numeros[i + 1]) {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
            }
        }
    }
    cout <<"\n Ordenados:\n";
    for (i = 0; i < TAM; i++) {
        cout << numeros[i]<<" ";
    }
    cout <<"\n";
    return 0;
}
