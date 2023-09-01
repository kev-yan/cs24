#include "CountyMap.h"
#include "County.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

void CountyMap::addNode(LinkedList *ll, Node* newNode){
    if(ll->head != ll->tail || ll->head != nullptr){
        ll->tail->next = newNode;
        ll->tail = ll->tail->next;
    }
    else{
        ll->head = newNode;
        ll->tail = newNode;
    }
}
/*
bool CountyMap::findNode(LinkedList list, int countyID){
    Node *curr = list.head;
    while(curr != nullptr){
        if(curr->county.name == counties[countyID]){
            return true;
        }
        else{
            curr = curr->next;
        }
    }
    return false;
}
*/
void CountyMap::printMatrix(){
    for(size_t i=0; i<adjList.size();i++){
        LinkedList *list;
        list = adjList.at(i);
        Node* curr = list->head;
        cout << i+1 << ": ";
        while(curr != nullptr){
            cout << curr->countyID << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
}

CountyMap::CountyMap(vector<County> counties, vector<vector<bool> > adjMatrix) {
    this->counties = counties;
    for(size_t i=0; i<adjMatrix.size(); i++){
        //Node* first = new Node();
        County currCounty = counties.at(i);
        LinkedList *adjLL = new LinkedList();
        //first->countyID = static_cast<int>(i);
        //addNode(adjLL, first);
        //this->counties[currCounty.name] = counties.at(i);
        //cout << i << ": ";
        for(size_t j=0; j<adjMatrix.at(i).size(); j++){
            //cout << adjMatrix.at(i).at(j) << " ";
    
            if(adjMatrix.at(i).at(j) == true){
                //cout << j << " ";
                Node* newNode = new Node();
                newNode->countyID = static_cast<int>(j);
                addNode(adjLL, newNode);
                adjMatrix.at(j).at(i) = false;
            }
        }
        //cout << endl;
        adjList.push_back(adjLL);
    }
    //cout << adjList.at(0).head->countyID << endl;
}

CountyMap::CountyMap(const CountyMap& other) {
    counties = other.counties;
    adjList = other.adjList;
}

CountyMap::~CountyMap() {
    for(LinkedList *list : adjList){
        Node* temp = list->head;
        Node* curr = list->head;
        while(temp != nullptr){
            temp = curr->next;
            delete curr;
            curr = curr->next;
        }
    }
}

County CountyMap::getCounty(int countyID) { //countyid is index
    return counties.at(countyID);
}

int CountyMap::getNumCounties() {
    return counties.size();
}

bool CountyMap::countyAdjacency(int countyID1, int countyID2){
    LinkedList *list = adjList.at(countyID1);
    Node* curr = list->head;
    while(curr != nullptr){
        //cout << "countyID: " << curr->countyID << endl;
        if(curr->countyID == countyID2){
            return true;
        }
        curr = curr->next;
    }
    list = adjList.at(countyID2);
    curr = list->head;
    while(curr != nullptr){
        //cout << "countyID: " << curr->countyID << endl;
        if(curr->countyID == countyID1){
            return true;
        }
        curr = curr->next;
    }
    return false;
    //how is this O(1)

}

bool CountyMap::checkValidItinerary(vector<int> itinerary) {

    for(size_t i=1; i<itinerary.size(); i++){
        if(this->countyAdjacency(itinerary.at(static_cast<int>(i-1)), itinerary.at(static_cast<int>(i))) == false){
            return false;
        }
    }
    return true;
    //go through each countyId in itenerary and check if there are edges between each county
    // TODO
}

vector<int> CountyMap::getAdjacentCounties(int index) {
    vector<int> newCounties;
    LinkedList *list = adjList.at(index);
    Node *curr = list->head;
    while(curr != nullptr){
        newCounties.push_back(curr->countyID);
    }
    return newCounties;
    // TODO
}

/*
void CountyMap::setEdge(int first, int second){
    adjMatrix.at(first).at(second) = true;
}
*/

// helper functions may follow