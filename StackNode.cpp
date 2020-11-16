#include <iostream>
#include <string>
using namespace std;

class StackNode {
  string word;
  StackNode *previo;

  public:
    StackNode(){
      cout<<"Constructor vacío"<<endl;
      word="";
    }
    StackNode(string word){
      this->word=word;
      previo=NULL;
    }
    string get_word(){
      return word;
    }
    void set_previo(StackNode* new_stack_node){
      previo=new_stack_node;
    }
    StackNode *get_previo(){
      return previo;
    }
};