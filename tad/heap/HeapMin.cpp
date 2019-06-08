//
// Created by jlucasoliveira on 03/05/19.
//

#include "Heap.h"
#include "HeapMin.h"
#include <utility>
#include <iostream>

using namespace std;


HeapMin::HeapMin()
{
	this->size = 0;
	this->capacity = 1;
	this->queue = new int[50];
}

HeapMin::HeapMin(int* vet, int n)
{
	this->size = this->capacity = n;
	this->queue = vet;
	for (int i = n/2; i > 0; i--)
		this->down(i);

}

HeapMin::~HeapMin()
{
}

void HeapMin::up(int index)
{
	while(index > 1 && this->queue[parent(index)] > this->queue[index])
	{
		std::swap(this->queue[parent(index)], this->queue[index]);
		index = parent(index);
	}
}

void HeapMin::down(int index)
{
	int left = child_left(index);
	int right = child_right(index);
	int largest;

	if (left <= this->size && this->queue[left] < this->queue[index])
		largest = left;
	else largest = index;
	if (right <= this->size && this->queue[right] < this->queue[largest])
		largest = right;
	if (largest != index)
	{
		std::swap(this->queue[index], this->queue[largest]);
		down(parent(index));
	}
}

void HeapMin::MinHeapInsert(int value)
{
	this->queue[++this->size] = value;
	up(this->size);
}

void HeapMin::HeapDecreaseKey(int index, int key)
{
	if (key > this->queue[index])
	{
		std::cout << "Erro::Nova chave eh maior que a atual.";
		return;
	}
	this->queue[index] = key;
	up(index);
}

/*
int HeapMin::remove()
{
	if (this->size > 0)
	{
		int bkp_urgency = extract();
		this->queue[1] = this->queue[this->size--];
		max_heapfy(1);
		return bkp_urgency;
	}else std::cout << "Erro::Heap vazio.";
}
*/

int HeapMin::HeapExtractMin()
{
	if (this->size > 0)
		return this->queue[1];
	cout << "Erro::Heap vazio";
}