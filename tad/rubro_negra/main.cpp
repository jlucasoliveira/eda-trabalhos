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
		if (res == 1)
		{
			// Leitura do valor, o inserindo na arvore
			int valor;
			cout << "Valor: ";
			cin >> valor;
			arvore.inserir(valor);
		}
		else if (res == 2)
		{
			// Leitura do valor, o buscando na arvore caso existe sera removido
			int valor;
			cout << "Valor: ";
			cin >> valor;
			arvore.remover(valor);
		}
		else if (res == 3) cout << "Altura: " << arvore.abb_altura() << endl << "(Sem contar os T.nil)" << endl;
		else if (res == 4) arvore.abb_pre_ordem();
	} while (res < 5);

	return 0;
}
