#include "WordList.h"
#include <iostream>
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
    cutoff++;
    cout << points.size() << endl;
    //Point tempPoint;
    for(size_t i=0; i<mWords.size(); i++){
        if(mWords.at(i).length() == points.size()){
            //get new score
        }
    }
    Heap *temp = new Heap(maxcount);
    



    return *temp;
}
