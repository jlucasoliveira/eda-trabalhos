#ifndef RUBRO_NEGRA_RUBRO_NEGRA_H
#define RUBRO_NEGRA_RUBRO_NEGRA_H

// Definido as cores como "constantes" usando macros; Escolhor usar valores booleanos para as cores
// já que o custo é de um bit
#define BLACK true
#define RED false

#include <iostream>

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
	}

	~no(){
		delete this;
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

	No minimo(No no);
	No buscar_no(int valor);
	No _buscar_no(No no, int valor);

	void rotacao_esquerda(No x);
	void rotacao_direita(No x);
	void balancear_inserir(No z);
	void transplante(No u, No v);
	void deletar_remocao(No z);
	void balancear_remocao(No x);

public:

	int abb_altura();
	void inserir(int valor);
	void remover(int valor);
	void abb_pre_ordem();
};

#endif //RUBRO_NEGRA_RUBRO_NEGRA_H