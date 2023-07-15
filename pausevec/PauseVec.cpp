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
        if(count > static_cast<int>(num)){
            //cout << "stops"<< endl;
            count = static_cast<int>(temp2);
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
void PauseVec::print1(){
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
    if(index >= num){
        throw std::out_of_range("index not found");
    }
    else if(arr[index] != -1){
        return arr[index];
    }

    else{
        smash();
        return arr[index];
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


int PauseVec::remove(size_t index){
    int removed = -1;
    if(index > num){
        throw std::out_of_range("index not found");
    }
    else{
        if(arr[index] == -1){
            smash();
            /*
            if(arr[index] != -1){
                arr[index] = -1;

                num--;
            }
            */
        }
        //else{
        removed = arr[index];
        arr[index] = -1;
        num--;
       // }
    }
    if(num <= cap/4){
        smash();
    }
    return removed;
}
void PauseVec::remove_val(int value){
    //bool seen = false;
    int count;
    for(size_t i=0; i<cap; i++){
        if(arr[i] == value){
            arr[i] = -1;
            count++;
            num--;
        }
        /*
        else if(count >= static_cast<int>(num)){
            i=cap;
        }
        */
        //else if(arr[i] == -1){
          //  seen = true;
        //}
    }
    /*
    if(seen){
        smash();
    }
    */
    if(num <= cap/4){
        smash();
    }
}

/*
int main(){
    PauseVec *temp = new PauseVec();

   temp->push(1);
   temp->push(2);
   temp->push(3);
   temp->push(4);
   temp->remove_val(3);
   temp->remove_val(1);
   temp->print();

    return 0;
}

*/








