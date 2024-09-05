#ifndef BSTREEDICTIONARY_H
#define BSTREEDICTIONARY_H

#include "Dictionary.h"
#include "KVPair.h"
#include "BSTree.h"
#include "DLinkedList.h"
template <typename K, typename V>
//Estructura adaptada de un árbol binario para utilizar pares llave-valor
class BSTreeDictionary : public Dictionary<K, V> {
private:
    //árbol binario de pares por adaptar
    BSTree<KVPair<K, V>> pairs;
public:
    //constructor y destructor
    BSTreeDictionary() {}
    ~BSTreeDictionary() {}
    //inserta un par dependiendo de su llave-valor
    void insert(K key, V value) {
        KVPair<K, V> p(key, value);
        pairs.insert(p);
    }
    //Remueve un par dependiendo de su llave
    V remove(K key) {
        KVPair<K, V> p(key);
        p = pairs.remove(p);
        return p.value;
    }
    //Obtiene el valor del par con una llave en específico
    V getValue(K key) {
        KVPair<K, V> p(key);
        p = pairs.find(p);
        return p.value;
    }
    //Cambia el valor de un par con una llave en específico
    void setValue(K key, V value) {
        KVPair<K, V> p(key, value);
        pairs.remove(p);
        pairs.insert(p);
    }
    //determina si un par existe a partir de su llave
    bool contains(K key){
        KVPair<K,V> p(key);
        return pairs.contains(p);
    }
    //Obtiene una lista de llaves en el árbol
    List<K>* getKeys() {
        List<KVPair<K, V>> *elements = pairs.getElements();
        List<K> *keys = new DLinkedList<K>();
        for (elements->goToStart(); !elements->atEnd(); elements->next()) {
            auto p = elements->getElement();
            keys->append(p.key);
        }
        delete elements;
        return keys;
    }
    //Obtiene una lista de valores en el árbol
    List<V>* getValues() {
        List<KVPair<K, V>> *elements = pairs.getElements();
        List<V> *values = new DLinkedList<V>();
        for (elements->goToStart(); !elements->atEnd(); elements->next()) {
            auto p = elements->getElement();
            values->append(p.value);
        }
        delete elements;
        return values;
    }
    //Obtiene el tamaño del árbol
    int getSize(){
        return pairs.getSize();
    }
};

#endif // BSTREEDICTIONARY_H
