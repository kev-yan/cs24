#include "ChunkyList.h"
#include "MyChunkyList.h"
#include "MyChunkyNode.h"
#include <iostream>

using namespace std;

// This is an example main file - it won't be graded.
// Use it to interact with your list and make sure it works!

int main() {
  //MyChunkyList* list = new MyChunkyList(5);

  MyChunkyNode* temp = new MyChunkyNode();
  temp->newNode(4);
  temp->print();

}
