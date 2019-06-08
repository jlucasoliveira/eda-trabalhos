#include <iostream>
#include "HeapMax.h"

using namespace std;

int menu()
{
	cout << endl << "[ MENU ]" << endl;
	cout << "1. Inserir Elemento" << endl;
	cout << "2. Remover Maior Elemento" << endl;
	cout << "3. Visualizar Maior Elemento" << endl;
	cout << "4. Transformar Vetor em Heap" << endl;
	cout << "5. Sair" << endl << endl;
	int res;
	cin >> res;
	return res;
}

int main()
{

	HeapMax *ed;
	ed = new HeapMax();
	int res;
	do
	{
		res = menu();
		if (res == 1)
		{
			int valor;
			cout << "Valor: ";
			cin >> valor;
			ed->insert(valor);
		}
		else if (res == 2) ed->remove();
		else if (res == 3) cout << "Valor: " << ed->extract();
		else if (res == 4);
		
	} while (res < 4);

	return 0;
}