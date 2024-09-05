#ifndef TRIENODE_H
#define TRIENODE_H

#include "BSTreeDictionary.h"

class TrieNode{
private:
    //el único atributo privado que es de tipo diccionario de hijos
    Dictionary<char, TrieNode*> *children;



public:
    //atributos publicos por su constante uso
    bool isFinal;
    int prefixCount;
    int letterNumber;
    ArrayList<int>* lineNumbers;
    //constructor, inicializa los atributos
    TrieNode(){
        letterNumber=0;
        isFinal = false;
        prefixCount = 0;
        children = new BSTreeDictionary<char, TrieNode*>();
        lineNumbers= new ArrayList<int>();
    }
    //destructor, elimina la memoria solicitada
    ~TrieNode(){
        delete children;
        delete lineNumbers;
    }
    //retorna una lista con los números de línea
    ArrayList<int>* getLineNumbers(){
        return lineNumbers;
    }
    //busca si este nodo alguno de sus hijos contiene el caracter
    bool contains(char c) {
        return children->contains(c);
    }
    //agrega un nuevo nodo con el caracter insertado a los hijos
    void add(char c){
        TrieNode *newNode = new TrieNode();
        children->insert(c, newNode);
    }
    //retorna el hijo con el caracter solicitado
    TrieNode* getChild(char c) {
        return children->getValue(c);
    }
    //remueve un caracter solicitado de la lista de hijos
    void remove(char c) {
        children->remove(c);
    }
    //retorna una lista de hijos
    List<char>* getChildren(){
        return children->getKeys();
    }
    //retorna una lista de punteros a los hijos del nodo
    List<TrieNode*>* getChildrenPointers(){
        return children->getValues();
    }
};

#endif // TRIENODE_H
