#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdexcept>
#include "Queue.h"
#include "Node.h"

using std::runtime_error;

template <typename E>
class LinkedQueue : public Queue<E> {
private:
    Node<E> *front;
    Node<E> *back;
    int size;

public:
    LinkedQueue() {
        front = back = new Node<E>();
        size = 0;
    }
    ~LinkedQueue() {
        clear();
        delete front;
    }
    void enqueue(E element){
        back = back->next = new Node<E>(element);
        size++;
    }
    E dequeue() {
        if (size == 0)
            throw runtime_error("Queue is empty");
        E result = front->next->element;
        Node<E> *temp = front->next;
        front->next = temp->next;
        delete temp;
        if (size == 1)
            back = front;
        size--;
        return result;
    }
    E getFront(){
        if (size == 0)
            throw runtime_error("Queue is empty");
        return front->next->element;
    }
    void clear(){
        while (front->next != nullptr){
            back = front->next;
            front->next = back->next;
            delete back;
        }
        back = front;
        size = 0;
    }
    bool isEmpty(){
        return size == 0;
    }
    int getSize() {
        return size;
    }
    void enqueueFront(E element){
        Node<E> *temp = new Node<E>(element);
        temp->next = front->next;
        front->next = temp;
        size++;
    }
    E dequeueRear(){
        if (size == 0)
            throw runtime_error("Queue is empty");
        E result = back->element;
        Node<E> *temp = new Node<E>(front->next);
        while(temp->next!=back){
            temp = temp->next;
        }
        back = temp;
        temp = temp->next;
        delete temp;
        size--;
        return result;
    }
    E rearValue(){
        return back->element;
    }
    void print(){
        Node<E> *temp = front->next;
        int i = 0;
        while(i < size){
            cout << temp->element << ", ";
            temp = temp->next;
            i++;
        }
        cout << endl;
    }
};

#endif // LINKEDQUEUE_H
