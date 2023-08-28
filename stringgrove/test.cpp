#include "MyGrove.h"
#include <iostream>

using namespace std;

// Use this file to test your MyGrove class!
// This file won't be graded - do whatever you want.

int main() {
  char testing[] = "apple";
  char test2[] = "says";
  char test3[] = "mouse";
  char test4[] = "bottle";
  //char test4[] = "key";
  //char testing[] = "";
  MyGrove* first = new MyGrove(testing);
  MyGrove* second = new MyGrove(test2);
  MyGrove* third = new MyGrove(test3);
  MyGrove* fourth = new MyGrove(test4);
  //MyGrove* fifth = new MyGrove("s");
  MyGrove* fifth = new MyGrove(testing);

  //MyGrove* test = new MyGrove(test4);
  const MyGrove* newFirst;
  const MyGrove* newSecond;
  const MyGrove* newThird;
  const MyGrove* newFourth;

  newFirst = first->substr(0,4);
  newFirst->printWord();
  newFirst = first->concat(fifth);
  newFirst = newFirst->concat(fifth);
  cout << newFirst->len() << endl;
  newFirst = newFirst->substr(14, 14);
  newFirst->printWord();
  newFirst = first->concat(second);
  newSecond = third->concat(fourth);
  MyGrove temp1 = *newFirst;
  MyGrove temp2 = *newSecond;
  MyGrove *temp3 = &temp1;
  MyGrove *temp4 = &temp2;
  newThird = temp3->concat(temp4);
  newFourth = newThird->concat(fifth);
  /*
  for(int i=0; i<21; i++){
    cout << newFourth->charAt(i) << endl;
  }
  */
  //cout << newFourth->len() << endl;
  
  newSecond = newFourth->substr(0, 20);
  newSecond = first->substr(0,2);
  /*
  for(int i=0; i<21; i++){
    cout << newFourth->charAt(i);
  }
  cout << endl;
  */
  cout << newSecond->len() << endl;
  newSecond->printWord();
  //newThird = newFirst->concat(newSecond);
  //newThird = fourth->substr(0, 7);
  //newThird->printWord();
  //cout << fourth->len() << endl;
 // MyGrove* newTest = new MyGrove(" please");

  // TODO: Replace this with something useful!

  //cout << test->len() << endl;
  //cout << newTest->len() << endl;
  return 0;
}
