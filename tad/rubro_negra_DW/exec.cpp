#include <iostream>
#include "rubro_negra.h"

using namespace std;

int menu()
{
	cout << endl;
	cout << "[ MENU ]" << endl;
	cout << "1. Iserir Elemento" << endl;
	cout << "2. Remover Elemento" << endl;
	cout << "3. Altura da Árvore" << endl;
	cout << "4. Percurso em pre-ordem" << endl;
	cout << "5. Percurso em in-ordem" << endl;
	cout << "6. Percurso em pos-ordem" << endl;
	cout << "7. Sair" << endl;
	cout << "Resposta: ";
	int res;
	cin >> res;
	return res;
}

int main()
{
	int res;
	RBTree arvore;
	do
	{
		res = menu();	
		if (res == 1)
		{
			int valor;
			cout << "Valor: ";
			cin >> valor;
			arvore.inserir(valor);
		}
		else if (res == 2)
		{
			int valor;
			cout << "Valor: ";
			cin >> valor;
			arvore.remover(valor);
		}
		else if (res == 3) cout << "Altura: " << arvore.abb_altura() << endl << "(Sem contar os T.nil)" << endl;
		else if (res == 4) arvore.abb_pre_ordem();
		else if (res == 5) arvore.abb_in_ordem();
		else if (res == 6) arvore.abb_pos_ordem();
	} while (res < 7);
	
	return 0;
}
