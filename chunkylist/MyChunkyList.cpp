#include "MyChunkyList.h"
//#include "MyChunkyNode.h"
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
            tailPtr = headPtr;
            //headPtr->newNode(1);
            //headPtr->setItem(0, item);
            num++;
        }
        /*
        else{
            MyChunkyNode* curr = findNode(index);
            int newInd = newIndex(index);                                   //MIGHT TAKE TOO LONG TO RUN
            std::string newItem = item;
            if(curr->count() < max){
                curr->setItem(newInd, newItem);
                num++;
            }
        }
        */
        
    }
}

std::string& MyChunkyList::lookup(int index){
    if(index < 0 || index > num){
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
    if(index < 0 || index > num){
        throw std::out_of_range("index not found");
    }
    else{
        if(headPtr == nullptr){
            throw std::out_of_range("index not found");
        }
    }
}

MyChunkyNode* MyChunkyList::head() const{
    return headPtr;
}

MyChunkyNode* MyChunkyList::tail() const{
    return tailPtr;
}

/*
int main(){
    MyChunkyList* test = new MyChunkyList(3);
   // MyChunkyNode* curr;
    //test->insert(0, "test");
    //curr = test->head();
    //curr->print();
    
}
*/