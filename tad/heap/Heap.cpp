#include "Heap.h"
#include <cstdlib>
#include <iostream>

void swap(int* num1, int* num2)
{
    int aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

Heap::Heap()
{
    this->size = 0;
    this->capacity = 1;
    this->queue = new int[this->capacity];
}

Heap::Heap(int* vet, int n)
{
    this->size = this->capacity = n;
    this->queue = vet;
    for (int i = n/2; i > 0; i--)
        this->max_down(i);
    
}

void Heap::recapacity()
{
    this->capacity*=2;
    this->queue = (int*) realloc(this->queue, this->capacity*sizeof(int));
}

void Heap::max_up(int index)
{
    while(index > 1 && this->queue[parent(index)] < this->queue[index])
    {
        swap(&this->queue[parent(index)], &this->queue[index]);
        index = parent(index);
    }
}

void Heap::max_down(int index)
{
    int left = left(index);
    int right = right(index);
    int largest;

    if (left <= this->size && this->queue[left] > this->queue[index])
        largest = left;
    else largest = index;
    if (right <= this->size && this->queue[right] > this->queue[largest])
        largest = right;
    if (largest != index)
    {
        swap(&this->queue[index], &this->queue[largest]);         
        max_down(parent(index));
    }   
}

void Heap::max_insert(int value)
{
    if (this->size == this->capacity) recapacity();
    this->queue[this->size++] = value;
    max_up(this->size);
}

void Heap::increase_key(int index, int key)
{
    if (key < this->queue[index])
    {
        std::cout << "Erro::Nova chave eh menor que a atual.";
        return;
    }
    this->queue[index] = key;
    max_up(index);
}


int Heap::max_remove()
{
    if (this->size > 0)
    {
    int bkp_urgency = extract();
    this->queue[1] = this->queue[this->size--];
    max_down(1);
    return bkp_urgency;
    }else std::cout << "Erro::Heap vazio.";
}

int Heap::extract()
{
    if (this->size > 0)
        return this->queue[1];
    std::cout << "Erro::Heap vazio";
}