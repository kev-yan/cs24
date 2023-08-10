#include "MyGrove.h"
#include <iostream>

using namespace std;

// Use this file to test your MyGrove class!
// This file won't be graded - do whatever you want.

int main() {
  char testing[] = "apple";
  char test2[] = "says";
  char test3[] = "mouse";
  //char test4[] = "key";
  //char testing[] = "";
  MyGrove* first = new MyGrove(testing);
  MyGrove* second = new MyGrove(test2);
  MyGrove* third = new MyGrove(test3);
  //MyGrove* test = new MyGrove(test4);
  const MyGrove* newThird;
  const MyGrove* fourth;

  newThird = first->concat(second);
  fourth = newThird->concat(third);
  cout << fourth->charAt(9) << endl;
  
  newThird = fourth->substr(0, 7);
  newThird->printWord();
  //cout << fourth->len() << endl;
 // MyGrove* newTest = new MyGrove(" please");

  // TODO: Replace this with something useful!

  //cout << test->len() << endl;
  //cout << newTest->len() << endl;
  return 0;
}
