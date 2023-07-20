#include "MyChunkyNode.h"

// TODO: Member Function Implementation

MyChunkyNode::MyChunkyNode(){
    num = 0;
    arr = new int[0];
    this->prev = nullptr;
    this->next = nullptr;
}
~MyChunkyNode::MyChunkyNode(){
    delete arr[];
}

int MyChunkyNode::count() const{
    return num;
}
std::string* MyChunkyNode::items() const{

}

MyChunkyNode::MyChunkyNode* prev() const{
    return this->prev;
}

MyChunkyNode::MyChunkyNode* next() const{
    return this->next;
}

