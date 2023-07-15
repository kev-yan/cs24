#include <iostream>
#include "PauseVec.h"

using namespace std;
PauseVec* create_pausevec(){
    return new PauseVec;
}
int* PauseVec::fill(int index){
    int* temp = new int[index];
    for(int i=0; i<index; i++){
        temp[i] = -1;
    }
    return temp;

}

void PauseVec::smash(){
    int *temp;
    int temp2 = cap;
    if(cap/4 < num || cap < 2){
       //temp = new int[cap];
        temp = fill(cap);
    }
    else{
        temp = fill(cap/2);
        cap = cap/2;
        //temp = new int[cap/2];
    }
    int count = 0;
    for(int i=0; i<static_cast<int>(temp2); i++){
        if(arr[i] != -1){
            temp[count] = arr[i];
            count++;
        }
}
    delete[] arr;
    arr = temp;
}
void PauseVec::print(){
    for(int i=0; i<static_cast<int>(cap); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
PauseVec::PauseVec(){
    num = 0;
    cap = 1;
    arr = fill(1);
}
PauseVec::~PauseVec(){
    delete[] arr;
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
        int *newArr = fill(cap*2);
        //int* newArr = new int[cap*2];
        for(int i=0; i<static_cast<int>(num); i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        cap = cap*2;
        arr[num] = count;
    }
    
    else{
        if(arr[cap-1] != -1){
            arr[cap-1] = count;
        }
        else{
            arr[cap-1] = count;
            smash();
        }
    }
    if(count != -1){
        num++;
    }



}
int PauseVec::lookup(unsigned long int index){
    if(arr[index] != -1 && index < cap){
        return arr[index];
    }
    else{
        throw std::out_of_range("index not found");
    }
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
    if(index >= num){
        throw std::out_of_range("index not found");
    }
    else{
        if(arr[index] == -1){

        }

    }
}
void PauseVec::remove_val(int value){

}

/*
int main(){
    PauseVec *temp = new PauseVec();

    temp->push(1);
    temp->print();
    temp->push(1);
    temp->print();
    temp->push(1);
    temp->print();
    temp->push(1);
    temp->print();
    temp->push(1);
    temp->print();
    temp->push(1);
    temp->print();
    temp->push(1);
    temp->print();

    

    return 0;
}
*/









