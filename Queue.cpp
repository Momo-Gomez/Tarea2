#include <iostream>
using namespace std;
#include "QueueNode.cpp"

class Queue{
  QueueNode *first;
public:
  Queue(){
    first=NULL;
  }
  void push(string palabra,int fila,int columna, char direccion){
    QueueNode *nuevo= new QueueNode(palabra, fila, columna,  direccion);

    if(first==NULL){
      first=nuevo;
    }
    else {
      QueueNode *aux=first;
      while(aux->getNext() != NULL){
        aux=aux->getNext();
      }
      aux->setNext(nuevo);
    }
    
  }

  bool isEmpty(){
    return first==NULL;
  }

  int size(){
    int contador;
    if(isEmpty()){
      return 0;
    }else{
      QueueNode *aux = first;
      while(aux->getNext()!=NULL){
        contador++;
      }
      return contador;
    }
  }

  void dequeue(){
  
    QueueNode *aux=first;
    first=first->getNext();
    
    cout<<"Palabra eliminada: "<<aux->getPalabra()<<endl; 
    
    delete aux;
    
  }
  void show(){
    QueueNode *aux=first;
    while(aux->getNext() != NULL){
      cout<<"Palabra: "<<aux->getPalabra()<<endl;
      aux=aux->getNext();
    }
    cout<<"Palabra: "<<aux->getPalabra()<<endl;
  }
};