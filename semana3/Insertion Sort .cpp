/*
    Algoritmo Insertion Sort em C++
    //na pior hipotese o algoritmo sera O(n²).. ordem decrescente como descrito no
     elementos_lista
*/
#include <iostream>
#include <vector>



int main ()
{
    std::vector<int> elementos_lista = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    std::cout<<"\n Entrada dos dados: \n";
    for(int i=0;i<16;i++)
    {
       std::cout <<elementos_lista[i]<<"\t";
    }
    // for da posição dados
    for(int psDados=1; psDados<16; psDados++)
    {
        int lista_temp = elementos_lista[psDados];
        int j= psDados-1;
        // enquanto houver posições válidas  faça ...


        while(j>=0 && lista_temp <= elementos_lista[j])
        {
            // Pega o numero que tá na posição e passa ele para frente
            elementos_lista[j+1] = elementos_lista[j];
            j = j-1;
        }
        elementos_lista[j+1] = lista_temp;
    }
    std::cout<<"\n Lista ordenada: \n";
    for(int i=0;i<16;i++)
    {
        std::cout <<elementos_lista[i]<<"\t";
    }
}

