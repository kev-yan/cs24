#include "MyChunkyList.h"
#include <string>
#include <iostream>
using namespace std;

void MyChunkyList::print(){
    MyChunkyNode* temp = headPtr;
    cout << "listNum: " << num << endl;
    int i = 0;
    while(temp != nullptr){
        cout << "---------------NODE " << i << "---------------" << endl;
        temp->print();
        temp = temp->next();
        i++;
    }

}
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
        else{
            return curr;
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
    newNode->setPrev(node);
    node->setNext(newNode);
    newNode->next()->setPrev(newNode);
    if(max%2 == 0){
        for(int i=0;i<max/2;i++){
            newNode->setItem(i, node->getItem(i+max/2));
            //node->deleteItem(i+max/2);
        }
        for(int i=0; i<max/2;i++){
            node->deleteItem(max/2);
        }
    }
    else{
        for(int i=(max-(max/2));i<max;i++){
            //cout << "i: " << i << endl;
            newNode->setItem(i-(max-(max/2)), node->getItem(i));
            //node->deleteItem(i);
        }
        for(int i=(max-(max/2));i<max;i++){
            node->deleteItem(max-(max/2));
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
    int temp = 0;
    bool hold= true;
    MyChunkyNode* curr = headPtr;
    while(hold){
        if(curr != nullptr){
            if((temp+curr->count()) >= index || curr != nullptr){
                hold = false;
            }
            else{
                temp = temp+curr->count();
                curr = curr->next();
            }
        }
        else{
            hold = false;
        }
    }
    return curr;

}

int MyChunkyList::newIndex(int index){
    int temp = 0;
    bool hold= true;
    MyChunkyNode* curr = headPtr;
    while(hold){
        if(curr != nullptr){
            if((temp+curr->count()) >= index || curr == nullptr){
                hold = false;
            }
            else{
                temp = temp+curr->count();
                curr = curr->next();
            }
        }
        else{
            hold = false;
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
    delete headPtr;
    while(headPtr != nullptr){
        MyChunkyNode* temp = headPtr->next();                      //FIX THIS
        delete headPtr;
        headPtr = temp;
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
    int maxNum = ((num-1)/max+1)*max;
    //cout << maxNum << endl;
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
            //std::cout << "beginning" << std::endl;
            num++;
        }
        
        else{
            MyChunkyNode* curr = findNode(index);
            int newInd = newIndex(index);
            if(curr->count() == max){
                if(headPtr == curr && index == 0){
                    MyChunkyNode* newNode = new MyChunkyNode();
                    if(curr->next() != nullptr){
                        curr->next()->setPrev(newNode);
                    }
                    newNode->setMax(max);
                    newNode->setNext(curr->next());
                    newNode->setPrev(curr);
                    curr->setNext(newNode);
                    newNode->newNode(max);
                    newNode->setItem(0, item);
                    num++;
                }
                else if(tailPtr == curr && index == maxNum){
                    MyChunkyNode* newNode = new MyChunkyNode();
                    newNode->setMax(max);
                    newNode->setNext(curr->next());
                    newNode->setPrev(curr);
                    curr->setNext(newNode);
                    newNode->newNode(max);
                    newNode->setItem(0, item);
                    num++;
                }
                else{
                    //urr = findNode(index-1);
                    split(curr);
                    //newInd = newInd+(max/2);
                    if(max%2 != 0){
                        curr = curr->next();
                    }
                    curr->setItem(max/2, item);
                    //curr->next()->print();
                    num++;
                }
            }   
            /*
            else if(curr == nullptr){
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
            */
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
        int temp = newIndex(index);
        std::string *item;
        MyChunkyNode* curr = findNode(index);
        item = curr->items();   
        return item[temp];
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
           // cout << "need to fix";
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
    MyChunkyList* test = new MyChunkyList(5);
    MyChunkyNode* curr;
    //delete test;
    
    test->insert(0, "A");
    test->insert(1, "B");
    test->insert(2, "C"); 
    test->insert(3, "D");
    test->insert(3, "asd");
    test->insert(1, "asdasd");
    test->head()->deleteItem(2);
    //test->tail()->deleteItem(1);
    //test->merge(test->head());
    //test->insert(0, "asd");
    //test->insert(4, "asd");
    //test->head()->deleteItem(3);
    //test->insert(4, "xcv");
    //test->insert(4, "A");
    //test->insert(2, "a");

    test->print();

    
    //curr = test->head();
    //curr->print();
    //test->tail()->print();
   // test->insert(4, "a");
    //test->insert(4, "a");
    //test->insert(4, "a");
    //curr->next()->print();
    //cout << test->head() << " " << test->tail() << endl;
   // curr->print();
    //currTail = test->tail();
    //currTail->print();
   // currTail = test->merge(currTail);
    //(test->tail())->print();
    //cout << test->tail() << endl;
   // cout << curr;
}

*/
