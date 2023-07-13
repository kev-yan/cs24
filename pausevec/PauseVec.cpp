#include <iostream>
#include "PauseVec.h"


using namespace std;
/*
Node* PauseVec::findLast() const{
    Node *curr = list->head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    return curr;
}
*/
PauseVec::PauseVec(){
    count = 0;
    capacity = 1;
    arr = new int[1];
    
    //list = new LinkedList();
    //list->head = new Node();
    //list->head->data = 1;
}
PauseVec::~PauseVec(){
    delete[] arr;
   /*
    Node* currNode;
    Node *temp;
    
    currNode = list->head;
    while(currNode != nullptr){
        temp = currNode->next;
        delete currNode;
        currNode = temp;
    }
    delete list;
    */
}

int PauseVec::getCapacity() const{
    return capacity;
}
size_t PauseVec::getCount() const{
    return count;
}
void PauseVec::setCount(size_t num){
    count = num;
}
void PauseVec::push(int num){
    int tempCount = int(count);
    if(count == capacity){
        int* newArr = new int[count*2];
        for(int i=0; i<count; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        capacity = capacity*2;
    }
    count++;
    arr[count] = num;
    
    /*
    Node* temp = new Node();
    temp->data = num;
    if(count == capacity){
        for(int i=0; i<capacity; i++){
            Node *newNode = new Node();
            list->tail->next = newNode;   
            list->tail = newNode;
        }
        capacity = capacity*2;
    }
    list->tail->next = temp;
    list->tail = temp;
    count++;
    */

}
int PauseVec::lookup(int index){
    /*
    Node* curr;
    int i=0;
    while(i != index){
        if(curr == nullptr){
            throw std::out_of_range("index not found");
        }
        else{
            curr = curr->next;
            i++;
        }
    }
    return curr->data;
    */
}
void PauseVec::mutate(int index, int value){
}

void PauseVec::remove(int index){
    /*
    Node* curr = list->head;
    int i=0;
    while(i != (index-1)){
        if(curr == nullptr){
            throw std::out_of_range("index not found");
        }
        else{
            curr = curr->next;
        }
    }
    Node *after = curr->next->next;
    delete curr->next;
    curr->next = after;
    if(capacity % 2 == 0){
        // cut in half and move everything
        //change capacity to n/2
    }
    count = count - 1;
    */


    
}


int main(){
    return 0;
}
