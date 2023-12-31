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
        while(!(isWord(curr))){
            Node* left = curr->left;
            Node* right = curr->right;
            if(index < left->length){
                curr = left;
            }
            else{
                index = index-(left->length);
                curr = right;
            }
        }
        return curr;
        /*
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
            */
    }
}

int MyGrove::getIndex(Node* newNode, int index) const{
    if(isWord(newNode)){
        return index;
    }
    else{
        Node* curr = newNode;
        while(!(isWord(curr))){
            Node* left = curr->left;
            Node* right = curr->right;
            if(index < left->length){
                curr = left;
            }
            else{
                index = index-(left->length);
                curr = right;
            }
        }
        return index;
        /*
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
            */
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
        int count = 0;
        for(int i=0; i<length; i++){
            temp = getNode(root, i);
            //cout << i << endl;
            if(temp != old){
                //cout << (int*) &(temp->word[0]) << endl;

                cout << temp->word;
                count++;
            }

            old = temp;
            
        }
        cout << endl;
        cout << "nodes: " << count << endl;
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

        if(other->giveRoot() != nullptr){
            //MyGrove* newGrove = new MyGrove(nullptr); //fix this maybe!
            MyGrove* newGrove = new MyGrove();
            Node* newRoot = new Node();
            newRoot->left = root;
            //root->parent = newRoot;
        // root->parent = newRoot;
            newRoot->right = other->giveRoot();
            //ther->giveRoot()->parent = newRoot;
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
    //char *newString = new char[newLength+1];
    char *newString = new char[newLength];
    Node* first = getNode(root, start);
    Node* second = getNode(root, end);
    int firstIndex = getIndex(root, start);
    int secondIndex = getIndex(root, end);
    //int temp = 0;
    if(first == second){
        if(firstIndex != 0 || secondIndex != second->length){
            
            for(int i=firstIndex; i<=secondIndex; i++){
                newString[i-firstIndex] = first->word[i];
            }
            //newString[newLength+1] = '\0';
            const char* newnewString = newString;
            MyGrove* newGrove = new MyGrove(newnewString);
            return newGrove;
        }
        else{
            const MyGrove *temp = new MyGrove(first);
            return temp;
        }
    }
    else{
        Node* left;
        Node* right;
        if(firstIndex == 0 || secondIndex == second->length){
            if(firstIndex == 0){
                left = first;
            }
            else{
                char* tempString = new char[first->length - firstIndex];
                for(int i=firstIndex; i<first->length; i++){
                    tempString[i-firstIndex] = first->word[i];
                }
                left = new Node();
                left->word = tempString;
                left->length = strlen(tempString);
            }
            if(secondIndex == second->length){
                right = second;
            }
            else{
                char* tempString2 = new char[first->length - secondIndex];
                for(int i=0; i<= secondIndex; i++){
                    tempString2[i] = second->word[i];
                }
                right = new Node();
                right->word = tempString2;
                right->length = strlen(tempString2);
            }
            MyGrove* newGrove = new MyGrove();
            if(left->length + right->length == start-end+1){
                Node* newLeft = concatNode(left, right);
                newGrove->root = newLeft;
                newGrove->length = newLeft->length;
                return newGrove;
            }
            else{
                const MyGrove* temp = this->substr(start+left->length, end-right->length);
                Node* temp2 = temp->root;
                Node* newLeft = concatNode(left, temp2);
                Node* newRight = concatNode(newLeft, right);
                MyGrove* newGrove = new MyGrove();
                newGrove->root = newRight;
                newGrove->length = newRight->length;
                return newGrove;
            }

        }
        /*
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
                left = new Node();
                left->word = newString;
                left->length = strlen(newString);
            }
            //MyGrove* right;
            //cout << left->word << endl;
            Node* newRoot;
            Node* right = getNode(root, start+len1);
            int tempLength = right->length;
            while(totalLength+tempLength <= (newLength)){ //might be able to just add this inbetween the original for i loops
                newRoot = concatNode(left, right);
                right = getNode(root, start+len1+tempLength);
                //cout << "middle: " << right->word << endl;
                temp += right->length;
                left = newRoot;
                tempLength += right->length;
            }    
            char* newnewString;
            if(secondIndex < second->length){
                newnewString = new char[secondIndex];
                for(int i=0; i<=secondIndex; i++){
                    newnewString[i] = second->word[i];
                }
                hold = true;
            }
            else{
                right = second;
                hold = false;
            }    
            if(hold){
                right = new Node();
                right->word = newnewString;
                right->length = strlen(newnewString);
                //cout << "here: " << right->word << endl;
                newRoot = concatNode(left, right);
                finalGrove = new MyGrove(newRoot);
                return finalGrove;
            }
            else{
                //cout << "maybe here" << endl;
                //cout << right->word << endl;
                newRoot = concatNode(left, right);
                finalGrove = new MyGrove(newRoot);
                return finalGrove;
            }
            
        }
        
        else{
            if(firstIndex == 0 || secondIndex == second->length){
                Node* left;
                Node* right;
                if(firstIndex == 0){
                    left = first;
                }
                else{
                    char* tempString = new char[first->length-firstIndex];
                    for(int i=firstIndex; i<first->length; i++){
                        tempString[i-firstIndex] = first->word[i];
                        temp++;
                    }
                    left = new Node();
                    left->word = tempString;
                    left->length = strlen(newString);
                }
                if(secondIndex == second->length){
                    right = second;
                }
                else{
                    char* tempString2 = new char[secondIndex];
                    for(int i=0; i<=secondIndex; i++){
                        tempString2[i] = second->word[i];
                    }
                    right = new Node();
                    right->word = tempString2;
                    right->length = strlen(tempString2);
                }
                Node* newRoot = concatNode(left, right);
                MyGrove* newGrove = new MyGrove();
                newGrove->root = newRoot;
                newGrove->length = newRoot->length;
                return newGrove;
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
        }
        */
        //newString[newLength+1] = '\0';
        MyGrove* newGrove = new MyGrove(newString);
        return newGrove;
    }
    
}