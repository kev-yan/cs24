#ifndef NODE_H
#define NODE_H

struct Node{
	double data;
	Node* next;
};

struct LinkedList{
	Node *head;
	Node *tail;
};

#endif

