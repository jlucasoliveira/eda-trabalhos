#include "matrix/GrafoM.h"
#include <tgmath.h>
#include <iostream>

using namespace std;
/* 17
int k_regular(Grafo *g)
{
    int i = 0;
    while (i < 9)
    {
        if (g->degree(i) != g->degree(i+1))
        {
            cout << "NAO";
            return;
        }
        i++;
    }
    cout << "SIM";
    return g->degree(0);
}
*/


int main()
{
    Grafo *g = new Grafo(4, false);

    g->addEdge(0, 1);
    g->addEdge(1, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 0);
    g->printMatrix();
    //g->addEdge(2, 9);
    //g->addEdge(0, 6);
    //g->addEdge(4, 9);
    //g->addEdge(2, 6);
    //g->addEdge(6, 4);
}