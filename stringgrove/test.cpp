#include "MyGrove.h"
#include <iostream>

using namespace std;

// Use this file to test your MyGrove class!
// This file won't be graded - do whatever you want.

int main() {
  char testing[] = "apple";
   char test2[] = "says";
  // char test3[] = "mouse";
  // char test4[] = "bottle";
  //char test4[] = "key";
  //char testing[] = "";
  MyGrove* first = new MyGrove(testing);
   MyGrove* second = new MyGrove(testing);
   MyGrove* third = new MyGrove(test2);
  // MyGrove* fourth = new MyGrove(test4);
  //MyGrove* fifth = new MyGrove("s");
  //MyGrove* fifth = new MyGrove(testing);


  //MyGrove* test = new MyGrove(test4);
  const MyGrove* newFirst;
  const MyGrove* newSecond;
  const MyGrove* newThird;
  const MyGrove* newFourth;

  

  newFirst = first->concat(first);
  newFirst->printWord();
  //newFirst->printWord();
  newSecond = newFirst->concat(second);

  //newSecond->printWord();
  cout << endl;
  newFourth = newSecond->concat(third);
  //newFourth->printWord();
  cout << endl;
  newThird = newFourth->substr(2, 14);
  cout << newThird->len() << endl;
  newThird->printWord();
  
  //cout << newThird->len() << endl;
  
  return 0;
}
