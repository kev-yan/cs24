#ifndef MYSTACK_H
#define MYSTACK_H
#include <vector>

#include "Stack.h"
#include "LinkedList.h"
class MyStack: public Stack {

  // TODO: Member Variables
  LinkedList* list;

  //void clearLL();
  void getVal(int index);
  void remove(int index);
  void add(int index);

public:
  // TODO: Constructor & Destructor
  MyStack();
  ~MyStack();

  // Required Stack functions.
  // See Stack.h for descriptions.
  void print();
  void   clear();
  bool   is_empty() const;
  void   push(double item);
  double pop();
  double top() const;

  // TODO: Add helper functions if necessary.
};

#endif
