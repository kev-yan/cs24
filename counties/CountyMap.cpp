#include "CountyMap.h"
#include "County.h"
#include <vector>
#include <iostream>

using namespace std;


void CountyMap::printMatrix(){
    for(int i=0; i<adjMatrix.size();i++){
        for(int j=0; i<adjMatrix.at(i).size(); i++){
            cout << adjMatrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

CountyMap::CountyMap(vector<County> counties, vector<vector<bool> > adjMatrix) {
    this->counties = counties;
    this->adjMatrix = adjMatrix;
    // TODO
}

CountyMap::CountyMap(const CountyMap& other) {
    // TODO
}

CountyMap::~CountyMap() {
    // TODO
}

County CountyMap::getCounty(int index) {
    return counties.at(index);
}

int CountyMap::getNumCounties() {
    return counties.size();
}

bool CountyMap::countyAdjacency(int index1, int index2) {
    
    // TODO
}

bool CountyMap::checkValidItinerary(vector<int> itinerary) {
    //go through each countyId in itenerary and check if there are edges between each county
    // TODO
}

vector<int> CountyMap::getAdjacentCounties(int index) {
    // TODO
}

void CountyMap::setEdge(int first, int second){
    adjMatrix.at(first).at(second) = true;
}
// helper functions may follow