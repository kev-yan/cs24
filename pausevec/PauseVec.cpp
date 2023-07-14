#include <iostream>
#include "PauseVec.h"


using namespace std;
void PauseVec::smash(){
    int *temp;
    if(capacity/4 < (static_cast<int>(count))){
        temp = new int[count];
    }
    else{
        temp = new int[count/2];
        capacity = capacity/2;
    }
    int num = 0;
    for(int i=0; i<capacity; i++){
        if(arr[i] != -1){
            temp[num] = arr[i];
            num++;
        }
}
    int *hold = arr;
    arr = temp;
    delete[] hold;
}
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
    int tempCount = static_cast<int>(count);
    if(tempCount == capacity){
        int* newArr = new int[tempCount*2];
        for(int i=0; i<tempCount; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        capacity = capacity*2;
    }
    if(num != -1){
        count++;
    }

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
int PauseVec::lookup(unsigned long int index){
    if(arr[index] != -1 && index <= capacity){
        return arr[index];
    }
    else{
        throw std::out_of_range("index not found");
    }
    
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
void PauseVec::mutate(size_t index, int value){
    if(index <= capacity){
        arr[index] = value;
    }
    else{
        throw std::out_of_range("index not found");
    }
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
    PauseVec *temp = new PauseVec();
    temp->push(1);
    temp->push(2);
    temp->push(3);
    temp->push(-1);
 
    temp->smash();
    cout << temp->getCapacity() << endl;
    cout << temp->getCount() << endl;
    cout << temp->lookup(2) << endl;
    temp->mutate(2, 5);
    cout << temp->lookup(2) << endl;
    
    return 0;
}
