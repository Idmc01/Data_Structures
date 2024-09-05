#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include "BSTNode.h"
#include "DLinkedList.h"
#include <iostream>

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class BSTree{
private:
    //Definición de atributos
    BSTNode<E> *root;
    //Método auxiliar del método insertar que permite de forma recursiva agregar un elemento al árbol
    BSTNode<E>* insertAux(BSTNode<E> *current, E element){
        if(current == nullptr){
            return new BSTNode<E>(element);
        }
        //si el arbol no permite valores repetidos
        if(element == current->element){
            throw runtime_error("Duplicate key");
        }
        if(element < current->element){
            current->left = insertAux(current->left, element);
            return current;
        }else{
            current->right = insertAux(current->right, element);
            return current;
        }
    }
    //Método recursivo para encontrar un elemento en el árbol
    E findAux(BSTNode<E> *current, E element){
        if(current == nullptr){
            throw runtime_error("Element not found");
        }
        if(element == current->element){
            return current->element;
        }
        if(element < current->element){
            return findAux(current->left, element);
        }else{
            return findAux(current->right, element);
        }
    }
    //Método recursivo para remover un elemento del árbol
    BSTNode<E>* removeAux(BSTNode<E> *current, E element, E *result){
        if (current == nullptr){
            throw runtime_error("Element not found");
        }
        if( element < current->element ){
          current->left = removeAux(current->left, element, result);
          return current;
        }
        if( element > current->element ){
          current->right = removeAux(current->right, element, result);
          return current;
        }else{
            *result = current->element;
            if(current->childrenCount() == 0){
                delete current;
                return nullptr;
            }
            if(current->childrenCount() == 1){
                auto child = current->getUniqueChild();
                delete current;
                return child;
            }else{
                // tienes dos hijos
                BSTNode<E> *succesor = getSuccesor(current);
                swap(current, succesor);
                current->right = removeAux(current->right, element, result);
                return current;
            }
        }
    }
    //Este método ayuda a encontrar el sucesor de un nodo para sustituirlo en caso de usar el método remove()
    BSTNode<E>* getSuccesor(BSTNode<E> *current){
        BSTNode<E> *successor = current->right;
        while(successor->left != nullptr){
            successor = successor->left;
        }
        return successor;
    }
    //Cambia de lugar un nodo con otro
    void swap(BSTNode<E> *node1, BSTNode<E> *node2){
        E temp = node1->element;
        node1->element = node2->element;
        node2->element = temp;
    }
    //Método recursivo para encontrar si un árbol contiene un método
    bool constainsAux(BSTNode<E> *current, E element){
        if(current == nullptr)
            return false;
        if(element == current->element)
            return true;
        if(element < current->element)
            return constainsAux(current->left, element);
        else
            return constainsAux(current->right, element);
    }
    //Método recursivo para limpiar de elementos un árbol
    void clearAux(BSTNode<E> *current){
        if(current == nullptr)
            return;
        clearAux(current->left);
        clearAux(current->right);
        delete current;
    }
    //Enlista los elementos de un árbol
    void getElementsAux(BSTNode<E> *current, List<E> *list){
        if(current == nullptr)
            return;
        getElementsAux(current->left, list);
        list->append(current->element);
        getElementsAux(current->right, list);
    }
    //Obtiene la cantidad de elementos en un árbol (método recursivo)
    int getSizeAux(BSTNode<E> *current){
        if(current == nullptr)
            return 0;
        return 1 + getSizeAux(current->left) + getSizeAux(current->right) + 1;
    }

public:
    //constructor
    BSTree(){
        root = nullptr;
    }
    //destructor
    ~BSTree(){
        clear();
    }
    //Inserta un elemento en el árbol con la función auxiliar
    void insert(E element){
        root = insertAux(root, element);
    }
    //encuentra un elemento en el árbol con la función auxiliar
    E find(E element){
        return findAux(root, element);
    }
    //remueve un elemento del árbol con la función auxiliar
    E remove(E element){
        E result;// = find(element);
        root = removeAux(root, element, &result);
        return result;
    }
    //Determina si un elemento está en el árbol con la función auxiliar
    bool contains(E element){
        return constainsAux(root, element);
    }
    //limpia el árbol con la función auxiliar
    void clear(){
        clearAux(root);
        root = nullptr;
    }
    //Obtiene los elementos en el árbol con la función auxiliar
    List<E>* getElements(){
        List<E> *elements = new DLinkedList<E>();
        getElementsAux(root, elements);
        return elements;
    }
    //Obtiene la cantidad de elementos en el árbol con la función auxiliar
    int getSize(){
        return getSizeAux(root);
    }
};

#endif // BSTREE_H
