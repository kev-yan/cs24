#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


void rightCap(int num, string input1){
    string input = input1;
    int length = input.length();
    vector<int> upper;
    int i;
    for(i=0; i<length; i++){
        if(isupper(input[i])){
            int index = (i+num) % length;
            if(index < 0){
                index += length;
            }
            upper.push_back(index);
            input[i] = tolower(input[i]);
        }
    }

    unsigned int j;
    for(j=0;j<upper.size();j++){
        input[upper.at(j)] = toupper(input[upper.at(j)]);
    }
    cout << input << endl;
    cout << "num: " << num << "input: " << input1 << endl;

}


int main(int argc, char* argv[]){
    cout << "argc: " << argc << endl;
    //if(argc == 3){
      //  rightCap(atoi(argv[1]), argv[2]);
   // }
    /*
    else{
        if(argc > 2){
            string temp = argv[1];
            for(int i=2; i<(argc);i++){
                temp = temp + " " + argv[i];
            }
            rightCap(stoi(argv[0]), temp);
        }
        else{
            cout << "doesn't work: "<< argc << " " << argv[1] << " " << argv[2];
            cout << "please try again";
        }
        */
    }
    

/*
int main(int argc, char* argv[]){
    if(argc == 3){
        rightCap(atoi(argv[1]), argv[2]);
    }
    else{
        if(argc >= 3){
            string temp = argv[2];
            for(int i=3; i<(argc);i++){
                temp = temp + " " + argv[i];
            }
            rightCap(stoi(argv[1]), temp);
        }
        else{
            cout << "doesn't work: " << argc << " " << argv[1] << " " << argv[2];
            cout << "please try again";
        }
    }
    */

