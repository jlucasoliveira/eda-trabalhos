//lista Grafos 
// MATRIX

Grafo* Grafo::complement()
{
    Grafo *c = new Grafo(this->V, this->direcionado);

    for (int i = 0; i < 10; i++)
        for (int j = 0; i < 10; j++)
            if (!this->hasEdge(i, j)) c->addEdge(i, j);
        
    return c;
}

bool Grafo::isDirect()
{
    for (int i = 0; i < this->V; i++)
        for (int j = 0; j < this->V; j++)
            if (this->M[i][j] != this->M[j][i]) return false;
    return true;
}

struct no
{
    signed int cor:2;
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

struct noD
{
    unsigned int cor:1;
    int d, f, valor;
    struct noD* pai;

    noD(){}

    noD(int valor, int cor, int d, int f, struct noD* pai)
    {
        this->valor = valor;
        this->cor = cor;
        this->d = d;
        this->f = f;
        this->pai = pai;
    }

};

No* Grafo::bfs(int starter)
{
    No* v = new no[this->V];
    for (int i = 0; i < this->V; i++)
        if (i != starter) v[i] = *(new no(i, WHITE, INT_MAX, nullptr));

    No s = *(new no(starter, GREY, 0, nullptr));
    v[starter] = s;

    queue<No> *q = new queue<No>;
    q->push(s);
    while(!q->empty())
    {
        No u = q->front();
        q->pop();
        for (int i = 0; i < this->V; i++)
            if (this->M[u.valor][i])
                if (v[i].cor == WHITE)
                {
                    v[i].cor = GREY;
                    v[i].d = u.d+1;
                    v[i].pai = &v[u.valor];
                    q->push(v[i]);
                }

    }
    delete q;
    return v;
}

string pai(No* pai)
{
    if (pai == nullptr) return "[inicial]";
    return to_string(pai->valor);
}

void Grafo::imprimeNFS(No* v)
{
    for (int i = 0; i < this->V; i++)
        cout << "[ no= " << v[i].valor << ", d= " << v[i].d << ", pai= " << pai(v[i].pai) << ", cor= " << v[i].cor << " ]" << endl;
}

bool Grafo::kColoracoes(int starter)
{
    No* v = new no[this->V];
    for (int i = 0; i < this->V; i++)
        v[i] = *(new no(i, UNCHECKED, INT_MAX, nullptr));

    v[starter].cor = WHITE;
    v[starter].d = 0;

    queue<No> *q = new queue<No>;
    q->push(v[starter]);
    while (!q->empty())
    {
        No u = q->front();
        q->pop();
        for (int i = 0; i < this->V; i++)
            if (this->M[u.valor][i])
            {
                if (v[i].cor == UNCHECKED)
                {
                    v[i].cor = !u.cor;
                    v[i].d = u.d+1;
                    v[i].pai = &v[u.valor];
                    q->push(v[i]);
                }
                else if (v[i].cor == u.cor)
                {
                    delete q;
                    return false;
                }
            }
    }

    this->imprimeNFS(v);
    delete q;
    return true;

}

NoD* Grafo::dfs(int starter)
{
    NoD* v = new noD[this->V];
    stack<NoD> *s = new stack<NoD>;

    for (int i = 0; i < this->V; i++)
        v[i] = *(new noD(i, WHITE, 0, 0, nullptr));

    int tempo = 0;
    for (int i = 0; i < this->V; i++)
        if (v[i].cor == WHITE)
        {
            s->push(v[i]);
            while (!s->empty())
            {
                NoD n = s->top();
                n.d = ++tempo;
                n.cor = GREY;
                for (int j = 0; j < this->V; j++)
                    if (this->M[n.valor][j])
                        if (v[j].cor == WHITE)
                        {
                            v[j].pai = &v[n.valor];
                            s->push(v[j]);
                            break;
                        }
                n.f = ++tempo;
            }
        }

    delete s;
}

////
////

// list Adj

Grafo* Grafo::transposto()
{
    Grafo *gpi = new Grafo(this->V, this->direcionado);
    list<int>::iterator it;

    for (int i = 0; i < this->V; i++)
    {
        if (!listAdj[i].empty())
            for (it = this->listAdj[i].begin(); it != this->listAdj[i].end(); it++)
                gpi->listAdj[*it].push_back(i);
    }

    return gpi;
}

Grafo* Grafo::multigraph(){
    Grafo *m = new Grafo(this->V, false);

    for (int i = 0; i < this->V; i++)
        for (int j = 0; j < this->V; j++)
            if (i != j && this->temAresta(i, j) && this->temAresta(j, i)) m->addAresta(i, j);
    return m;
}

