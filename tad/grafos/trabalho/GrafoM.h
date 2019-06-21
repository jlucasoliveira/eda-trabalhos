/*
    Aluno: José Lucas Oliveira da Silva
    Matrícula: 0421691
*/

#ifndef GRAFO_M_H
#define GRAFO_M_H

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
    int getNumberVertex();
    bool isDirected();
    
    // Questao 1
    void coloringWithTwoColors(int);

    // Questao 2
    void detectingQuatraticCycles();

};

#endif //GRAFO_M_H