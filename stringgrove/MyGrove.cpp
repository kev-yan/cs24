#include "MyGrove.h"
#include <iostream>
using namespace std;

void MyGrove::setWord(char* str){
    root->word = str;
}

MyGrove::MyGrove(const char* str){
    root = new Node();
    root->word = str;
    length = strlen(str);
}

int MyGrove::len() const{
    return length;
}


const MyGrove* MyGrove::concat(MyGrove* other) const{
    Node* newRoot = new Node();
    newRoot->left = root;
    newRoot->right = other;
    root = newRoot;
    if(other){}
    return nullptr;
}

char MyGrove::charAt(int index) const{
    index = index+1;
    return 'a';
}

const MyGrove* MyGrove::substr(int start, int end) const{
    start = start + end;
    return nullptr;
}
