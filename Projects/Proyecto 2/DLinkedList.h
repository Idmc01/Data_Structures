#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "List.h"
#include "DNode.h"
#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class DLinkedList: public List<E>{
private:
    DNode<E> *head;
    DNode<E> *current;
    DNode<E> *tail;
    int size;

public:
    DLinkedList(){
        current = head =  new DNode<E>(nullptr,nullptr);
        head->next = tail = new DNode<E>(nullptr,head);
        size = 0;
    }
    ~DLinkedList(){
        clear();
        delete head;
        delete tail;
    }
    void insert(E element){
        current->next = current->next->previous =
        new DNode<E>(element,current->next,current);
        size++;
    }
    void append(E element){
        tail->previous = tail->previous->next =
        new DNode<E>(element,tail,tail->previous);
        size++;
    }
    E remove(){
        if(size == 0){
            throw runtime_error("List is empty.");
        }
        if(current->next == tail){
            throw runtime_error("No current element.");
        }
        E result = current->next->element;
        current->next = current->next->next;
        delete current->next->previous;
        current->next->previous = current;
        size--;
        return result;
    }
    void clear(){
        current = head->next;
        while(current != tail){
            head->next = current->next;
            delete current;
            current = head->next;
        }
        current = tail->previous = head;
        size = 0;
    }
    E getElement(){
        if(size == 0){
            throw runtime_error("List is empty.");
        }
        if(current->next == tail){
            throw runtime_error("No current element.");
        }
        return current->next->element;
    }
    void goToStart(){
        current = head;
    }
    void goToEnd(){
        current = tail->previous;
    }
    void goToPos(int pos){
        if(pos <0 || pos> size)
            throw runtime_error("Index out of range. ");
        current = head;
        for(int i = 0; i < pos; i++){
            current = current->next;
        }
    }
    void next(){
        if(current->next != tail){
            current = current->next;
        }
    }
    void previous(){
        if(current->previous != head){
            current = current->previous;
        }
    }
    bool atStart(){
        return current == head;
    }
    bool atEnd(){
        //return current->next == tail;
        return current == tail->previous;
    }
    int getPos(){
        DNode<E> *temp = head;
        int pos = 0;
        while(temp->next != current){
            temp = temp->next;
            pos++;
        }
        return pos;
    }
    int getSize(){
        return size;
    }
    void print(){
        DNode<E> *oldCurrent = current;
        cout<<"[ ";
        for(goToStart(); !atEnd(); next()){
            cout << getElement() << " ";
        }
        cout << " ]"<<endl;
        current = oldCurrent;
    }


};

#endif // DLINKEDLIST_H
