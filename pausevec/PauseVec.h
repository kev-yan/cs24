#include "LinkedList.h"
#ifndef PAUSEVEC_H
#define PAUSEVEC_H

// This provides the size_t type:
#include <cstddef>
#include <vector>



class PauseVec {
  // Member Variables
  LinkedList *list;
  vector <int> arr;
  size_t count;
  int capacity;

  // Helper Functions
  Node findLast() const;
public:
  // Constructor and Destructor
  PauseVec();
  ~PauseVec();


  // Member Functions
  void setCount(size_t num);
  size_t getCount() const;
  int getCapacity() const;
  void push(int num);
  int lookup(int index);
  void mutate(int index, int value);
  void remove(int index);
  void remove_val(int value);

};

// Used by the autograder:
PauseVec* create_pausevec();

#endif
