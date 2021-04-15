#include <cstdlib>
#include <iostream>

// Funçāo desse algoritmo: ordena um array. Primeiro divide-se o array em duas partes;
//uma parte contém o array ordenado, a outra os arrays desordenados. A cada etapa pegamos
// o elemento e o ordenamos no local apropriado, o array vai perdendo elementos até que ele seja ordenado.
//Pega-se o primeiro elemento do array Nāo ordenado e acha o seu local no array ordenado, compara-se com
// a primeira posiçāo atrás dele, se é menor eu posso inverter a posiçāo. A cada chamada identifica a posiçāo
//anterior ao elemento. Caso o número já esteja ordenado, nāo faço alteraçāo.

using namespace std;

int main(int argc, char** argv) {
    double notas[10] = {9, 6, 5, 9, 8, 10, 9.6, 8.5, 9.9, 7.9};
    double aux;

    for(int i=0; i<9; i++){
     
     
        for(int j=i+1; j>0; j--) {
            
            
            if(notas[j] < notas[j-1]){
                aux = notas [j];
                notas [j] = notas[j-1];
                notas [j-1] = aux;
            }
            else
                break;
        }
    }
    for(int i=0; i<10; i++)
        cout << notas[i] << endl;
    cout << endl;
    return 0;

}
