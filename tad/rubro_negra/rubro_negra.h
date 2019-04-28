#ifndef RUBRO_NEGRA_RUBRO_NEGRA_H
#define RUBRO_NEGRA_RUBRO_NEGRA_H

// Definido as cores como "constantes" usando macros; Escolhi usar valores booleanos para as cores
#define BLACK true
#define RED false

struct no
{
	struct no *pai, *esq, *dir;
	bool cor;
	int valor;

	// Construtor para o T.nil
	no(){
		this->pai = this->esq = this->dir = nullptr;
		this->cor = BLACK;
	}

	// Construtor comum, não definimos a cor já que na inserção a adicionados
	no(int valor){
		this->valor = valor;
		this->cor = RED;
	}
};

typedef struct no* No;

class RBTree {

private:

	No nil = new no();
	No raiz = nil;

	void visitar(No);
	int _abb_altura(No);
	void _abb_pre_ordem(No);

	No abb_minimo(No);
	No buscar_no(int);
	No _buscar_no(No, int);

	int ab_num_filhos(No);
	void rotacao_esquerda(No);
	void rotacao_direita(No);
	void balancear_inserir(No);
	void substitui(No, No);
	void deletar_remocao(No);
	void balancear_remocao(No);

public:
	~RBTree();
	int abb_altura();
	void inserir(int);
	void remover(int);
	void abb_pre_ordem();
};

#endif //RUBRO_NEGRA_RUBRO_NEGRA_H