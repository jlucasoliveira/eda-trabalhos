//
// Created by jlucasoliveira on 03/05/19.
//

#ifndef HEAP_HEAPMIN_H
#define HEAP_HEAPMIN_H

#include "Heap.h"


class HeapMin
{

private:
	int size;
    int capacity;
    int* queue;

	void up(int);
	void down(int);

public:

	HeapMin();
	HeapMin(int*, int);
	~HeapMin();

    int HeapMinimum();
    int HeapExtractMin();
    void HeapDecreaseKey(int, int);
    void MinHeapInsert(int);

};


#endif //HEAP_HEAPMIN_H
