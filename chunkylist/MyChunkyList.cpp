#include "MyChunkyList.h"
#include <string>
#include <iostream>

MyChunkyNode* MyChunkyList::findNode(int index){
    if(index < 0 || index > num){
        return nullptr;
    }
    int temp = 0;
    bool hold= true;
    MyChunkyNode* curr = headPtr;
    while(hold){
        if((temp+max) > index || curr == nullptr){
            hold = false;
        }
        else{
            temp = temp+max;
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
        if((temp+max) > index || curr == nullptr){
            hold = false;
        }
        else{
            temp = temp+max;
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
            headPtr->setMax(max);
            headPtr->newNode(4);
            headPtr->setItem(0, item);
            //std::cout << "beginning" << std::endl;
            num++;
        }
        
        else{
           // std::cout << "new insert" << std::endl;
            MyChunkyNode* curr = findNode(index);
            int newInd = newIndex(index);                                   //MIGHT TAKE TOO LONG TO RUN
            curr->print();
           // std::cout << "found node" << std::endl;
            if(curr->count() < max){
                    //std::cout << "new Node insert" << std::endl;
                curr->setItem(newInd, item);
                num++;
            }
            else{
                //std::cout << "inserting" << std::endl;
                MyChunkyNode* temp = new MyChunkyNode();
                curr->setNext(temp);
                temp->setPrev(curr);
                curr->setItem(0, item);

            }
        }
        
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


int main(){
    //std::cout << "test";
    MyChunkyList* test = new MyChunkyList(4);
    MyChunkyNode* curr = new MyChunkyNode();
    test->insert(0, "test");
    test->insert(1, "testing");
    curr = test->head();
    curr->print();
    
}

