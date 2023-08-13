#include "WordList.h"
#include <iostream>
#include <cmath>
using namespace std;


WordList::WordList(std::istream& stream){
    string temp;
    while(stream >> temp){
        mWords.push_back(temp);
    }
    cout << "length: " << mWords.size() << endl;
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    //cout << "x and y: " << points.at(0).x << " " << maxcount << cutoff << endl;
    //cout << "cutoff: " << cutoff << points.at(0).x << endl;
    Heap *temp = new Heap(maxcount);
    //Point tempPoint;
    
    for(size_t i=0; i<mWords.size(); i++){
        if(mWords.at(i).length() == points.size()){
            string word = mWords.at(i);
            float newScore = 0;
            float distance;
            bool lower = true;
            for(size_t j=0; j<points.size(); j++){
                if(!islower(word[j])){
                    lower = false;
                }
                int temp = word[j]-97;
                float inX = points.at(j).x;
                float inY = points.at(j).y;
                float wordX = QWERTY[temp].x;
                float wordY = QWERTY[temp].y;
                distance = sqrt((inX-wordX)*(inX-wordX) + (inY-wordY)*(inY-wordY));
                distance = 1/(10*pow(distance,2)+1);
                newScore += distance;
            }
            newScore = newScore / points.size();
            if(temp->count() < maxcount && newScore > cutoff && lower){
                temp->push(word, newScore);
            }
            else if(lower && newScore > cutoff){
                temp->pushpop(word, newScore);
            }
        }
    }
    //cout << temp->count() << endl;
    return *temp;
}
