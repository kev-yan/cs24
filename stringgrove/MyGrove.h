#ifndef MYGROVE_H
#define MYGROVE_H

#include "StringGrove.h"

class MyGrove: public StringGrove<MyGrove> {
  // TODO: Member Variables
public:
  // TODO: Constructor

  // Required StringGrove functions.
  // See StringGrove.h for descriptions.
  int     len() const;
  StringGrove*    concat(StringGrove* other) const;
  char 	  charAt(int index) const;
  StringGrove*    substr(int start, int end) const;

  // TODO: Add helper functions if necessary.
};

#endif
