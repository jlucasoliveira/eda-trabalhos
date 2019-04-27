#include <iostream>
#include "heap.h"
#include <vector>;

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

Heap* build_heap_from_input()
{
	int valor, n;
	cout << "Tamanho do vetor: ";
	cin >> n;
	int* vet = new int[n];
	
	for (int i = i; i <= n; i++)
	{
		cout << "Valor: ";
		cin >> valor;
		vet[i] = valor;
	}
	return new Heap(vet, n);
}

int main()
{

	Heap* ed = new Heap();
	int res;
	do
	{
		res = menu();
		if (res == 1)
		{
			int valor;
			cout << "Valor: ";
			cin >> valor;
			ed->max_insert(valor);
		}
		else if (res == 2) ed->max_remove();
		else if (res == 3) cout << "Valor: " << ed->extract();
		else if (res == 4)
		
	} while (res < 4);

	return 0;
}