#ifndef NODOESPECIAL2_H
#define NODOESPECIAL2_H


class NodoEspecial2{
public:
    int numero;
    DLinkedList<NodoEspecial2*>* conexiones;
    bool caminoMasCorto;
    bool esFinal;
    bool tieneObjeto;
    NodoEspecial2(){
        conexiones=new DLinkedList<NodoEspecial2*>();
        esFinal=false;
        tieneObjeto=false;
        caminoMasCorto=false;
    }
    ~NodoEspecial2(){
        delete conexiones;
    }

    NodoEspecial2* getRandomConnection(){
        if(conexiones->getSize()==0){
            throw runtime_error("No hay conexiones");
        }
        else{
            int randomDigit=rand() % conexiones->getSize();
            conexiones->goToPos(randomDigit);
            return conexiones->getElement();
        }

    }
    void agregarConexion(NodoEspecial2* nodo){
        conexiones->append(nodo);
    }
};

#endif // NODOESPECIAL2_H
