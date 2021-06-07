//Mediana
#include <iostream>





int main()
{
    int tam = 0;
    float mediana ;


    std::cout << "qtd de numeros que seram digitados ?";
    std::cin >> tam;

    int vector[tam];
    if (tam <= 0)
    {
        return 0;
    }else {
        std::cout << "Digite o numero\n ";
        for (int i = 0; i < tam; i++) {


            std::cin >> vector[i];
        }
    }



    if (tam % 2 != 0)
    {
        mediana = vector[tam / 2]; //pega o elemento do meio
    }
    else
    {
        mediana = (float)(vector[tam / 2 - 1] + vector[tam / 2]) / 2;
    }

    std::cout << "Mediana: \n";
    std::cout << mediana << std::endl;

    return 0;
}