/*
    Aluno: José Lucas Oliveira da Silva
    Matrícula: 0421691
*/

#ifndef GRAFO_M_H
#define GRAFO_M_H

#define WHITE 0
#define GREY 1
#define UNCHECKED -1

struct no;
typedef struct no No;

class Grafo
{

private:
    int **M;
    int V;
    bool directed;

public:

    Grafo(int, bool);
    ~Grafo();

    void addEdge(int, int);
    void removeEdge(int, int);
    bool hasEdge(int, int);
    void printNeighbour(int);
    void printMatrix();
    int degree(int);
    void coloringWithTwoColors(int);
    int getNumberVertex();

};

#endif //GRAFO_M_H