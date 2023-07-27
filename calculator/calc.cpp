#include "Stack.h"
#include "MyStack.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
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
    return (first * -1.0);
  }
  else {
    return -1.0;
  }
}

bool isConvertable(string input){
  try{
      stod(input);
      //string test = to_string(temp);
      bool seen = false;
      for(int i=0; i<(int)input.size(); i++){
        if(i > 0){
          if(!isdigit(input[i])){
            if(input[i] != '.' || !seen){
              return false;
            }
            else{
              seen = true;
            }
          }
          else{
          }
        }
        else{
          if(!(isdigit(input[0]) || (input[0] == '-') || (input[0] == '+'))){
            return false;
          }
        }
      }
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
int main(){
  MyStack* temp = new MyStack();
  string input;
  string output;
  int count = 0;
  double num;
  while(getline(cin, input)){
    bool exists = false;
    stringstream ss;
    bool broke = false;
    ss << input;
    while(ss >> output){
      exists = true;
      if(!broke){
        if(isOperator(output)){
          doMath(temp, output, broke);
        }
        else if(isConvertable(output)){
          num = stod(output);
          temp->push(num);
          count++;
          }
        else{
          broke = true;
          cout << "Unknown token." << endl;
          }
        }
      
    }
    if(!broke && exists){
      double result = temp->pop();
      if(temp->is_empty()){
        cout << "= " << result << endl;
        }
      else{
        cout << "Too many operands." << endl;
      }
    }
    else if(!exists){
      cout << "No expression." << endl;
    }

  }
  delete temp;

}
