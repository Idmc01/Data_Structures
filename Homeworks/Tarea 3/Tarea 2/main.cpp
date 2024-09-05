#include <iostream>
#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){



        LinkedList<int> *L = new LinkedList<int>();
        LinkedList<int> *I = new LinkedList<int>();
        ArrayList<int> *A = new ArrayList<int>(5);
        ArrayList<int> *B = new ArrayList<int>(5);


        L->append(1);
        L->append(2);
        L->append(3);
        L->append(4);
        L->append(5);

        I->append(1);
        I->append(2);
        I->append(3);
        I->append(4);
        I->append(5);

        A->append(1);
        A->append(2);
        A->append(3);
        A->append(4);
        A->append(5);

        B->append(1);
        B->append(2);
        B->append(3);
        B->append(4);
        B->append(5);

        L->append(6);
        A->append(9);
        //A->remove();
        A->print();
        B->print();
        //cout<<A->equals(B)<<endl;



        int valor,posi,elemen;
        while (true){
            cout<<"En este momento se crearon 4 listas diferentes esto con el fin de probar lo métodos de ambos tipos de listas\nEstas son:\n"<<endl;
            cout<<"LinkedList:"<<endl;
            cout<<"1. Nombre: L"<<endl;
            L->print();
            cout<<"2. Nombre I"<<endl;
            I->print();
            cout<<"\nArrayList:"<<endl;
            cout<<"1. Nombre A"<<endl;
            A->print();
            cout<<"2. Nombre B"<<endl;
            B->print();

            cout<<"\nAclaración: Las 2 ArrayLists tienen un tamaño máximo de 5(de ser necesario revisar el main), se menciona para corroborar que el método expand() funciona\n"<<endl;
            cout<<"Continuando con la revisión, probaremos primero los métodos de las ArrayLists\n"<<endl;
            cout<<"Estos cambios se realizarán en la primer lista de nombre A\n"<<endl;
            cout<<"Primero probaremos el método Insert()\n"<<endl;
            cout<<"En este momento el temaño de la lista es: "<<A->getSize()<<endl;
            cout<<"Por favor indique el valor que desea insertar en la lista: "<<endl;
            cin>>valor;
            A->insert(valor);
            cout<<"Con los cambios esta es la lista resultante:"<<endl;
            A->print();
            cout<<"En este momento el temaño de la lista es: "<<A->getSize()<<endl;
            cout<<"\n"<<endl;
            cout<<"Seguimos con el metodo Append()\n"<<endl;
            cout<<"Por favor inserte el valor al que desea hacerle append en la lista:"<<endl;
            cin>>valor;
            A->append(valor);
            cout<<"Con los cambios esta es la lista resultante:"<<endl;
            A->print();
            cout<<"\n"<<endl;
            cout<<"Luego para probar el método remove() se va a aprovechar para probar tambien el metodo goToPos()\n"<<endl;
            cout<<"Por favor indique la posición donde se encuentra el elemento que desea eliminar: "<<endl;
            cin>>posi;
            A->goToPos(posi);
            cout<<"Eliminando elemento en la posición: "<<A->getPos()<<endl;
            cout<<"Se eliminó el ememento "<<A->remove()<<endl;
            cout<<"Con los cambios esta es la lista resultante:"<<endl;
            A->print();
            cout<<"\n"<<endl;
            cout<<"Seguimos con el metodo indexOff():\n"<<endl;
            cout<<"por favor indique el elemento a buscar:"<<endl;
            cin>>elemen;
            cout<<"El elemento "<<elemen<<" esta en la posición "<<A->indexOf(elemen)<<"\n"<<endl;
            cout<<"Luego vamos a probar el metodo contains() (recordar que en booleanos el numero 1 es true y el 0 es false)"<<endl;
            cout<<"Por favor indique el elemento a buscar:"<<endl;
            cin>>elemen;
            cout<<"El resultado de la busqueda es "<<A->contains(elemen)<<endl;

            cout<<"Ahora haremos las mismas pruebas pero con una LinkedList \n En este caso la de nombre L"<<endl;
            cout<<"Primero probaremos el método Insert()\n"<<endl;
            cout<<"En este momento el tamaño de la lista es: "<<L->getSize()<<endl;
            cout<<"Por favor indique el valor que desea insertar en la lista: "<<endl;
            cin>>valor;
            L->insert(valor);
            cout<<"Con los cambios esta es la lista resultante:"<<endl;
            L->print();
            cout<<"En este momento el temaño de la lista es: "<<L->getSize()<<endl;
            cout<<"\n"<<endl;
            cout<<"Seguimos con el metodo Append()\n"<<endl;
            cout<<"Por favor inserte el valor al que desea hacerle append en la lista:"<<endl;
            cin>>valor;
            L->append(valor);
            cout<<"Con los cambios esta es la lista resultante:"<<endl;
            L->print();
            cout<<"\n"<<endl;
            cout<<"Luego para probar el método remove() se va a aprovechar para probar tambien el metodo goToPos()\n"<<endl;
            cout<<"Por favor indique la posición donde se encuentra el elemento que desea eliminar: "<<endl;
            cin>>posi;
            L->goToPos(posi);
            cout<<"Eliminando elemento en la posición: "<<L->getPos()<<endl;
            cout<<"Se eliminó el ememento "<<L->remove()<<endl;
            cout<<"Con los cambios esta es la lista resultante:"<<endl;
            L->print();
            cout<<"\n"<<endl;
            cout<<"Seguimos con el metodo indexOff():\n"<<endl;
            cout<<"por favor indique el elemento a buscar:"<<endl;
            cin>>elemen;
            cout<<"El elemento "<<elemen<<" esta en la posición "<<L->indexOf(elemen)<<"\n"<<endl;
            cout<<"Luego vamos a probar el metodo contains() (recordar que en booleanos el numero 1 es true y el 0 es false)"<<endl;
            cout<<"Por favor indique el elemento a buscar:"<<endl;
            cin>>elemen;
            cout<<"El resultado de la busqueda es "<<L->contains(elemen)<<"\n"<<endl;

            cout<<"La siguiente prueba se debe realizar con las 4 listas, se probará el método equals()\nrecordar que en este momentolas listas I y B son iguales, puede que L y A no\n(recordar que en booleano 1 es true y 0 en false)"<<endl;
            cout<<"Primero compararemos el ArrayList A con el ArrayList B"<<endl;
            cout<<"A:"<<endl;
            A->print();
            cout<<"B"<<endl;
            B->print();
            cout<<"El resultado de esta comparación es "<<A->equals(B)<<"\n"<<endl;
            cout<<"Luego compararemos el ArrayList A con la LinkedList L"<<endl;
            cout<<"A:"<<endl;
            A->print();
            cout<<"L"<<endl;
            L->print();
            cout<<"El resultado de esta comparación es "<<A->equals(L)<<"\n"<<endl;
            cout<<"Lo siguiente será en viceversa"<<endl;
            cout<<"Vamos a comparar la LinkedList L con la LinkedList I"<<endl;
            cout<<"L:"<<endl;
            L->print();
            cout<<"I"<<endl;
            I->print();
            cout<<"El resultado de esta comparación es "<<L->equals(I)<<"\n"<<endl;
            cout<<"Luego vamos a comparar la LinkedList L con el ArrayList A"<<endl;
            cout<<"L:"<<endl;
            L->print();
            cout<<"A"<<endl;
            A->print();
            cout<<"El resultado de esta comparación es "<<L->equals(A)<<"\n"<<endl;
            cout<<"Para terminar compararemos el ArrayList B con la LinkedList I"<<endl;
            cout<<"B:"<<endl;
            B->print();
            cout<<"I"<<endl;
            I->print();
            cout<<"El resultado de esta comparación es "<<I->equals(B)<<"\n"<<endl;
            cout<<"Y viceversa:"<<endl;
            cout<<"El resultado de esta comparación es "<<B->equals(I)<<"\n"<<endl;
            cout<<"Como penultima prueba se va a probar el metodo extend"<<endl;
            cout<<"Primero se va a extender el ArrayList A con el ArrayList B"<<endl;
            cout<<"A"<<endl;
            A->print();
            cout<<"B"<<endl;
            B->print();
            A->extend(B);
            cout<<"El resultado del extend es: "<<endl;
            A->print();
            cout<<"\n"<<endl;
            cout<<"Luego se va a probar con la LinkedList L y la LinkedList I"<<endl;
            cout<<"L:"<<endl;
            L->print();
            cout<<"I"<<endl;
            I->print();
            L->extend(I);
            cout<<"El resultado del extend es: "<<endl;
            L->print();
            cout<<"\n"<<endl;
            cout<<"Luego se va a probar con el ArrayList A y la LinkedList L"<<endl;
            cout<<"L:"<<endl;
            L->print();
            cout<<"A"<<endl;
            A->print();
            L->extend(A);
            cout<<"El resultado del extend es: "<<endl;
            L->print();
            cout<<"\n"<<endl;
            cout<<"Para terminar se va a probar el método clear() con el ArrayList B y la LinkedList I"<<endl;
            cout<<"B"<<endl;
            B->print();
            cout<<"I"<<endl;
            I->print();
            B->clear();
            I->clear();
            cout<<"El resultado es"<<endl;
            cout<<"B"<<endl;
            B->print();
            cout<<"I"<<endl;
            I->print();
            break;
        }
}
