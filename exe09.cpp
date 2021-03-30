//Implemente o algoritmo de busca em largura.

#include <iostream>
#include <list>
#include <queue> // fila

using namespace std;

class Grafo
{
    int V; // quantidade de vértices
    list<int> *adj; // ponteiro para um array

public:
    explicit Grafo(int V);
    void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo


    void bfs(int v);
};

Grafo::Grafo(int V)
{
    this->V = V; // atribui o número de vértices
    adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
    // adiciona vértice v2 à lista de vértices adjacentes de v1
    adj[v1].push_back(v2);
}

void Grafo::bfs(int v)
{
    queue<int> fila;
    bool visitados[V]; // visitados

    for(int i = 0; i < V; i++)
        visitados[i] = false;

    cout << "Visitando vertice " << v << " ...\n";
    visitados[v] = true; // marca como visitado

    while(true)
    {
        list<int>::iterator it;
        for(it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if(!visitados[*it])
            {
                cout << "Visitando vertice " << *it << " ...\n";
                visitados[*it] = true;
                fila.push(*it); // insere na fila
            }
        }

        // verifica se a fila NÃO está vazia
        if(!fila.empty())
        {
            v = fila.front(); // obtém o primeiro elemento
            fila.pop(); // remove da fila
        }
        else
            break;
    }
}

int main()
{
    int V = 12;

    Grafo grafo(V);

    // adicionando as arestas
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(1, 7);
    grafo.adicionarAresta(1, 8);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(2, 3);
    grafo.adicionarAresta(3, 4);
    grafo.adicionarAresta(3, 5);
    grafo.adicionarAresta(8, 9);
    grafo.adicionarAresta(8, 12);
    grafo.adicionarAresta(9, 10);
    grafo.adicionarAresta(9, 11);

    grafo.bfs(1);

    return 0;
}