#ifndef HEAP_H
#define HEAP_H
#define parent(i) (i/2)
#define left(i) (i*2)
#define right(i) ((i)*2+1)

class Heap{

private:
    int size;
    int capacity;
    int* queue;

    void recapacity();
    void max_up(int index);
    void max_down(int index);

public:
    Heap();
    Heap(int* vet, int n);
    
    void max_insert(int value);
    void increase_key(int index, int key);
    int max_remove();
    int extract();

};



#endif //HEAP_H