#ifndef MYGROVE_H
#define MYGROVE_H

#include "StringGrove.h"
#include "node.h"

class MyGrove: public StringGrove<MyGrove> {
  // TODO: Member Variables
  int length;
  Node* root;
// create node class - w/ member variables left, right, maybe parent, length
// create root node of tree class
  void setWord(char* str);
  Node* giveRoot();
  void setLength(int size);
  void setRoot(Node* other);
  bool isWord(Node* curr) const;
  Node* getNode(Node* curr, int index) const;
  int getIndex(Node* curr, int index) const;
public:
  MyGrove(const char* str);

  // Required StringGrove functions.
  // See StringGrove.h for descriptions.
  int     len() const;
  const MyGrove*    concat(MyGrove* other) const;
  char 	  charAt(int index) const;
  const MyGrove*    substr(int start, int end) const;
  
  void printWord() const;
  Node* getRoot() const;

  // TODO: Add helper functions if necessary.
};

#endif
