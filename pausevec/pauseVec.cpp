#include <iostream>
#include <vector>
#include "PauseVec.h"

using namespace std;

PauseVec::PauseVec(){
    count = 0;
    capacity = 1;
    list = new LinkedList();
    list->head = new Node();
    list->head->data = 1;
}
PauseVec::~PauseVec(){
    Node* currNode;
    Node *temp;
    currNode = list->head;
    while(currNode != nullptr){
        temp = currNode->next;
        delete currNode;
        currNode = temp;
    }
    delete list;
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
    Node* currNode;
    Node* temp = new Node();
    temp->data = num;
    currNode = list->head;
    while(currNode->next != nullptr){
        currNode = currNode->next;
    }
    currNode->next = temp;
    list->tail = temp;

}
int PauseVec::lookup(int index){
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
}


int main(){
    return 0;
}
