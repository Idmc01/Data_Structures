#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#define DEFAULT_MAX_SIZE 1024

#include "Stack.h"
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayStack : public Stack<E> {
private:
    E *elements;
    int max;
    int size;

public:
    ArrayStack(int max = DEFAULT_MAX_SIZE) {
        elements = new E[max];
        this->max = max;
        size = 0;
    }
    ~ArrayStack() {
        delete [] elements;
    }
    void push(E element) {
        if (size == max){
           E *temp;
           temp = new E[max*2];
           for (int i = 0; i<size; i++){
            temp[i] = elements[i];
           }
           delete []elements;
           elements = temp;
           max = max*2;
        }
        elements[size] = element;
        size++;
    }
    E pop() {
        if(size == 0)
            throw runtime_error("Stack underflow");
        size--;
        return elements[size];
    }
    E topValue() {
        if (size == 0)
            throw runtime_error("Stack is empty");
        return elements[size - 1];
    }
    void clear() {
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << elements[i] << ", ";
        }
        cout << endl;
    }
};

#endif // ARRAYSTACK_H
