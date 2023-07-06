#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


void rightCap(long long int num, string input1){
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

}


int main(int argc, char* argv[]){
    string input;
    if(argc == 2){
        getline(cin, input);
        rightCap(atoi(argv[1]), input);
    }
    
    else{
        cout << "please try again" << endl;
    }
}
    
