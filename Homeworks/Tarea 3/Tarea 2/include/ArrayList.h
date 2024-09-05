#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#include "List.h"
#include<stdexcept>
#include<iostream>

#define DEFAULT_MAX_SIZE 1024

using std::runtime_error;
using std::cout;
using std::endl;

template<typename E>
class ArrayList : public List<E>{
private:
    E *elements;
    int max;
    int pos;
    int size;

    void checkCurrentElement(){
        if(size == 0){
            throw runtime_error("List is empty");
        }
        if (pos == size){
            throw runtime_error("No current element");
        }
    }
    void expand(){
        E *temp;
        temp = new E[max *2];
        for(int i = 0; i < size; i++){
            temp[i] = elements[i];
        }
        delete [] elements;
        elements = temp;
        max = max*2;
    }
public:
    ArrayList(int max = DEFAULT_MAX_SIZE){
        elements = new E[max];
        this->max = max;
        size = pos = 0;
    }
    ~ArrayList(){
        delete [] elements;
    }
    ///////////////Tarea/////////////////
    int indexOf(E element){
        int notIn = -1;
        if(size == 0)
            throw runtime_error("List is empty");
        for(int i = 0; i < size; i++){
            if(elements[i] == element)
                return i;
        }
        return notIn;
    }
    bool contains(E element){
        if (size == 0)
            throw runtime_error("List is empty");
        for(int i = 0; i < size; i++){
            if (elements[i] == element)
                return true;
        }
        return false;
    }
    void extend(List<E> *L){
        L->goToStart();
        while(!L->atEnd()){
            append(L->getElement());
            L->next();
        }
    }
    bool equals(List<E> *L){
        goToStart();
        L->goToStart();
        int i = 0;
        while(!L->atEnd()){
            if (L->getElement() != getElement())
                return false;
            L->next();
            next();
            i++;
        }
        if(!atEnd()){
            return false;
        }else{
        return true;
        }
    }
    /////////////////////////////////////////////
    void insert(E element){
        if(size == max){
            //throw runtime_error("List is full.");
            expand();
        }
        for(int i = size; i > pos; i--){
            elements[i] = elements[i - 1];
        }
        elements[pos] = element;
        size++;
    }
    void append(E element){
        if(size == max){
            //throw runtime_error("List is full");
            expand();
        }
        elements[size] = element;
        size++;
    }
    E remove(){
        if(size == 0){
            throw runtime_error("List is empty");
        }
        if (pos == size){
            throw runtime_error("No current element");
        }
        E result = elements[pos];
        for(int i = pos + 1; i < size; i++){
            elements[i - 1] = elements[i];
        }
        size--;
        return result;
    }
    void clear(){
        size = pos = 0;
        /*
        delete []elements;
        elements = new E[max];*/
    }
    E getElement(){
       checkCurrentElement();
       return elements[pos];
    }
    void goToStart(){
        pos = 0;
    }
    void goToEnd(){
        pos = size;
    }
    void goToPos(int newPos){
        if(newPos <  0 || newPos > size){
            throw runtime_error("Position out of range");
        }
        pos = newPos;
    }
    void next(){
        if(pos < size){
            pos++;
        }
    }
    void previous(){
        if(pos > 0){
            pos--;
        }
    }
    bool atStart(){
        return pos == 0;
    }
    bool atEnd(){
        return pos == size;
    }
    int getPos(){
        return pos;
    }
    int getSize(){
        return size;
    }
    void print(){
       int oldPos = pos;
       cout<<"[ ";
       for(goToStart(); !atEnd(); next()){
            cout<<getElement()<<" ";
       }
       cout<<"]"<<endl;
       pos = oldPos;
    }
};


#endif // ARRAYLIST_H
