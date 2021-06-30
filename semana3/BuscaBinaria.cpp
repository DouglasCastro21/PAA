//Algoritmo Busca Binária
//divisão e conquista
//complexidade 	O(log n) 

#include <iostream>
#include "vector"

   

int buscaBinaria(std::vector<int> &vetor, int esquerdo, int direito, int chave)

{
    int meio = (esquerdo + direito) / 2; 

    if (esquerdo > direito) 
    {
        return -1;
    }

    if (vetor[meio] == chave) 
    {
        return meio;
    }

    if (vetor[meio] < chave){ 
        return buscaBinaria(vetor, meio + 1, direito, chave); 
    }
    else{ 
        return buscaBinaria(vetor, esquerdo, meio - 1, chave); 
    }
}

int main()
{
    int k;
    std::cout << "Digite o numero a ser pesquisado:\n";
    std::cin >> k;
    std::vector<int> vector = {1, 2, 4, 5, 6, 7, 8, 9, 0};

    if (buscaBinaria(vector, 0, vector.size(), k) >= 0)
    {
        std::cout << "Encontrado" << std::endl;
    }
    else
    {
        std::cout << "Nao encontrado" << std::endl;
    }

    return 0;
}
