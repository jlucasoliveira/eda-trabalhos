/*
    Aluno: José Lucas Oliveira da Silva
    Matrícula: 0421691
*/

#include "GrafoM.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

vector<Grafo*>* get_from_file(string file)
{
    ifstream fileOpened(file);
    vector<Grafo*> *grafos = new vector<Grafo*>;

    string qtdeGrafo;
    while (getline(fileOpened, qtdeGrafo))
    {
        if (qtdeGrafo.empty() || stoi(qtdeGrafo) == 0) continue;
        string u, v;
        Grafo *grafo = new Grafo(stoi(qtdeGrafo), true);
        while (getline(fileOpened, u) && !u.empty())
        {
            getline(fileOpened, v);
            grafo->addEdge(stoi(u), stoi(v));
        }
        grafos->push_back(grafo);
    }
    fileOpened.close();
    return grafos;
}

void delete_graphs(vector<Grafo*> *grafos)
{
    for (Grafo *grafo : *grafos)
        delete grafo;
    delete grafos;
}

int main()
{   
    // QUESTAO 1
    srand(time(NULL));
    vector<Grafo*> *grafos1 = get_from_file("grafos1.txt");
    for (Grafo *grafo : *grafos1)
    {
        int rn = rand()%(grafo->getNumberVertex());
        //grafo->coloringWithTwoColors(rn);
        grafo->printMatrix();
        cout << endl;
        grafo->detectingQuatraticCycles();
        cout << endl;
    }

    //QUESTAO 2

    delete_graphs(grafos1);
}
