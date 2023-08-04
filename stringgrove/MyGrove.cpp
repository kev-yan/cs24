#include "MyGrove.h"


MyGrove::MyGrove(){
    length = 0;
    root = nullptr;
}

int MyGrove::len() const{
    return length;
}

StringGrove* MyGrove::concat(StringGrove* other) const{
    return other;
}

char MyGrove::charAt(int index) const{
    return 'a';
}

StringGrove* MyGrove::subsrt(int start, int end) const{
    return nullptr;
}
