/* Implemente a estrutura de dados binary search tree e os m´etodos buscarNoArvore e inserir.
   Árvore de pesquisa e inserção binária
   Uma árvore binária de busca serve para o armazenamento de dados na
    memória do computador e a sua subseqüente recuperação
    árvores binárias recursivamente.

   Complexidade:    O(log n)
*/
#include<iostream>
using namespace std;
// Defini o Nó
struct NoArvore {
    int dados;
    NoArvore* comeco;           //   comeco <== ||  ==>fim
    NoArvore* fim;
};

// cria um novo Nó
NoArvore* ObterNovoNoArvore(int dados) {
    NoArvore* novoNoArvore = new NoArvore();
    novoNoArvore->dados = dados;
    novoNoArvore->comeco = novoNoArvore->fim = NULL;
    return novoNoArvore;
}

// insere um novo Nó
NoArvore* InserirNoArvore(NoArvore* raiz, int dados) {
    if(raiz == NULL) {
        raiz = ObterNovoNoArvore(dados);
    }
        //  insira na subárvore esquerda.
    else if(dados <= raiz->dados) {
        raiz->comeco = InserirNoArvore(raiz->comeco, dados);
    }
        // insira na subárvore direita.
    else {
        raiz->fim = InserirNoArvore(raiz->fim, dados);
    }
    return raiz;
}
/*
	Pesquisar um elemento Na Arvore,
*/
bool buscarNoArvore(NoArvore* raiz, int dados) {
    if(raiz == NULL) {
        return false;
    }
    else if(raiz->dados == dados) {
        return true;
    }
    else if(dados <= raiz->dados) {
        return buscarNoArvore(raiz->comeco, dados);
    }
    else {
        return buscarNoArvore(raiz->fim, dados);
    }
}
int main() {
    NoArvore* raiz = NULL;
    raiz = InserirNoArvore(raiz, 10);
    raiz = InserirNoArvore(raiz, 11);
    raiz = InserirNoArvore(raiz, 12);
    raiz = InserirNoArvore(raiz, 13);
    raiz = InserirNoArvore(raiz, 14);
    raiz = InserirNoArvore(raiz, 15);
    raiz = InserirNoArvore(raiz, 16);
    raiz = InserirNoArvore(raiz, 17);
    raiz = InserirNoArvore(raiz, 18);
    raiz = InserirNoArvore(raiz, 19);
    raiz = InserirNoArvore(raiz, 20);
    raiz = InserirNoArvore(raiz, 21);

    int numero;
    cout<<"Pesquisar numero:\t";
    cin>>numero;
    // Se o número for encontrado, imprima

    if(buscarNoArvore(raiz, numero) == true)
        cout << "Encontrado!!!!\n";
        else cout<<"Não encontrado\n";
}
