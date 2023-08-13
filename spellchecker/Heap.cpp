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
Heap percUp(Heap &list, size_t index){
    Heap::Entry curr = list.lookup(index);
    Heap newHeap(list);
    curr = newHeap.pop();
    return newHeap;
}


Heap::Heap(size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    mData = new Entry[capacity];
}

Heap::Heap(const Heap& other){
    
    //mData = other.lookup(0);                       //does it make a copy or does it point to the same array
    //cout << "does this" << endl;
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
    //cout << "not this " << endl;
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
    if(index < mCount){
        return mData[index];
    }
    else{
        throw std::out_of_range("out of range");
    }
    
}

Heap::Entry Heap::pop(){
    if(mCount > 0){
        Entry popped(mData[0]);
        Entry temp;
        Entry newtemp;
        newtemp.score = 0;
        bool biggest = true;
        mCount--;
        size_t index = 0;
        size_t newIndex;
        mData[0] = mData[mCount];
        mData[mCount] = newtemp;
        //while(biggest && ((index*2+2) < mCount-1)){
        while(biggest && index*2+2 < mCapacity){
            //cout << index*2+2 << endl;
            if(mData[index*2+2].score != 0 && mData[index*2+2].score < mData[index*2+1].score && mData[index*2+1].score < mData[index].score){
                newIndex = index*2+2;
                temp = mData[index];
                mData[index] = mData[newIndex];
                mData[newIndex] = temp;
                index = newIndex;
                //cout << "here" << endl;
            }
            else if(mData[index*2+1].score > 0 && mData[index*2+1].score < mData[index].score){
                //cout << mData[index*2+1].score << "ASDA" << endl;
                newIndex = index*2+1;
                temp = mData[index];
                mData[index] = mData[newIndex];
                mData[newIndex] = temp;
                index = newIndex;
                //cout << "here2" << endl;
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
        Entry temp;
        temp.value = value;
        temp.score = score;
        //mData[mCount-1] = temp;
        return temp;
    }
}

void Heap::push(const std::string& value, float score){    
    if(mCount >= mCapacity){
        throw std::overflow_error("overflow error");
    }
    else{
        Entry curr;
        Entry parent;
        int index;
        bool biggest = true;
        for(size_t i=0; i<mCapacity; i++){
            if(mData[i].score == 0){
                //mData[i] = *temp;
                mData[i].score = score;
                mData[i].value = value;
                index = i;
                i = mCapacity;
            }
        }
        mCount++;
        while(biggest){
            if((index-1)/2 >= 0){
                parent = mData[(index-1)/2];
                curr = mData[index];
                if(curr.score < parent.score){
                    //cout << curr.value << ": entered" << endl;
                    Entry temp = parent;
                    mData[(index-1)/2] = curr;
                    mData[index] = parent;
                    index = (index-1)/2;
                }
                else{
                    //cout << curr.value << ": entered" << endl;
                    biggest = false;
                }
            }
            else{
                biggest = false;
            }
        }
    }
    //print();
}

const Heap::Entry& Heap::top() const{
    if(mCount > 0){
        return mData[0];
    }
    else{
        throw std::underflow_error("underflow error");
    }
}

