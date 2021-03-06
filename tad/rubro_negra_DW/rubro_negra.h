#ifndef RUBRO_NEGRA_RUBRO_NEGRA_H
#define RUBRO_NEGRA_RUBRO_NEGRA_H
#define BLACK true
#define RED false
#include <iostream>

struct no
{
	struct no* pai;
	struct no* esq;
	struct no* dir;
	bool cor;
	int valor;

	no(){
		this->pai = nullptr;
		this->esq = nullptr;
		this->dir = nullptr;
		this->cor = BLACK;
	}

	no(int valor){
		this->valor = valor;
	}
};

typedef struct no* No;

class RBTree {

private:

	No nil = new no();
	No raiz = nil;

	void visitar(No no);
	std::string cor_string(bool cor);
	int _abb_altura(No no);
	void _abb_pre_ordem(No no);
	void _abb_in_ordem(No no);
	void _abb_pos_ordem(No no);

	No minimo(No no);
	No buscar_no(int valor);
	No _buscar_no(No no, int valor);

	void rotacaoEsquerda(No x);
	void rotacaoDireita(No x);
	void balancear_inserir(No z);
	void transplante(No u, No v);
	void deletar_remocao(No z);
	void balancear_remocao(No x);

public:

	int abb_altura();
	void inserir(int valor);
	void remover(int valor);
	
	void abb_pre_ordem();
	void abb_in_ordem();
	void abb_pos_ordem();
};

#endif //RUBRO_NEGRA_RUBRO_NEGRA_H