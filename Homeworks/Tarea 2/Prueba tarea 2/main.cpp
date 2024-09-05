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
        cout<<"En este momento se cre� una matriz predefinida, la cual se presenta a continuaci�n:"<<endl;
        matriz.print();
        cout<<"Como revisi�n se van a probar todos los diferentes m�todos solicitados en orden"<<endl;
        cout<<"Como aclaraci�n, los m�todos print(), getRows y getColumns se mostrar�n durante las pruebas ya que son necesarios para mostrar los cambios"<<endl;



        cout<<"comenzaremos con el m�todo getValue, el cual le dir� el valor que se encuentra en la posici�n que usted decida"<<endl;
        cout<<"Por favor indique el N�MERO de fila donde se encuentra el valor que necesita:"<<endl;
        cin>> fila;
        cout<<"Por favor indique el N�MERO de columna donde se encuentra el valor que se solicita"<<endl;
        cin>>columna;
        cout<<"El valor que busc� es:"<<matriz.getValue(fila,columna)<<endl;
        cout<<"\n"<<endl;



        cout<<"Ahora vamos a probar el m�todo setValue, el cual le da el valor que usted elija al valor en la posici�n que usted elija"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Por favor indique el n�mero de fila donde se encuentra el valor al que desea colocar el nuevo valor:"<<endl;
        cin>>fila;
        cout<<"Por favor indique el n�mero de columna donde se encuentra el valor al que desea colocar el nuevo valor: "<<endl;
        cin>>columna;
        cout<<"Por favor indique el N�MERO del nuevo valor:"<<endl;
        cin>>valor;
        matriz.setValue(columna,fila,valor);
        cout<<"Se ha cambiado el valor, a continuaci�n se le mostrar� la matriz con los cambios realizados:"<<endl;
        matriz.print();
        cout<<"\n"<<endl;



        cout<<"A continuaci�n se probar� el m�todo addRow, el cual a�ade una nueva fila la cual se llenar� con el valor que usted le de"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Tambien, para la prueba del m�todo getRows, en este momento hay una cantidad de "<<matriz.getRows()<<" filas"<<endl;
        cout<<"Por favor indique el valor que tendran los elementos de la nueva fila:"<<endl;
        cin>>valor;
        matriz.addRow(valor);
        cout<<"La nueva matriz con los cambios aplicados es esta:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getRows()<<" de filas"<<endl;
        cout<<"\n"<<endl;


         cout<<"A continuaci�n se probar� el m�todo removeRow; el cual elimina de la matriz una fila a su elecci�n"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getRows()<<" de filas"<<endl;
        cout<<"Por favor indique el N�MERO de fila que desea eliminar:"<<endl;
        cin>>fila;
        matriz.removeRow(fila);
        cout<<"La nueva matriz con los cambios aplicados es:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getRows()<<" filas"<<endl;
        cout<<"\n"<<endl;



        cout<<"A continuaci�n se probar� el m�todo removeColumn; el cual elimina de la amtriz una columna a su elecci�n"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"Por favor indique el N�MERO de columna que desea eliminar:"<<endl;
        cin>>columna;
        matriz.removeColumn(columna);
        cout<<"La nueva matriz con los cambios aplicados es:"<<endl;
        matriz.print();
        cout<<"\n"<<endl;


        cout<<"Acontinuaci�n se probar� el m�todo addColumn, el cual a�ade una columna la cual se llenar� con el valor que usted le de"<<endl;
        cout<<"En este momento la matriz es:"<<endl;
        matriz.print();
        cout<<"Tambien, para la prueba del m�todo getColumns, en este momento hay una cantidad de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"Por favor indique el valor que tendr�n los elementos de la nueva columna:"<<endl;
        cin>>valor;
        matriz.addColumn(valor);
        cout<<"La nueva matriz con los cambios aplicados es esta:"<<endl;
        matriz.print();
        cout<<"Ahora hay un total de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"\n"<<endl;



        cout<<"Ahora hay un total de "<<matriz.getColumns()<<" columnas"<<endl;
        cout<<"A continuaci�n se propar� el metodo transpose, el cual va a transponer la matriz"<<endl;
        cout<<"La matriz actual es:"<<endl;
        matriz.print();
        matriz.transpose();
        cout<<"Luego de la transposicion la matriz resultante es:"<<endl;
        matriz.print();
        cout<<"\n"<<endl;

        cout<<"Para terminar se probar� el m�todo setAll, el cual le asigna un valor a su elecci�n a todos los elementos de la matriz"<<endl;
        cout<<"La matriz actual es:"<<endl;
        matriz.print();
        cout<<"Por favor indique el valor que desea que tengan los elementos de la matriz:"<<endl;
        cin>>valor;
        matriz.setAll(valor);
        cout<<"Luego de los cambios la matriz resultante es:"<<endl;
        matriz.print();
        cout<<"Y con esto concluiria la prueba de todos los m�todos existentes para la matriz"<<endl;
        break;
    }
}



