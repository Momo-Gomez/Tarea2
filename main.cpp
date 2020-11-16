#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include<string>
using namespace std;

//tomar palabra de la pila
//cantidad de letras de la palabra
//posicion del tablero 0,0 (partiendo)
//if coincide, se queda, else, avanza
//for vertical, horizontal y diagonal, con la cantidad de letras

//retornar una matriz?

int tamaño_fila_Cuadricula(){
  int filas_cuadricula;
  cout<<"Ingrese el número de filas: ";
  cin>>filas_cuadricula;
  return filas_cuadricula;
}
int tamaño_columna_Cuadricula(){
  int columnas_cuadricula;
  cout<<"Ingrese el número de columnas: ";
  cin>>columnas_cuadricula;
  return columnas_cuadricula;
}

void creacion_cuadricula(char** cuadricula,int filas_cuadricula,int columnas_cuadricula){
  for (int i=0; i<filas_cuadricula;++i){
    cuadricula[i]= new char[columnas_cuadricula]; 
    for (int j=0; j<columnas_cuadricula; ++j){
      cuadricula[i][j]=0;
    } 
  }
}

void ingresar_letras_a_cuadricula(char** cuadricula,int filas_cuadricula, int columnas_cuadricula ){
  cout<<"Ingrese todas las letras separadas por un espacio: ";
  for (int i = 0; i<(filas_cuadricula); ++i) {
    for (int j = 0; j<(columnas_cuadricula); ++j) {
      cin>>cuadricula[i][j];
    }
  }
}
void show_cuadricula(char** cuadricula,int filas_cuadricula,int columnas_cuadricula){
  for (int i=0; i<filas_cuadricula;++i){ 
    for (int j=0; j<columnas_cuadricula; ++j){
      cout<<cuadricula[i][j]<<" ";
    }
    cout<<endl; 
  }
}
//
int numeroPalabras(){
  int cantidad_palabras;
  cout<<"Ingrese el número de palabras buscar: ";
  cin>>cantidad_palabras;
  return cantidad_palabras;
}

void ingresar_palabras_a_buscar(Stack* palabras_a_buscar,int cantidad_palabras){
  for (int i=0; i<cantidad_palabras;i++){
    char* palabra_buscada;
    cout<< "Ingrese la plabra número "<<(i+1)<<": ";
    scanf("%s",palabra_buscada);
    palabras_a_buscar->push(palabra_buscada);
    }
  }

void buscar_palabra_vertical(char** cuadricula, string palabra_buscada,Queue* palabras_encontradas,int filas_cuadricula, int columnas_cuadricula){
  int cont=0;// para saber cuantas letras son iguales
  int fila=-1;
  int columna=-1;
  for (int i = 0; i<(filas_cuadricula); ++i) {
    for (int j = 0; j<(columnas_cuadricula); ++j) {
      if (palabra_buscada[i]==cuadricula[i][j]){  
        cont++;
        if(cont==1){
          fila=i;
          columna=j;
        }
      }else{
        break;
      }
    }
    if (cont!=palabra_buscada.length()){
      cont=0;
    }else{
      palabras_encontradas->push(palabra_buscada,fila, columna,'v');
    }
  }
}

void buscar_palabra_horizontal(char** cuadricula, string palabra_buscada,Queue* palabras_encontradas,int filas_cuadricula, int columnas_cuadricula){
  for (int a=0;a<filas_cuadricula;a++){
    for(int b=0;b<columnas_cuadricula;b++){
      if (palabra_buscada.length()<=(columnas_cuadricula-b)){//compara que en horizontal hayan =  o mas cantidad de letras que la palabra a buscar
        string palabra_cuadricula;
        for (int c=0;c<palabra_buscada.length();c++){//une todas las letras que estasn desde la posision actual hasta la cantidad de letras que tiene la palabra a buscar
          palabra_cuadricula=+ cuadricula[a][b];
          
        }
        if(palabra_cuadricula==palabra_buscada){//compara la plabra obtenia en el for anterior
            palabras_encontradas->push(palabra_buscada,a,b,'h');
        }
      }
    }

  }
}

void buscar_palabra_diagonal(char** cuadricula, string palabra_buscada,Queue* palabras_encontradas,int filas_cuadricula, int columnas_cuadricula){
  for (int a=0;a<filas_cuadricula;a++){
    for(int b=0;b<columnas_cuadricula;b++){
      if (palabra_buscada.length()<=(columnas_cuadricula-b) && palabra_buscada.length()<=(filas_cuadricula-a)){//compara que en horizontal y verticar  hayan =/o mas cantidad de letras que la palabra a buscar
        string palabra_cuadricula;
        int cont=0;
        for (int c=0;c<palabra_buscada.length();c++){//une todas las letras que estasn desde la posision actual hasta la cantidad de letras que tiene la palabra a buscar
          palabra_cuadricula=+ cuadricula[a+cont][b+cont];//avanza en diagonal creando una palabra que luego será comaprada con la plabra buscada 
          cont=+1;
        }
        if(palabra_cuadricula==palabra_buscada){
            palabras_encontradas->push(palabra_buscada,a,b,'d');
        }

      }
    }

  }

}

void buscar_palabra(char** cuadricula, Stack* palabras_a_buscar,Queue* palabras_encontradas,int filas_cuadricula, int columnas_cuadricula){
  string palabra_buscada;
  while (!palabras_a_buscar->isEmpty()){
    palabra_buscada=palabras_a_buscar->pop();
    buscar_palabra_vertical(cuadricula,palabra_buscada,palabras_encontradas,filas_cuadricula,columnas_cuadricula);
    buscar_palabra_horizontal(cuadricula,palabra_buscada,palabras_encontradas,filas_cuadricula,columnas_cuadricula);
    buscar_palabra_diagonal(cuadricula,palabra_buscada,palabras_encontradas,filas_cuadricula,columnas_cuadricula);
  }
}

int main() {
  int filas_cuadricula = tamaño_fila_Cuadricula();
  int columnas_cuadricula= tamaño_columna_Cuadricula();
  int cantidad_palabras;
  Stack* palabras_a_buscar = new Stack();
  Queue* palabras_encontradas= new Queue();
  char** cuadricula=new char*[filas_cuadricula];
  creacion_cuadricula(cuadricula,filas_cuadricula,columnas_cuadricula);
  ingresar_letras_a_cuadricula(cuadricula,filas_cuadricula,columnas_cuadricula);
  cantidad_palabras=numeroPalabras();
  ingresar_palabras_a_buscar(palabras_a_buscar,cantidad_palabras);
  buscar_palabra(cuadricula,palabras_a_buscar,palabras_encontradas,filas_cuadricula,columnas_cuadricula);
  palabras_encontradas->show();
}