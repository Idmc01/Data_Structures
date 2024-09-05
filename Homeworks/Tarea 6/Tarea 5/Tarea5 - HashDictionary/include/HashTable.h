#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Dictionary.h"
#include "KVPair.h"
#include "LinkedList.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
using std::cout;
using std::endl;

template <typename K, typename V>
class HashTable : public Dictionary<K, V> {
private:
    LinkedList<KVPair<K, V> > *buckets;
    int nbuckets;

    int h(K key) {
        return compress(hashCodePolynomial(key));
    }
    // Genera un código hash polinomial con constante de 33
    template <typename T>
    int hashCodePolynomial(T key) {
        int a = 33;
        int result = 0;
        char* bytes = reinterpret_cast<char*>(&key);
        for (unsigned int i = 0; i < sizeof(K); i++) {
            result += bytes[i] * pow(a, i);
        }
        return result;
    }
    int hashCodePolynomial(string key) {
        int a = 33;
        int result = 0;
        for (unsigned int i = 0; i < key.length(); i++) {
            result += key[i] * pow(a, i);
        }
        return result;
    }
    // Función de compresión por multiplicación, suma y división
    int compress(int hashCode) {
        int a = 1097;
        int b = 1279;
        return abs(a * hashCode + b) % nbuckets;
    }
    // Método auxiliar que verifica que una llave no exista.
    // Si se encuentra la llave, lanza exepción.
    // La posición actual de la lista queda señalando al final
    // de la lista.
    void checkNotExisting(K key) throw (runtime_error) {
        if (buckets[h(key)].contains(key))
            throw runtime_error("Duplicated key.");
    }
    // Método auxiliar que verifica que una llave sí exista.
    // Si no se encuentra la llave, lanza excepción
    // La posición actual de la lista queda señalando al
    // elemento buscado.
    void checkExisting(K key) throw (runtime_error) {
        if (!buckets[h(key)].contains(key)) {
            throw runtime_error("Key not found.");
        }
    }

public:
    HashTable(int nbuckets = 1021) {
        buckets = new LinkedList<KVPair<K, V> >[nbuckets];
        this->nbuckets = nbuckets;
    }
    ~HashTable() {
        delete [] buckets;
    }
    void insert(K key, V value) {
        checkNotExisting(key);
        KVPair<K, V> p(key, value);
        buckets[h(key)].append(p);
    }
    V remove(K key) {
        checkExisting(key);
        KVPair<K, V> p(key);
        p = buckets[h(key)].remove();
        return p.getValue();
    }
    V getValue(K key) {
        checkExisting(key);
        KVPair<K, V> p = buckets[h(key)].getElement();
        return p.getValue();
    }
    void setValue(K key, V value) {
        checkExisting(key);
        buckets[h(key)].remove();
        KVPair<K, V> p(key, value);
        buckets[h(key)].append(p);
    }
    void clear() {
        for (int i = 0; i < nbuckets; i++) {
            buckets[i].clear();
        }
    }
    bool contains(K key) {
        KVPair<K, V> p(key);
        return buckets[h(key)].contains(p);
    }
    List<K>* getKeys() {
        List<K> *keys = new LinkedList<K>();
        for(int i = 0; i < nbuckets; i++){
            buckets[i].goToStart();
            while (!buckets[i].atEnd()){
                    KVPair<K, V> p;
            p = buckets[i].getElement();
            keys->append(p.getKey());
            buckets[i].next();
            }
        }
        return keys;
    }
    List<V>* getValues() {
        List<V> *values = new LinkedList<V>();
        for (int i = 0; i < nbuckets; i++){
            buckets[i].goToStart();
            while(!buckets[i].atEnd()){
                KVPair<K, V> p;
                p = buckets[i].getElement();
                values->append(p.getValue());
                buckets[i].next();
            }
        }
        return values;
    }
    int getSize() {
        int size = 0;
        for(int i = 0; i < nbuckets; i++){
            size += buckets[i].getSize();
        }
        return size;
    }
    void update(Dictionary<K, V> *D) {
        List<K>* keys = D->getKeys();
        keys->goToStart();
        while (!keys->atEnd()){
            if (contains(keys->getElement())){
                    setValue(keys->getElement(),D->getValue(keys->getElement()));
                }else{
                    insert(keys->getElement(),D->getValue(keys->getElement()));
                }
                keys->next();
        }
    }
    void zip(List<K> *keys, List<V> *values) {
        if(keys->getSize() <= values->getSize()){
            keys->goToStart();
            values->goToStart();
            while(!keys->atEnd()){
                insert(keys->getElement(),values->getElement());
                keys->next();
                values->next();
            }
        }else{
        if(keys->getSize() >= values->getSize()){
            keys->goToStart();
            values->goToStart();
            while(!values->atEnd()){
                insert(keys->getElement(),values->getElement());
                keys->next();
                values->next();
        }
    }
    }
    }
};

#endif // HASHTABLE_H
