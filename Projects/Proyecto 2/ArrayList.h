#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "List.h"
#include <stdexcept>
#include <iostream>
#define DEFAULT_MAX_SIZE 1024

using namespace std;

template<typename E>
class ArrayList : public List<E>{
    private:
        E *elements;
        int max;
        int pos;
        int size;
        void checkCurrentElement(){
            if (size==0){
                throw runtime_error("Lista vacía");
            }
            if (pos==size){
                throw runtime_error("No hay elemento en la posición actual");
            }
        }

        void expand(){
            max=max*2;
            E *temp=new E[max];
            for(int i=0;i<size;i++){
                temp[i]=elements[i];
            }
            delete [] elements;
            elements=temp;
        }

    public:
        ArrayList(int max=DEFAULT_MAX_SIZE) {
            elements=new E[max];
            this->max=max;
            size=pos=0;
        }
        ~ArrayList() {
            delete[] elements;
        }
        void insert(E element){
            if (size==max){
                expand();
            }
            for (int i=size;i>pos; i--){
                elements[i]=elements[i-1];
            }
            elements[pos]=element;
            size++;
        }

        void append(E element){
            if (size==max){
                expand();
            }
            elements[size]=element;
            size++;
        }

        E remove(){
            checkCurrentElement();
            E result=elements[pos];
            for(int i=pos+1;i<size;i++){
                elements[i-1]=elements[i];
            }
            size--;
            return result;
        }

        void clear(){
            size=pos=0;
            delete [] elements;
            elements=new E[max];
        }

        E getElement(){
            checkCurrentElement();
            return elements[pos];
        }

        void goToStart(){
            pos=0;
        }

        void goToEnd(){
            pos=size;
        }

        void goToPos(int pos){
            if (pos<0 || pos>size){
                throw runtime_error("Posición fuera de rango");
            }
            this->pos=pos;
        }

        void previous(){
            if(pos>0){
                pos--;
            }
        }

        void next(){
            if(pos<size){
                pos++;
            }
        }

        bool atStart(){
            return pos==0;
        }

        bool atEnd(){
            return pos==size;
        }

        int getPos(){
            return pos;
        }

        int getSize(){
            return size;
        }

        void print(){
            int oldPos=pos;
            cout<<"[ ";
            for(goToStart();!atEnd();next()){
                cout<< getElement()<<" ";
            }
            cout<<"]"<<endl;
            pos=oldPos;
        }
        int indexOf(E element){
            int oldPos=pos;
            for(goToStart();!atEnd();next()){
                if(getElement()==element){
                    int answer=getPos();
                    pos=oldPos;
                    return answer;
                }
            }
            pos=oldPos;
            throw runtime_error("No se encontró el elemento.");
        }
        bool contains(E element){
            int oldPos=pos;
            for(goToStart();!atEnd();next()){
                if(getElement()==element){
                    pos=oldPos;
                    return true;
                }
            }
            pos=oldPos;
            return false;
        }
        void extend(List<E> *L){
            int oldPosL=L->getPos();
            for(L->goToStart();!L->atEnd();L->next()){
                if (size==max){
                    expand();
                }
                else{
                    append(L->getElement());
                }
            }
            L->goToPos(oldPosL);
        }
        bool equals(List<E> *L){
            int oldPos=pos;
            int oldPosL=L->getPos();
            for(int i=0;i<size;i++){
                goToPos(i);
                L->goToPos(i);
                if(getElement()!=L->getElement()){
                    goToPos(oldPos);
                    L->goToPos(oldPosL);
                    return false;
                }
            }
            goToPos(oldPos);
            L->goToPos(oldPosL);
            return true;

        }






};

#endif // ARRAYLIST_H
