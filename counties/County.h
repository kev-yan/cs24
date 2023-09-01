#ifndef COUNTY_H
#define COUNTY_H
#include <string>

class County {
	public:
		int population;
		std::string name;
};

struct Node{
	//std::string name;
	County county;
	int countyID;
	Node* next;
};

struct LinkedList{
	Node* head;
	Node* tail;
};

#endif