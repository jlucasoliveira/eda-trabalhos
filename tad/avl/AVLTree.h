//
// Created by jlucasoliveira on 02/05/19.
//

#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H

struct no;
typedef struct no* No;

class AVLTree
{

private:

	No root;
	bool desbalanceada;

	int _abb_minimo(No);
	int _abb_maximo(No);
	int _abb_altura(No);
	int _abb_folhas(No);
	void visitar(No);
	void _abb_pre_ordem(No);
	void _abb_in_ordem(No);
	void _abb_pos_ordem(No);

	No rotacao_direita(No);
	No rotacao_esquerda(No);
	No inserir(No, int);

	void mata_arvore_pos(No);

public:

	AVLTree();
	~AVLTree();

	int abb_minimo();
	int abb_maximo();
	int abb_altura();
	int abb_folhas();
	void abb_pre_ordem();
	void abb_in_ordem();
	void abb_pos_ordem();

	void inserir(int);

};


#endif //AVL_AVLTREE_H
