#ifndef TRIE_H
#define TRIE_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "TrieNode.h"
#include "HeapPriorityQueue.h"

using std::runtime_error;
using std::cout;
using std::endl;
using std::string;

/**
  * class Trie definida con un TrieNode
  * y los metodos necesario para su implementacion
  * autor: @author Andy, Kendall, Ian
  * version: 1.5
  */

class Trie{
private:
    //operadores de copia que no se desea utilizar
    void operator =(const Trie &other) {}
    Trie(const Trie &other) {}
    //nodo raíz, de donde salen todas las palabras
    TrieNode* root;

    /*
     * funciones auxiliar que ayuda a limpiar el trie
     * resive como parametro un TrieNode
     * recorre el trie y elimina los nodos
     */
    void clearAux(TrieNode *current){
        List<TrieNode*>* pointers = current->getChildrenPointers();
        pointers->goToStart();
        while(!pointers->atEnd()){
            clearAux(pointers->getElement());
            pointers->next();
        }
        delete current;
    }

    /*
     * funcion auxiliar que ayuda a buscar un prefijo en el trie
     *
     */
    void getMatchesAux(TrieNode *current, string prefix, List<string> *words) {
        if (current->isFinal)
            words->append(prefix);
        List<char> *children = current->getChildren();
        for (children->goToStart(); !children->atEnd(); children->next()){
            string newPrefix = prefix;
            char c = children->getElement();
            newPrefix.append(1, c);
            getMatchesAux(current->getChild(c), newPrefix, words);
        }
        delete children;
    }

    /*
     * funcion auxiliar que ayuda a buscar un prefijo en el trie
     *
     */
    void getMatchesAux2(TrieNode *current, string prefix, HeapPriorityQueue<string> *words) {
        if (current->isFinal){
            ArrayList<int>* numero = current->getLineNumbers();
            words->insert(prefix,numero->getSize());
        }
        List<char> *children = current->getChildren();
        for (children->goToStart(); !children->atEnd(); children->next()){
            string newPrefix = prefix;
            char c = children->getElement();
            newPrefix.append(1, c);
            getMatchesAux2(current->getChild(c), newPrefix, words);
        }
        delete children;
    }

    /*
     * funcion auxiliar que ayuda a buscar las palabras que tiene una cantidad de letras
     * que fue solicitado por el usuario
     */
    void getWordsWithThisLengthAux(TrieNode *current, string prefix, List<string> *words, int length){
        if(current->isFinal){
            if(current->letterNumber==length){
                words->append(prefix);
            }
        }
        else{
            if(current->letterNumber!=length){
                List<char> *children = current->getChildren();
                for (children->goToStart(); !children->atEnd(); children->next()){
                    string newPrefix = prefix;
                    char c = children->getElement();
                    newPrefix.append(1, c);
                    getWordsWithThisLengthAux(current->getChild(c), newPrefix, words, length);
                }
                delete children;
            }
        }
    }
public:
    //constructor, inicializa la raíz
    Trie() {
        root = new TrieNode();
    }
    //destructor, limpia el trie y elimina la raíz
    ~Trie(){
        clear();
        delete root;
    }
    //inserta un elemento en el trie y agrega a su nodo el número de fila donde apareció
    void insert(string word,int fileLine){
        TrieNode *current = root;
        if(!containsWord(word)){
            for (unsigned int i = 0; i < word.size(); i++){
                current->prefixCount++;
                if (!current->contains(word[i]))
                    current->add(word[i]);
                current = current->getChild(word[i]);
            }
            current->letterNumber=word.size()-1;
            current->prefixCount++;
            current->isFinal = true;
            current->lineNumbers->append(fileLine);
        }
        else{
            for (unsigned int i = 0; i < word.size(); i++){
                current = current->getChild(word[i]);
            }
            current->lineNumbers->append(fileLine);
        }

    }
    //determina si el trie contiene una palabra en específico
    bool containsWord(string word){
        TrieNode *current = root;
        for (unsigned int i = 0; i < word.size(); i++){
            if(!current->contains(word[i]))
                return false;
            current = current->getChild(word[i]);
        }
        return current->isFinal;
    }
    //determina si el trie contiene un prefijo en específico
    bool containsPrefix(string prefix){
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return false;
            current = current->getChild(prefix[i]);
        }
        return true;
    }
    //cuenta la cantidad de veces que aparece un prefijo
    int prefixCount(string prefix) {
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return 0;
            current = current->getChild(prefix[i]);
        }
        return current->prefixCount;
    }
    //retorna una lista con los números de fila en los que aparece una palabra
    ArrayList<int>* getLineNumbers(string word){
        TrieNode *current = root;
        for (unsigned int i = 0; i < word.size(); i++){
            if(!current->contains(word[i]))
                return current->getLineNumbers();
            current = current->getChild(word[i]);
        }

        return current->getLineNumbers();
    }
    //retorna la cantidad de líneas en las que aparece una palabra
    int getLineNumbersLength(string word){
        TrieNode *current = root;
        for (unsigned int i = 0; i < word.size(); i++){
            if(!current->contains(word[i]))
                return current->getLineNumbers()->getSize();
            current = current->getChild(word[i]);
        }

        return current->getLineNumbers()->getSize();
    }
    //remueve una palabra del trie
    void remove(string word) {
        if(!containsWord(word))
            throw runtime_error("Word not found");
        TrieNode *current = root;
        for(unsigned int i = 0; i < word.size(); i++){
            current->prefixCount--;
            TrieNode *child = current->getChild(word[i]);
            if (current->prefixCount == 0)
                delete current;
            else if(child->prefixCount == 1)
                current->remove(word[i]);
            current = child;
        }
        current->prefixCount--;
        if (current->prefixCount == 0)
            delete current;
        else
            current->isFinal = false;
    }
    //limpia el trie de todos sus nodos y solo deja la raíz
    void clear() {
        clearAux(root);
        root = new TrieNode();
    }
    //retorna una lista con todas las palabras que contiene el trie
    List<string>* getMatches(string prefix) {
        List<string> *words = new ArrayList<string>();
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return words;
            current = current->getChild(prefix[i]);
        }
        getMatchesAux(current, prefix, words);
        return words;
    }
    //retorna un heap priority queue con todas la palabras con un prefijo en específico
    HeapPriorityQueue<string>* getMatches2(string prefix) {
        HeapPriorityQueue<string> *words = new HeapPriorityQueue<string>(root->prefixCount);
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return words;
            current = current->getChild(prefix[i]);
        }
        getMatchesAux2(current, prefix, words);
        return words;
    }
    //retorna una lista de palabras con una cantidad de letras en específico
    List<string>* getWordsWithThisLength(int length) {
        length--;
        List<string> *words = new DLinkedList<string>();
        TrieNode *current = root;
        getWordsWithThisLengthAux(current, "", words, length);
        return words;
    }
};

#endif // TRIE_H
