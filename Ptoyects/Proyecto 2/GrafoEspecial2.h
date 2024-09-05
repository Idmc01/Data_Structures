#ifndef GRAFOESPECIAL2_H
#define GRAFOESPECIAL2_H
#include "DLinkedList.h"
#include "NodoEspecial2.h"
class GrafoEspecial2
{
    public:
        NodoEspecial2* nodos;
        int filas;
        int columnas;
        GrafoEspecial2(int filas,int columnas) {
            nodos=new NodoEspecial2[filas*columnas];
            this->columnas=columnas;
            this->filas=filas;

            for(int i=0;i<filas*columnas;i++){
                nodos[i].numero=i;
            }
            for(int i=0;i<filas*columnas;i++){
                if(i==0){
                    //el caso si el nodo está en la esquina superior izquierda
                    nodos[i].agregarConexion(&nodos[i+columnas]);
                    nodos[i].agregarConexion(&nodos[i+1]);
                }
                else if(i==columnas-1){
                    //el caso si el nodo es el nodo esquina derecha superior
                    nodos[i].agregarConexion(&nodos[i+columnas]);
                    nodos[i].agregarConexion(&nodos[i-1]);
                }
                else if(i==(filas*columnas-columnas)){
                    //el caso si el nodo es el nodo esquina izquierda inferior
                    nodos[i].agregarConexion(&nodos[i-columnas]);
                    nodos[i].agregarConexion(&nodos[i+1]);
                }
                else if(i==(filas*columnas-1)){
                    //el caso si el nodo es el nodo esquina derecha inferior
                    nodos[i].agregarConexion(&nodos[i-columnas]);
                    nodos[i].agregarConexion(&nodos[i-1]);
                }
                else if(i<columnas){
                    //el caso si el nodo está en el lado superior pero no es esquina
                    nodos[i].agregarConexion(&nodos[i+columnas]);
                    nodos[i].agregarConexion(&nodos[i-1]);
                    nodos[i].agregarConexion(&nodos[i+1]);
                }
                else if(i>(filas*columnas-columnas)){
                    //el caso si el nodo está en el lado inferior pero no es esquina
                    nodos[i].agregarConexion(&nodos[i-columnas]);
                    nodos[i].agregarConexion(&nodos[i-1]);
                    nodos[i].agregarConexion(&nodos[i+1]);
                }
                else if ((i+1)%(columnas)==0){
                    //el caso si el nodo está en el lado derecho y no es esquina
                    nodos[i].agregarConexion(&nodos[i-columnas]);
                    nodos[i].agregarConexion(&nodos[i+columnas]);
                    nodos[i].agregarConexion(&nodos[i-1]);
                }
                else if (i%columnas==0){
                    //el caso si el nodo está en el lado izquierdo y no es esquina
                    nodos[i].agregarConexion(&nodos[i-columnas]);
                    nodos[i].agregarConexion(&nodos[i+columnas]);
                    nodos[i].agregarConexion(&nodos[i+1]);
                }
                else{
                    nodos[i].agregarConexion(&nodos[i-columnas]);
                    nodos[i].agregarConexion(&nodos[i+columnas]);
                    nodos[i].agregarConexion(&nodos[i-1]);
                    nodos[i].agregarConexion(&nodos[i+1]);
                }
            }
        }
        virtual ~GrafoEspecial2() {
            delete [] nodos;
        }
        NodoEspecial2* crearArbolDeExpansionProfundidad(){
            bool* visitados=new bool[filas*columnas];

            LinkedStack<NodoEspecial2*>* pilaDeNodos=new LinkedStack<NodoEspecial2*>();

            DLinkedList<int>* recorrido=new DLinkedList<int>();

            NodoEspecial2* arbolProfundidad=new NodoEspecial2[filas*columnas];

            for (int i=0;i<filas*columnas;i++){
                visitados[i]=false;
                arbolProfundidad[i].numero=i;
            }
            visitados[0]=true;

            NodoEspecial2* currentNode;
            pilaDeNodos->push(&nodos[0]);
            NodoEspecial2* randomConnection;
            while(!pilaDeNodos->isEmpty()){

                currentNode=pilaDeNodos->topValue();
                while(!encerrado(currentNode->conexiones, visitados)){
                    randomConnection=currentNode->getRandomConnection();
                    if(!visitados[randomConnection->numero]){
                        pilaDeNodos->push(&nodos[currentNode->numero]);
                        recorrido->append(currentNode->numero);
                        //primero se agrega la conexión de el primer nodo al siguiente
                        arbolProfundidad[currentNode->numero].agregarConexion(&arbolProfundidad[randomConnection->numero]);
                        //después se agrega la conexión del siguiente nodo al primero
                        arbolProfundidad[randomConnection->numero].agregarConexion(&arbolProfundidad[currentNode->numero]);
                        currentNode=randomConnection;
                        visitados[currentNode->numero]=true;
                    }
                    if(encerrado(currentNode->conexiones, visitados)){
                        recorrido->append(currentNode->numero);
                        visitados[currentNode->numero]=true;
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
        NodoEspecial2* crearArbolDeExpansionAnchura(){
            bool* visitados=new bool[filas*columnas];

            LinkedQueue<NodoEspecial2*>* colaDeNodos=new LinkedQueue<NodoEspecial2*>();

            DLinkedList<int>* recorrido=new DLinkedList<int>();

            NodoEspecial2* arbolAnchura=new NodoEspecial2[filas*columnas];
            for(int i=0;i<filas*columnas;i++){
                arbolAnchura[i].numero=i;
                visitados[i]=false;
            }
            visitados[0]=true;

            NodoEspecial2* currentNode;

            colaDeNodos->enqueue(&nodos[0]);
            recorrido->append(0);
            visitados[0]=true;
            NodoEspecial2* randomConnection;
            while(!colaDeNodos->isEmpty()){
                currentNode=colaDeNodos->getFront();
                while(!encerrado(currentNode->conexiones, visitados)){
                    randomConnection=currentNode->getRandomConnection();

                    if(!visitados[randomConnection->numero]){
                        colaDeNodos->enqueue(&nodos[randomConnection->numero]);
                        recorrido->append(randomConnection->numero);
                        visitados[randomConnection->numero]=true;
                        //primero se agrega la conexión de el primer nodo al siguiente
                        arbolAnchura[currentNode->numero].agregarConexion(&arbolAnchura[randomConnection->numero]);
                        //después se agrega la conexión del siguiente nodo al primero
                        arbolAnchura[randomConnection->numero].agregarConexion(&arbolAnchura[currentNode->numero]);
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
        NodoEspecial2* crearArbolDeExpansionPrim(){
            NodoEspecial2* arbolPrim=new NodoEspecial2[filas*columnas];

            DLinkedList<NodoEspecial2*>* nodosAgregados=new DLinkedList<NodoEspecial2*>();

            for(int i=0;i<filas*columnas;i++){
                arbolPrim[i].numero=i;
            }

            nodosAgregados->append(&nodos[0]);

            NodoEspecial2* currentNode;

            int nodoRandom;

            NodoEspecial2* conexionRandom;

            nodosAgregados->goToStart();

            while(nodosAgregados->getSize()!=filas*columnas){
                nodoRandom=rand()%nodosAgregados->getSize();

                nodosAgregados->goToPos(nodoRandom);

                currentNode=nodosAgregados->getElement();

                conexionRandom=currentNode->getRandomConnection();

                if(!estaEnLaLista(nodosAgregados,conexionRandom)){
                    nodosAgregados->append(conexionRandom);
                    //primero se agrega la conexión de el primer nodo al siguiente
                    arbolPrim[currentNode->numero].agregarConexion(&arbolPrim[conexionRandom->numero]);
                    //después se agrega la conexión del siguiente nodo al primero
                    arbolPrim[conexionRandom->numero].agregarConexion(&arbolPrim[currentNode->numero]);
                }
            }
            delete nodosAgregados;
            return arbolPrim;

        }
        bool estaEnLaLista(DLinkedList<NodoEspecial2*>* lista,NodoEspecial2* nodo){
            for(int i=0;i<lista->getSize();i++){
                lista->goToPos(i);
                if(lista->getElement()->numero==nodo->numero){
                    return true;
                }
            }
            return false;

        }
        bool encerrado(DLinkedList<NodoEspecial2*>* conexiones,bool* listaBooleanos){
            for(conexiones->goToStart();!conexiones->atEnd();conexiones->next()){
                if(!listaBooleanos[conexiones->getElement()->numero]){
                    return false;
                }
            }
            return true;
        }
        bool recorridoTotal(bool* listaBooleanos){
            for (int i=0;i<filas*columnas;i++){
                if(!listaBooleanos[i]){
                    return false;
                }
            }
            return true;
        }
        void print(){
            for(int i=0;i<filas*columnas;i++){
                if(i<10 && i!=0){
                    cout<<" ";
                }
                if(i%columnas==0 && i!=0){
                    cout<<endl;
                }

                cout<<nodos[i].numero<<" ";
            }
            cout<<endl;
        }

};

#endif // GRAFOESPECIAL2_H
