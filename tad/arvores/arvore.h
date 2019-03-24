typedef struct no
{
	int dado;
	struct no *esq;
	struct no *dir;
	struct no *pai;
} No;

typedef No* p_no;

p_no criar_arvore(int dado, p_no dir, p_no esq, p_no pai);
p_no procurar_no(p_no raiz, int chave);
int numero_nos(p_no raiz);
int altura(p_no raiz);