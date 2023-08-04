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
public:
  // TODO: Constructor
  MyGrove();

  // Required StringGrove functions.
  // See StringGrove.h for descriptions.
  int     len() const;
  StringGrove*    concat(StringGrove* other) const;
  char 	  charAt(int index) const;
  StringGrove*    substr(int start, int end) const;

  // TODO: Add helper functions if necessary.
};

#endif
