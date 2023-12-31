#include "Heap.h"
#include <iostream>

using namespace std;

/*
void Heap::print(){
    for(size_t i=0; i<mCount; i++){
        cout << i << ": " << mData[i].value << ", " << mData[i].score << endl;
    }
    cout << "-------------------" << endl;
}
*/


Heap::Heap(size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    //Entry temp[capacity];
    //mData[capacity];
    mData = new Entry[capacity];
}

Heap::Heap(const Heap& other){
    mData = new Entry[other.capacity()];
    for(size_t i=0;i<other.count();i++){
        Entry temp;
        std::string newVal = (other.lookup(i)).value;
        float newScore = (other.lookup(i)).score;
        temp.value = newVal;
        temp.score = newScore;
        mData[i] = temp;
    }
    mCount = other.count();
    mCapacity = other.capacity();
    
}


Heap::Heap(Heap&& other){
    //cout << "entereed" << endl;
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
    if(index < mCount){
        return mData[index];
    }
    else{
        throw std::out_of_range("out of range");
    }
    
}

Heap::Entry Heap::pop(){
    if(mCount > 0){
        Entry popped = mData[0];
        Entry temp;
        Entry newtemp;
        bool biggest = true;
        mCount--;
        size_t index = 0;
        size_t newIndex;
        mData[0] = mData[mCount];
        mData[mCount] = newtemp;
        while(biggest && index*2+2 < mCapacity){
            if(index*2+2 < mCount && mData[index*2+2].score < mData[index*2+1].score && mData[index*2+1].score < mData[index].score){
                newIndex = index*2+2;
                temp = mData[index];
                mData[index] = mData[newIndex];
                mData[newIndex] = temp;
                index = newIndex;
            }
            else if(index*2+1 < mCount && mData[index*2+1].score < mData[index].score){
                newIndex = index*2+1;
                temp = mData[index];
                mData[index] = mData[newIndex];
                mData[newIndex] = temp;
                index = newIndex;
            }
            else{
                biggest = false;
            }
        }
        return popped;
    }
    else{
        throw std::underflow_error("underflow error");
    }
    
}


Heap::Entry Heap::pushpop(const std::string& value, float score){
    if(mCount == 0){
        throw std::underflow_error("underflow error");
    }
    else{
        Entry popped = mData[0];
        Entry temp;
        Entry newTemp;
        temp.value = value;
        temp.score = score;
        size_t index = 0;
        size_t newIndex;
        bool biggest = true;
        mData[0] = temp;
        while(biggest && index*2+2 < mCapacity){
            if(index*2+2 < mCount && mData[index*2+2].score < mData[index*2+1].score && mData[index*2+1].score < mData[index].score){
                newIndex = index*2+2;
                newTemp = mData[index];
                mData[index] = mData[newIndex];
                mData[newIndex] = newTemp;
                index = newIndex;
            }
            else if(index*2+1 < mCount && mData[index*2+1].score < mData[index].score){
                newIndex = index*2+1;
                newTemp = mData[index];
                mData[index] = mData[newIndex];
                mData[newIndex] = newTemp;
                index = newIndex;
            }
            else{
                biggest = false;
            }
        }

        return popped;
    }
}

void Heap::push(const std::string& value, float score){    
    if(mCount >= mCapacity){
        throw std::overflow_error("overflow error");
    }
    else{
        Entry curr;
        Entry parent;
        int index = mCount;
        bool biggest = true;
        mData[mCount].score = score;
        mData[mCount].value = value;
        mCount++;
        while(biggest){
            if((index-1)/2 >= 0){
                parent = mData[(index-1)/2];
                curr = mData[index];
                if(curr.score < parent.score){
                    Entry temp = parent;
                    mData[(index-1)/2] = curr;
                    mData[index] = parent;
                    index = (index-1)/2;
                }
                else{
                    biggest = false;
                }
            }
            else{
                biggest = false;
            }
        }
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

