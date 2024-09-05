#include <iostream>
#include "GrafoEspecial.h"
#include "NodoEspecial.h"
#include "GrafoEspecial2.h"
#include "NodoEspecial2.h"
#include "time.h"
#include <SFML/Graphics.hpp>
#define NUMERO_OBJETOS 4
using namespace std;
void imprimirArreglo(GrafoEspecial2* grafo,NodoEspecial2* laberinto)
{

    //profundidad();
    sf::RenderWindow window(sf::VideoMode(650, 650), "Proyecto 2 Estructuras de Datos");
    sf::RectangleShape rect[grafo->columnas*grafo->filas];
    int x = 0, y = 0, i = 0;
    int nodofila = 0;

    while (window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        DLinkedList<NodoEspecial2*>* conexiones;
        while (i < grafo->columnas*grafo->filas) {

            rect[i].setSize(sf::Vector2f(20, 20));
            conexiones=laberinto[i].conexiones;
            if(nodofila<grafo->columnas){
                for(conexiones->goToStart();!conexiones->atEnd();conexiones->next()){
                    if(conexiones->getElement()->numero==i+1){
                        //el nodo de la derecha
                        rect[i].setSize(sf::Vector2f(20+35,20));
                        rect[i].setPosition(x,y);
                    }
                    else if(conexiones->getElement()->numero==i+grafo->columnas){
                        //el nodo de abajo
                        rect[i].setSize(sf::Vector2f(20,20+35));
                        rect[i].setPosition(x,y);
                    }
                    else{
                        rect[i].setPosition(x,y);
                    }
                    window.draw(rect[i]);
                }
                x+=35;
                rect[i].setFillColor(sf::Color::Cyan);


                if(laberinto[i].esFinal){
                    rect[i].setFillColor(sf::Color::Red);
                }
                if(laberinto[i].tieneObjeto){
                    rect[i].setFillColor(sf::Color::Yellow);
                }
                i++;
                nodofila++;
            }
            else{
                y+=35;
                x=0;
                nodofila=0;
            }

        }

        i = 0;
        x = 0;
        y = 0;
        window.display();
    }
}
    void printConnections(NodoEspecial2* arreglo, int filas, int columnas){
        DLinkedList<NodoEspecial2*>* conexiones;
        for(int i=0;i<filas*columnas;i++){
            cout<<arreglo[i].numero<<": ";
            conexiones=arreglo[i].conexiones;
            for(conexiones->atStart();!conexiones->atEnd();conexiones->next()){
                if(!conexiones->atEnd())
                cout<<conexiones->getElement()->numero<<" ";
            }
            cout<<endl;
            cout<<"Cantidad de conexiones: "<<conexiones->getSize()<<endl;
        }
    }
bool nodoEstaEnLaLista(DLinkedList<NodoEspecial2*>* conexiones, int numeroNodo){
    for(conexiones->goToStart();!conexiones->atEnd();conexiones->next()){
        if(conexiones->getElement()->numero==numeroNodo){
             return true;
        }

    }
    return false;
}
bool inMiddle(int numero,int filas,int columnas){
    if(numero<columnas)return false;
    if(numero>(filas*columnas-columnas))return false;
    if ((numero+1)%(columnas)==0)return false;
    if (numero%columnas==0) return false;
    return true;
}
void generarObjetosYFin(GrafoEspecial2* grafo,NodoEspecial2* laberinto){
    printConnections(laberinto,grafo->filas,grafo->columnas);
    int randomFin;
    int inicio=grafo->columnas*grafo->filas/2;
    int fin=grafo->columnas*grafo->filas;
    randomFin= inicio + (rand()%(fin-inicio+1));
    laberinto[randomFin].esFinal=true;
    randomFin=rand()%grafo->filas*grafo->columnas;
    for(int i=0;i<=NUMERO_OBJETOS;i++){
        randomFin=1+rand()%(grafo->filas*grafo->columnas);
        laberinto[randomFin].tieneObjeto=true;
    }

    randomFin=rand()%(grafo->filas*grafo->columnas);
    int intRandomConnection=rand()%4;
    DLinkedList<NodoEspecial2*>* conexiones;
    int contador=0;
    while(contador<(grafo->filas*grafo->columnas*5/100)){
        if(laberinto[randomFin].conexiones->getSize()<4 && inMiddle(randomFin,grafo->filas,grafo->columnas)){
            conexiones=laberinto[randomFin].conexiones;
            intRandomConnection=rand()%4;
            cout<<"Numero: "<<randomFin<<endl;
            if(intRandomConnection==0 &&!nodoEstaEnLaLista(conexiones, randomFin-grafo->columnas)){
                cout<<"Conexion: "<<randomFin-grafo->columnas<<endl;
                //primero se agrega la conexión de el primer nodo al siguiente
                laberinto[randomFin].agregarConexion(&laberinto[randomFin-grafo->columnas]);
                //después se agrega la conexión del siguiente nodo al primero
                laberinto[randomFin-grafo->columnas].agregarConexion(&laberinto[randomFin]);
                contador++;
                randomFin=rand()%(grafo->filas*grafo->columnas);
            }
            if(intRandomConnection==1 && !nodoEstaEnLaLista(conexiones, randomFin+grafo->columnas)){
                cout<<"Conexion: "<<randomFin+grafo->columnas<<endl;
                //primero se agrega la conexión de el primer nodo al siguiente
                laberinto[randomFin].agregarConexion(&laberinto[randomFin+grafo->columnas]);
                //después se agrega la conexión del siguiente nodo al primero
                laberinto[randomFin+grafo->columnas].agregarConexion(&laberinto[randomFin]);
                contador++;
                randomFin=rand()%(grafo->filas*grafo->columnas);
            }
            if(intRandomConnection==2 && !nodoEstaEnLaLista(conexiones, randomFin-1)){
                cout<<"Conexion: "<<randomFin-1<<endl;
                //primero se agrega la conexión de el primer nodo al siguiente
                laberinto[randomFin].agregarConexion(&laberinto[randomFin-1]);
                //después se agrega la conexión del siguiente nodo al primero
                laberinto[randomFin-1].agregarConexion(&laberinto[randomFin]);
                contador++;
                randomFin=rand()%(grafo->filas*grafo->columnas);
            }
            if(intRandomConnection==3 && !nodoEstaEnLaLista(conexiones, randomFin+1)){
                cout<<"Conexion: "<<randomFin+1<<endl;
                //primero se agrega la conexión de el primer nodo al siguiente
                laberinto[randomFin].agregarConexion(&laberinto[randomFin+1]);
                //después se agrega la conexión del siguiente nodo al primero
                laberinto[randomFin+1].agregarConexion(&laberinto[randomFin]);
                contador++;
                randomFin=rand()%(grafo->filas*grafo->columnas);
            }
        }
        else{
            randomFin=rand()%(grafo->filas*grafo->columnas);
        }
    }
    imprimirArreglo(grafo,laberinto);

}
void profundidad2(){
    cout<<"Determine la cantidad de filas del mapa: ";
    int filas;
    cin>>filas;
    cout<<"Determine la cantidad de columnas del mapa: ";
    int columnas;
    cin>>columnas;
    GrafoEspecial2* grafo=new GrafoEspecial2(filas,columnas);
    grafo->print();
    NodoEspecial2* laberintoProfundidad=grafo->crearArbolDeExpansionProfundidad();
    generarObjetosYFin(grafo,laberintoProfundidad);
}
void anchura2(){
    cout<<"Determine la cantidad de filas del mapa: ";
    int filas;
    cin>>filas;
    cout<<"Determine la cantidad de columnas del mapa: ";
    int columnas;
    cin>>columnas;
    GrafoEspecial2* grafo=new GrafoEspecial2(filas,columnas);
    grafo->print();
    NodoEspecial2* laberintoAnchura=grafo->crearArbolDeExpansionAnchura();
    generarObjetosYFin(grafo,laberintoAnchura);
}
void prim2(){
    cout<<"Determine la cantidad de filas del mapa: ";
    int filas;
    cin>>filas;
    cout<<"Determine la cantidad de columnas del mapa: ";
    int columnas;
    cin>>columnas;
    GrafoEspecial2* grafo=new GrafoEspecial2(filas,columnas);
    grafo->print();
    NodoEspecial2* laberintoPrim=grafo->crearArbolDeExpansionPrim();
    generarObjetosYFin(grafo,laberintoPrim);
}

int main(){
    srand(time(NULL));
    while(true){
        cout<<"1- Laberinto de profundidad"<<endl;
        cout<<"2- Laberinto de anchura"<<endl;
        cout<<"3- Laberinto de prim"<<endl;
        cout<<"Determine el recorrido de laberinto que desea implementar: ";
        int numero;
        cin>>numero;
        if (numero==1){
            profundidad2();
        }
        if(numero==2){
            anchura2();
        }
        if(numero==3){
            prim2();
        }
        cout<<"¿Desea realizar otro recorrido?(S/N) ";
        string letra;
        cin>>letra;
        if(letra=="N"){
            break;
        }
    }
    return 0;
}
