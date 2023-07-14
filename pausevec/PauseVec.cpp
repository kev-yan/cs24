#include <iostream>
#include "PauseVec.h"


using namespace std;
void PauseVec::smash(){
    int *temp;
    if(cap/4 < num){
        temp = new int[num];
    }
    else{
        temp = new int[num/2];
        cap = cap/2;
    }
    int count = 0;
    for(int i=0; i<static_cast<int>(cap); i++){
        if(arr[i] != -1){
            temp[count] = arr[i];
            count++;
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
    num = 0;
    cap = 1;
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

int PauseVec::capacity() const{
    return cap;
}
size_t PauseVec::count() const{
    return num;
}
void PauseVec::setCount(size_t count){
    num = count;
}
void PauseVec::push(int count){
    if(num == cap){
        int* newArr = new int[num];
        for(int i=0; i<static_cast<int>(num); i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        cap = cap*2;
    }
    if(count != -1){
        num++;
    }

    arr[num] = count;
    

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
    if(arr[index] != -1 && index < cap){
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
    if(index < cap){
        arr[index] = value;
    }
    else{
        throw std::out_of_range("index not found");
    }
}


void PauseVec::remove(size_t index){
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
void PauseVec::remove_val(int value){
    
}


int main(){
    PauseVec *temp = new PauseVec();
    temp->push(1);
    temp->push(2);
    temp->push(3);
    temp->push(-1);
 
    temp->smash();
    cout << temp->capacity() << endl;
    cout << temp->count() << endl;
    cout << temp->lookup(2) << endl;
    temp->mutate(2, 5);
    cout << temp->lookup(2) << endl;

    return 0;
}
