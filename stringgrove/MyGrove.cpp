#include "MyGrove.h"
#include <iostream>
#include <cstring>
using namespace std;

Node* MyGrove::concatNode(Node* first, Node* second) const{
    Node* temp = new Node();
    temp->left = first;
    //first->parent = temp;
    temp->right = second;
    //second->parent = temp;
    temp->length = first->length + second->length;
    return temp;
}

Node* MyGrove::giveRoot() const{
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
    else{
        //cout << "not root" << endl;
        Node* temp = nullptr;
        Node* old = nullptr;
        for(int i=0; i<length; i++){
            temp = getNode(root, i);
            if(temp != old){
                //cout << (int*) &(temp->word[0]) << endl;
                cout << temp->word;
            }

            old = temp;
            
        }
    }
}

MyGrove::MyGrove(){
}

MyGrove::MyGrove(Node* node){
   root = node;
   length = node->length;
}

MyGrove::MyGrove(const char* str){
    root = new Node();
    if(str != nullptr){
        length = strlen(str);
        root->length = strlen(str);
        //cout << length << ": length" << endl;
        root->word = str;
    }
    else {
        length = 0;
    }
}

int MyGrove::len() const{
    return length;
}



const MyGrove* MyGrove::concat(const MyGrove* other) const{
    if(root != nullptr){
        /*
        if(other->giveRoot() = root){
            MyGrove* newGrove = new myGrove();
            Node* newRoot = new Node();
            newRoot->left = root
        }
    */

        if(other->giveRoot() != nullptr){
            //MyGrove* newGrove = new MyGrove(nullptr); //fix this maybe!
            MyGrove* newGrove = new MyGrove();
            Node* newRoot = new Node();
            newRoot->left = root;
            root->parent = newRoot;
        // root->parent = newRoot;
            newRoot->right = other->giveRoot();
            other->giveRoot()->parent = newRoot;
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
}

const MyGrove* MyGrove::substr(int start, int end) const{
    int newLength = end - start+1;
    if(newLength > length){
        throw std::out_of_range("out of range");
    }
    //char newString[newLength];
    char *newString = new char[newLength+1];
    Node* first = getNode(root, start);
    Node* second = getNode(root, end);
    int firstIndex = getIndex(root, start);
    int secondIndex = getIndex(root, end);
    int temp = 0;
    if(first == second){
        for(int i=firstIndex; i<=secondIndex; i++){
            newString[i-firstIndex] = first->word[i];
        }
        newString[newLength+1] = '\0';
        const char* newnewString = newString;
        MyGrove* newGrove = new MyGrove(newnewString);
        return newGrove;
    }
    else{
        int len1 = first->length - firstIndex;
        int totalLength = secondIndex+len1+1;
        bool hold;
        MyGrove* finalGrove;
        if((totalLength) < newLength){
            Node* left;
            if(firstIndex != 0){
                for(int i=firstIndex; i<first->length; i++){
                newString[i-firstIndex] = first->word[i];
                temp++;
                hold = true;
                }
            }
            else{
                left = first;
                hold = false;
            }
            //MyGrove* left = new MyGrove(newString);
            if(hold){
                left->word = newString;
                left->length = strlen(newString);
            }
            //MyGrove* right;
            Node* newRoot;
            Node* right = getNode(root, start+len1);
            int tempLength = right->length;
            while(totalLength+tempLength <= newLength){ //might be able to just add this inbetween the original for i loops

                newRoot = concatNode(left, right);
                right = getNode(root, start+len1+tempLength);
                temp += right->length;
                left = newRoot;
                tempLength = right->length;
            /*
                for(int i=0; i<tempNode->length; i++){
                    newString[temp+i] = tempNode->word[i];
                }
                temp += tempNode->length;
                tempNode = getNode(root, start+len1+tempLength);
                tempLength += tempNode->length;
                */
                
            }
            
            if(secondIndex != second->length){
                for(int i=0; i<=secondIndex; i++){
                    newString[i+temp] = second->word[i];
                }
                hold = true;
            }
            else{
                right = second;
                hold = false;
            }    

            if(hold){
                right = new Node();
                right->word = newString;
                right->length = strlen(newString);
                newRoot = concatNode(left, right);
                finalGrove = new MyGrove(newRoot);
                return finalGrove;
            }
            else{
                newRoot = concatNode(left, right);
                finalGrove = new MyGrove(newRoot);
                return finalGrove;
            }
            
        }
        
        else{
            for(int i=firstIndex; i<first->length; i++){
                newString[i-firstIndex] = first->word[i];
                temp++;
            }
            for(int i=0; i<=secondIndex; i++){
                newString[i+temp] = second->word[i];
            }
        }
        newString[newLength+1] = '\0';
        MyGrove* newGrove = new MyGrove(newString);
        return newGrove;
    }
    
}