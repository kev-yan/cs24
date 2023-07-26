#include "Stack.h"
#include "MyStack.h"
#include <iostream>
#include <cmath>
using namespace std;

bool isOperator(string input){
  if(input == "+" || input == "-" || input == "*" || input == "/" || input == "%" || input == "^" || input == "~"){
    return true;
  }
  return false;
}
// TODO: Calculator helper fuctions, if necessary.
//int main(){
int main(int argc, char* argv[]){
  //MyStack* temp = new MyStack();
  if(argc == 2){
    string input;
    input = argv[1];
  }
}
