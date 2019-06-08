//
// Created by jlucasoliveira on 02/05/19.
//

#include "AVLTree.h"
#include <climits>
#include <iostream>


struct no{
	int dado;
	signed balanco:2;
	struct no *dir, *esq;

	no(int dado)
	{
		this->dado = dado;
		this->balanco = 0;
		this->dir = this->esq = nullptr;
	}

	~no()
	{
	}
};

AVLTree::AVLTree()
{
	this->desbalanceada = true;
	this->root = nullptr;
}

AVLTree::~AVLTree()
{
	mata_arvore_pos(this->root);
}

void AVLTree::mata_arvore_pos(No raiz)
{
	if (raiz == nullptr) return;
	mata_arvore_pos(raiz->esq);
	mata_arvore_pos(raiz->dir);
	delete raiz;
}


int AVLTree::_abb_minimo(No raiz)
{
	if (raiz == nullptr) return INT_MAX;
	else if (raiz->esq == nullptr) return raiz->dado;
	else return _abb_minimo(raiz->esq);
}

int AVLTree::abb_minimo()
{
	return _abb_minimo(this->root);
}

int AVLTree::_abb_maximo(No raiz)
{
	if (raiz == nullptr) return INT_MIN;
	else if (raiz->dir == nullptr) return raiz->dado;
	else return _abb_maximo(raiz->dir);
}

int AVLTree::abb_maximo()
{
	return _abb_maximo(this->root);
}

int AVLTree::_abb_altura(No raiz)
{
	if (raiz == nullptr) return 0;
	int esq = _abb_altura(raiz->esq);
	int dir = _abb_altura(raiz->dir);
	return 1 + (esq > dir ? esq : dir);
}

int AVLTree::abb_altura()
{
	return _abb_altura(this->root);
}

int AVLTree::_abb_folhas(No raiz)
{
	if (raiz == nullptr) return 0;
	else if (raiz->esq == nullptr && raiz->dir == nullptr) return 1;
	else return _abb_folhas(raiz->esq) + _abb_folhas(raiz->dir);
}

int AVLTree::abb_folhas()
{
	return _abb_altura(this->root);
}

void AVLTree::visitar(No raiz)
{
	std::cout << "[ valor= " << raiz->dado << ", balanco= " << raiz->balanco << " ] ";
}

void AVLTree::_abb_pre_ordem(No raiz)
{
	if (raiz == nullptr) return;
	visitar(raiz);
	_abb_pre_ordem(raiz->esq);
	_abb_pre_ordem(raiz->dir);
}

void AVLTree::abb_pre_ordem()
{
	return _abb_pre_ordem(this->root);
}

void AVLTree::_abb_in_ordem(No raiz)
{
	if (raiz == nullptr) return;
	_abb_in_ordem(raiz->esq);
	visitar(raiz);
	_abb_in_ordem(raiz->dir);
}

void AVLTree::abb_in_ordem()
{
	return _abb_in_ordem(this->root);
}

void AVLTree::_abb_pos_ordem(No raiz)
{
	if (raiz == nullptr) return;
	_abb_pos_ordem(raiz->esq);
	_abb_pos_ordem(raiz->dir);
	visitar(raiz);
}

void AVLTree::abb_pos_ordem()
{
	return _abb_pos_ordem(this->root);
}

No AVLTree::rotacao_direita(No raiz)
{
	No ptu = raiz->esq;

	//Rotação Simples para direita
	if (ptu->balanco == -1)
	{
		raiz->esq = ptu->dir;
		ptu->dir = raiz;
		raiz->balanco = 0;
		raiz = ptu;
	}
		//Rotação Dupla para direita
	else
	{
		No ptv = ptu->dir;
		ptu->dir = ptv->esq;
		ptv->esq = ptu;
		raiz->esq = ptv->dir;
		ptv->dir = raiz;
		raiz->balanco = (ptv->balanco == -1) ? 1 : 0;
		ptu->balanco = (ptv->balanco == 1) ? -1 : 0;
		raiz = ptv;
	}

	raiz->balanco = 0;
	this->desbalanceada = false;
	return raiz;
}

No AVLTree::rotacao_esquerda(No raiz)
{
	No ptu = raiz->dir;

	//Rotação Simples para esquerda
	if (ptu->balanco == 1)
	{
		raiz->dir = ptu->esq;
		ptu->esq = raiz;
		raiz->balanco = 0;
		raiz = ptu;
	}
		//Rotação Dupla esquerda
	else
	{
		No ptv = ptu->esq;
		ptu->esq = ptv->dir;
		ptv->dir = ptu;
		raiz->dir = ptv->esq;
		ptv->esq = raiz;
		raiz->balanco = (ptv->balanco == -1) ? 1 : 0;
		ptu->balanco = (ptv->balanco == 1) ? -1 : 0;
		raiz = ptv;
	}

	raiz->balanco = 0;
	this->desbalanceada = false;
	return raiz;
}

No AVLTree::inserir(No raiz, int valor)
{
	if (raiz == nullptr)
	{
		raiz = new no(valor);
		this->desbalanceada = true;
		return raiz;
	}
	else if (valor < raiz->dado)
	{
		raiz->esq = inserir(raiz->esq, valor);
		if (this->desbalanceada)
		{
			raiz->balanco-=1;
			if (raiz->balanco == -1)
				this->desbalanceada = true;
			else if (raiz->balanco == 0)
				this->desbalanceada = false;
			else if (raiz->balanco == -2)
				raiz = rotacao_direita(raiz);
		}

	}
	else if (valor > raiz->dado)
	{
		raiz->dir = inserir(raiz->dir, valor);
		if (this->desbalanceada)
		{
			raiz->balanco+=1;
			if (raiz->balanco == 1)
				this->desbalanceada = true;
			else if (raiz->balanco == 0)
				this->desbalanceada = false;
			else if (raiz->balanco == 2)
				raiz = rotacao_esquerda(raiz);
		}
	}
	return raiz;
}

void AVLTree::inserir(int valor)
{
	this->root = inserir(this->root, valor);
}