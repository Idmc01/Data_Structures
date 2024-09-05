#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "List.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

template<typename E>
class LinkedList : public List<E>{
private:
    Node<E> *head;
    Node<E> *current;
    Node<E> *tail;
    int size;

public:
    LinkedList(){
        tail = current = head = new Node<E>();
        size = 0;
    }
    ~LinkedList(){
        clear();
        delete head;
    }
    ///////////Tarea//////////////////////
    int indexOf(E element){
        goToStart();
        int notIn = -1;
        if(size == 0)
            throw runtime_error("List is empty");
        int i = 0;
        while(current!=nullptr){
            if(current->element == element)
                return i;
            current = current->next;
            i++;
        }
        return notIn;
    }
    bool contains(E element){
        goToStart();
        while (current!=nullptr){
            if (current->element == element)
                return true;
            current = current->next;
        }
        return false;
    }
    void extend(List<E> *L){
        L->goToStart();
        while (!L->atEnd()){
            append(L->getElement());
            L->next();
        }
    }
    bool equals(List<E> *L){
        L->goToStart();
        current=head->next;
        int x = 0;
        while(!L->atEnd()){
            if (L->getElement() != current->element){
                return false;}
            if(current == tail){
                L->next();
                if(!L->atEnd()){
                    return false;
                }
                return true;
            }
            L->next();
            current=current->next;
            x++;
        }
        if(x!=size){
            return false;
        }
        return true;
    }
    /////////////////////////////////////
    void insert(E element){
        current->next = new Node<E>(element, current->next);
        if(current == tail){
            tail = current->next;
        }
        size++;
    }
    void append(E element){
        tail = tail->next = new Node<E>(element);
        size++;
    }
    E remove(){
        if(size == 0)
            throw runtime_error("List is empty");
        if(current->next == nullptr)
            throw runtime_error("No current element");
        E result = current->next->element;
        Node<E> *temp = current->next;
        current->next = temp->next;
        if(temp == tail)
            tail = current;
        delete temp;
        size--;
        return result;
    }
    void clear(){
        while(head->next !=nullptr){
            current = head->next;
            head->next = current->next;
            delete current;
        }
        current = tail = head;
        size = 0;
    }
    E getElement(){
        if(size == 0)
            throw runtime_error("List is empty");
        if(current->next == nullptr)
            throw runtime_error("No current element");
        return current->next->element;
    }
    void goToStart(){
        current = head;
    }
    void goToEnd(){
        current = tail;
    }
    void goToPos(int pos){
        if(pos < 0 || pos > size)
            throw runtime_error("index out of range");
        current = head;
        for (int i = 0; i < pos; i++)
            current = current->next;
    }
    void next(){
        if(current != tail)
            current = current->next;
    }
    void previous(){
        if(current != head){
        Node<E> *temp = head;
            while(temp->next != current)
                temp = temp->next;
            current = temp;
        }
    }
    bool atStart(){
        return current == head;
    }
    bool atEnd(){
        return current == tail;
    }
    int getPos(){
        int pos = 0;
        Node<E> *temp = head;
        while(temp != current){
            temp = temp->next;
            pos++;
        }
        return pos;
    }
    int getSize(){
        return size;
    }
    void print(){
        Node<E> *oldCurrent = current;
        cout<< "[ ";
        for(goToStart(); !atEnd(); next())
            cout<<getElement()<<" ";
        cout<<"]"<<endl;
        current = oldCurrent;
    }
};
#endif // LINKEDLIST_H
