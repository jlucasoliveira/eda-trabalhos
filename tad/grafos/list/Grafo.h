#ifndef GRAFO_H
#define GRAFO_H

#include <list>

struct no;
typedef struct no No;

class Grafo
{

private:

    int V;
    bool direcionado;
    std::list<int> *listAdj;
    void removerLista(std::list<int>, int);

public:

    Grafo(int, bool);
    ~Grafo();

    void addAresta(int, int);
    void removerAresta(int, int);
    bool temAresta(int, int);
    void imprimeListaAdj();
    Grafo* transposto();
    Grafo* multigraph();

    No* bfs(int);
    void imprimeBFS(No*);
};

#endif //GRAFO_H