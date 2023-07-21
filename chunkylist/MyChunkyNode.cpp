#include "MyChunkyNode.h"
#include <iostream>

using namespace std;


// TODO: Member Function Implementation

void MyChunkyNode::smash(){
    //int* temp = new int[num-1];
    for(int i = 0; i<num; i++){
        //if(arr)
    }
}

void MyChunkyNode::newNode(int size){
    arr = new std::string[size];
    for(int i=0; i<size; i++){
        arr[i] = "";
    }
}

void MyChunkyNode::setItem(int index, std::string item){
    if(arr[index] == ""){
        num++;
    }
    arr[index] = item;

}

void MyChunkyNode::print(){
    for(int i=0; i<max; i++){
        cout << i << ": " << arr[i] << endl;
    }
}

void MyChunkyNode::setMax(int size){
    max = size;
}

MyChunkyNode::MyChunkyNode(){
    num = 0;
    arr = nullptr;
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
    return arr;
}

MyChunkyNode* MyChunkyNode::prev() const{
    return prevPtr;
}

MyChunkyNode* MyChunkyNode::next() const{
    return nextPtr;
}
void MyChunkyNode::setPrev(MyChunkyNode* temp){
    prevPtr = temp;
}
void MyChunkyNode::setNext(MyChunkyNode* temp){
    nextPtr = temp;
}

/*
int main(){
    MyChunkyNode* temp = new MyChunkyNode();
    std::string test = "test";
    temp->setMax(4);
    temp->newNode(4);
    temp->setItem(2, test);
    temp->setItem(2, "testing");
    temp->print();
    cout << temp->count();
    cout << "works";
}
*/