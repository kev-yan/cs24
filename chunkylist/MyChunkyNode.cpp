#include "MyChunkyNode.h"

// TODO: Member Function Implementation

MyChunkyNode::MyChunkyNode(){
    num = 0;
    arr = new int[1];
    prevPtr = nullptr;
    nextPtr = nullptr;
}
MyChunkyNode::~MyChunkyNode(){
    delete[] arr;
}

int MyChunkyNode::count() const{
    return num;
}
std::string* MyChunkyNode::items() const{
    return nullptr;
}

MyChunkyNode* MyChunkyNode::prev() const{
    return prevPtr;
}

MyChunkyNode* MyChunkyNode::next() const{
    return nextPtr;
}

