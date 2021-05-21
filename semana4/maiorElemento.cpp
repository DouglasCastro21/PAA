#include <iostream>
#include <vector>


void imprimiElementos(std::vector<int>& elementos){
    std::cout << "Vetor de elementos: ";
    for (auto i : elementos)
        std::cout << i << " ";
    std::cout << std::endl;
}

// Encontra o elemento máximo
int maiorElemento(std::vector<int>& elementos){
    int maiorElemento=elementos.front();
    for( int i = 1; i< elementos.size(); i++){
        if(elementos[i] > maiorElemento){
            maiorElemento=elementos[i];
        }
    }
    return maiorElemento;
}

int main()
{



    std::vector<int> elementos = {34,65,8,5,12,9,21};

    imprimiElementos(elementos);



    std::cout << "Vetor com o maior elemento: " << maiorElemento(elementos) << "\n";


}