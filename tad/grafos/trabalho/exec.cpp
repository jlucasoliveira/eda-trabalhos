/*
    Aluno: José Lucas Oliveira da Silva
    Matrícula: 0421691
*/

#include "GrafoM.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

vector<Grafo*>* get_from_file(string file, bool diretecd)
{
    ifstream fileOpened(file);
    vector<Grafo*> *graphs = new vector<Grafo*>;

    int degreeGraph, u, v;
    string line;

    while(getline(fileOpened, line))
    {
        stringstream sg(line);
        sg >> degreeGraph;
        if (degreeGraph == 0) break;
        Grafo *graph = new Grafo(degreeGraph, diretecd);
        while(getline(fileOpened, line))
        {
            stringstream uv(line);
            uv >> u >> v;
            if (u == 0 && v == 0) break;
            graph->addEdge(u, v);
        }
        graphs->push_back(graph);
    }

    fileOpened.close();
    return graphs;
}

void delete_graphs(vector<Grafo*> *graphs)
{
    for (Grafo *graph : *graphs)
        delete graph;
    delete graphs;
}

int main()
{   
    
    srand(time(NULL));
    vector<Grafo*> *grafos1 = get_from_file("grafos1.txt", false);

    /*
    // QUESTAO 1

    for (Grafo *grafo : *grafos1)
    {
        int rn = rand()%(grafo->getNumberVertex());
        grafo->coloringWithTwoColors(rn);
    }
    */

    //QUESTAO 2

    for (Grafo *grafo : *grafos1)
    {
        grafo->printMatrix();
        cout << endl;
        grafo->detectingQuatraticCycles();
        cout << endl;
    }

    delete_graphs(grafos1);
}
