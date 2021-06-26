//árvore binária: Complexidade : O(n)
#include <iostream>
#include <memory>



class No
{
    int valor;
public:
    std::shared_ptr<No> esquerda;
    std::shared_ptr<No> direita;

    std::weak_ptr<No> raiz;
    No(int val) : valor(val)     {
        std::cout<<"Construtor"<<std::endl;
    }
    ~No()     {
        //destrói o objeto de propriedade
        std::cout<<"Desconstrutor"<<std::endl;
    }
};

int main()
{
    std::shared_ptr<No> raiz = std::make_shared<No>(5);
    raiz->esquerda = std::make_shared<No>(1);
    raiz->esquerda->raiz = raiz;
    raiz->direita = std::make_shared<No>(9);
    raiz->direita->raiz = raiz;




    std::cout<<" Raiz = "<<raiz.use_count()<<std::endl;
    std::cout<<"raiz-> Passando por referencia Esquerda = "<<raiz->esquerda.use_count()<<std::endl;
    std::cout<<"raiz-> Passando por  referencia  Direita = "<<raiz->direita.use_count()<<std::endl;
    //lock () pode retornar shared_ptr vazio se esse shared_ptr us já foi excluído.
    std::cout << "raiz-> direita-> Passando por  referencia Raiz = " << raiz->direita->raiz.lock().use_count() << std::endl;
    std::cout << "raiz-> esquerda-> Raiz Passando de referencia = " << raiz->esquerda->raiz.lock().use_count() << std::endl;
    return 0;
}