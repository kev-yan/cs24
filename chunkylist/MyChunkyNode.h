#ifndef MYCHUNKYNODE_H
#define MYCHUNKYNODE_H

#include "ChunkyNode.h"

class MyChunkyNode: public ChunkyNode {
  // TODO: Add any member variables you need.
  private:
  int num;
  MyChunkyNode* prevPtr;
  MyChunkyNode* nextPtr;
  std::string* arr;

  void smash();

public:
  MyChunkyNode();
  ~MyChunkyNode();


  // These functions are needed by the autograder.
  // See ChunkyNode.h for their descriptions.
  int           count() const;
  std::string*  items() const;
  MyChunkyNode* prev()  const;
  void setPrev(MyChunkyNode* temp);
  MyChunkyNode* next()  const;
  void setNext(MyChunkyNode* temp);

  // TODO: Add any other member functions you need.
};

#endif
