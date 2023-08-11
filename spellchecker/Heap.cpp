#include "Heap.h"
#include <iostream>

using namespace std;

void percUp(Heap list, size_t index){
    Entry curr = list.lookup(index);
    if((index-1)/2 >= 0){
        Entry parent = list.lookup((index-1)/2);
        if(parent.score > curr.score){
            Entry temp = parent;
            list.pop((index-1)/2);
            list.push()
        }
    }
}

Heap::Heap(size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    mData = new Entry[capacity];
}

Heap::Heap(const Heap& other){
    
    //mData = other.lookup(0);                       //does it make a copy or does it point to the same array
    
    mData = new Entry[other.count()];
    for(size_t i=0;i<other.count();i++){
        Entry* temp = new Entry();
        std::string newVal = (other.lookup(i)).value;
        float newScore = (other.lookup(i)).score;
        temp->value = newVal;
        temp->score = newScore;
        mData[i] = *temp;
    }
    mCount = other.count();
    mCapacity = other.capacity();
    
}


Heap::Heap(Heap&& other){
    /*
    mData = new Entry[other.count()];
    for(size_t i=0;i<other.count();i++){
        Entry* temp = new Entry();
        std::string newVal = (other.lookup(i)).value;
        float newScore = (other.lookup(i)).score;
        temp->value = newVal;
        temp->score = newScore;
        mData[i] = *temp;
    }
    //mData = other.lookup(0);                              //same thing as above
    */
    mData = other.mData;
    other.mData = nullptr;
    mCount = other.count();
    mCapacity = other.capacity();
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

const Heap::Entry& Heap::lookup(size_t index) const{
    if(index < mCount && index >= 0){
        return mData[index];
    }
    else{
        throw std::out_of_range("out of range");
    }
    
}

Heap::Entry Heap::pop(){
    Entry temp;
    Entry popped = mData[mCount-1];
    mData[mCount-1] = temp;
    mCount = mCount-1;
    return popped;
    
}

Heap::Entry Heap::pushpop(const std::string& value, float score){
    if(mCount == 0){
        throw std::underflow_error("underflow error");
    }
    else{
        Entry *temp = new Entry();
        temp->value = value;
        temp->score = score;
        //mData[mCount-1] = temp;
        return *temp;
    }
}

void Heap::push(const std::string& value, float score){    
    if(mCount >= mCapacity){
        throw std::overflow_error("overflow error");
    }
    else{
        Entry *temp = new Entry();
        temp->value = value;
        temp->score = score;
        mData[mCount] = *temp;
        mCount++;
    }
}

const Heap::Entry& Heap::top() const{
    if(mCount > 0){
        return mData[0];
    }
    else{
        throw std::underflow_error("underflow error");
    }
}

