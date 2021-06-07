//Implemente o m´etodo interpolation search.
#include<vector>
#include <iostream>

int interpolationSearch(std::vector<int> &vetor, int n, int elemento)
{

    int inicio = 0, fim = (n - 1);



    while (inicio <= fim && elemento >= vetor[inicio] && elemento <= vetor[fim])
    {
        if (inicio == fim)
        {
            if (vetor[inicio] == elemento)

                return inicio;


            return -1;
        }

        int posicao = inicio + (((double)(fim - inicio) /(vetor[fim] - vetor[inicio])) * (elemento - vetor[inicio]));

        //  ponto encontrado
        if (vetor[posicao] == elemento)
            return posicao;


        if (vetor[posicao] < elemento)
            inicio = posicao + 1;


        else
            fim = posicao - 1;
    }
    return -1;
}

int main()
{

    int num;

    // Vetor de itens em que a pesquisa irá
    // ser conduzido.

    std::cout<<"Digite um numero para pesquisa:\n";
    std::cin >> num;

    std::vector<int>vetor = {6,5,23,12,45,7, 1, 7, 2, 8, 9};
    int n = sizeof(vetor)/sizeof(vetor[0]);

    int elemento = num;
    int posicao = interpolationSearch(vetor, n, elemento);



    if(posicao != -1 )
        std::cout << "Numero encontrado!!!  ---  posicao:\n" << posicao;
    else
        std::cout<<"Numero nao encontrado.\n";

    return 0;
}