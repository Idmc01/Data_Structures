#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdexcept>
#include "Queue.h"
#include "Node.h"

using std::runtime_error;

template <typename E>
class LinkedQueue:public Queue<E>{
private:
    Node<E>* front;
    Node<E>* back;
    int size;
public:
    LinkedQueue(){
        front=back=new Node<E>();
        size=0;
    }

    ~LinkedQueue(){
        clear();
        delete front;
    }







    void enqueue(E element){
        back=back->next=new Node<E>(element);
        size++;
    }
    E dequeue(){
        if (size==0){
            throw runtime_error("Queue is empty");
        }
        E result=front->next->element;
        Node<E> *temp=front->next;
        front->next=temp->next;
        delete temp;
        if (size==1){
            back=front;
        }
        size--;
        return result;

    }

    E getFront(){
        if (size==0){
            throw runtime_error("Queue is empty");
        }
        return front->next->element;
    }
    void clear(){
        while(front->next!=nullptr){
            back=front->next;
            front->next=back->next;
            delete back;
        }
        back=front;
        size=0;
    }

    bool isEmpty(){
        return size==0;
    }
    int getSize(){
        return size;
    }
    void enqueueFront(E element){
        front->next=new Node<E>(element,front->next);
        if (size==0)
            back=front->next;
        size++;
    }
    E dequeueRear(){
        if (size==0){
            throw runtime_error("Queue is empty");
        }

        size--;
        Node<E> *temp=front;

        for(int i=0;i<size;i++){
            temp=temp->next;
        }
        E result=back->element;
        delete back;
        back=temp;
        back->next=nullptr;
        return result;
    }
    E rearValue(){
        if (size==0){
            throw runtime_error("Queue is empty");
        }
        return back->element;
    }
    void print(){
        Node<E> *temp=front;
        cout<<"[ ";
        for(int i=0;i<size;i++){
            temp=temp->next;
            cout<<temp->element<<" ";
        }
        cout<<"]"<<endl;
    }

};

#endif // LINKEDQUEUE_H
