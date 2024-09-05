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
        //declaraci�n de atributos
        E *elements;
        int max;
        int pos;
        int size;
        //Revisa si existe el elemento en la posici�n actual
        void checkCurrentElement(){
            if (size==0){
                throw runtime_error("Lista vac�a");
            }
            if (pos==size){
                throw runtime_error("No hay elemento en la posici�n actual");
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
        //inserta un elemento al ArrayList en la posici�n actual
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
        //Remueve el elemento en la posici�n actual
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
        //Retorna el elemento en la posici�n actual
        E getElement(){
            checkCurrentElement();
            return elements[pos];
        }
        //Lleva la posici�n actual al inicio
        void goToStart(){
            pos=0;
        }
        //Lleva la posici�n actual al final
        void goToEnd(){
            pos=size;
        }
        //Lleva la posici�n actual a la posici�n indicada por el par�metro
        void goToPos(int pos){
            if (pos<0 || pos>size){
                throw runtime_error("Posici�n fuera de rango");
            }
            this->pos=pos;
        }
        //Lleva la posici�n actual a la anterior
        void previous(){
            if(pos>0){
                pos--;
            }
        }
        //Lleva la posici�n actual a la siguiente
        void next(){
            if(pos<size){
                pos++;
            }
        }
        //Consulta si la posici�n actual est� al inicio

        bool atStart(){
            return pos==0;
        }
        //Consulta si la posici�n actual est� al final
        bool atEnd(){
            return pos==size;
        }
        //Obtiene la posci�n actual de la lista
        int getPos(){
            return pos;
        }
        //Consulta si el tama�o de la lista
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
        //Obtiene el �ndice de un elemento en la lista
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
            throw runtime_error("No se encontr� el elemento.");
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
