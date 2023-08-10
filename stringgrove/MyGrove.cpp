#include "MyGrove.h"
#include <iostream>
using namespace std;

Node* MyGrove::giveRoot(){
    return root;
}

Node* MyGrove::getRoot() const{
    return root;
}

Node* MyGrove::getNode(Node* newNode, int index) const{
    if(isWord(newNode)){
        return newNode;
    }
    else{
        Node* curr = newNode;
        while(curr->length > index && !(isWord(curr))){
                curr = curr->left;
            }
            if(index >= curr->length){
                int newLength = curr->length;
                curr = curr->parent->right;
                if(isWord(curr)){
                    return curr;
                }
                else{
                    index = index-newLength;
                    return getNode(curr, index);
                }
            }
            else{
                return curr;
            }
    }
}

int MyGrove::getIndex(Node* newNode, int index) const{
    if(isWord(newNode)){
        return index;
    }
    else{
        Node* curr = newNode;
        while(curr->length > index && !(isWord(curr))){
                curr = curr->left;
            }
            if(index >= curr->length){
                int newLength = curr->length;
                curr = curr->parent->right;
                if(isWord(curr)){
                    return index-newLength;
                }
                else{
                    index = index-newLength;
                    return getIndex(curr, index);
                }
            }
            else{
                return index;
            }
    }
}

bool MyGrove::isWord(Node* curr) const{
    if(curr->right == nullptr && curr->left == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void MyGrove::setWord(char* str){
    root->word = str;
}

void MyGrove::setLength(int size){
    length = size;
}

void MyGrove::setRoot(Node* other){
    root = other;
}
void MyGrove::printWord() const{
    if(isWord(root)){
        cout << root->word << endl;
    }
}

MyGrove::MyGrove(const char* str){
    root = new Node();
    if(str != nullptr){
        length = strlen(str);
        root->length = strlen(str);
        root->word = str;
    }
    else {
        length = 0;
    }
}

int MyGrove::len() const{
    return length;
}


const MyGrove* MyGrove::concat(MyGrove* other) const{
    if(root != nullptr){
        if(other->giveRoot() != nullptr){
            MyGrove* newGrove = new MyGrove(nullptr);
            Node* newRoot = new Node();
            newRoot->left = root;
            newRoot->left->parent = newRoot;
        // root->parent = newRoot;
            newRoot->right = other->giveRoot();
            newRoot->right->parent = newRoot;
            newRoot->length = root->length + other->giveRoot()->length;
            //newRoot->right = newRoot;
            newGrove->setLength(length+other->len());
            newGrove->setRoot(newRoot);
            //root = newRoot;
            return newGrove;
        }
    }
    else{
        return other;
    }
    
    return nullptr;

}

char MyGrove::charAt(int index) const{
    if(isWord(root)){
        return root->word[index];
    }
    else{
        Node* curr = getNode(root, index);
        int newIndex = getIndex(root, index);
        return curr->word[newIndex];
        
    }
    /*
    if(isWord(root)){
        return root->word[index];
    }
    else{
        Node* curr = root;
        while(curr->length > index && !(isWord(curr))){
            curr = curr->left;
        }
        if(index >= curr->length){
            int newLength = curr->length;
            curr = curr->parent->right;
            if(isWord(curr)){
                return curr->word[index-newLength];
            }
            else{
                index = index-newLength;
                curr = getNode(curr, index);
                index = getIndex(curr, index);
                return curr->word[index];

            }
        }
        else{
            return curr->word[index];
        }
        
    }
    */
}

const MyGrove* MyGrove::substr(int start, int end) const{
    int newLength = end - start+1;
    char newString [newLength];
    Node* first = getNode(root, start);
    Node* second = getNode(root, end);
    int firstIndex = getIndex(root, start);
    int secondIndex = getIndex(root, end);
    int temp = 0;
    if(first == second){
        for(int i=firstIndex; i<=secondIndex; i++){
            newString[i-firstIndex] = first->word[i];
            //cout << first->word[i] << endl;
        }
        const char* newnewString = newString;
        MyGrove* newGrove = new MyGrove(newnewString);
        return newGrove;
    }
    else{
        for(int i=firstIndex; i<first->length; i++){
            newString[i-firstIndex] = first->word[i];
            temp++;
            //cout << newString[i-firstIndex] << endl;
        }
        cout << newString << endl;
        //cout << "-----------------" << temp << "-----------" << endl;
        for(int i=0; i<secondIndex; i++){
            newString[i+temp] = second->word[i];
            //cout << newString << endl;
        }
        cout << newString << endl;
        const char* newnewString = newString;
        cout << newString << endl;                      //if I remove this cout statement, it prints trash values
        MyGrove* newGrove = new MyGrove(newnewString);
        return newGrove;
    }
    
}
