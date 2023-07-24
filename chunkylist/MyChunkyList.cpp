#include "MyChunkyList.h"
#include <string>
#include <iostream>
using namespace std;

void MyChunkyList::clearNode(MyChunkyNode* curr){
    if(headPtr == tailPtr && headPtr == curr){
        headPtr = nullptr;
        tailPtr = nullptr;
    }
    else if(headPtr == curr){
        headPtr = curr->next();
        if(curr->next() != nullptr){
            curr->next()->setPrev(nullptr);
        }
    }
    else if(tailPtr == curr){
        if(tailPtr->prev() != nullptr){
            tailPtr->prev()->setNext(nullptr);
        }
        tailPtr = curr->prev();
    }
    else{
        curr->prev()->setNext(curr->next());
        curr->next()->setPrev(curr->prev());
    }
    delete curr;

}

void MyChunkyList::print(){
    MyChunkyNode* temp = headPtr;
    cout << "listNum: " << num << endl;
    cout << "head address: " << headPtr << endl;
    cout << "tail address: " << tailPtr << endl;
    int i = 0;
    while(temp != nullptr){
        cout << "---------------NODE " << i << "---------------" << endl;
        cout << "address: " << temp << endl;
        temp->print();
        temp = temp->next();
        i++;
    }
}
void MyChunkyList::printBack(){
    MyChunkyNode* temp = tailPtr;
    cout << "listNum: " << num << endl;
    int i = 0;
    while(temp != nullptr){
        cout << "---------------NODE " << i << "---------------" << endl;
        cout << "address: " << temp << endl;
        temp->print();
        temp = temp->prev();
        i++;
    }    

}

void MyChunkyList::merge(MyChunkyNode* curr){ // might have to be MyChunkyNode* or be in the MyChunkyList
    if(curr->count() <= max){

            if(curr->prev() != nullptr && (curr->count() + curr->prev()->count()) <= max/2){
            MyChunkyNode* previous = curr->prev();
            MyChunkyNode* newNode = new MyChunkyNode();
            newNode->setNext(curr->next());
            newNode->setPrev(previous->prev());
            newNode->newNode(max);
            if(previous->prev() != nullptr){
                previous->prev()->setNext(newNode);
            }
            if(newNode->next() != nullptr){
                newNode->next()->setPrev(newNode);
            }
            for(int i=0; i<previous->count(); i++){
                newNode->setItem(i, previous->getItem(i));
            }
            for(int i=0; i<curr->count(); i++){
                newNode->setItem(i+previous->count(), curr->getItem(i));
            }
            newNode->setMax(max);
            if(headPtr == previous){
                headPtr = newNode;
            }
            if(tailPtr == curr){
                tailPtr = newNode;
            }
            delete curr;
            delete previous;

            
        }
        else if(curr->next() != nullptr && (curr->count() + curr->next()->count()) <= max/2){

            MyChunkyNode* after = curr->next();
            MyChunkyNode* newNode = new MyChunkyNode();
            if(curr->prev() != nullptr){
                curr->prev()->setNext(newNode);
            }
            if(after->next() != nullptr){
                after->next()->setPrev(newNode);
            }
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
            if(headPtr == curr){
                headPtr = newNode;
            }
            if(tailPtr == after){
                tailPtr = newNode;
            }
            delete curr;
            delete after;
            
        }
    }
}

void MyChunkyList::split(MyChunkyNode* node2){
    MyChunkyNode* node = node2;
    MyChunkyNode* newNode = new MyChunkyNode();
    newNode->newNode(max);
    newNode->setNext(node->next());
    newNode->setPrev(node);
    node->setNext(newNode);
    if(newNode->next() != nullptr){
        newNode->next()->setPrev(newNode);
    }
    if(max%2 == 0){
        for(int i=0;i<max/2;i++){
            newNode->setItem(i, node->getItem(i+max/2));
        }
        for(int i=0; i<max/2;i++){
            node->deleteItem(max/2);
        }
    }
    else{
        for(int i=(max-(max/2));i<max;i++){
            newNode->setItem(i-(max-(max/2)), node->getItem(i));
        }
        for(int i=(max-(max/2));i<max;i++){
            node->deleteItem(max-(max/2));
        }
    }


    if(tailPtr == node){
        tailPtr = newNode;
    }

}

void MyChunkyList::split2(MyChunkyNode* node, int index, std::string item){
    MyChunkyNode* newNode = new MyChunkyNode();
    newNode->newNode(max);
    newNode->setNext(node->next());
    newNode->setPrev(node);
    node->setNext(newNode);
    if(newNode->next() != nullptr){
        newNode->next()->setPrev(newNode);
    }
    if(max%2 == 0){
        if(index <= max/2){
            for(int i=max/2; i<max; i++){
                newNode->setItem(i-(max/2), node->getItem(i));
            }
            for(int i=max/2; i<max; i++){
                node->deleteItem(max/2);
            }
            node->setItem(index, item);
        }
        else{
            for(int i=(max/2+1); i<max; i++){
                newNode->setItem(i-(max/2+1), node->getItem(i));
            }
            for(int i=(max/2+1); i<max; i++){
                node->deleteItem(max/2+1);
            }
            newNode->setItem(index-node->count(), item);
        }
    }
    else{
        if(index <= max/2){
            for(int i=max/2; i<max; i++){
                newNode->setItem(i-max/2, node->getItem(i));

            }
            for(int i=max/2; i<max; i++){
                node->deleteItem(max/2);
            }
            node->setItem(index, item);
        }
        else{
            for(int i=max/2+1; i<max; i++){
                newNode->setItem(i-(max/2+1), node->getItem(i));
            }
            for(int i=max/2+1; i<max; i++){
                node->deleteItem(max/2+1);
            }
            newNode->setItem(index-node->count(), item);
        }

    }
    if(tailPtr == node){
        tailPtr = newNode;
    }

}


MyChunkyNode* MyChunkyList::findNode(int index){
    //int maxNum = (num/max+1)*max;

    if(index < 0 || index > num){
        return nullptr;
    }
    if(index == num){
        return tailPtr;
    }
    bool hold= true;
    MyChunkyNode* curr = headPtr;
    while(hold){
            if((curr->count()) > index || curr == nullptr){
                hold = false;
            }
            else{
                if(index == curr->count()){
                    if(curr->next() == nullptr){
                        return curr;
                    }
                    else{
                        return curr->next();
                    }
                }
                else{
                index = index-curr->count();
                curr = curr->next();
                }
            }
        
    }
    return curr;

}

int MyChunkyList::newIndex(int index){
    bool hold= true;
    MyChunkyNode* curr = headPtr;
    while(hold){      
            if((curr->count()) > index || curr == nullptr){
                hold = false;
            }
            else{
                if(index == curr->count()){
                    if(curr->next() == nullptr){
                        return curr->count();
                    }
                    else{
                        return 0;
                    }
                }
                else{
                index = index-curr->count();
                curr = curr->next();
                }
            }
    }

    return index;
}

MyChunkyList::MyChunkyList(int chunksize){
    num = 0;
    max = chunksize;
    headPtr = nullptr;
    tailPtr = nullptr;
}

MyChunkyList::~MyChunkyList(){
    //delete headPtr;
    MyChunkyNode* temp = headPtr;
    MyChunkyNode* temp2;
    while(temp != nullptr){
        temp2 = temp->next();
        delete temp;
        temp = temp2;                      
    }  
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
            headPtr->newNode(max);
            headPtr->setItem(0, item);
            num++;
        }
        
        else{
            MyChunkyNode* curr = findNode(index);
            int newInd = newIndex(index);
            if(curr->count() == max){
                if(headPtr == curr && index == 0){
                    MyChunkyNode* newNode = new MyChunkyNode();
                    newNode->setMax(max);
                    newNode->setNext(curr);
                    newNode->setPrev(curr->prev());
                    curr->setPrev(newNode);
                    newNode->newNode(max);
                    newNode->setItem(0, item);
                    num++;
                    headPtr = newNode;
                }
                else if(tailPtr == curr && newInd == curr->count()){
                    MyChunkyNode* newNode = new MyChunkyNode();
                    newNode->setMax(max);
                    newNode->setNext(curr->next());
                    newNode->setPrev(curr);
                    curr->setNext(newNode);
                    newNode->newNode(max);
                    newNode->setItem(0, item);
                    tailPtr = newNode;
                    num++;
                }
                else{
                    int newInd = newIndex(index);
                    split2(curr, newInd, item);
                    num++;
                }
            }   
            else{
                int newInd = newIndex(index);
                curr->setItem(newInd, item);
                num++;
            }
        }
        
    }
}

std::string& MyChunkyList::lookup(int index){
    if(index < 0 || index >= num){
        throw std::out_of_range("index not found");
    }
    else{
        int temp = newIndex(index);
        std::string *item;
        MyChunkyNode* curr = findNode(index);
        item = curr->items();   
        return item[temp];
    }
}

void MyChunkyList::remove(int index){
    if(index < 0 || index >= num){
        throw std::out_of_range("index not found");
    }
    else{
        if(headPtr == nullptr){
            throw std::out_of_range("index not found");
        }
        else{
           MyChunkyNode* curr = findNode(index);
           int newInd = newIndex(index);
           curr->deleteItem(newInd);
            if(curr->isEmpty()){
                clearNode(curr);
           }
           else if(curr->count() < max){
                merge(curr);
           }

           num--;

        }
    }
}

MyChunkyNode* MyChunkyList::head() const{
    return headPtr;
}

MyChunkyNode* MyChunkyList::tail() const{
    return tailPtr;
}


