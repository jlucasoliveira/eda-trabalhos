/*
    Aluno: José Lucas Oliveira da Silva
    Matrícula: 0421691
*/

#include "GrafoM.h"
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

Grafo::Grafo(int vertices, bool directed)
{
    this->V = vertices;
    this->directed = directed;
    this->M = new int*[this->V];

    for (int i = 0; i < this->V; i++)
       this->M[i] = new int[this->V];

    for (int i = 0; i < this->V; i++)
        for (int j = 0; j <this->V; j++)
            this->M[i][j] = 0;
}

Grafo::~Grafo()
{
    for (int i = 0; i < this->V; i++)
        delete[] this->M[i];
    delete[] this->M;
}

void Grafo::addEdge(int u, int v)
{
    if (u >= this->V || v >= this->V)
    {
        cout << "Valor(es) incorreto(s)...";
        return;
    }
    this->M[u][v] = 1;
    if (!this->directed) this->M[v][u] = 1;
}

void Grafo::removeEdge(int u, int v)
{
    this->M[u][v] = 0;
    if (!this->directed) this->M[v][u] = 0;
}

bool Grafo::hasEdge(int u, int v)
{
    return this->M[u][v] == 1?true:false;
}

void Grafo::printNeighbour(int u)
{
    for (int i = 0; i < this->V; i++)
        if (this->M[u]) cout << i << " ";
}

void Grafo::printMatrix()
{
    for (int i = 0; i < this->V; i++)
    {
        for (int j = 0; j < this->V; j++)
            cout << std::setw(1) << this->M[i][j] << " ";
        cout << endl;
    }
}

int Grafo::degree(int u)
{
    int count = 0;
    for (int i = 0; i < this->V; i++)
    {
        if (this->M[u][i]) count++;
        if (this->directed && this->M[i][u]) count++;
    }

    return count;
}

int Grafo::getNumberVertex()
{
    return this->V;
}

bool Grafo::isDirected()
{
    return this->directed;
}

// QUESTAO 1


// No de arvore em largura do grafo gerada pelo BFS alterado para o problema
typedef struct no
{
    int value;
    signed tag:3; // ja precisamos de apenas 3 estados precisamos apenas de 3 bits sendo 1 para sinal, neste caso

    no(){}

    // construtor padrao usado para simplificar a marcacao inicial do algoritmo
    no (int value)
    {
        this->value = value;
        this->tag = UNCHECKED;
    }

    no(int value, int tag)
    {
        this->value = value;
        this->tag = tag;
    }

    // ja que nao crio nenhum ponteiro na struct implementarei o destrutor vazio
    ~no(){}

} No;


void deleteTree(No** tree, int size)
{
	// deletando a arvore criada
	for (int index = 0; index < size; index++)
		delete tree[index];
	delete[] tree;
}

string color(int tag)
{
	if (tag == WHITE) return "R";
	return "B";
}

void printBFSChanged(No** bsfTree, int size)
{
	for (int index = 0; index < size; index++)
		cout << bsfTree[index]->value << " " << color(bsfTree[index]->tag) << endl;
}

void Grafo::coloringWithTwoColors(int starter)
{
    int size = this->V;
    No** bsfTree = new no*[size];
    
    // preenchendo a arvore com os valores padrao e o valor de cada vertice
    // dereferenciei o objeto criado
    for (int index = 0; index < size; index++)
        if (index != starter) bsfTree[index] = new no(index);

	// criando a raiz da arvore
    bsfTree[starter] = new no(starter, WHITE);
	// fila para a ordem de procedencia na visita
    queue<No*> *q = new queue<No*>;
    q->push(bsfTree[starter]);
    //printBFSChanged(bsfTree, size);
    // enquanto houverem nos alcancaveis o algoritmo sera executado
    while (!q->empty())
	{
    	// guardando o primeiro no da fila
    	No* current = q->front();
    	q->pop();
    	for (int index = 0; index < size; index++)
    		if (current->value != index && this->hasEdge(current->value, index))
			{
    			if (bsfTree[index]->tag == UNCHECKED)
				{
    				bsfTree[index]->tag = !current->tag;
                    //cout << "cor: " << bsfTree[index]->tag << endl;
    				q->push(bsfTree[index]);
				}
    			else if (bsfTree[index]->tag == current->tag)
				{
    				deleteTree(bsfTree, size);
    				delete q;
    				cout << "NAO" << endl;
                    return;
				}
			}
	}

    cout << "SIM" << endl;
    printBFSChanged(bsfTree, size);

    deleteTree(bsfTree, size);
    delete q;
}


void Grafo::detectingQuatraticCycles()
{
    int size = this->V;

    int mult[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mult[i][j] = 0;
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                mult[i][j] += this->M[i][k] * this->M[k][j];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << std::setw(1) << mult[i][j] << " ";
        cout << endl;
    }
}