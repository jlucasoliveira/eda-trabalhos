/*
 * Autor: José Lucas Olveira da Silva
 * Matrícula: 0421691
 */


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

void RBTree::rotacao_esquerda(No eixo)
{
	No filho_direito = eixo->dir;
	eixo->dir = filho_direito->esq;
	if (filho_direito->esq != this->nil) filho_direito->esq->pai = eixo;
	filho_direito->pai = eixo->pai;
	if (eixo->pai == this->nil) this->raiz = filho_direito;
	else if (eixo->pai->esq == eixo) eixo->pai->esq = filho_direito;
	else eixo->pai->dir = filho_direito; 
	filho_direito->esq = eixo;
	eixo->pai = filho_direito;
}

void RBTree::rotacao_direita(No eixo)
{
	No filho_esquerdo = eixo->esq;
	eixo->esq = filho_esquerdo->dir;
	if (filho_esquerdo->dir != this->nil) filho_esquerdo->dir->pai = eixo;
	filho_esquerdo->pai = eixo->pai;
	if (eixo->pai == this->nil) this->raiz = filho_esquerdo;
	else if (eixo->pai->esq == eixo) eixo->pai->esq = filho_esquerdo;
	else eixo->pai->dir = filho_esquerdo;
	filho_esquerdo->dir = eixo;
	eixo->pai = filho_esquerdo;
}

// Equivalente ao algoritmo insert_fixup do Cormen, completada;
void RBTree::balancear_inserir(No novo_no)
{
	No no_tio;
	// caso o pai do novo seja vermelho,
	// ou seja, enfrige a Prop. IV
	while (!novo_no->pai->cor)
	{
		if (novo_no->pai->pai->esq == novo_no->pai)
		{
			no_tio = novo_no->pai->pai->dir;
			if (no_tio->cor)
			{
				if (novo_no->pai->dir == novo_no)
				{
					novo_no = novo_no->pai;
					rotacao_esquerda(novo_no);
				}
				novo_no->pai->cor = BLACK;
				novo_no->pai->pai->cor = RED;
				rotacao_direita(novo_no->pai->pai);
			}
		}
		else
		{
			no_tio = novo_no->pai->pai->esq;
			if (no_tio->cor)
			{
				if (novo_no->pai->esq == novo_no)
				{
					novo_no = novo_no->pai;
					rotacao_direita(novo_no);
				}
				novo_no->pai->cor = BLACK;
				novo_no->pai->pai->cor = RED;
				rotacao_esquerda(novo_no->pai->pai);
			}
		}

		if (!no_tio->cor)
		{
			novo_no->pai->cor = BLACK;
			no_tio->cor = BLACK;
			novo_no->pai->pai->cor = RED;
			novo_no = novo_no->pai->pai;
		}
	}
	this->raiz->cor = BLACK;
}

void RBTree::inserir(int valor)
{
	No novo_no = new(nothrow) no(valor);
	if (novo_no == nullptr)
	{
		cout << "Erro:: Não foi possivel alocar memoria";
		exit(1);
	}

	No tmp = this->raiz;
	No tmp_pai = this->nil;

	while (tmp != this->nil)
	{
		// Definido o pai do novo no, ou seja procurando sua posicao na arvore
		tmp_pai = tmp;
		if (tmp->valor > valor) tmp = tmp->esq;
		else tmp = tmp->dir;
	}

	// inserindo o novo no como filho de seu pai e atribuindo valores
	// padroes ao novo no
	if (tmp_pai == this->nil) this->raiz = novo_no;
	else if (tmp_pai->valor < valor) tmp_pai->dir = novo_no;
	else tmp_pai->esq = novo_no;

	novo_no->pai = tmp_pai;
	novo_no->esq = this->nil;
	novo_no->dir = this->nil;

	balancear_inserir(novo_no);
}

// Recebe um no qualquer e retorna o numero de filhos
int RBTree::ab_num_filhos(No pai)
{
	if (pai->esq == pai->dir) return 0;
	else if (pai->esq == this->nil || pai->dir == this->nil) return 1;
	else return 2;
}

// retorna o irmao de um determinado no
No RBTree::ab_irmao(No node)
{
	if (node->pai->esq == node) return node->pai->dir;
	return node->pai->esq;
}

/*
 * Substitui um determinado nó por outro "aos olhos do pai"
 */

void RBTree::substitui(No removido, No substituto)
{
	if (this->raiz == removido) this->raiz = substituto;
	else if (removido->pai->esq == removido)
		removido->pai->esq = substituto;
	else removido->pai->dir = substituto;

	if (substituto != this->nil)
		substituto->pai = removido->pai;
}

void RBTree::removerBB(No node)
{
	No irmao = ab_irmao(node);
	if (irmao->cor)
	{
			// caso 2
		if (irmao->dir->cor && irmao->esq->cor)
		{
			if (!irmao->pai->cor) irmao->pai->cor = BLACK;
			if (irmao != this->nil) irmao->cor = RED;
		}
		else
		{
			if (irmao->pai->dir == irmao)
			{
				// caso 3
				if (irmao->dir->cor && !irmao->esq->cor)
				{
					irmao->cor = RED;
					irmao->esq->cor = BLACK;
					rotacao_direita(irmao);
				}
					// caso 4
				else {
					bool pai_cor = irmao->pai->cor;
					irmao->pai->cor = BLACK;
					irmao->cor = pai_cor;
					irmao->dir->cor = BLACK;
					rotacao_esquerda(irmao->pai);
				}
			}
			else
			{
				// caso 3
				if (irmao->esq->cor && !irmao->dir->cor)
				{
					irmao->cor = RED;
					irmao->dir->cor = BLACK;
					rotacao_esquerda(irmao);
				}
					// caso 4
				else {
					bool pai_cor = irmao->pai->cor;
					irmao->pai->cor = BLACK;
					irmao->cor = pai_cor;
					irmao->esq->cor = BLACK;
					rotacao_direita(irmao->pai);
				}
			}
		}
	}
		// caso 1
	else
	{
		irmao->pai->cor = RED;
		irmao->cor = BLACK;
		if (irmao->pai->dir == irmao)
			rotacao_esquerda(irmao->pai);
		else rotacao_direita(irmao->pai);
	}
	this->raiz->cor = BLACK;
}

void RBTree::deletar_remocao(No node)
{
	int num_filhos = ab_num_filhos(node);
	if (num_filhos == 1)
	{
		No filho = node->esq;
		if (filho == this->nil) filho = node->dir;
		substitui(node, filho);
		if (node->cor)
		{
			if (!filho->cor) filho->cor = node->cor;
			else removerBB(filho);
		}
		delete node;
	}
	else
	{
		if (num_filhos == 0)
		{
			if (node->cor) removerBB(node);
			substitui(node, this->nil);
			delete node;
		}
		else
		{
			No sucessor = abb_minimo(node->dir);
			node->valor = sucessor->valor;
			deletar_remocao(sucessor);
		}
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

void RBTree::destroir_arvore(No node)
{
	if (node == this->nil) return;
	destroir_arvore(node->esq);
	destroir_arvore(node->dir);
	delete node;
}

RBTree::~RBTree()
{
	destroir_arvore(this->raiz);
	delete this->nil;
}