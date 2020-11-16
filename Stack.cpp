#include <iostream>
#include <string>
#include "StackNode.cpp"
using namespace std;

class Stack{
  StackNode *last;
  public:
  Stack(){
    last=NULL;
  }

  bool isEmpty (){
    return last==NULL;
  }

  void push(string word){
    StackNode *new_stack_node= new StackNode(word); 
    if (!isEmpty()){
      new_stack_node->set_previo(last);
    }
    last= new_stack_node;
  }

  string pop(){
    StackNode* remove=last;
    string word = last->get_word();
    last= last->get_previo();
    delete remove;
    return word;
  }

  int size(){
    int cont=0;
    StackNode* aux = last;
    while(aux!=NULL){
      cont++;
      aux= aux->get_previo();
    }
    return cont;
  }
  void show (){
    StackNode* aux= last;
    while (aux!=NULL){
      cout<<aux->get_word()<<endl;
      aux=aux->get_previo();
    }
  }

  ~Stack(){
    cout<<"removing stack..."<<endl;
    while (last!=NULL){
      StackNode* remove = last;
      last=last->get_previo();
      delete remove;
    }
  }

};