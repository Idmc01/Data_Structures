#ifndef NODOESPECIAL_H
#define NODOESPECIAL_H
#define ARRIBA 0
#define ABAJO 1
#define IZQUIERDA 2
#define DERECHA 3

class NodoEspecial{
public:
    int numero;
    NodoEspecial* conexionArriba;
    NodoEspecial* conexionAbajo;
    NodoEspecial* conexionIzquierda;
    NodoEspecial* conexionDerecha;
    bool visitado;
    bool esFinal;
    bool tieneObjeto;
    NodoEspecial(){}
    NodoEspecial(int numero){
        this->numero=numero;
        conexionArriba=nullptr;
        conexionAbajo=nullptr;
        conexionIzquierda=nullptr;
        conexionDerecha=nullptr;
        visitado=false;
        esFinal=false;
        tieneObjeto=false;
    }
    ~NodoEspecial(){}
    int getNumero(){
        return this->numero;
    }
    NodoEspecial* getConexion(int direccion){
        switch(direccion){
        case ARRIBA:
            return conexionArriba;
            break;
        case ABAJO:
            return conexionAbajo;
            break;
        case IZQUIERDA:
            return conexionIzquierda;
            break;
        case DERECHA:
            return conexionDerecha;
            break;
        }
        return nullptr;
    }
    void agregarConexion(int direccion,NodoEspecial* nodo){
        switch(direccion){
        case ARRIBA:
            conexionArriba=nodo;
            break;
        case ABAJO:
            conexionAbajo=nodo;
            break;
        case IZQUIERDA:
            conexionIzquierda=nodo;
            break;
        case DERECHA:
            conexionDerecha=nodo;
            break;
        }
    }
};

#endif // NODOESPECIAL_H
