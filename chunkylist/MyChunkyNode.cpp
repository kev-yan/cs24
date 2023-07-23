#include "MyChunkyNode.h"
#include <iostream>
#include <string>

using namespace std;


// TODO: Member Function Implementation



void MyChunkyNode::newNode(int size){
    arr = new std::string[size];
    for(int i=0; i<size; i++){
        arr[i] = "";
    }
    max = size;
}

void MyChunkyNode::setItem(int index, std::string item){
    if(num<max){
        if(arr[index] != ""){
            int i;
            std::string* temp = new std::string[max];
            for(i=0;i<index;i++){
                temp[i] = arr[i];
            }
            temp[index] = item;
            for(i=index;i<max;i++){
                temp[i+1] = arr[i]; 
            }
            delete[] arr;
            arr = temp;
            num++;
        }
        else{
            arr[index] = item;
            num++;
        }
    }
    

}

void MyChunkyNode::deleteItem(int index){
    if(index < 0 || index >= max){
        //cout << "broken" << endl;
    }
    else {
       if(arr[index] != ""){
            int i;
            std::string* temp = new std::string[max];
            for(i=0;i<index;i++){
               // cout << "i: " << arr[i] << endl;
                temp[i] = arr[i];
            }
            for(i=index+1;i<max;i++){
                //cout << "i: " << arr[i] << endl;
                temp[i-1] = arr[i]; 
            }
            delete[] arr;
            arr = temp;
            num--;
        }
        else{
            cout << "something went wrong" << endl;
        }
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

