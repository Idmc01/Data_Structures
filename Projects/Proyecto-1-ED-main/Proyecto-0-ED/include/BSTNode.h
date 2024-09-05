#ifndef BSTNODE_H
#define BSTNODE_H

template <typename E>
class BSTNode{
public:
    //Definición de atributos
    E element;
    BSTNode<E> *left;
    BSTNode<E> *right;
    //Constructor
    BSTNode(E element){
        this->element = element;
        left = nullptr;
        right = nullptr;
    }
    //Destrcutor
    ~BSTNode(){}
    //Retorna la cantidad de hijos del nodo
    int childrenCount(){
        return (left == nullptr? 0 : 1) + (right == nullptr? 0 : 1);
    }
    //retorna el único hijo del nodo
    BSTNode<E> *getUniqueChild(){
        return left == nullptr?  right : left;
    }

};

#endif // BSTNODE_H
