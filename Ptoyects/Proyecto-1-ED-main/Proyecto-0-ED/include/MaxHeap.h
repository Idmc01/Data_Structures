#ifndef MAXHEAP_H
#define MAXHEAP_H
#define DEFAULT_MAX_SIZE 1024

#include <stdexcept>

using std::runtime_error;

template <typename E>
class MaxHeap{
    //usa una estructura jerárquica
private:
    // definición de atributos del max heap
    E *elements;
    int max;
    int size;
    //de acuerdo a las reglas propuestas para los heaps sube elementos dependiendo de si es mayor que su padre
    void siftUp(int pos){
        while (pos > 0 && elements[pos] > elements[parent(pos)]){
            swap(pos, parent(pos));
            pos = parent(pos);
        }
    }
    //busca el padre de un elemento
    int parent(int pos){
        return (pos - 1) / 2;
    }
    //busca el hijo izquierdo de un elemento
    int leftChild(int pos){
        return pos * 2 + 1;
    }
    //busca el hijo derecho de un elemento
    int rightChild(int pos){
        return pos *2 + 2;
    }
    //cambia dos elementos de valor
    void swap(int pos1, int pos2) {
        E temp = elements[pos1];
        elements[pos1] = elements[pos2];
        elements[pos2] = temp;
    }
    //intercambia elementos dependiendon de si es menor que su hijo mayor
    void siftDown(int pos){
        while (!isLeaf(pos) && elements[pos] < elements[greaterChild(pos)]) {
            int gChild = greaterChild(pos);
            swap(pos, gChild);
            pos = gChild;
        }
    }
    //determina si un elemento es una hoja(no tiene hijos)
    bool isLeaf(int pos) {
        if (pos < 0 || pos >= size)
            throw runtime_error("Index out of range");
        return leftChild(pos) >= size;
    }
    //determina el hijo mayor
    int greaterChild(int pos) {
        if (pos < 0 || pos >= size)
            throw runtime_error("Index out of range");
        if (rightChild(pos) >= size ||
            elements[leftChild(pos)] > elements[rightChild(pos)])
            return leftChild(pos);
        return rightChild(pos);
    }
    //expande la memoria al doble
    void expand(){
        E *temp;
        temp = new E[max*2];
        for(int i = 0; i < size; i++){
            temp[i] = elements[i];
        }
        delete [] elements;
        elements = temp;
        max = max*2;
    }
public:
    //constructor, inicializa los atributos
    MaxHeap(int max = DEFAULT_MAX_SIZE) {
        if (max < 1)
            throw runtime_error("Invalid array size");
        elements = new E[max];
        this->max = max;
        size = 0;
    }
    //destructor, elimina el arreglo de elementos
    ~MaxHeap(){
        delete [] elements;
    }
    //inserta elementos en el max heap
    void insert(E element){
        if (size == max)
            //throw runtime_error("Heap is full");
            expand();
        elements[size] = element;
        siftUp(size);
        size++;
    }
    //retorna el primero en la jerarquía
    E first(){
        if (size == 0)
            throw runtime_error("Heap is empty");
        return elements[0];
    }
    //remueve el primero en la jerarquía
    E removeFirst(){
        if (size == 0)
            throw runtime_error("Heap is empty");
        return remove(0);
    }
    //remueve un elemento en específico según su posición
    E remove(int pos){
        if (pos >= size || pos < 0)
            throw runtime_error("Index out of range");
        swap(pos, size - 1);
        size--;
        if(size > 1)
            siftDown(pos);
        return elements[size];
    }
    //obtiene el tamaño del heap
    int getSize() {
        return size;
    }
};

#endif // MAXHEAP_H
