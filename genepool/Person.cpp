#include "Person.h"
#include <iostream>

using namespace std;

// Person Member Functions
void Person::getName() const{
    cout << mName << endl;
}

Person::Person(std::string newName, Gender newGender, Person* newMother, Person* newFather){
    mName = newName;
    mGender = newGender;
    mMother = newMother;
    mFather = newFather;
}


const std::string& Person::name() const{
    return mName;
}

Gender Person::gender() const{
    return mGender;
}

Person* Person::mother() {
    return mMother;
}

Person* Person::father() {
    return mFather;
}

  std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::children(){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::daughters(){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::descendants(){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::grandchildren(){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::granddaughters(){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::grandsons(){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::sons(){
    std::set<Person*> test;
    return test;
  }
  std::set<Person*> Person::uncles(PMod pmod, SMod smod){
        std::set<Person*> test;
    return test;
  }


/*
int main(){
    string newName = "dave";
    Gender test = Gender::MALE;
    Person* newFather = new Person(newName, test, nullptr, nullptr);
    newFather->getName();

}
*/