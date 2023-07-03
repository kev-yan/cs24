#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

void rightCap(int num, string input){
    int length = input.length();
    vector<int> upper;
    int i;
    for(i=0; i<length; i++){
        if(isupper(input[i])){
            int index = (i+num) % length;
            upper.push_back(index);
            input[i] = tolower(input[i]);
        }
    }
    for(i=0;i<upper.size();i++){
        input[upper.at(i)] = toupper(input[upper.at(i)]);
    }
    cout << input << endl;

}

int main(int argc, char* argv[]){
    if(argc == 3){
        rightCap(stoi(argv[1]), argv[2]);
    }
    else{
        cout << "please try again" << endl;
    }
    
}