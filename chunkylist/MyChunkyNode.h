#ifndef MYCHUNKYNODE_H
#define MYCHUNKYNODE_H

#include "ChunkyNode.h"
#include <string>

class MyChunkyNode: public ChunkyNode {
  // TODO: Add any member variables you need.
  private:
  int num;
  int max;
  MyChunkyNode* prevPtr;
  MyChunkyNode* nextPtr;
  std::string* arr;


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
  void newNode(int size);
  void print();
  void setItem(int index, std::string item);
  void setMax(int size);
  std::string getItem (int index);
  void deleteItem(int index);
  void printMax();
  //void merge();
  // TODO: Add any other member functions you need.
};

#endif
