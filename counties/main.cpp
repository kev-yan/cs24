#include <iostream>
#include "CountyMap.h"

using namespace std;

int main(){
    vector<bool> first = {0, 1, 1, 0};
    vector<bool> second = {1, 0, 1, 1};
    vector<bool> third = {1, 1, 0, 1};
    vector<bool> fourth = {0, 1, 1, 0};
    vector<int> test = {0, 3, 1, 2};
    
    County one;
    one.population = 1;
    one.name = "one";
    County two;
    two.population = 2;
    two.name = "two";
    County three;
    three.population = 3;
    three.name = "three";
    County four;
    four.population = 4;
    four.name = "four";
    vector<County> counties;
    counties.push_back(one);
    counties.push_back(two);
    counties.push_back(three);
    counties.push_back(four);

    vector<vector<bool> > adjMatrix;
    adjMatrix.push_back(first);
    adjMatrix.push_back(second);
    adjMatrix.push_back(third);
    adjMatrix.push_back(fourth);

    CountyMap *countyMap = new CountyMap(counties, adjMatrix);
    //cout << "compiled" << endl;
    //countyMap->printMatrix();
    County temp = countyMap->getCounty(2);
    
    //cout << countyMap->getNumCounties() << endl;
    //cout << temp.population << endl;

    //cout << countyMap->countyAdjacency(0,1) << endl;
    vector<int> test1;
    test1 = countyMap->getAdjacentCounties(1);
    for(size_t i=0; i<test1.size();i++){
        cout << test1.at(i) << " ";
    }
    cout << endl;
    cout << countyMap->checkValidItinerary(test) << endl;
    

}