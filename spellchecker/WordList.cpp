#include "WordList.h"
#include <iostream>
#include <cmath>
using namespace std;


WordList::WordList(std::istream& stream){
    string temp;
    while(stream >> temp){
        mWords.push_back(temp);
    }
    //cout << "length: " << mWords.size() << endl;
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap *temp = new Heap(maxcount);
    vector<string> words;
    for(size_t i=0; i<mWords.size(); i++){
        if(mWords.at(i).length() == points.size()){ 
            string word = mWords.at(i);
            float newScore = 0;
            float distance;
            float size = points.size();
            bool lower = true;
            for(size_t j=0; j<words.size();j++){
                if(words.at(j) == word){
                    lower = false;
                }
            }
            for(size_t j=0; j<size; j++){
                if(!islower(word[j])){
                    lower = false;
                }
                int temp2 = word[j]-97; 
                float inX = points.at(j).x;
                float inY = points.at(j).y;
                float wordX = QWERTY[temp2].x;
                float wordY = QWERTY[temp2].y;
                distance = sqrt(pow(inX-wordX, 2) + pow(inY-wordY, 2));
                distance = 1/((10*pow(distance,2))+1);
                newScore += distance;
            }
            newScore = newScore / size;
            if(temp->count() < maxcount && newScore >= cutoff && lower){
                //temp->push(word, newScore);
                temp->push(word, newScore);
                words.push_back(word);
            }
            else if(lower && newScore >= cutoff && temp->lookup(0).score < newScore){
                //temp->pushpop(word, newScore);
                const Heap::Entry newTemp = temp->pop();
                temp->push(word, newScore);
                words.push_back(word);
            }
        }
    }
    Heap ret = *temp;
    delete temp;
    return ret;
}
