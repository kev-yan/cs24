#include "MyStack.h"
#include <iostream>
using namespace std;

// TODO: Implement MyStack member functions here.

void MyStack::print(){
    Node* temp = list->head;
    int i =0;
    cout << "head" << list->head << endl;
    cout << "tail" << list->tail << endl;
    while(temp != nullptr){  
        cout << i << ": " << temp->data << endl;
        i++;
        temp = temp->next;
    }
}

MyStack::MyStack(){
    list = new LinkedList();
}

MyStack::~MyStack(){
    Node* temp;
    while(list->head != nullptr){
        temp = list->head;
        list->head = temp->next;
        delete temp;
    }

    delete list;
}


void MyStack::clear(){                              //IF LEAKED MEMORY ITS HERE WITH TAIL NOT BEING DELETED
    Node* temp;
    while(list->head != nullptr){
        temp = list->head;
        list->head = temp->next;
        delete temp;
    }
}


bool MyStack::is_empty() const{
    if(list->head == nullptr){
        return true;
    }
    return false;
}

void MyStack::push(double item){
    Node* temp = new Node();
    temp->data = item;
    if(list->head == nullptr){
        list->head = temp;
        list->tail = temp;
    }
    else if (list->tail != nullptr){
        list->tail->next = temp;
        list->tail = temp;
    }
}

double MyStack::pop(){
    if(list->tail == nullptr){
        throw std::underflow_error("underflow error");
    }
    else if(list->head == list->tail){
        double val = list->head->data;
        delete list->head;
        list->head = nullptr;
        list->tail = nullptr;
        return val;
    }
    else{
        Node* temp = list->head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        double val = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        list->tail = temp;
        return val;
    }

}
double MyStack::top() const{
     if(list->tail == nullptr){
        throw std::underflow_error("underflow error");
    }
    else if(list->head == list->tail){
        double val = list->head->data;
        return val;
    }
    else{
        Node* temp = list->head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        double val = temp->next->data;
        return val;
    }
}