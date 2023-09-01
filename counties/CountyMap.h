#ifndef COUNTYMAP_H
#define COUNTYMAP_H

#include <vector>
#include <map>
#include "County.h"

using namespace std;

class CountyMap {
	private:
		//storage requirement: O(e), e = number of edges between counties

		//add private variables here
		vector<County> counties;
		
		//std::map<std::string, County> counties;
		vector<LinkedList *> adjList;

		void addNode(LinkedList *ll, Node *newNode);
		//bool findNode(LinkedList list, int countyID);		
	public:
		//constructor
		//performance: O(n^2), n = number of counties
		CountyMap(vector<County> counties, vector<vector<bool> > adjacencyMatrix);

		CountyMap(const CountyMap& other) ;

		~CountyMap();

		//performance: O(1)
		County getCounty(int countyID);

		//performance: O(1)
		bool countyAdjacency(int countyID1, int countyID2);

		//performance: O(1)
		int getNumCounties();
		
		//performance: O(n), n = number of counties
		vector<int> getAdjacentCounties(int countyID);

		//performance: O(n), n = number of counties in the itinerary
		bool checkValidItinerary(vector<int> itinerary);

		void printMatrix();
		//void setEdge(int first, int second);

};

#endif