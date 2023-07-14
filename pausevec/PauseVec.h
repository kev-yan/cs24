#include "LinkedList.h"
#ifndef PAUSEVEC_H
#define PAUSEVEC_H

// This provides the size_t type:
#include <cstddef>



class PauseVec {
  // Member Variables
  int *arr;
  size_t num;
  size_t cap;

  // Helper Functions
public:
  // Constructor and Destructor
  PauseVec();
  ~PauseVec();


  // Member Functions
  void smash();
  void setCount(size_t num);
  size_t count() const;
  int capacity() const;
  void push(int count);
  int lookup(unsigned long int index);
  void mutate(size_t index, int value);
  void remove(int index);
  void remove_val(int value);

};

// Used by the autograder:
PauseVec* create_pausevec();

#endif
