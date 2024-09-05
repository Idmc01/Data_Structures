#ifndef KVPAIR_H
#define KVPAIR_H

#include <iostream>

using std::ostream;

template <typename K, typename V>
//pares llave-valor
class KVPair{
public:
    //atributos del par
    K key;
    V value;
    // distintos constructores
    KVPair(K key, V value){
        this->key = key;
        this->value = value;
    }
    KVPair(K key){
        this->key = key;
    }
    KVPair(){}
    KVPair (const KVPair<K, V>&  obj){
        key = obj.key;
        value = obj.value;
    }
    //métodos para configurar que pasa cuando se agregan diferentes operadores entre pares
    void operator = (const KVPair<K, V>& obj){
        key = obj.key;
        value = obj.value;
    }
    bool operator == (const KVPair<K, V>& obj){
        return key == obj.key;
    }
    bool operator != (const KVPair<K, V>& obj){
        return key != obj.key;
    }
    bool operator <= (const KVPair<K, V>& obj){
        return key <= obj.key;
    }
    bool operator < (const KVPair<K, V>& obj){
        return key < obj.key;
    }
    bool operator >= (const KVPair<K, V>& obj){
        return key >= obj.key;
    }
    bool operator > (const KVPair<K, V>& obj){
        return key > obj.key;
    }


};
//método especial para que sea posible imprimir un par llave valor.
template <typename K, typename v>
ostream& operator << (ostream& os, const KVPair<K, v>& obj){
    os << "(" << obj.key << ", " << obj.value << ")";
    return os;
}


#endif // KVPAIR_H
