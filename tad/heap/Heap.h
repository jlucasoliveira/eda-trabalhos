#ifndef HEAP_H
#define HEAP_H

#define parent(i) (i/2)
#define child_left(i) (i*2)
#define child_right(i) ((i)*2+1)

class Heap{

protected:

    int size;
    int capacity;
    int* queue;

    virtual void recapacity() = 0;
    virtual void up(int) = 0;
    virtual void down(int) = 0;

public:
    
    virtual void insert(int) = 0;
    virtual void increase_key(int, int) = 0;
    virtual int remove() = 0;
    virtual int extract() = 0;

};

#endif //HEAP_H