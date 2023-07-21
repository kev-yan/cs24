#include "MyChunkyList.h"
#include <iostream>

MyChunkyNode* MyChunkyList::findNode(int index){
    if(index < 0 || index >= num){
        return nullptr;
    }
    int temp = 0;
    bool hold= true;
    MyChunkyNode* curr = headPtr;
    while(hold){
        if((temp+curr->count()) > index){
            hold = false;
        }
        else{
            temp = temp+curr->count();
            curr = curr->next();
        }
    }
    return curr;
}

int MyChunkyList::newIndex(int index){
    int temp = 0;
    bool hold= true;
    MyChunkyNode* curr = headPtr;
    while(hold){
        if((temp+curr->count()) > index){
            hold = false;
        }
        else{
            temp = temp+curr->count();
            curr = curr->next();
        }
    }
    return index-temp;
}

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
    if(index < 0 || index > num){
        throw std::out_of_range("index not found");
    }
    else{
        if(headPtr == nullptr){
            headPtr = new MyChunkyNode();
            tail = headPtr;
            headPtr->newNode(max);
        }
        MyChunkyNode* curr = findNode(index);
        int newInd = newIndex(index);                                   //MIGHT TAKE TOO LONG TO RUN
        std::string newItem = item;
        if(curr->count() < max){
            curr->setItem(newInd, newItem);
        }
    }
}

std::string& MyChunkyList::lookup(int index){
    if(index < 0 || index >= num){
        throw std::out_of_range("index not found");
    }
    else{
        int temp = 0;
        bool hold= true;
        MyChunkyNode* curr = headPtr;
        std::string* item;
        while(hold){
            if((temp+curr->count()) > index){
                hold = false;
            }
            else{
                temp = temp+curr->count();
                curr = curr->next();
            }
        }
        temp = index-temp;
        item = curr->items();
        return item[temp-1];
    }
}

void MyChunkyList::remove(int index){
    std::cout << index;
}

MyChunkyNode* MyChunkyList::head() const{
    return headPtr;
}

MyChunkyNode* MyChunkyList::tail() const{
    return tailPtr;
}
