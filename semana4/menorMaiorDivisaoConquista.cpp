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

// Encontra o elemento mínimo
int menorElemento(std::vector<int>& elementos){
    int  menorElemento=elementos.front();
    for( int i = 1; i< elementos.size(); i++){
        if(elementos[i] < menorElemento){
            menorElemento=elementos[i];
        }
    }
    return menorElemento;
}

int main()
{



    std::vector<int> elementos = {9, 6, 3, 2, 8,5,4,1,7,0};

    imprimiElementos(elementos);

    std::cout << "Vetor com o menor elemento: " << menorElemento(elementos) << "\n";



    std::cout << "Vetor com o maior elemento: " << maiorElemento(elementos) << "\n";


}
