//
// Created by jlucasoliveira on 03/05/19.
//

#include "HeapMax.h"
#include <utility>
#include <climits>
#include <iostream>

using namespace std;


HeapMax::HeapMax()
{
	this->size = 0;
	this->capacity = 1;
	this->queue = new int[50];
}

HeapMax::HeapMax(int* vet, int n)
{
	this->size = this->capacity = n;
	this->queue = vet;
	for (int i = n/2; i > 0; i--)
		this->down(i);

}

HeapMax::~HeapMax()
{
}

void HeapMax::up(int index)
{
	while(index > 1 && this->queue[parent(index)] < this->queue[index])
	{
		std::swap(this->queue[parent(index)], this->queue[index]);
		index = parent(index);
	}
}

void HeapMax::down(int index)
{
	int left = child_left(index);
	int right = child_right(index);
	int largest;

	if (left <= this->size && this->queue[left] > this->queue[index])
		largest = left;
	else largest = index;
	if (right <= this->size && this->queue[right] > this->queue[largest])
		largest = right;
	if (largest != index)
	{
		std::swap(this->queue[index], this->queue[largest]);
		down(parent(index));
	}
}

void HeapMax::max_heapfy(int index)
{
	int left, right, largest = index;
	while (largest < this->size/2)
	{
		left = child_left(index);
		right = child_right(index);

		if (left <= this->size && this->queue[left] > this->queue[index])
			largest = left;
		if (right <= this->size && this->queue[right] > this->queue[largest])
			largest = right;

		if (largest == index) return;
		std::swap(this->queue[index], this->queue[largest]);
	}
}

void HeapMax::insert(int value)
{
	this->queue[++this->size] = value;
	up(this->size);
}

void HeapMax::increase_key(int index, int key)
{
	if (key < this->queue[index])
	{
		std::cout << "Erro::Nova chave eh menor que a atual.";
		return;
	}
	this->queue[index] = key;
	up(index);
}


int HeapMax::remove()
{
	if (this->size > 0)
	{
		int bkp_urgency = extract();
		this->queue[1] = this->queue[this->size--];
		max_heapfy(1);
		return bkp_urgency;
	}else std::cout << "Erro::Heap vazio.";
}

int HeapMax::extract()
{
	if (this->size > 0)
		return this->queue[1];
	cout << "Erro::Heap vazio";
}

void HeapMax::HeapDelete(int index)
{
	this->queue[index] = INT_MIN;
	down(index);
	this->size--;
}