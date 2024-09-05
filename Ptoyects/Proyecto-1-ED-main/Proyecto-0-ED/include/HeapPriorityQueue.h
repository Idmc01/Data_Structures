#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include "PriorityQueue.h"
#include "MaxHeap.h"
#include "KVPair.h"
#include <stdexcept>

using std::runtime_error;

template <typename E>
class HeapPriorityQueue : public PriorityQueue<E> {
private:
    //atributos de la cola, un max heap con llave de entero y valor de elemento
    MaxHeap<KVPair<int, E>> elements;
    //int priorities;

public:
    //constructor
    HeapPriorityQueue(int max = DEFAULT_MAX_SIZE) : elements(max) {
    }
    //destructor
    ~HeapPriorityQueue() {}
    void insert(E element, int priority){
        KVPair<int, E> p(priority, element);
        elements.insert(p);
    }
    //editado del implementado en clase para retornar el valor del par con la mayor llave,
    E min(){
        auto p = elements.first();
        return p.value;
    }
    //Al igual que el anterior es editado para remover el elemento con la llave mayor
    E removeMin() {
        auto p = elements.removeFirst();
        return p.value;
    }
    //determina si la cola está vacía
    bool isEmpty(){
        return elements.getSize() == 0;
    }
    //obtiene el tamaño de la cola
    int getSize(){
        return elements.getSize();
    }
};

#endif // HEAPPRIORITYQUEUE_H
