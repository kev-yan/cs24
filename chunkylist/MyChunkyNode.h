#ifndef MYCHUNKYNODE_H
#define MYCHUNKYNODE_H

#include "ChunkyNode.h"

class MyChunkyNode: public ChunkyNode {
  // TODO: Add any member variables you need.
  private:
  int num;
  int* arr[];
  MyChunkyNode* prev;
  MyChunkyNode* next;

public:
  // TODO: Constructor(s)
  MyChunkyNode();
  ~MyChunkyNode();

  // TODO: Destructor

  // These functions are needed by the autograder.
  // See ChunkyNode.h for their descriptions.
  int           count() const;
  std::string*  items() const;
  MyChunkyNode* prev()  const;
  MyChunkyNode* next()  const;

  // TODO: Add any other member functions you need.
};

#endif
