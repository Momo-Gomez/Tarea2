#include <iostream>
#include <string>
using namespace std;
class QueueNode {
  
  public:
  string palabra;// no se necesita mostrarla por letras por eso se pone String
  int fila;
  int columna;
  char direccion;
  QueueNode *next;


  
  QueueNode(){
    palabra="";
    int fila=-1;
    int columna=-1;
    direccion=0;
    next=NULL;
  }
  
  QueueNode(string palabra,int fila,int columna, char direccion){
    this->palabra=palabra;
    this->fila= fila;
    this->columna= columna;
    this->direccion= direccion;
    next=NULL;
  }
  
  string getPalabra(){
    return palabra;
  }
  
  void setNext(QueueNode *nodo){
    next=nodo;
  }
  
  QueueNode *getNext(){
    return next;
  }

};