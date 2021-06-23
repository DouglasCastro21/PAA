// Algoritmo do Caminhamentos  preorder, postorder e inorder para Árvore Binária.
#include <iostream>
using namespace std;


struct No {
    int dados;
    struct No *esquerda, *direita;
    No(int dados)
    {
        this->dados = dados;
        esquerda = direita = NULL;
    }
};

// Pré-ordem:
void Preorder(struct No* no)
{
    if (no == NULL)
        return;


    cout << no->dados << " ";
    Preorder(no->esquerda);
    Preorder(no->direita);
}

//Pós-ordem
void Postorder(struct No* no)
{

    if (no == NULL)
        return;

    Postorder(no->esquerda);
    Postorder(no->direita);
    cout << no->dados << " ";
}

// Em ordem
void Inorder(struct No* no)
{
    if (no == NULL)
        return;


    Inorder(no->esquerda);
    cout << no->dados << " ";
    Inorder(no->direita);
}

int main()
{
    struct No* raiz = new No(6);
    raiz->esquerda = new No(5);
    raiz->direita = new No(4);
    raiz->esquerda->esquerda = new No(3);
    raiz->esquerda->direita = new No(2);
    raiz->direita->direita = new No(1);

    cout << "\nPre-ordem da arvore binaria: \n";
    Preorder(raiz);

    cout << "\nPos-ordem da arvore binaria: \n";
    Postorder(raiz);

    cout << "\nEm ordem  da arvore binaria:\n";
    Inorder(raiz);

    return 0;
}