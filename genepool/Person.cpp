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
    if(pmod == PMod::PATERNAL){
        if(mFather != nullptr && mFather->father() != nullptr){
            test.insert(mFather->father());
        }
    }
    else if(pmod == PMod::MATERNAL){
        if(mMother != nullptr && mMother->father() != nullptr){
            test.insert(mMother->father());
        }
    }
    else{
        if(mMother != nullptr && mMother->father() != nullptr){
            test.insert(mMother->father());
        }
        if(mFather != nullptr && mFather->father() != nullptr){
            test.insert(mFather->father());
        }
    }
    return test;
}
std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> test;
    if(pmod == PMod::PATERNAL){
        if(mFather != nullptr && mFather->mother() != nullptr){
            test.insert(mFather->mother());
        }
    }
    else if(pmod == PMod::MATERNAL){
        if(mMother != nullptr && mMother->mother() != nullptr){
            test.insert(mMother->mother());
        }
    }
    else{
        if(mMother != nullptr && mMother->mother() != nullptr){
            test.insert(mMother->mother());
        }
        if(mFather != nullptr && mFather->mother() != nullptr){
            test.insert(mFather->mother());
        }
    }
    return test;
}
std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> test;
    if(pmod == PMod::PATERNAL){
        if(mFather != nullptr && mFather->mother() != nullptr){
            test.insert(mFather->mother());
        }
        if(mMother != nullptr && mMother->father() != nullptr){
            test.insert(mMother->father());
        }
    }
    else if(pmod == PMod::MATERNAL){
        if(mMother != nullptr && mMother->mother() != nullptr){
            test.insert(mMother->mother());
        }
        if(mFather != nullptr && mFather->father() != nullptr){
            test.insert(mFather->father());
        }
    }
    else{
        if(mMother != nullptr && mMother->mother() != nullptr){
            test.insert(mMother->mother());
        }
        if(mFather != nullptr && mFather->mother() != nullptr){
            test.insert(mFather->mother());
        }
        if(mMother != nullptr && mMother->father() != nullptr){
            test.insert(mMother->father());
        }
        if(mFather != nullptr && mFather->father() != nullptr){
            test.insert(mFather->father());
        }
    }
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