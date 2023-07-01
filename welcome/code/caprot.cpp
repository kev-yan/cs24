#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[]){

    if(argc == 3){
        int temp = argc;
        string test;
        //cout << argv[2];
        test = argv[2];
        cout << temp << endl;
        cout << test << endl;
    }
    else{
        cout << "please try again" << endl;
    }
    
}