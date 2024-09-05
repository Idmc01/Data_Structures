#ifndef DNODE_H
#define DNODE_H

template <typename E>
class DNode{
public:
    //atributos del Dnodo
    E element;
    DNode<E> *next;
    DNode<E> *previous;
    //constructores del Dnodo, inicializan los atributos
    DNode(E element,DNode<E> *next,DNode<E> *previous){
        this->element = element;
        this->next = next;
        this->previous = previous;
    }
    DNode(DNode<E> *next, DNode<E> *previous){
        this->next = next;
        this->previous = previous;
    }
};

#endif // DNODE_H
