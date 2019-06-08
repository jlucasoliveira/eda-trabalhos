#include "Grafo.h"
#include <iostream>
#include <list>

using namespace std;

struct no
{
    unsigned int cor:1;
    int d, valor;
    struct no* pai;

    no(){}

    no(int valor, int cor, int distancia, struct no* pai)
    {
        this->valor = valor;
        this->cor = cor;
        this->d = distancia;
        this->pai = pai;
    }

};

Grafo::Grafo(int vertices, bool direcionado)
{
    this->V = vertices;
    this->direcionado = direcionado;
    this->listAdj = new list<int>[this->V];
}

Grafo::~Grafo()
{
    for (int i = 0; i < this->V; i++)
        listAdj[i].clear();
    delete listAdj;
}

void Grafo::addAresta(int u, int v)
{
    listAdj[u].push_back(v);
    if (!direcionado) listAdj[v].push_back(u);
}

void Grafo::removerAresta(int u, int v)
{
    listAdj[u].remove(v);
    if (!direcionado) listAdj[v].remove(u);
}

bool Grafo::temAresta(int u, int v)
{
    list<int>::iterator it;

    for (it = this->listAdj[u].begin(); it != this->listAdj[u].end(); it++)
        if (*it == v) return true;

    return false;
}

void Grafo::imprimeListaAdj()
{
    for (int i = 0; i < this->V; i++)
    {
        cout << "Lista de adjacencia de " << i << ": ";
        for (int it : listAdj[i])
            cout << it << " ";
        cout << endl;
    }
}
