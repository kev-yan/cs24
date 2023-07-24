#include "MyChunkyList.h"
#include <string>
#include <iostream>
using namespace std;

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
MyChunkyNode* MyChunkyList::merge(MyChunkyNode* curr){ // might have to be MyChunkyNode* or be in the MyChunkyList
    if(curr->count() <= (max/2)){
        if(curr->prev() != nullptr && (curr->prev())->count() <= max/2){
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
            delete curr;
            delete previous;
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
            if(curr->prev() != nullptr){
                curr->prev()->setNext(newNode);
            }
            if(after->next() != nullptr){
                after->next()->setPrev(newNode);
            }
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
    if(newNode->next() != nullptr){
        newNode->next()->setPrev(newNode);
    }
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

void MyChunkyList::split2(MyChunkyNode* node, int index, std::string item){
    //MyChunkyNode* node = node2;
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
    //HERE
    else{
        if(index <= max/2){
            for(int i=max/2; i<max; i++){
                newNode->setItem(i-max/2, node->getItem(i));

            }
            for(int i=max/2; i<max; i++){
                node->deleteItem(max/2);
            }
            //node->print();
            //cout << "here" << endl;
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
        /*
        for(int i=(max-(max/2));i<max;i++){
            //cout << "i: " << i << endl;
            newNode->setItem(i-(max-(max/2)), node->getItem(i));
            //node->deleteItem(i);
        }
        for(int i=(max-(max/2));i<max;i++){
            node->deleteItem(max-(max/2));
        }
        */
    }
    /*
    cout << "HEREHERHER " << newNode << endl;
    newNode->print();
    cout << node->next()  << endl;
    cout << node->prev() << endl;
    cout << "here" << endl;
    cout << newNode << endl;
    cout << newNode->count() << endl;
    cout << "new" << endl;
    cout << newNode->prev() << endl;
    */
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
   // int temp = 0;
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
        
        /*
        else{
            hold = false;
        }
        */
    }
    return curr;

}

int MyChunkyList::newIndex(int index){
    //int temp = 0;
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
            /*
        else{
            hold = false;
        }
        */
    }
    /*
    while(hold){
        if(curr != nullptr){
            if((temp+curr->count()) >= index || curr == nullptr){
                hold = false;
            }
            else{
                temp = temp+curr->count();
                
                if(temp != index){
                    curr = curr->next();
                }
                else{
                    hold = false;
                }
                
            }
        }
        else{
            hold = false;
        }
        */
    
    return index;
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
            //cout << index << " " <<newInd << " " << curr << endl;
            //cout << maxNum << endl;
            //cout << "current curr: " << curr << endl;
            if(curr->count() == max){
                if(headPtr == curr && index == 0){
                    //int newInd = newIndex(index);
                    //cout << "entered" << endl;
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
                else if(tailPtr == curr && index == maxNum){
                    //int newInd = newIndex(index);
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
                //curr->print();
                int newInd = newIndex(index);
                curr->setItem(newInd, item);
                num++;
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
           MyChunkyNode* curr = findNode(index);
           int newInd = newIndex(index);
           curr->deleteItem(newInd);
           if(curr->count() <= max/2){
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


/*
int main(){
    //std::cout << "test";
    MyChunkyList* test = new MyChunkyList(4);
    //MyChunkyNode* curr;
    //delete test;
    test->insert(0, "1");
    test->insert(0, "2");
    test->insert(0, "3");
    test->insert(0, "4");
    //test->print();
    test->insert(4, "test");
    test->insert(4, "test");
    test->insert(4, "test");
    test->insert(4, "test");
    test->insert(8, "a");
    test->insert(8, "tet");
    test->insert(8, "st");
    test->insert(8, "tt");

    test->remove(5);
    test->remove(5);
    test->remove(0);
test->print();
    test->remove(0);
test->print();
    //test->remove(4);





    
    //test->print();

    //test->print();
   // test->print();

    

    cout << endl << endl << endl;
    test->insert(2, "TESTa");
    test->insert(2, "TESTb");
    test->insert(2, "TESTc");
    test->insert(2, "TESTd");
    test->insert(5, "TESTe");
    //test->print();
    test->insert(5, "TESTf");
    test->insert(8, "HOLD ON");
    test->insert(8, "TESTg");
    test->insert(5, "BREAK");
    //test->printBack();
    test->print();
    //cout << test->lookup(9);
    //test->remove(9);
    cout << endl << endl << endl;
    //test->print();
    
 
}

*/