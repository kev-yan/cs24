#include "MyChunkyList.h"

MyChunkyList::MyChunkyList(int chunksize){
    num = 0;
    max = chunksize;
    headPtr = nullptr;
    tailPtr = nullptr;
}

MyChunkyList::~MyChunkyList(){
    while(headPtr != tailPtr){
        MyChunkyNode* temp = headPtr->next();
        headPtr->~MyChunkyNode();
        delete headPtr;
        headPtr = temp;
    }
    tailPtr->~MyChunkyNode();
    delete tailPtr;
}

int MyChunkyList::count() const{
    int total = 0;
    MyChunkyNode* temp = headPtr;
    while(temp != nullptr){
        total += temp->count();
        temp = temp->next();
    }
    return total;
}

void MyChunkyList::insert(int index, const std::string& item){
    int temp = index;
}

std::string& MyChunkyList::lookup(int index){
    int temp = index;
}

void MyChunkyList::remove(int index){
    int temp = index;
}

MyChunkyNode* MyChunkyList::head() const{
    return headPtr;
}

MyChunkyNode* MyChunkyList::tail() const{
    return tailPtr;
}

