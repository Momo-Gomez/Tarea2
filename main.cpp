#include <iostream>
#include<stdio.h>
#include <string>
#include "Stack.cpp"
#include "Queue.cpp"
using namespace std;

//tomar palabra de la pila
//cantidad de letras de la palabra
//posicion del tablero 0,0 (partiendo)
//if coincide, se queda, else, avanza
//for vertical, horizontal y diagonal, con la cantidad de letras

//retornar una matriz?

void tamañoCuadricula(int* filas_cuadricula, int* columnas_cuadricula){
  cout<<"Ingrese el número de filas: ";
  cin>>*filas_cuadricula;
  cout<<"Ingrese el número de columnas: ";
  cin>>*columnas_cuadricula;
}

void creacion_cuadricula(char** cuadricula,int* filas_cuadricula,int* columnas_cuadricula){
  cuadricula= new char* [*filas_cuadricula];
  for (int i=0; i<*filas_cuadricula;++i){
    cuadricula[i]= new char[*columnas_cuadricula]; 
    for (int j=0; j<*columnas_cuadricula; ++j){
      cuadricula[i][j]='a';
      cout<<cuadricula[i][j];
    }
    cout<<endl;
  }
}
void ingresar_letras_a_cuadricucula(char** cuadricula,int* filas_cuadricula, int* columnas_cuadricula ){
  char aux=0;
  cout<<"Ingrese todas las letras: ";
  for (int i = 0; i <*filas_cuadricula; ++i) {
   for (int j = 0; j <*columnas_cuadricula; ++j) {
     cin>>aux;
     cuadricula[i][j]=aux;
    }
  }
}
int numeroPalabras(){
  int nPalabras;
  cout<<"Ingrese el número de palabras"<<endl;
  cin>>nPalabras;
  return nPalabras;
}

int main() {
  int* filas_cuadricula=new int;
  int* columnas_cuadricula=new int;
  char** cuadricula= NULL;
  tamañoCuadricula(filas_cuadricula,columnas_cuadricula);
  creacion_cuadricula(cuadricula,filas_cuadricula,columnas_cuadricula);
  ingresar_letras_a_cuadricucula(cuadricula,filas_cuadricula,columnas_cuadricula);
  }