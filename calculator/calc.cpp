#include "Stack.h"
#include "MyStack.h"
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

bool isOperator(string input){
  if(input == "+" || input == "-" || input == "*" || input == "/" || input == "%" || input == "^" || input == "~"){
    return true;
  }

  return false;
}

double doOperation(string input, double first, double second){
  if(input == "+"){
    return (first + second);
  }
  else if(input == "-"){
    return (first-second);
  }
  else if(input == "*"){
    return (first*second);
  }
  else if(input == "/"){
    return (first/second);
  }
  else if(input == "%"){
    return (fmod(first, second));
  }
  else if(input == "^"){
    return pow(first, second);
  }
  else if(input == "~"){
    //cout << "ere " << endl;
    return (first * -1.0);
  }
  else {
    return -1.0;
  }
}

bool isConvertable(string input){
  try{
      stod(input);
      return true;
  }
  catch(...){
    return false;
  }
}

void doMath(MyStack* list, string input, bool &broke){
    if(list->is_empty()){
      cout << "Not enough operands." << endl;
      broke = true;
    }
    else{
      double second = list->pop();
      if(input == "~"){
        list->push(doOperation(input, second, 0.0));
      }
      else if(list->is_empty()){
        cout << "Not enough operands." << endl;
        broke = true;
      }
      else{
        if((input == "%" || input == "/") && second == 0.0){
          cout << "Division by zero." << endl;
          broke = true;
        }
        else{
          double first = list->pop();
          list->push(doOperation(input, first, second));
        }
      }
    }

}

// TODO: Calculator helper fuctions, if necessary.
//int main(){
int main(){
  //cout << doOperation("~", 2.0, 5.0) << endl << endl;
  
  MyStack* temp = new MyStack();
  string input;
  string output;
  int count = 0;
  double num;
  
  while(true){
    bool broke = false;
    stringstream ss;
    getline(cin, input);
    ss << input;
    while(ss >> output){
      if(isOperator(output)){
        doMath(temp, output, broke);
        if(broke){
          cout << "something broke" << endl;
        }
        else{
         cout << "result: " << temp->top() << endl;
        }
        break;
      }
      else{
        if(isConvertable(output)){
          num = stod(output);
          temp->push(num);
          count++;
        }
        else{
          cout << "Unknown token." << endl;
        }
      }
  
    }
    //cout << count << endl << endl << endl;
    //temp->print();
    //cout << endl << endl << endl << endl;
    //temp->clear();
  }
  

}
