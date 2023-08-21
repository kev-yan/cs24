#include "GenePool.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// GenePool Member Functions
GenePool::GenePool(std::istream& stream){
    if(stream.fail()){
        cout << "could not open file" << endl;
    }
    string input;
    while(std::getline(stream, input)){
        if(input.substr(0, 1) != "#"){
            string newName;
            string genderName;
            Gender gender;
            string fatherName;
            string motherName;
            Person* father;
            Person* mother;
            std::stringstream ss(input);
            getline(ss, newName, '\t');
            
            //std::getline(ss, newName, '\t');
            getline(ss, genderName, '\t');
            if(genderName == "male"){
                gender = Gender::MALE;
            }
            else{
                gender = Gender::FEMALE;
            }
            getline(ss, fatherName, '\t');
            if(fatherName != "???"){
                father = people[fatherName];
            }
            else{
                father = nullptr;
            }
            getline(ss, motherName, '\t');
            if(motherName != "???"){
                mother = people[motherName];
            }
            else{
                mother = nullptr;
            }
            Person *newPerson = new Person(newName, gender, mother, father);
            people[newName] = newPerson;
        }
        
    }

}

GenePool::~GenePool(){
   // map<string, Person*>::iterator it;
    //for(it=people.begin(); it != table.end(); it++){}
    for(auto [name, person]: people){
        delete person;
    }
    people.clear();
}

std::set<Person*> GenePool::everyone() const{
    set<Person*> list;
    for(auto [name, person]: people){
        list.insert(person);
    }
    return list;
}

Person* GenePool::find(const std::string& name) const{
    for(auto [newName, person]: people){
        if(name == newName){
            return person;
        }
    }
    return nullptr;

}
