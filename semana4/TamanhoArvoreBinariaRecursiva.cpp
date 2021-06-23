// calcula o tamanho da árvore Binaria
#include <bits/stdc++.h>


class no
{
    public:
    int dados;
    no* esquerdo;
    no* direito;
};
no* novoNo(int dados)
{
    no* No = new no();
    No->dados = dados;
    No->esquerdo = NULL;
    No->direito = NULL;

    return(No);
}

//calcula o tam Nó
int size(no* no)
{
    if (no == NULL)
        return 0;
    else
        return(size(no->esquerdo) + 1 + size(no->direito));
}

int main()
{
    no *raiz = novoNo(0);
    raiz->esquerdo = novoNo(8);
    raiz->direito = novoNo(0);
    raiz->esquerdo->esquerdo = novoNo(4);
    raiz->esquerdo->direito = novoNo(2);
    raiz->esquerdo->esquerdo = novoNo(8);
    raiz->esquerdo->direito = novoNo(7);
    raiz->esquerdo->esquerdo = novoNo(12);
    raiz->esquerdo->direito = novoNo(43);

    std::cout << "O tamanho da arvore Binaria é : " << size(raiz);
    return 0;
}
