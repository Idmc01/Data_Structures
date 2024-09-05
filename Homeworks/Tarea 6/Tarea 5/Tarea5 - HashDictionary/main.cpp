#include <iostream>
#include "include\HashTable.h"
#include "include/LinkedList.h"

using namespace std;

int main() {
    cout << "Bienvenido a la revisión de la tarea 5, se van a revisar las funciones con 2 pruebas, una con hash con pares int-string y otra con pares string-int:" << endl;
    //Prueba 1
    cout << "Prueba 1" << endl;
    Dictionary<int,string> *hashT = new HashTable<int,string>();
    hashT->insert(3,"tres");
    hashT->insert(1,"uno");
    hashT->insert(5,"cinco");
    cout << "En este momento el hash cuenta con los siguientes elementos: " << endl;
    List<int> *keys = hashT->getKeys();
    List<string> *values = hashT->getValues();
    cout << "Llaves: " << endl;
    for (keys->goToStart(); !keys->atEnd(); keys->next()){
        cout << keys->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values->goToStart(); !values->atEnd(); values->next()){
        cout << values->getElement() << endl;
    }
    cout << "Para probar tanto los metodos getKeys() como getValue(), contains(), setValue() e insert() vamos a realizar el método update()"<< endl;
    Dictionary<int,string> *update1 = new HashTable<int,string>();
    update1->insert(36, "treintaiseis");
    update1->insert(14, "catorce");
    cout << "El diccionario con el que se actualizará el hash contiene lo siguiente: " << endl;
    List<int> *keysup = update1->getKeys();
    List<string> *valuesup = update1->getValues();
    cout << "Llaves: " << endl;
    for (keysup->goToStart(); !keysup->atEnd(); keysup->next()){
        cout << keysup->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (valuesup->goToStart(); !valuesup->atEnd(); valuesup->next()){
        cout << valuesup->getElement() << endl;
    }
    hashT->update(update1);
    cout << "Luego de realizar el método el resultado es que el primer hash cuenta con los siguientes elementos: "<< endl;
    keys = hashT->getKeys();
    values = hashT->getValues();
    cout << "Llaves: " << endl;
    for (keys->goToStart(); !keys->atEnd(); keys->next()){
        cout << keys->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values->goToStart(); !values->atEnd(); values->next()){
        cout << values->getElement() << endl;
    }
    cout << "pára probar el método remove(), vamos a eliminar un elemento del hash:" << endl;
    cout << "eliminando" << hashT->remove(5) << endl;
    cout << "El resultado de la eliminación deja al hash con los siguientes valores:" << endl;
    keys = hashT->getKeys();
    values = hashT->getValues();
    cout << "Llaves: " << endl;
    for (keys->goToStart(); !keys->atEnd(); keys->next()){
        cout << keys->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values->goToStart(); !values->atEnd(); values->next()){
        cout << values->getElement() << endl;
    }
    cout << "Ahora vamos a probar el método zip()" << endl;
    List<int> *pruebazip1 = new LinkedList<int>();
    List<string> *pruebazip2 = new LinkedList<string>();
    pruebazip1->append(24);
    pruebazip2->append("veinticuatro");
    pruebazip1->append(28);
    pruebazip2->append("veintiocho");
    cout << "La lista de llaves que añadiremos al hash contiene los siguientes elementos:" << endl;
    pruebazip1->goToStart();
    pruebazip2->goToStart();
    while(!pruebazip1->atEnd()){
        cout << pruebazip1->getElement() << endl;
        pruebazip1->next();
    }
    cout << "La lista de valores que añadiremos al hash contiene los siguientes elementos:" << endl;
    while(!pruebazip2->atEnd()){
        cout << pruebazip2->getElement() << endl;
        pruebazip2->next();
    }
    hashT->zip(pruebazip1,pruebazip2);
    cout << "Luego de utlizar el método zip() el hash contiene los siguientes elementos: " << endl;
    keys = hashT->getKeys();
    values = hashT->getValues();
    cout << "Llaves: " << endl;
    for (keys->goToStart(); !keys->atEnd(); keys->next()){
        cout << keys->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values->goToStart(); !values->atEnd(); values->next()){
        cout << values->getElement() << endl;
    }
    //Prueba 2
    cout << "Ahora haremos las mismas pruebas pero con pares int-string: " << endl;
    Dictionary<string,int> *hashT2 = new HashTable<string,int>();
    hashT2->insert("tres",3);
    hashT2->insert("uno",1);
    hashT2->insert("cinco",5);
    cout << "En este momento el hash cuenta con los siguientes elementos: " << endl;
    List<string> *keys2 = hashT2->getKeys();
    List<int> *values2 = hashT2->getValues();
    cout << "Llaves: " << endl;
    for (keys2->goToStart(); !keys2->atEnd(); keys2->next()){
        cout << keys2->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values2->goToStart(); !values2->atEnd(); values2->next()){
        cout << values2->getElement() << endl;
    }
    cout << "Para probar tanto los metodos getKeys() como getValue(), contains(), setValue() e insert() vamos a realizar el método update()"<< endl;
    Dictionary<string,int> *update2 = new HashTable<string,int>();
    update2->insert("treintaiseis",36);
    update2->insert("catorce",14);
    cout << "El diccionario con el que se actualizará el hash contiene lo siguiente: " << endl;
    List<string> *keysup2 = update2->getKeys();
    List<int> *valuesup2 = update2->getValues();
    cout << "Llaves: " << endl;
    for (keysup->goToStart(); !keysup->atEnd(); keysup->next()){
        cout << keysup2->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (valuesup->goToStart(); !valuesup->atEnd(); valuesup->next()){
        cout << valuesup2->getElement() << endl;
    }
    hashT2->update(update2);
    cout << "Luego de realizar el método el resultado es que el primer hash cuenta con los siguientes elementos: "<< endl;
    keys2 = hashT2->getKeys();
    values2 = hashT2->getValues();
    cout << "Llaves: " << endl;
    for (keys2->goToStart(); !keys2->atEnd(); keys2->next()){
        cout << keys2->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values2->goToStart(); !values2->atEnd(); values2->next()){
        cout << values2->getElement() << endl;
    }
    cout << "pára probar el método remove(), vamos a eliminar un elemento del hash:" << endl;
    cout << "eliminando" << hashT2->remove("cinco") << endl;
    cout << "El resultado de la eliminación deja al hash con los siguientes valores:" << endl;
    keys2 = hashT2->getKeys();
    values2 = hashT2->getValues();
    cout << "Llaves: " << endl;
    for (keys2->goToStart(); !keys2->atEnd(); keys2->next()){
        cout << keys2->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values2->goToStart(); !values2->atEnd(); values2->next()){
        cout << values2->getElement() << endl;
    }
    cout << "Ahora vamos a probar el método zip()" << endl;
    List<string> *pruebazip11 = new LinkedList<string>();
    List<int> *pruebazip22 = new LinkedList<int>();
    pruebazip22->append(24);
    pruebazip11->append("veinticuatro");
    pruebazip22->append(28);
    pruebazip11->append("veintiocho");
    cout << "La lista de llaves que añadiremos al hash contiene los siguientes elementos:" << endl;
    pruebazip11->goToStart();
    pruebazip22->goToStart();
    while(!pruebazip11->atEnd()){
        cout << pruebazip11->getElement() << endl;
        pruebazip11->next();
    }
    cout << "La lista de valores que añadiremos al hash contiene los siguientes elementos:" << endl;
    while(!pruebazip22->atEnd()){
        cout << pruebazip22->getElement() << endl;
        pruebazip22->next();
    }
    hashT2->zip(pruebazip11,pruebazip22);
    cout << "Luego de utlizar el método zip() el hash contiene los siguientes elementos: " << endl;
    keys2 = hashT2->getKeys();
    values2 = hashT2->getValues();
    cout << "Llaves: " << endl;
    for (keys2->goToStart(); !keys2->atEnd(); keys2->next()){
        cout << keys2->getElement() << endl;
    }
    cout << "Valores:" << endl;
    for (values2->goToStart(); !values2->atEnd(); values2->next()){
        cout << values2->getElement() << endl;
    }
    cout << "Muchas gracias por la revisión" << endl;
};
