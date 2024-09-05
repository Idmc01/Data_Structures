#ifndef BSTREEDICTIONARY_H
#define BSTREEDICTIONARY_H

#include "Dictionary.h"
#include "KVPair.h"
#include "BSTree.h"
#include "DLinkedList.h"
template <typename K, typename V>
class BSTreeDictionary : public Dictionary<K, V> {
private:
    BSTree<KVPair<K, V>> pairs;
public:
    BSTreeDictionary() {}
    ~BSTreeDictionary() {}
    void insert(K key, V value) {
        KVPair<K, V> p(key, value);
        pairs.insert(p);
    }
    V remove(K key) {
        KVPair<K, V> p(key);
        p = pairs.remove(p);
        return p.value;
    }
    V getValue(K key) {
        KVPair<K, V> p(key);
        p = pairs.find(p);
        return p.value;
    }
    void setValue(K key, V value) {
        KVPair<K, V> p(key, value);
        pairs.remove(p);
        pairs.insert(p);
    }
    bool contains(K key){
        KVPair<K,V> p(key);
        return pairs.contains(p);
    }
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
    int getSize(){
        return pairs.getSize();
    }
};

#endif // BSTREEDICTIONARY_H
