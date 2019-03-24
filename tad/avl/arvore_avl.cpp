#include <iostream>
#include <climits>

using namespace std;

class No
{
public:
	No* dir;
	No* esq;
	int dado;
	int balanco;

	No(int dado, int balanco, No* pt_esq = nullptr, No* pt_dir = nullptr)
	{
		this->dado = dado;
		this->balanco = balanco;
		this->esq = pt_esq;
		this->dir = pt_dir;
	}

	~No(){}

};


class AVL
{
	public:
		bool desbalanceada = false;
		No* root = nullptr;

		int _abb_minimo(No* raiz)
		{
			if (raiz == nullptr) return INT_MIN;
			else if (raiz->esq == nullptr) return raiz->dado;
			else return _abb_minimo(raiz);
		}


		int _abb_maximo(No* raiz)
		{
			if (raiz == nullptr) return INT_MAX;
			else if (raiz->dir == nullptr) return raiz->dado;
			else return _abb_maximo(raiz->dir);
		}

		int abb_minimo()
		{
			return _abb_minimo(root);
		}
		int abb_maximo()
		{
			return _abb_maximo(root);
		}

		int abb_altura(No* raiz)
		{
			if (raiz == nullptr) return 0;
			int esq = abb_altura(raiz->esq);
			int dir = abb_altura(raiz->dir);
			return 1 + (esq > dir ? esq : dir);
		}

		int abb_folhas(No* raiz)
		{
			if (raiz == nullptr) return 0;
			else if (raiz->esq == nullptr && raiz->dir == nullptr) return 1;
			else return abb_folhas(raiz->esq) + abb_folhas(raiz->dir);
		}

		void visitar(No* raiz)
		{
			cout << raiz->dado << " ";
		}

		void abb_pre_ordem(No* raiz)
		{
			if (raiz == nullptr) return;
			visitar(raiz);
			abb_pre_ordem(raiz->esq);
			abb_pre_ordem(raiz->dir);
		}

		void abb_in_ordem(No* raiz)
		{
			if (raiz == nullptr) return;
			abb_in_ordem(raiz->esq);
			visitar(raiz);
			abb_in_ordem(raiz->dir);
		}

		void abb_pos_ordem(No* raiz)
		{
			if (raiz == nullptr) return;
			abb_pos_ordem(raiz->esq);
			abb_pos_ordem(raiz->dir);
			visitar(raiz);
		}

		No* rotacao_direita(No* raiz)
		{
			No* pt_esq = raiz->esq;
			//Rotação Simples para direita
			if (pt_esq->balanco == -1)
			{
				raiz->esq = pt_esq->dir;
				pt_esq->dir = raiz;
				raiz->balanco = 0;
				raiz = pt_esq;
			}
			//Rotação Dupla para direita
			else
			{
				No* pt_dir_esq = pt_esq->dir;
				pt_esq->dir = pt_dir_esq->esq;
				pt_dir_esq->dir = pt_esq;
				raiz->esq = pt_dir_esq->dir;
				pt_dir_esq->dir = raiz;
				raiz->balanco = (pt_dir_esq->balanco == -1) ? 1 : 0;
				pt_esq->balanco = (pt_dir_esq->balanco == 1) ? -1 : 0;
				raiz = pt_dir_esq;
			}
			
			raiz->balanco = 0;
			this->desbalanceada = false;
			return raiz;
		}

		No* rotacao_esquerda(No* raiz)
		{
			No* pt_dir = raiz->dir;
			//Rotação Simples para esquerda
			if (pt_dir->balanco == 1)
			{
				raiz->dir = pt_dir->esq;
				pt_dir->esq = raiz;
				raiz->balanco = 0;
				raiz = pt_dir;
			}
			//Rotação Dupla esquerda
			else
			{
				No* pt_esq_dir = pt_dir->esq;
				pt_dir->esq = pt_esq_dir->dir;
				pt_esq_dir->dir = pt_dir;
				raiz->dir = pt_esq_dir->esq;
				pt_esq_dir->esq = raiz;
				raiz->balanco = (pt_esq_dir->balanco == -1) ? 1 : 0;
				pt_dir->balanco = (pt_esq_dir->balanco == 1) ? -1 : 0;
				raiz = pt_esq_dir;
			}

			raiz->balanco = 0;
			this->desbalanceada = false;
			return raiz;
		}

		No* inserir(No* raiz, int valor)
		{
			if (raiz == nullptr)
			{
				raiz = new No(valor, 0);
				this->desbalanceada = true;
				return raiz;
			}
			else if (valor < raiz->dado)
			{
				raiz->esq = inserir(raiz->esq, valor);
				if (this->desbalanceada)
				{	
					switch (raiz->balanco)
					{
						case -1:
							raiz->balanco = 0;
							this->desbalanceada = false;
							break;
						case 0:
							raiz->balanco = -1;
							break;
						case 1:
							raiz = rotacao_direita(raiz);
					}
				}

			}
			else if (valor > raiz->dado)
			{
				raiz->dir = inserir(raiz->dir, valor);
				if (this->desbalanceada)
				{
					switch (raiz->balanco)
					{
						case -1:
							raiz->balanco = 0;
							this->desbalanceada = true;
							break;
						case 0:
							raiz->balanco = 1;
							break;
						case 1:
							rotacao_esquerda(raiz);
					}
				}
			}
			return raiz;
		}
};

int main(){

	AVL alv;
	
	alv.root = alv.inserir(alv.root, 19);
	alv.root = alv.inserir(alv.root, 15);
	alv.root = alv.inserir(alv.root, 1);
	alv.root = alv.inserir(alv.root, 5);
	alv.root = alv.inserir(alv.root, 3);
	alv.root = alv.inserir(alv.root, 20);
	alv.root = alv.inserir(alv.root, 41);
	alv.root = alv.inserir(alv.root, 70);

	alv.abb_pre_ordem(alv.root);
	cout << endl; 
	alv.abb_in_ordem(alv.root);
	cout << endl;
	alv.abb_pos_ordem(alv.root);

}