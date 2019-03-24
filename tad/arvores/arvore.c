#include "arvore.h"

p_no criar_arvore(int dado, p_no dir, p_no esq, p_no pai)
{
	p_no no = (No*) malloc(sizeof(No*));

	no->dado = dado;
	no->dir = dir;
	no->esq = esq;
	no->pai = pai;
	return no;
}

p_no procurar_no(p_no raiz, int chave)
{
	if (raiz == NULL || raiz->dado == chave) return raiz;
	p_no esq = procurar_no(raiz->esq, chave);
	if (esq != NULL) return esq;
	return procurar_no(raiz->dir, chave);
}

int numero_nos(p_no raiz){
	if (raiz == NULL) return 0;
	return numero_nos(raiz->esq) + 
			numero_nos(raiz->dir) + 1;
}

int altura(p_no raiz){
	if (raiz == NULL) return 0;
	int esq = altura(raiz->esq);
	int dir = altura(raiz->dir);
	return 1 + (esq > dir ? esq : dir);
}