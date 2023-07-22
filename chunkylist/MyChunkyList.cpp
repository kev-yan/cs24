#include "MyChunkyList.h"
#include <string>
#include <iostream>
using namespace std;

MyChunkyNode* MyChunkyList::merge(MyChunkyNode* curr){ // might have to be MyChunkyNode* or be in the MyChunkyList
    if(curr->count() <= (max/2)){
        
        if(curr->prev() != nullptr && (curr->prev())->count() <= max/2){
            MyChunkyNode* previous = curr->prev();
            MyChunkyNode* newNode = new MyChunkyNode();
            newNode->setNext(curr->next());
            newNode->setPrev(previous->prev());
            newNode->newNode(max);
            for(int i=0; i<previous->count(); i++){
                newNode->setItem(i, newNode->getItem(i));
            }

            for(int i=0; i<curr->count(); i++){
                newNode->setItem(i+previous->count(), curr->getItem(i+previous->count()));
            }
            newNode->setMax(max);
            delete curr;
            delete curr->prev();
            if(headPtr == previous){
                headPtr = newNode;
            }
            if(tailPtr == curr){
                tailPtr = curr;
            }
            return newNode;
            
        }
        else if(curr->next() != nullptr && (curr->next())->count() <= max/2){
            //MyChunkyNode* toDelete = curr;
            MyChunkyNode* after = curr->next();
            MyChunkyNode* newNode = new MyChunkyNode();
            newNode->setNext(after->next());
            newNode->setPrev(curr->prev());
            newNode->newNode(max);
            for(int i=0; i<curr->count(); i++){
                newNode->setItem(i, curr->getItem(i));
            }
            for(int i=0; i<after->count(); i++){
                newNode->setItem(i+curr->count(), after->getItem(i));
            }
            newNode->setMax(max);
            delete curr;
            delete after;
            if(headPtr == curr){
                headPtr = newNode;
            }
            if(tailPtr == after){
                tailPtr = newNode;
            }
            return newNode;
        }
    }
    else{
        return curr;
    }
}

void MyChunkyList::split(MyChunkyNode* node2){
    MyChunkyNode* node = node2;
    MyChunkyNode* newNode = new MyChunkyNode();
    newNode->newNode(max);
    newNode->setNext(node->next());
    node->setNext(newNode);
    if(max%2 == 0){
        for(int i=0;i<max/2;i++){
            newNode->setItem(i, node->getItem(i+max/2));
            node->deleteItem(i+max/2);
        }
    }
    else{
        for(int i=(max-(max/2));i<max;i++){
            //cout << "i: " << i << endl;
            newNode->setItem(i-(max-(max/2)), node->getItem(i));
            node->deleteItem(i);
        }
    }
    if(tailPtr == node){
        tailPtr = newNode;
    }

}


MyChunkyNode* MyChunkyList::findNode(int index){
    int maxNum = (num/max+1)*max;
    if(index < 0 || index >= maxNum){
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
        headPtr->~MyChunkyNode();                         //FIX THIS
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
    int maxNum = (num/max+1)*max;
    if(index < 0 || index > maxNum){
        throw std::out_of_range("index not found");
    }
    else{
        
        if(headPtr == nullptr){
            headPtr = new MyChunkyNode();
            tailPtr = headPtr;
            headPtr->setMax(max);
            headPtr->newNode(max);
            headPtr->setItem(0, item);
            //std::cout << "beginning" << std::endl;
            num++;
        }
        
        else{
            MyChunkyNode* curr = findNode(index);
            int newInd = newIndex(index);
            if(curr == nullptr){
                curr = findNode(index-1);
                split(curr);
                //cout << "work" << endl;
                newInd = newInd+(max/2);
                if(max%2 != 0){
                    curr = curr->next();
                }
                curr->setItem(newInd, item);
                num++;
                
            }
            //else if(curr->count() < max){
                //cout << "count: " << curr->count() << endl;
            else{
                if(curr->getItem(newInd) == ""){
                    num++;
                }
                curr->setItem(newInd, item);
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
        else{

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
    //std::cout << "test";
    MyChunkyList* test = new MyChunkyList(6);
    MyChunkyNode* curr;
    MyChunkyNode* currTail;
    test->insert(0, "1");
    test->insert(1, "2");
    test->insert(2, "3");
    //test->insert(2, "WORKA");
    test->insert(3, "4");
    test->insert(4, "5");
    test->insert(5, "6");
    test->insert(6, "ASDJONFDA");

   // test->insert(6, "testa");
    curr = test->head();
    curr->deleteItem(3);
    //cout << test->head() << " " << test->tail() << endl;
   // curr->print();
    currTail = test->tail();
    //currTail->print();
    curr = test->merge(curr);
    (test->tail())->print();
    cout << test->tail() << endl;
    cout << curr;

}

*/
