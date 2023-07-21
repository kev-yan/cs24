#include "MyChunkyNode.h"
#include <iostream>

using namespace std;


// TODO: Member Function Implementation
/*
void MyChunkyNode::merge(){ // might have to be MyChunkyNode* or be in the MyChunkyList
    if(num <= (max/2)){
        if(prevPtr->count() <= max/2){
            MyChunkyNode* previous = prevPtr;
            MyChunkyNode* newNode = new MyChunkyNode();
            newNode->setNext(nextPtr);
            newNode->setPrev(previous->prev());
            newNode->newNode(num+previous->count());
            for(int i=0; i<previous->count(); i++){
                newNode->setItem(newNode->getItem(i));
            }

            for(int i=0; i<num; i++){
                newNode->setItem(arr[i+previous->count()]);
            }
            newNode->setMax(max);
            return newNode;
            //TODO: delete nodes
            
        }
        else if(nextPtr->count() <= max/2){
            MyChunkyNode* after = nextPtr;
            MyChunkyNode* newNode = new MyChunkyNode();
            newNode->setNext(nextPtr);
            newNode->setPrev(after->prev());
            newNode->newNode(num+after->count());
            for(int i=0; i<after->count(); i++){
                newNode->setItem(after->getItem(i));
            }
            for(int i=0; i<num; i++){
                newNode->setItem(arr[i+after->count()]);
            }
            newNode->setMax(max);
            return newNode;
        }
    }
    for(int i = 0; i<num; i++){
        //if(arr)
    }
}
*/
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

std::string MyChunkyNode::getItem(int index){
    return arr[index];
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
    temp->setMax(1);
    temp->newNode(4);
    temp->setItem(2, test);
    temp->setItem(2, "testing");
    temp->print();
    cout << temp->count();
    cout << "works";
}
*/
