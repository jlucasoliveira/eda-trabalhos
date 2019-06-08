#include <iostream>
#include "AVLTree.h"

using namespace std;

int menu()
{
	int res;
	cout << endl << "------------------------" << endl;
	cout << "Implementacao Arvore AVL" << endl;
	cout << "------------------------" << endl;
	cout << "1. Inserir elemento na arvore" << endl;
	cout << "2. Percurso em pre-ordem" << endl;
	cout << "3. Percurso em in-ordem" << endl;
	cout << "4. Percurso em pos-ordem" << endl;
	cout << "5. Altura da Arvore" << endl;
	cout << "6. Numero de folhas da arvore" << endl;
	cout << "7. Valor maximo e minino da arvore" << endl;
	cout << "8. Sair" << endl;
	cout << "Sua escolha: ";
	cin >> res;
	return res;
}

int main()
{

	AVLTree *avl = new AVLTree();

	int res;
	do
	{
		res = menu();
		if (res == 1)
		{
			int valor;
			cout << "Valor: ";
			cin >> valor;
			avl->inserir(valor);
		}
		else if (res == 2) avl->abb_pre_ordem();
		else if (res == 3) avl->abb_in_ordem();
		else if (res == 4) avl->abb_pos_ordem();
		else if (res == 5) cout << "Altura: " << avl->abb_altura() << endl;
		else if (res == 6) cout << "Número de folhas: " << avl->abb_folhas() << endl;
		else if (res == 7) cout << "Minimo: " << avl->abb_minimo() << " | Maximo: " << avl->abb_maximo() << endl;
	}
	while(res < 8);

	delete avl;
}