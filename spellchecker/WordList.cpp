#include "WordList.h"
#include <iostream>
using namespace std;


WordList::WordList(std::istream& stream){
    string temp;
    while(stream >> temp){
        mWords.push_back(temp);
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    cout << points.at(0).x << " " << maxcount << cutoff << endl;
    Heap *temp = new Heap(maxcount);
    return *temp;
}
