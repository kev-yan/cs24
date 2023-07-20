#include "MyChunkyNode.h"

// TODO: Member Function Implementation

MyChunkyNode::MyChunkyNode(){
    count = 0;
    arr = new int[0];
    this->prev = nullptr;
    this->next = nullptr;
}
~MyChunkyNode::MyChunkyNode(){
    delete arr[];
    
}

int MyChunkyList::count(){
    return this->count;
}