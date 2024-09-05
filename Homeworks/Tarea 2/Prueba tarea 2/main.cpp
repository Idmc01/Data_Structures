#include <iostream>
#include "Matrix.h"
using namespace std;

int main(){
    Matrix <int> matriz(10,15);
    for(int i = 0; i < matriz.getRows();i++){
        for (int j = 0; j<matriz.getColumns(); j++){
            matriz.setValue(i,j,i+j);
        }
    }
    int fila, columna, valor;
    while (true){
        cout<<"En este momento se creó una matriz predefinida, la cual se presenta a continuación:"<<endl;
        matriz.print();
        cout<<"Como revisión se van a probar todos los diferentes métodos solicitados en orden"<<endl;
        cout<<"Como aclaración, los métodos print(), getRows y getColumns se mostrarán durante las pruebas ya que son necesarios para mostrar los cambios"<<endl;



        cout<<"comenzaremos con el método getValue, el cual le dirá el valor que se encuentra en la posición que usted decida"<<endl;
        cout<<"Por favor indique el NÚMERO de fila donde se encuentra el valor que necesita:"<<endl;
        cin>> fila;
        cout<<"Por favor indique el NÚMERO de columna donde se encuentra el valor que se solicita"<<endl;
        cin>>columna;
        cout<<"El valor que buscó es:"<<matriz.getValue(fila,columna)<<endl;
        cout<<"\n"<<endl;



        cout<<"Ahora vamos a probar el método setValue, el cual le da el valor que usted elija al valor en la posición que usted elija"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Por favor indique el número de fila donde se encuentra el valor al que desea colocar el nuevo valor:"<<endl;
        cin>>fila;
        cout<<"Por favor indique el número de columna donde se encuentra el valor al que desea colocar el nuevo valor: "<<endl;
        cin>>columna;
        cout<<"Por favor indique el NÚMERO del nuevo valor:"<<endl;
        cin>>valor;
        matriz.setValue(columna,fila,valor);
        cout<<"Se ha cambiado el valor, a continuación se le mostrará la matriz con los cambios realizados:"<<endl;
        matriz.print();
        cout<<"\n"<<endl;



        cout<<"A continuación se probará el método addRow, el cual añade una nueva fila la cual se llenará con el valor que usted le de"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Tambien, para la prueba del método getRows, en este momento hay una cantidad de "<<matriz.getRows()<<" filas"<<endl;
        cout<<"Por favor indique el valor que tendran los elementos de la nueva fila:"<<endl;
        cin>>valor;
        matriz.addRow(valor);
        cout<<"La nueva matriz con los cambios aplicados es esta:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getRows()<<" de filas"<<endl;
        cout<<"\n"<<endl;


         cout<<"A continuación se probará el método removeRow; el cual elimina de la matriz una fila a su elección"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getRows()<<" de filas"<<endl;
        cout<<"Por favor indique el NÚMERO de fila que desea eliminar:"<<endl;
        cin>>fila;
        matriz.removeRow(fila);
        cout<<"La nueva matriz con los cambios aplicados es:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getRows()<<" filas"<<endl;
        cout<<"\n"<<endl;



        cout<<"A continuación se probará el método removeColumn; el cual elimina de la amtriz una columna a su elección"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"Por favor indique el NÚMERO de columna que desea eliminar:"<<endl;
        cin>>columna;
        matriz.removeColumn(columna);
        cout<<"La nueva matriz con los cambios aplicados es:"<<endl;
        matriz.print();
        cout<<"\n"<<endl;


        cout<<"Acontinuación se probará el método addColumn, el cual añade una columna la cual se llenará con el valor que usted le de"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Tambien, para la prueba del método getColumns, en este momento hay una cantidad de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"Por favor indique el valor que tendrán los elementos de la nueva columna:"<<endl;
        cin>>valor;
        matriz.addColumn(valor);
        cout<<"La nueva matriz con los cambios aplicados es esta:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"\n"<<endl;



        cout<<"Ahora hay un total de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"A continuación se propará el metodo transpose, el cual va a transponer la matriz"<<endl;
        cout<<"La matriz actual es:"<<endl;
        matriz.print();
        matriz.transpose();
        cout<<"Luego de la transposicion la matriz resultante es:"<<endl;
        matriz.print();
        cout<<"\n"<<endl;

        cout<<"Para terminar se probará el método setAll, el cual le asigna un valor a su elección a todos los elementos de la matriz"<<endl;
        cout<<"La matriz actual es:"<<endl;
        matriz.print();
        cout<<"Por favor indique el valor que desea que tengan los elementos de la matriz:"<<endl;
        cin>>valor;
        matriz.setAll(valor);
        cout<<"Luego de los cambios la matriz resultante es:"<<endl;
        matriz.print();
        cout<<"Y con esto concluiria la prueba de todos los métodos existentes para la matriz"<<endl;
        break;
    }
}



