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
        //declaración de atributos
        E *elements;
        int max;
        int pos;
        int size;
        //Revisa si existe el elemento en la posición actual
        void checkCurrentElement(){
            if (size==0){
                throw runtime_error("Lista vacía");
            }
            if (pos==size){
                throw runtime_error("No hay elemento en la posición actual");
            }
        }
        //Expande la memoria al doble
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
        //Constructor, inicializa los atributos
        ArrayList(int max=DEFAULT_MAX_SIZE) {
            elements=new E[max];
            this->max=max;
            size=pos=0;
        }
        //Destructor, elimina la memoria solicitada
        ~ArrayList() {
            delete[] elements;
        }
        //inserta un elemento al ArrayList en la posición actual
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
        //Inserta un elemento al final del ArrayList
        void append(E element){
            if (size==max){
                expand();
            }
            elements[size]=element;
            size++;
        }
        //Remueve el elemento en la posición actual
        E remove(){
            checkCurrentElement();
            E result=elements[pos];
            for(int i=pos+1;i<size;i++){
                elements[i-1]=elements[i];
            }
            size--;
            return result;
        }
        //Limpia la lista
        void clear(){
            size=pos=0;
            delete [] elements;
            elements=new E[max];
        }
        //Retorna el elemento en la posición actual
        E getElement(){
            checkCurrentElement();
            return elements[pos];
        }
        //Lleva la posición actual al inicio
        void goToStart(){
            pos=0;
        }
        //Lleva la posición actual al final
        void goToEnd(){
            pos=size;
        }
        //Lleva la posición actual a la posición indicada por el parámetro
        void goToPos(int pos){
            if (pos<0 || pos>size){
                throw runtime_error("Posición fuera de rango");
            }
            this->pos=pos;
        }
        //Lleva la posición actual a la anterior
        void previous(){
            if(pos>0){
                pos--;
            }
        }
        //Lleva la posición actual a la siguiente
        void next(){
            if(pos<size){
                pos++;
            }
        }
        //Consulta si la posición actual está al inicio

        bool atStart(){
            return pos==0;
        }
        //Consulta si la posición actual está al final
        bool atEnd(){
            return pos==size;
        }
        //Obtiene la posción actual de la lista
        int getPos(){
            return pos;
        }
        //Consulta si el tamaño de la lista
        int getSize(){
            return size;
        }
        //Imprime la lista
        void print(){
            int oldPos=pos;
            cout<<"[ ";
            for(goToStart();!atEnd();next()){
                cout<< getElement()<<" ";
            }
            cout<<"]"<<endl;
            pos=oldPos;
        }
        //Obtiene el índice de un elemento en la lista
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
        //Consulta si la lista contiene un elemento
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
        //Extiende la lista a partir de otra lista
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
        //Consulta si una lista es equivalente a esta
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
