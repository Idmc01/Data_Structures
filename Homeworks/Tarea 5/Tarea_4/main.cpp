#include <iostream>
#include "MinHeap.h"
#include "LinkedList.h"

#include <string>
#include <cstdlib>
#include <time.h>
#include <string.h>

using namespace std;

int main(){
    MinHeap<int> *heap1 = new MinHeap<int>();
    MinHeap<int> *heap2 = new MinHeap<int>();
    List<int> *lista = new LinkedList<int>();
    List<int> *lista2 = new LinkedList<int>();
    int opcion;
    cout << "Bienvenido a la revision de la tarea 4" << endl;
    cout << "Por favor indique el numero de elementos que desea incluir en los heaps: ";
    cin >> opcion;
    srand(time(0));
    for (int i = 0; i < opcion; i++){
        heap1->insert(rand());
        heap2->insert(rand());
    }
    cout << "El primer heap contiene los elementos: " << endl;
    heap1->printArray();
    cout << "\n" << endl;
    cout << "El segundo heap contiene los elementos: " << endl;
    heap2->printArray();
    cout << "\n" << endl;
    cout << "Ahora utilizaremos el metodo merge() para unir el segundo heap con el primero \n" << endl;
    heap1->merge(heap2);
    cout << "El resultado del método es el siguiente heap:" << endl;
    heap1->printArray();
    cout << "\n" << endl;
    int top;
    cout << "Para revisar la funcion removeTop() por favor indique el valor del top de elementos que desee:" ;
    cin >> top;
    lista->extend(heap1->removeTop(top));
    cout << "La lista del top resultante es: " << endl;
    lista->print();
    delete lista;
    cout << "\n" << endl;
    cout << "Ahora vamos a imprimir el contenido restante del heap utilizando removeFirst() para probar la funcion isEmpty()" << endl;
    while(!heap1->isEmpty()){
        cout << "Eliminando" << endl;
        cout << heap1->removeFirst() << endl;
    }
    cout << "\n" << endl;
    cout << "Por favor seleccione otra cantidad de elementos para crear un arreglo y probar la funcion Heapify(): ";
    cin >>opcion;
    int *arreglo = new int[opcion];
    for (int i = 0; i < opcion; i++){
        arreglo[i] = rand();
    }
    heap1->heapify(arreglo,opcion);
    cout << "\n" << endl;
    cout << "El resultado de hacer Heapify en el primer heap es:" << endl;
    heap1->printArray();
    cout << "\n" << endl;
    cout << "Para terminar se realizara la funcion removeTop() con la cantidad de elementos del heap \n" << endl;
    lista2->extend(heap1->removeTop(opcion));
    cout << "El resultado es la siguiente lista:" << endl;
    lista2->print();
    delete lista2;
    cout << "\nMuchas gracias por realizar la revision de la tarea 4!" << endl;
    return 0;
}
