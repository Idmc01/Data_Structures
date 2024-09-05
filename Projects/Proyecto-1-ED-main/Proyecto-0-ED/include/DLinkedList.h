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
    //Atributos de una DLinkedList
    DNode<E> *head;
    DNode<E> *current;
    DNode<E> *tail;
    int size;

public:
    //constructor
    DLinkedList(){
        current = head =  new DNode<E>(nullptr,nullptr);
        head->next = tail = new DNode<E>(nullptr,head);
        size = 0;
    }
    //destructor
    ~DLinkedList(){
        clear();
        delete head;
        delete tail;
    }
    //inserta un elemento en la posición actual de la lista
    void insert(E element){
        current->next = current->next->previous =
        new DNode<E>(element,current->next,current);
        size++;
    }
    //inserta un elemento al final de la lista
    void append(E element){
        tail->previous = tail->previous->next =
        new DNode<E>(element,tail,tail->previous);
        size++;
    }
    //remueve el elemento en la posición actual de la lista
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
    //limpia la lista de elementos
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
    //Obtiene el elemento en la posición actual
    E getElement(){
        if(size == 0){
            throw runtime_error("List is empty.");
        }
        if(current->next == tail){
            throw runtime_error("No current element.");
        }
        return current->next->element;
    }
    //lleva la posición al inicio
    void goToStart(){
        current = head;
    }
    //lleva la posición al final
    void goToEnd(){
        current = tail->previous;
    }
    //Va hacia la posición indicada por el parámetro
    void goToPos(int pos){
        if(pos <0 || pos> size)
            throw runtime_error("Index out of range. ");
        current = head;
        for(int i = 0; i < pos; i++){
            current = current->next;
        }
    }
    //va hacia la siguiente posición
    void next(){
        if(current->next != tail){
            current = current->next;
        }
    }
    //va a la posición anterior
    void previous(){
        if(current->previous != head){
            current = current->previous;
        }
    }
    //Consulta si la posición actual está al inicio
    bool atStart(){
        return current == head;
    }
    //Consulta si la posición actual está al final
    bool atEnd(){
        //return current->next == tail;
        return current == tail->previous;
    }
    //Obtiene la posición actual
    int getPos(){
        DNode<E> *temp = head;
        int pos = 0;
        while(temp->next != current){
            temp = temp->next;
            pos++;
        }
        return pos;
    }
    //obttiene el tamaño de la lista
    int getSize(){
        return size;
    }
    //Imprime la lista
    void print(){
        DNode<E> *oldCurrent = current;
        for(goToStart(); !atEnd(); next()){
            cout << getElement() << " ";
        }
        cout << endl;
        current = oldCurrent;
    }


};

#endif // DLINKEDLIST_H
