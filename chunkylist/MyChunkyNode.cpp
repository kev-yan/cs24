#include "MyChunkyNode.h"
#include <iostream>
#include <string>

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
            newNode->newNode(max);
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
            newNode->newNode(max);
            for(int i=0; i<after->count(); i++){
                newNode->setItem(i, after->getItem(i));
            }
            for(int i=0; i<num; i++){
                newNode->setItem(i+after->count(), arr[i]);
            }
            newNode->setMax(max);
            return newNode;
        }
    }
}

*/
void MyChunkyNode::newNode(int size){
    arr = new std::string[size];
    for(int i=0; i<size; i++){
        arr[i] = "";
    }
    max = size;
}

void MyChunkyNode::setItem(int index, std::string item){
    if(arr[index] == ""){
        num++;
    }
    arr[index] = item;

}

void MyChunkyNode::deleteItem(int index){
    if(index < 0 || index >= max){
        cout << "broken" << endl;
    }
    else {
        arr[index] = "";
        num--;
    }
}

std::string MyChunkyNode::getItem(int index){
    return arr[index];
}

void MyChunkyNode::print(){
    cout << "max: " << max << endl;
    cout << "count: " << num << endl;
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
    MyChunkyNode* first = new MyChunkyNode();
    MyChunkyNode* second = new MyChunkyNode();

    first->setNext(second);
    second->setNext(first);

    first->newNode(3);
    first->setMax(4);

    second->newNode(3);
    second->setMax(4);

    first->setItem(0, "A");
    first->setItem(1, "B");
    first->setItem(2, "C");


    second->setItem(0, "D");
    second->setItem(1, "E");
    second->setItem(2, "F");

    first->print();
    second->print();
}
*/

