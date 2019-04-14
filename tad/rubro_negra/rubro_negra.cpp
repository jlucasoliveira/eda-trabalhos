#include <iostream>
#include "rubro_negra.h"

using namespace std;

// Para a melhor visualização das cores já que obtei em usar valores booleanos
string RBTree::cor_string(bool cor){
	if (cor) return "BLACK";
	return "RED";
}

void RBTree::visitar(No no)
{
	cout << "[ valor= " << no->valor << " , cor= " << RBTree::cor_string(no->cor) << " ] ";
}

No RBTree::_buscar_no(No no, int valor)
{
	if (no == this->nil) return nullptr;
	else if (no->valor == valor) return no;
	else if (no->valor < valor) return _buscar_no(no->dir, valor);
	else return _buscar_no(no->esq, valor);
}

No RBTree::buscar_no(int valor)
{
	return _buscar_no(this->raiz, valor);
}

void RBTree::_abb_pre_ordem(No no)
{
	if (no == this->nil) return;
	visitar(no);
	_abb_pre_ordem(no->esq);
	_abb_pre_ordem(no->dir);
}

/*
 * Função usada apenas para chamar a real função de percurso em pré ordem, respeitando o encapsulamento
 */

void RBTree::abb_pre_ordem()
{
	return _abb_pre_ordem(this->raiz);
}

int RBTree::_abb_altura(No no)
{
	if (no == this->nil) return 0;
	int esq = _abb_altura(no->esq);
	int dir = _abb_altura(no->dir);
	return 1 + (esq > dir ? esq : dir);
}

/*
 * Função "Externa" de altura; Como a função é recursiva (no caso), e sempre chamará a raiz,
 * criei essa função apenas para facilar a chamado da anterior. Respeitando o encapsulamento.
 */

int RBTree::abb_altura()
{
	return _abb_altura(this->raiz);
}

/*
 * Retorna o nó com o menor valor da árvore/subarvore
 * --Usado pra encontrar o sucessor de um nó a ser removido caso o mesmo tenha dois.
 */

No RBTree::minimo(No no){
	if (no->esq == this->nil) return no;
	return minimo(no->esq);
}

void RBTree::rotacaoEsquerda(No x){
	No y = x->dir;
	x->dir = y->esq;
	if (y->esq != this->nil) y->esq->pai = x;
	y->pai = x->pai;
	if (x->pai == this->nil) this->raiz = y;
	else if (x == x->pai->esq) x->pai->esq = y;
	else x->pai->dir = y;
	y->esq = x;
	x->pai = y;
}

void RBTree::rotacaoDireita(No x)
{
	No y = x->esq;
	x->esq = y->dir;
	if (y->dir != this->nil) y->dir->pai = x;
	y->pai = x->pai;
	if (x->pai == this->nil) this->raiz = y;
	else if (x == x->pai->esq) x->pai->esq = y;
	else x->pai->dir = y;
	y->dir = x;
	x->pai = y;
}

// Equivalente ao algoritmo insert_fixup do Cormen, completada;
void RBTree::balancear_inserir(No z)
{
	while (z->pai->cor == RED)
	{
		if (z->pai == z->pai->pai->esq)
		{
			No y = z->pai->pai->dir;
			if (y->cor == RED)
			{
				z->pai->cor = BLACK;
				y->cor = BLACK;
				z->pai->pai->cor = RED;
				z = z->pai->pai;
			}
			else
			{
				if (z == z->pai->dir)
				{
					z = z->pai;
					rotacaoEsquerda(z);
				}
				z->pai->cor = BLACK;
				z->pai->pai->cor = RED;
				rotacaoDireita(z->pai->pai);
			}
		}
		else
		{
			No y = z->pai->pai->esq;
			if (y->cor == RED)
			{
				z->pai->cor = BLACK;
				y->cor = BLACK;
				z->pai->pai->cor = RED;
				z = z->pai->pai;
			}
			else
			{
				if (z == z->pai->esq)
				{
					z = z->pai;
					rotacaoDireita(z);
				}
				z->pai->cor = BLACK;
				z->pai->pai->cor = RED;
				rotacaoEsquerda(z->pai->pai);
			}
		}
	}
	this->raiz->cor = BLACK;
}

void RBTree::inserir(int valor)
{
	No z = new no(valor);
	No y = this->nil;
	No x = this->raiz;
	while (x != this->nil)
	{
		y = x;
		if (z->valor < x->valor) x = x->esq;
		else x = x->dir;
	}
	z->pai = y;
	if (y == this->nil) this->raiz = z;
	else if (z->valor < y->valor) y->esq = z;
	else y->dir = z;
	z->esq = this->nil;
	z->dir = this->nil;
	z->cor = RED;
	balancear_inserir(z);
}

/*
 * Função de transferência de filhos para seu novo pai;
 * Ou transferência dos "familiares" de u para v
 */

void RBTree::transplante(No u, No v)
{
	if (u->pai == this->nil) this->raiz = v;
	else if (u->pai->esq == u) u->pai->esq = v;
	else u->pai->dir = v;
	v->pai = u->pai;
}

void RBTree::balancear_remocao(No x)
{
	while (x != this->raiz && x->cor == BLACK)
	{
		if (x == x->pai->esq)
		{
			No w = x->pai->dir;
			if (w->cor == RED)
			{
				w->cor = BLACK;
				x->pai->cor = RED;
				rotacaoEsquerda(x->pai);
				w = x->pai->dir;
			}
			if (w->esq->cor == BLACK && w->dir->cor == BLACK)
			{
				w->cor = RED;
				x = x->pai;
			}
			else
			{
				if (w->dir->cor == BLACK)
				{
					w->esq->cor = BLACK;
					w->cor = RED;
					rotacaoDireita(w);
				}
					w = x->pai->dir;
					w->cor = x->pai->cor;
					x->pai->cor  = BLACK;
					w->dir->cor = BLACK;
					rotacaoEsquerda(x->pai);
					x = this->raiz;
			}
		}
		else
		{
			No w = x->pai->esq;
			if (w->cor == RED)
			{
				w->cor = BLACK;
				x->pai->cor = RED;
				rotacaoDireita(x->pai);
				w = x->pai->esq;
			}
			if (w->dir->cor == BLACK && w->esq->cor == BLACK)
			{
				w->cor = RED;
				x = x->pai;
			}
			else
			{
				if (w->esq->cor == BLACK)
				{
					w->dir->cor = BLACK;
					w->cor = RED;
					rotacaoEsquerda(w);
				}
				w = x->pai->esq;
				w->cor = x->pai->cor;
				x->pai->cor  = BLACK;
				w->esq->cor = BLACK;
				rotacaoDireita(x->pai);
				x = this->raiz;
			}
		}
		x->cor = BLACK;
	}
}

/*
 *
 */

void RBTree::deletar_remocao(No z) {
	No x, y = z;
	bool y_cor_original = y->cor;
	if (z->esq == this->nil) {
		x = z->dir;
		transplante(z, x);
	} else if (z->dir == this->nil) {
		x = z->esq;
		transplante(z, x);
	} else {
		y = minimo(z->dir);
		y_cor_original = y->cor;
		No x = y->dir;
		if (y->pai == z) x->pai = y;
		else {
			transplante(y, y->dir);
			y->dir = z->dir;
			y->dir->pai = y;
		}
		transplante(z, y);
		y->esq = z->esq;
		y->esq->pai = y;
		y->cor = z->cor;
		delete z;
		if (y_cor_original == BLACK) balancear_remocao(x);
	}

}

/*
 * Função que chama a função de busca na árvore e envia o resultado, caso não nulo, para a real função de remoçao
 */

void RBTree::remover(int valor)
{
	No no = buscar_no(valor);
	if (no != nullptr) deletar_remocao(no);
}
