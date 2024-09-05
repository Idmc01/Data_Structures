#ifndef GRAFOESPECIAL_H
#define GRAFOESPECIAL_H
#include "NodoEspecial.h"
#include "DLinkedList.h"
#include <stdexcept>
#include <iostream>

#include <ctime>
#include <iostream>

#include <cstdlib>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include "LinkedStack.h"
#include "LinkedQueue.h"
using namespace std;

class GrafoEspecial
{

    public:

        int numeroColumnas;
        int numeroFilas;
        NodoEspecial* nodos;

        GrafoEspecial(int numeroFilas, int numeroColumnas) {
            this->numeroColumnas=numeroColumnas;
            this->numeroFilas=numeroFilas;
            nodos=new NodoEspecial[numeroFilas*numeroColumnas];
            for(int i=0;i<numeroFilas*numeroColumnas;i++){
                nodos[i]=NodoEspecial(i);
            }
            for(int i=0;i<numeroFilas*numeroColumnas;i++){
                if(i==0){
                    //el caso si el nodo está en la esquina superior izquierda
                    nodos[i].agregarConexion(ABAJO,&nodos[i+numeroColumnas]);
                    nodos[i].agregarConexion(DERECHA,&nodos[i+1]);
                }
                else if(i==numeroColumnas-1){
                    //el caso si el nodo es el nodo esquina derecha superior
                    nodos[i].agregarConexion(ABAJO,&nodos[i+numeroColumnas]);
                    nodos[i].agregarConexion(IZQUIERDA,&nodos[i-1]);
                }
                else if(i==(numeroFilas*numeroColumnas-numeroColumnas)){
                    //el caso si el nodo es el nodo esquina izquierda inferior
                    nodos[i].agregarConexion(ARRIBA,&nodos[i-numeroColumnas]);
                    nodos[i].agregarConexion(DERECHA,&nodos[i+1]);
                }
                else if(i==(numeroFilas*numeroColumnas-1)){
                    //el caso si el nodo es el nodo esquina derecha inferior
                    nodos[i].agregarConexion(ARRIBA,&nodos[i-numeroColumnas]);
                    nodos[i].agregarConexion(IZQUIERDA,&nodos[i-1]);
                }
                else if(i<numeroColumnas){
                    //el caso si el nodo está en el lado superior pero no es esquina
                    nodos[i].agregarConexion(ABAJO,&nodos[i+numeroColumnas]);
                    nodos[i].agregarConexion(IZQUIERDA,&nodos[i-1]);
                    nodos[i].agregarConexion(DERECHA,&nodos[i+1]);
                }
                else if(i>(numeroFilas*numeroColumnas-numeroColumnas)){
                    //el caso si el nodo está en el lado inferior pero no es esquina
                    nodos[i].agregarConexion(ARRIBA,&nodos[i-numeroColumnas]);
                    nodos[i].agregarConexion(IZQUIERDA,&nodos[i-1]);
                    nodos[i].agregarConexion(DERECHA,&nodos[i+1]);
                }
                else if ((i+1)%(numeroColumnas)==0){
                    //el caso si el nodo está en el lado derecho y no es esquina
                    nodos[i].agregarConexion(ARRIBA,&nodos[i-numeroColumnas]);
                    nodos[i].agregarConexion(ABAJO,&nodos[i+numeroColumnas]);
                    nodos[i].agregarConexion(IZQUIERDA,&nodos[i-1]);
                }
                else if (i%numeroColumnas==0){
                    //el caso si el nodo está en el lado izquierdo y no es esquina
                    nodos[i].agregarConexion(ARRIBA,&nodos[i-numeroColumnas]);
                    nodos[i].agregarConexion(ABAJO,&nodos[i+numeroColumnas]);
                    nodos[i].agregarConexion(DERECHA,&nodos[i+1]);
                }
                else{
                    nodos[i].agregarConexion(ARRIBA,&nodos[i-numeroColumnas]);
                    nodos[i].agregarConexion(ABAJO,&nodos[i+numeroColumnas]);
                    nodos[i].agregarConexion(IZQUIERDA,&nodos[i-1]);
                    nodos[i].agregarConexion(DERECHA,&nodos[i+1]);
                }
            }
        }

        virtual ~GrafoEspecial() {
            delete [] nodos;
        }
        NodoEspecial* crearArbolDeExpansionProfundidad(){
            bool* visitados=new bool[numeroFilas*numeroColumnas];

            LinkedStack<NodoEspecial*>* pilaDeNodos=new LinkedStack<NodoEspecial*>();

            DLinkedList<int>* recorrido=new DLinkedList<int>();

            NodoEspecial* arbolProfundidad;

            arbolProfundidad=new NodoEspecial[numeroFilas*numeroColumnas];
            for(int i=0;i<numeroFilas*numeroColumnas;i++){
                arbolProfundidad[i]=NodoEspecial(i);
            }

            for (int i=0;i<numeroFilas*numeroColumnas;i++){
                visitados[i]=false;
            }
            visitados[0]=true;

            NodoEspecial* currentNode;
            pilaDeNodos->push(&nodos[0]);
            int randomDigit;
            NodoEspecial* randomConnection;
            while(!pilaDeNodos->isEmpty()){
                currentNode=pilaDeNodos->topValue();
                while(!encerrado(currentNode, visitados)){
                    randomDigit=rand() % 4;
                    randomConnection=currentNode->getConexion(randomDigit);
                    if(randomConnection!=nullptr && !visitados[randomConnection->getNumero()]){
                        pilaDeNodos->push(&nodos[currentNode->getNumero()]);
                        recorrido->append(currentNode->getNumero());
                        //primero se agrega la conexión de el primer nodo al siguiente
                        arbolProfundidad[currentNode->getNumero()].agregarConexion(randomDigit
                                         ,&arbolProfundidad[currentNode->getConexion(randomDigit)->getNumero()]);
                        //después se agrega la conexión del siguiente nodo al primero
                        arbolProfundidad[currentNode->getConexion(randomDigit)->getNumero()].agregarConexion(randomDigit
                                         ,&arbolProfundidad[currentNode->getNumero()]);
                        currentNode=currentNode->getConexion(randomDigit);
                        visitados[currentNode->getNumero()]=true;
                    }
                    if(encerrado(currentNode, visitados)){
                        recorrido->append(currentNode->getNumero());
                        visitados[currentNode->getNumero()]=true;
                    }
                }
                pilaDeNodos->pop();
            }
            recorrido->print();
            delete []visitados;
            delete pilaDeNodos;
            delete recorrido;
            return arbolProfundidad;
        }

        NodoEspecial* crearArbolDeExpansionAnchura(){
            bool* visitados=new bool[numeroFilas*numeroColumnas];

            LinkedQueue<NodoEspecial*>* colaDeNodos=new LinkedQueue<NodoEspecial*>();

            DLinkedList<int>* recorrido=new DLinkedList<int>();

            NodoEspecial* arbolAnchura;

            arbolAnchura=new NodoEspecial[numeroFilas*numeroColumnas];
            for(int i=0;i<numeroFilas*numeroColumnas;i++){
                arbolAnchura[i]=NodoEspecial(i);
            }

            for (int i=0;i<numeroFilas*numeroColumnas;i++){
                visitados[i]=false;
            }
            visitados[(numeroColumnas/2)]=true;

            NodoEspecial* currentNode;

            colaDeNodos->enqueue(&nodos[(numeroColumnas/2)]);
            recorrido->append(nodos[(numeroColumnas/2)].getNumero());
            visitados[nodos[(numeroColumnas/2)].getNumero()]=true;
            int randomDigit;
            NodoEspecial* randomConnection;

            while(!colaDeNodos->isEmpty()){
                currentNode=colaDeNodos->getFront();

                while(!encerrado(currentNode, visitados)){
                    randomDigit=rand() % 4;
                    randomConnection=currentNode->getConexion(randomDigit);
                    if(randomConnection!=nullptr && !visitados[randomConnection->getNumero()]){
                        colaDeNodos->enqueue(&nodos[currentNode->getConexion(randomDigit)->getNumero()]);
                        recorrido->append(currentNode->getConexion(randomDigit)->getNumero());
                        visitados[currentNode->getConexion(randomDigit)->getNumero()]=true;
                        //primero se agrega la conexión de el primer nodo al siguiente
                        arbolAnchura[currentNode->getNumero()].agregarConexion(randomDigit
                                         ,&arbolAnchura[currentNode->getConexion(randomDigit)->getNumero()]);
                        //después se agrega la conexión del siguiente nodo al primero
                        arbolAnchura[currentNode->getConexion(randomDigit)->getNumero()].agregarConexion(randomDigit
                                         ,&arbolAnchura[currentNode->getNumero()]);

                    }
                }
                colaDeNodos->dequeue();
            }
            recorrido->print();
            delete []visitados;
            delete colaDeNodos;
            delete recorrido;
            return arbolAnchura;
        }


        NodoEspecial* crearArbolDeExpansionPrim(){
            bool* agregados=new bool[numeroFilas*numeroColumnas];
            NodoEspecial* arbolPrim=new NodoEspecial[numeroFilas*numeroColumnas];
            DLinkedList<NodoEspecial*>* nodosAgregados=new DLinkedList<NodoEspecial*>();
            for(int i=0;i<numeroFilas*numeroColumnas;i++){
                arbolPrim[i]=NodoEspecial(i);
                agregados[i]=false;
            }
            nodosAgregados->append(&nodos[0]);
            agregados[0]=true;
            NodoEspecial* currentNode=&nodos[0];
            int nodoRandom;
            int numeroConexionRandom;
            NodoEspecial* conexion;
            nodosAgregados->goToStart();
            while(!recorridoTotal(agregados)){
                nodoRandom=rand()%nodosAgregados->getSize();
                numeroConexionRandom=rand()%4;
                nodosAgregados->goToPos(nodoRandom);
                currentNode=nodosAgregados->getElement();
                conexion=currentNode->getConexion(numeroConexionRandom);
                agregados[conexion->getNumero()]=true;
                nodosAgregados->append(conexion);

                //primero se agrega la conexión de el primer nodo al siguiente
                arbolPrim[currentNode->getNumero()].agregarConexion(numeroConexionRandom
                                 ,&arbolPrim[currentNode->getConexion(numeroConexionRandom)->getNumero()]);
                //después se agrega la conexión del siguiente nodo al primero
                arbolPrim[currentNode->getConexion(numeroConexionRandom)->getNumero()].agregarConexion(numeroConexionRandom
                                 ,&arbolPrim[currentNode->getNumero()]);

            }

            /*NodoEspecial* arbolPrim=new NodoEspecial[numeroFilas*numeroColumnas];
            DLinkedList<NodoEspecial*>* nodosAgregados=new DLinkedList<NodoEspecial*>();
            bool* agregados=new bool[numeroFilas*numeroColumnas];

            DLinkedList<int>* recorrido=new DLinkedList<int>();
            for(int i=0;i<numeroFilas*numeroColumnas;i++){
                arbolPrim[i]=NodoEspecial(i);
                agregados[i]=false;
            }
            int randomDigit;
            nodosAgregados->append(&nodos[0]);
            NodoEspecial* currentNode=&nodos[0];
            agregados[0]=true;
            recorrido->append(0);
            while(!recorridoTotal(agregados)){
                randomDigit=rand() % nodosAgregados->getSize();
                nodosAgregados->goToPos(randomDigit);
                currentNode=nodosAgregados->getElement();
                randomDigit=rand()%4;

                //primero se agrega la conexión de el primer nodo al siguiente
                arbolPrim[currentNode->getNumero()].agregarConexion(randomDigit
                                 ,&arbolPrim[currentNode->getConexion(randomDigit)->getNumero()]);
                //después se agrega la conexión del siguiente nodo al primero
                arbolPrim[currentNode->getConexion(randomDigit)->getNumero()].agregarConexion(randomDigit
                                 ,&arbolPrim[currentNode->getNumero()]);

                nodosAgregados->append(&nodos[currentNode->getConexion(randomDigit)->getNumero()]);
                agregados[currentNode->getConexion(randomDigit)->getNumero()]=true;
                recorrido->append(currentNode->getConexion(randomDigit)->getNumero());
            }
            recorrido->print();

            delete agregados;
            return arbolPrim;*/
        }

        bool encerrado(NodoEspecial* nodo,bool* listaBooleanos){
            bool encerradoArriba=   nodo->conexionArriba==nullptr||listaBooleanos[nodo->conexionArriba->getNumero()];
            bool encerradoAbajo=    nodo->conexionAbajo==nullptr||listaBooleanos[nodo->conexionAbajo->getNumero()];
            bool encerradoIzquierda=nodo->conexionIzquierda==nullptr||listaBooleanos[nodo->conexionIzquierda->getNumero()];
            bool encerradoDerecha=  nodo->conexionDerecha==nullptr||listaBooleanos[nodo->conexionDerecha->getNumero()];
            return (encerradoAbajo && encerradoArriba && encerradoDerecha && encerradoIzquierda);
        }
        bool recorridoTotal(bool* listaBooleanos){
            for (int i=0;i<numeroFilas*numeroColumnas;i++){
                if(!listaBooleanos[i]){
                    return false;
                }
            }
            return true;
        }
        void print(){
            cout<<"[ ";
            for(int i=0;i<numeroFilas*numeroColumnas;i++){
                if(i%numeroColumnas==0 && i!=0){
                    cout<<endl;
                    cout<<"  ";

                }
                cout<<nodos[i].getNumero()<<" ";

            }
            cout<<" ]"<<endl;
        }

};

#endif // GRAFOESPECIAL_H
