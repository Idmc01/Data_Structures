#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"
using namespace std;

int main()
{
    int opcion, cant;
    string cadena;
    while (true){
        cout << "Revisión tarea 3 Estructuras de Datos" << endl;
        cout << "1. Pilas" << "\n" << "2. Colas" << endl;
        cout << "Por favor indique con UN NÚMERO la opción que desea realizar:" << endl;
        cin >> opcion;
        if(opcion == 1){
            cout <<"1. ArrayStack." << "\n" << "2. LinkedStack" << endl;
            cout << "Por favor indique con UN NÚMERO que tipo de pila desea utilizar:" << endl;
            cin >> opcion;
            if(opcion == 1){
                Stack<char> *pila = new ArrayStack<char>();
                cout << "Por favor escriba la cadena de caracteres a evaluar, presione enter al terminar" << endl;
                getline(cin,cadena);
                getline(cin,cadena);
                for (int i = 0; i < cadena.length(); i++){
                    if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '['){
                        pila->push(cadena[i]);
                        /*cout << "Insertando parentesis" << endl;
                        pila->print();
                        cout << "Top value" << endl;
                        cout << pila->topValue() << endl;*/
                    }
                    if(cadena[i] == ')'){
                        if (pila->isEmpty()){
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }
                        if (!pila->topValue() == '('){
                            pila->print();
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }else{
                            pila->pop();
                        }

                    }
                    if(cadena[i] == '}'){
                        cout << pila->topValue() << endl;
                        if (pila->isEmpty()){
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }
                        if (!pila->topValue() == '{'){
                            pila->print();
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }else{
                            pila->pop();
                        }
                    }
                    if(cadena[i] == ']'){
                        if (pila->isEmpty()){
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }
                        if (!pila->topValue() == '['){
                            pila->print();
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }else{
                            pila->pop();
                        }
                    }
                    }
        if (!pila->isEmpty()){
            cout << "La cadena de caracteres está incorrecta" << endl;
            break;
        }else{
            cout << "La cadena de caracteres es válida" << endl;
            break;
        }

    }
    if (opcion == 2){
        Stack<char> *pila = new LinkedStack<char>();
                cout << "Por favor escriba la cadena de caracteres a evaluar, presione enter al terminar" << endl;
                getline(cin,cadena);
                getline(cin,cadena);
                for (int i = 0; i < cadena.length(); i++){
                    if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '['){
                        pila->push(cadena[i]);
                        /*cout << "Ingresa parentesis" << endl;
                        pila->print();
                        cout << "Top value" << endl;
                        cout << pila->topValue() << endl;*/

                    }
                    if(cadena[i] == ')'){
                        if (pila->isEmpty()){
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }
                        if (pila->topValue() != '('){
                            pila->print();
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }else{
                            pila->pop();
                            cout << "borrando" << endl;
                            pila->print();
                        }

                    }
                    if(cadena[i] == '}'){
                        if (pila->isEmpty()){
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }
                        if (pila->topValue() != '{'){
                                pila->print();
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }else{
                            pila->pop();
                            cout << "borrando" << endl;
                            pila->print();
                        }
                    }
                    if(cadena[i] == ']'){
                        if (pila->isEmpty()){
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }
                        if (pila->topValue() != '['){
                            pila->print();
                            cout << "La cadena de caracteres está incorrecta" << endl;
                            break;
                        }else{
                            pila->pop();
                            cout << "borrando" << endl;
                            pila->print();
                        }
                    }
                    }
        if (!pila->isEmpty()){
            cout << "La cadena de caracteres está incorrecta" << endl;
            break;
        }else{
            cout << "La cadena de caracteres es válida" << endl;
            break;
        }
    }else{
        cout << "Elija una opción válida" << endl;
    }

    }
    if(opcion == 2){
        cout <<"1. ArrayQueue." << "\n" << "2. LinkedQueue" << endl;
            cout << "Por favor indique con UN NÚMERO que tipo de pila desea utilizar:" << endl;
            cin >> opcion;
            if (opcion == 1){
                Queue<int> * cola = new ArrayQueue<int>();
                cout << "Por favor indique la cantidad de operaciones a realizar a la cola" << endl;
                cin >> cant;
                srand(time(0));
                while(cant != 0){
                    int r = rand() % 100;
                    if (cola->isEmpty()){
                        int a = 1 + rand() % (3-1);
                        cout << "Random cola vacia: " << a << endl;
                        if(a == 1){
                            cout << "Insertanto en la cola el elemento: " << r << endl;
                            cola->enqueue(r);
                            cola->print();
                            cant--;
                        }
                        if (a == 2){
                            cout << "Insertanto en el inicio de la cola el elemento: " << r << endl;
                            cola->enqueueFront(r);
                            cola->print();
                            cant--;
                        }
                    }
                    else{
                    int num = 1 + rand() % (5-1);
                    cout << "random cola llena: " << num << endl;
                    if(num == 1){
                        cout << "Insertanto en la cola el elemento: " << r << endl;
                        cola->enqueue(r);
                        cola->print();
                        cant--;
                    }
                    if (num == 2){
                        cout << "Insertanto en el inicio de la cola el elemento: " << r << endl;
                        cola->enqueueFront(r);
                        cola->print();
                        cant--;
                    }
                    if (num == 3){
                        cout << "Eliminando de la cola: " << cola->dequeue() << endl;
                        //cola->dequeue();
                        cola->print();
                        cant--;
                    }
                    if (num == 4){
                        cout << "Eliminando del final de la cola: " << cola->dequeueRear() << endl;
                        //cola->dequeueRear();
                        cola->print();
                        cant--;
                    }
                    }
                }
                cout << "El resultado de la cola resultante es:" << endl;
                cola->print();
                break;
            }
            if (opcion == 2){
                Queue<int> * cola = new LinkedQueue<int>();
                cout << "Por favor indique la cantidad de operaciones a realizar a la cola" << endl;
                cin >> cant;
                srand(time(0));
                while(cant != 0){
                    int r = rand() % 100;
                    if (cola->isEmpty()){
                        int a = 1 + rand() % (3-1);
                        cout << "Random cola vacia: " << a << endl;
                        if(a == 1){
                            cout << "Insertanto en la cola el elemento: " << r << endl;
                            cola->enqueue(r);
                            cola->print();
                            cant--;
                        }
                        if (a == 2){
                            cout << "Insertanto en el inicio de la cola el elemento: " << r << endl;
                            cola->enqueueFront(r);
                            cola->print();
                            cant--;
                        }
                    }
                    else{
                    int num = 1 + rand() % (5-1);
                    cout << "random cola llena: " << num << endl;
                    if(num == 1){
                        cout << "Insertanto en la cola el elemento: " << r << endl;
                        cola->enqueue(r);
                        cola->print();
                        cant--;
                    }
                    if (num == 2){
                        cout << "Insertanto en el inicio de la cola el elemento: " << r << endl;
                        cola->enqueueFront(r);
                        cola->print();
                        cant--;
                    }
                    if (num == 3){
                        cout << "Eliminando de la cola: " << cola->dequeue() << endl;
                        //cola->dequeue();
                        cola->print();
                        cant--;
                    }
                    if (num == 4){
                        cout << "Eliminando del final de la cola: " << cola->dequeueRear() << endl;
                        //cola->dequeueRear();
                        cola->print();
                        cant--;
                    }
                    }
                }
                cout << "El resultado de la cola resultante es:" << endl;
                cola->print();
                break;
            }else{
                cout << "Elija una opción válida" << endl;
            }
    }else{
        cout << "Elija una opción válida" << endl;
    }
}
}

