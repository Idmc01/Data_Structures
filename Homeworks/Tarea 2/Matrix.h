#ifndef MATRIX_H
#define MATRIX_H

#include<stdexcept>

using std::runtime_error;


template <typename E>
class Matrix
{
public:
    int rows;
    int columns;
    E **matrix;

public:
    Matrix(int rows,int columns){
        if(rows<=0||columns<=0)
            throw runtime_error("Numero de filas y columnas debe ser mayor a cero");

        this->rows = rows;
        this->columns = columns;
        matrix = new E*[rows];
        for (int i = 0; i<rows;i++){
            matrix[i] = new E[columns];
        }
    }
    ~Matrix(){
        for(int i = 0; i< rows; i++){
            delete[] matrix [i];
        }
        delete [] matrix;
    }
    E getValue(int row, int column){
        if(row<0 || row>= rows)
            throw runtime_error("Fila invalida");
        if(column<0 || column>=columns)
            throw runtime_error("Columna invalida");
        return matrix[row][column];
    }
    void setValue(int row, int column, E value){
        if(row<0 || row>= rows)
            throw runtime_error("Fila invalida");
        if(column<0 || column>=columns)
            throw runtime_error("Columna invalida");
        matrix[row][column] = value;
    }
    int getRows(){
        return rows;
    }
    int getColumns(){
        return columns;
    }
    void setAll(E value){
    for (int i=0;i<rows;i++){
        for(int a=0;a<columns;a++){
            setValue(i,a,value);
        }
    }
    }
    void addRow(E value){
       E**temp;
        temp = new E*[rows+1];
        for (int i = 0; i<rows;i++){
            temp[i] = matrix[i];
        }
        temp[rows]=new E[columns];
        for (int a=0;a<columns;a++){
            temp[rows][a]=value;
        }
        delete []matrix;//arreglo al que apunta matrix
        matrix = temp;
        rows++;
    }
    void addColumn(E value){
    matrix[rows] = new E[columns+1];
    for (int i=0;i<rows;i++){
        for (int j=0;j<columns;j++){
            setValue(i,j,getValue(i,j));
        }
    }

    for (int a=0; a<rows;a++){
        matrix[a][columns]=value;
    }
    delete matrix[rows];
    columns++;
    }
    void removeRow(int row){
        if (row>=rows)
            throw runtime_error("Fila invalida");


    E**temp;
        temp = new E*[rows-1];
        for (int i = 0; i<rows-1;i++){
                if (i>=row){

                temp[i]=matrix[i+1];
                }
                else{
            temp[i] = matrix[i];
                }
        }
        delete []matrix;//arreglo al que apunta matrix
        matrix = temp;
        rows--;
    }

    void removeColumn(int col){
        if(col>=columns)
            throw runtime_error("columna invalida");
    matrix[rows] = new E[columns-1];
    for (int i=0;i<rows;i++){
        for (int j=0;j<columns-1;j++){
                if (j>=col){
                    setValue(i,j,getValue(i,j+1));
                }else{
            setValue(i,j,getValue(i,j));}
        }
    }
    delete matrix[rows];
    columns--;
    }
    void transpose(){
    E **temp;
    temp = new E*[columns];
    for (int i = 0; i<columns;i++){
            temp[i] = new E[rows];
            }
            for (int a = 0; a<columns;a++){
                for (int j = 0; j<rows;j++){
                    temp[a][j]=matrix[j][a];
                }
            }
            std::cout<<temp<<std::endl;

            delete[]matrix;
            matrix = temp;
            int x = rows;
            rows = columns;
            columns = x;

    }
    void print(){
    for(int i = 0; i < rows;i++){
        for (int j = 0; j<columns; j++){
             std::cout<<getValue(i,j)<<"\t";
        }
        std::cout<<std::endl;
    }
    }
};

#endif // MATRIX_H
