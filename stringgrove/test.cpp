#include "MyGrove.h"
#include <iostream>

using namespace std;

// Use this file to test your MyGrove class!
// This file won't be graded - do whatever you want.

int main() {
  char testing[] = "testing";
  MyGrove* test = new MyGrove(testing);

  // TODO: Replace this with something useful!

  cout << test->len() << endl;
  return 0;
}
