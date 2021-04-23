//Algoritmo Busca Binária
//divisão e conquista
//complexidade 	O(log n)  , Array


#include <iostream>


using namespace std;

int  main()
{
    int vector[20],tam,numPesquisado,pontoInical,pontoFinal;
    int posicaoVector,saida,valor;

    cout<<"Entre com o tamanho do vetor\t";
    cin >> tam;
    cout<<"\n Entre com os " << tam << " valores:\n";

    for(int i=0; i < tam; i++)
    {
        cin >> vector[i];
    }
    cout<<"Entre com o valor a ser buscado:\t";
    cin >> numPesquisado;
    pontoInical=0;
    pontoFinal= tam - 1;
    saida=0;

    while(pontoInical <= pontoFinal && saida == 0)
    {
        posicaoVector= (pontoInical + pontoFinal) / 2;
        if(numPesquisado > vector[posicaoVector])
        {
            pontoInical= posicaoVector + 1;
            valor= vector[posicaoVector];
        }
        else if(numPesquisado < vector[posicaoVector])
        {
            pontoFinal= posicaoVector - 1;
            valor=vector[posicaoVector];
        }
        else
            saida=1;
    }
    if(saida == 1)
        cout << "valor encontrado!!!! posicão no vetor :  " << posicaoVector ;
    else
        cout<<"valor não encontrado ";


}