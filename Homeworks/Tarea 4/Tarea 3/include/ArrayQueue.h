#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#define DEFAULT_MAX_SIZE 1024
#include "Queue.h"
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayQueue : public Queue<E> {
private:
    E *elements;
    int max;
    int front;
    int back;
    int size;

public:
    ArrayQueue(int max = DEFAULT_MAX_SIZE) {
        elements = new E[max];
        this->max = max;
        front = back = size = 0;
    }
    ~ArrayQueue() {
        delete [] elements;
    }
    void enqueue(E element) {
        if (size == max)
            throw runtime_error("Queue is full");
        elements[back] = element;
        back = (back + 1) % max;
        size++;
    }
    E dequeue() {
        if (size == 0)
            throw runtime_error("Queue is empty");
        front = (front + 1) % max;
        size--;
        return elements[(front + max -1) % max];
    }
    E getFront() {
        if (size == 0)
            throw runtime_error("Queue is empty");
        return elements[front];
    }
    void clear() {
        front = back = size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
    E dequeueRear(){
        if (size == 0)
            throw runtime_error("Queue is empty");
        back = (back + max -1) % max;
        size--;
        return elements[back];
    }
    void enqueueFront(E element){
        if (size == max)
            throw runtime_error("Queue is full");
        E *temp;
        temp = new E[max];
        temp[0] = element;
        for (int i = 0; i < size; i++){
            temp[i+1] = elements[i];
        }
        delete []elements;
        elements = temp;
        size++;
        front = 0;
        back = (back + 1) % max;
    }
    E rearValue(){
        if (size == 0)
            throw runtime_error("Queue is empty");
        return elements[back-1];
    }
    void print(){
        E *temp;
        temp = new E[max];
        int t = size;
        int i = 0;
        while(!isEmpty()){
            E elemen = dequeue();
            cout << elemen << ", " ;
            temp[i] = elemen;
            i++;
        }
        cout << endl;
        delete []elements;
        elements = temp;
        size = t;
        front = 0;
        back = back;
    }
};

#endif // ARRAYQUEUE_H
