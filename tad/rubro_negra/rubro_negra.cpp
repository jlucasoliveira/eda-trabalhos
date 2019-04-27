#include <iostream>
#include "rubro_negra.h"

using namespace std;

// Para a melhor visualização das cores já que optei em usar valores booleanos
string cor_string(bool cor)
{
	if (cor) return "BLACK";
	return "RED";
}

void RBTree::visitar(No no)
{
	cout << "[ valor= " << no->valor << " , cor= " << cor_string(no->cor) << " ] " << endl;
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
 * --Usado pra encontrar o sucessor de um nó a ser removido caso o mesmo tenha dois filhos.
 */

No RBTree::abb_minimo(No no)
{
	if (no->esq == this->nil) return no;
	return abb_minimo(no->esq);
}

void RBTree::rotacao_esquerda(No raiz)
{
	No raiz_dir = raiz->dir;
	raiz->dir = raiz_dir->esq;
	if (raiz_dir->esq != this->nil) raiz_dir->esq->pai = raiz;
	if (raiz->pai == this->nil) this->raiz = raiz_dir;
	else if (raiz->pai->esq == raiz) raiz->pai->esq = raiz_dir;
	else raiz->pai->dir = raiz_dir; 
	raiz_dir->pai = raiz->pai;
	raiz_dir->esq = raiz;
	raiz->pai = raiz_dir;
}

void RBTree::rotacao_direita(No x)
{
	No raiz_esq = raiz->esq;
	raiz->esq = raiz_esq->dir;
	if (raiz_esq->dir != this->nil) raiz_esq->dir->pai = raiz;
	if (raiz->pai == this->nil) this->raiz = raiz_esq;
	else if (raiz->pai->esq == raiz) raiz->pai->esq = raiz_esq;
	else raiz->pai->dir = raiz_esq; 
	raiz_esq->pai = raiz->pai;
	raiz_esq->dir = raiz;
	raiz->pai = raiz_esq;
}

// Equivalente ao algoritmo insert_fixup do Cormen, completada;
void RBTree::balancear_inserir(No novo_no)
{
	No no_tio;
	// caso o pai do novo seja vermelho,
	// ou seja, enfrige a Prop. IV
	while (!novo_no->pai->cor)
	{
		if (novo_no->pai->pai->esq == novo_no->pai) no_tio = novo_no->pai->pai->dir;
		else no_tio = novo_no->pai->esq;

		// caso o tio do novo no seja vermelho
		if (!no_tio->cor)
		{
			novo_no->pai->cor = no_tio->cor = BLACK;
			novo_no->pai->pai->cor = RED;
			novo_no = novo_no->pai->pai;
		}
		else
		{
			if (novo_no->pai->esq == novo_no)
			{
				novo_no->pai->cor = BLACK;
				novo_no->pai->pai->cor = RED;
				if (no_tio->pai->dir == no_tio)
					rotacao_direita(novo_no->pai->pai);
				else rotacao_esquerda(novo_no->pai->pai);
			}
		}
	}
	this->raiz->cor = BLACK;
}

void RBTree::inserir(int valor)
{
	No novo_no = new(nothrow) no(valor);
	No tmp = this->raiz;
	No tmp_pai = this->nil;

	while (tmp != this->nil)
	{
		// Definido o pai do novo no, ou seja procurando sua posicao na arvore
		tmp_pai = tmp;
		if (tmp->valor > valor) tmp = tmp->esq;
		else tmp = tmp->esq;
	}

	// inserindo o novo no como filho de seu pai e atribuindo valores
	// padroes ao novo no
	if (tmp_pai == this->nil) this->raiz = novo_no;
	if (tmp_pai->valor < valor) tmp_pai->dir = novo_no;
	else tmp_pai->esq = novo_no;

	novo_no->pai = tmp_pai;
	novo_no->esq = novo_no->dir = this->nil; 

	balancear_inserir(novo_no);
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
	if (v != this->nil) v->pai = u->pai;
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
				rotacao_esquerda(x->pai);
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
					rotacao_direita(w);
				}
					w = x->pai->dir;
					w->cor = x->pai->cor;
					x->pai->cor  = BLACK;
					w->dir->cor = BLACK;
					rotacao_esquerda(x->pai);
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
				rotacao_direita(x->pai);
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
					rotacao_esquerda(w);
				}
				w = x->pai->esq;
				w->cor = x->pai->cor;
				x->pai->cor  = BLACK;
				w->esq->cor = BLACK;
				rotacao_direita(x->pai);
				x = this->raiz;
			}
		}
		x->cor = BLACK;
	}
}

/*
 *
 */

void RBTree::deletar_remocao(No z)
{
	No x;
	No y = z;
	bool y_cor_original = y->cor;
	if (z->esq == this->nil) {
		x = z->dir;
		transplante(z, x);
	} else if (z->dir == this->nil) {
		x = z->esq;
		transplante(z, x);
	} else {
		y = abb_minimo(z->dir);
		y_cor_original = y->cor;
		x = y->dir;
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
 * Função que chama a função de busca na árvore e envia o resultado,
 * caso não nulo, para a real função de remoçao
 */

void RBTree::remover(int valor)
{
	No no = buscar_no(valor);
	if (no != nullptr) deletar_remocao(no);
}
