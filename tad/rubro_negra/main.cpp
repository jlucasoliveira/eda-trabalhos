/*
 * Autor: José Lucas Olveira da Silva
 * Matrícula: 0421691
 */


#include <iostream>
#include "rubro_negra.h"

using namespace std;

int menu()
{
	cout << endl;
	cout << "[ MENU ]" << endl;
	cout << "1. Inserir Elemento" << endl;
	cout << "2. Remover Elemento" << endl;
	cout << "3. Altura da Árvore" << endl;
	cout << "4. Percurso em pre-ordem" << endl;
	cout << "5. Sair" << endl;
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
		// Inserir
		if (res == 1)
		{
			int valor;
			cout << "Valor: ";
			cin >> valor;
			arvore.inserir(valor);
		}//Remover
		else if (res == 2)
		{
			int valor;
			cout << "Valor: ";
			cin >> valor;
			arvore.remover(valor);
		}//Altura da arvore
		else if (res == 3) cout << "Altura: " << arvore.abb_altura() << endl << "(Sem contar os T.nil)" << endl;
		// percurso em pre-ordem
		else if (res == 4) arvore.abb_pre_ordem();
	} while (res < 5);

	return 0;
}
