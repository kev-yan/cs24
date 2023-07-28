#include "StringGrove.h"
#include "MyGrove.h"

StringGrove* StringGrove::create() {
  // This will work if you use the obvious implementation.
  // Change it if you implement a different constructor!
  return new MyGrove();
}
