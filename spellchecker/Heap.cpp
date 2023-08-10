#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap(size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    mData = nullptr;
}

Heap::Heap(const Heap& other){
    //mData = other.lookup(0);                       //does it make a copy or does it point to the same array
    mData = new Entry[other.count()];
    for(int i=0;i<other.count();i++){
        Entry* temp = new Entry();
        std::string newVal = (other.lookup(i)).value;
        float newScore = (other.lookup(i)).score;
        temp->value = newVal;
        temp->score = newScore;
        mData[i] = temp;
    }
    mCount = other.count();
    mCapacity = other.capacity();
}

Heap::Heap(Heap&& other){
    mData = other.lookup(0);                              //same thing as above
    mCount = 0;
    mCapacity = 0;
}
Heap::~Heap(){
    delete[] mData;
}

size_t Heap::capacity() const{
    return mCapacity;
}

size_t Heap::count() const{
    return mCount;
}

const Entry& Heap::lookup(size_t index) const{
    if(mData[index] != nullptr){
        return mData[index];
    }
    else{
        throw std::out_of_range("out of range");
    }
}

Entry Heap::pop(){
    delete mData[mCount-1];
    mCount = mCount-1;
}

Entry Heap::pushpop(const std::string& value, float score){
    if(mCount == 0){
        throw std::underflow_error("underflow error");
    }
    else{
        cout << value << " " << score << endl;
    }
}

void Heap::push(const std::string& value, float score){
    if(mCount == mCapacity){
        throw std::overflow_error("overflow error");
    }
    else{
        cout << value << " " << score << endl;
    }
}

const Entry& top() const{
    if(count > 0){
        return mData[count-1];
    }
    else{
        throw std::underflow_error("underflow error");
    }
}