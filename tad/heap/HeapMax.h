//
// Created by jlucasoliveira on 03/05/19.
//

#ifndef HEAP_HEAPMAX_H
#define HEAP_HEAPMAX_H

//#include "Heap.h"
#define parent(i) (i/2)
#define child_left(i) (i*2)
#define child_right(i) ((i)*2+1)

class HeapMax
{

private:
	int size;
    int capacity;
    int* queue;

	void up(int);
	void down(int);

public:

	HeapMax();
	HeapMax(int*, int);
	~HeapMax();

	void insert(int);
	void increase_key(int, int);
	int remove();
	int extract();
	void max_heapfy(int);
	void HeapDelete(int);

};


#endif //HEAP_HEAPMAX_H
