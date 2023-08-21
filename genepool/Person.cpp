#include "Person.h"
#include <iostream>

using namespace std;

// Person Member Functions
void Person::getName() const{
    cout << mName << endl;
}

void Person::addChild(Person* person){
    mChildren.push_back(person);
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
   std::set<Person*> tempList;
   if(pmod == PMod::PATERNAL){
    if(mFather != nullptr){
        test = mFather->sisters(PMod::ANY, smod);
    }
   }
   else if(pmod == PMod::MATERNAL){
    if(mMother != nullptr){
        test = mMother->sisters(PMod::ANY, smod);
    }
   }
   else{
    if(mFather != nullptr){
        test = mFather->sisters(PMod::ANY, smod);
    }
    if(mMother != nullptr){
        tempList = mMother->sisters(PMod::ANY, smod);
    }
    test.merge(tempList);
   }
   return test;
}
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> test;
    std::set<Person*> newList;
    test = this->siblings(pmod, smod);
    for(Person* person: test){
        if(person->gender() == Gender::MALE){
            newList.insert(person);
        }
    }
    return newList;
}
std::set<Person*> Person::children(){
    std::set<Person*> test;
    for(size_t i=0; i<mChildren.size(); i++){
        test.insert(mChildren.at(i));
    }
    return test;
}
std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> test;
    return test;
}
std::set<Person*> Person::daughters(){
    std::set<Person*> test;
    for(size_t i=0; i<mChildren.size();i++){
        if(mChildren.at(i)->mGender == Gender::FEMALE){
            test.insert(mChildren.at(i));
        }
    }
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
        if(mFather != nullptr && mFather->father() != nullptr){
            test.insert(mFather->father());
        }
    }
    else if(pmod == PMod::MATERNAL){
        if(mMother != nullptr && mMother->mother() != nullptr){
            test.insert(mMother->mother());
        }
        if(mMother != nullptr && mMother->father() != nullptr){
            test.insert(mMother->father());
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
    std::set<Person*> siblings;
    std::set<Person*> list;
    std::set<Person*> kids;
    siblings = this->siblings(pmod, smod);
    for(Person* parent: siblings){
        kids = parent->sons();
        list.merge(kids);
    }

    return list;
}
std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> siblings;
    std::set<Person*> list;
    std::set<Person*> kids;
    siblings = this->siblings(pmod, smod);
    for(Person* parent: siblings){
        kids = parent->daughters();
        list.merge(kids);
    }

    return list;
}
std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> test;
    if(pmod == PMod::PATERNAL){
        if(mFather != nullptr){
            test.insert(mFather);    
        }
    }
    else if(pmod == PMod::MATERNAL){
        if(mMother != nullptr)
            test.insert(mMother);
    }
    else{
        if(mMother != nullptr){
            test.insert(mMother);
        }
        if(mFather != nullptr){
            test.insert(mFather);
        }
    }
    return test;
}
std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> test;
    if(pmod == PMod::PATERNAL){
        if(mFather == nullptr){
            return test;
        }
        else{
            if(smod == SMod::FULL){
                for(size_t i=0; i<mFather->mChildren.size(); i++){
                    if(mFather->mChildren.at(i)->mName != mName){
                        if(mFather->mChildren.at(i)->mFather == mFather && mFather->mChildren.at(i)->mMother == mMother){
                            test.insert(mFather->mChildren.at(i));
                        }
                    }
                }
            }
            else if(smod == SMod::HALF){
                for(size_t i=0; i<mFather->mChildren.size(); i++){
                    if(mFather->mChildren.at(i)->mName != mName){
                        if((mFather->mChildren.at(i)->mFather == mFather && mFather->mChildren.at(i)->mMother != mMother)){
                        test.insert(mFather->mChildren.at(i));
                    }
                    }
                
                }
            }
            else{
                for(size_t i=0; i<mFather->mChildren.size(); i++){
                    if(mFather->mChildren.at(i)->mName != mName){
                        if(mFather->mChildren.at(i)->mFather == mFather || mFather->mChildren.at(i)->mMother == mMother){
                        test.insert(mFather->mChildren.at(i));
                    }
                    }
                    
                }
            }
        }     
    }
    else if(pmod == PMod::MATERNAL){
        if(mMother == nullptr){
            return test;
        }
        else{
            if(smod == SMod::FULL){
                for(size_t i=0; i<mMother->mChildren.size(); i++){
                    if(mMother->mChildren.at(i)->mName != mName){
                        if(mMother->mChildren.at(i)->mFather == mFather && mMother->mChildren.at(i)->mMother == mMother){
                        test.insert(mMother->mChildren.at(i));
                    }
                }
                    
                }
            }
            else if(smod == SMod::HALF){
                for(size_t i=0; i<mMother->mChildren.size(); i++){
                    if(mMother->mChildren.at(i)->mName != mName){
                        if((mMother->mChildren.at(i)->mFather != mFather && mMother->mChildren.at(i)->mMother == mMother)){
                            test.insert(mMother->mChildren.at(i));
                        }
                    }
                }
            }
            else{
                for(size_t i=0; i<mMother->mChildren.size(); i++){
                    if(mMother->mChildren.at(i)->mName != mName){
                        if(mMother->mChildren.at(i)->mFather == mFather || mMother->mChildren.at(i)->mMother == mMother){
                            test.insert(mMother->mChildren.at(i));
                        }
                    }
                }
            }
        }
        
    }
    else{
        if(smod == SMod::FULL){
            if(mMother == nullptr || mFather == nullptr){
                return test;
            }
            if(mFather != nullptr){
               for(size_t i=0; i<mFather->mChildren.size(); i++){
                if(mFather->mChildren.at(i)->mName != mName){
                    if(mFather->mChildren.at(i)->mFather == mFather && mFather->mChildren.at(i)->mMother == mMother){
                    test.insert(mFather->mChildren.at(i));
                    }
                }
                } 
            }
            if(mMother != nullptr){
               for(size_t i=0; i<mMother->mChildren.size(); i++){
                if(mMother->mChildren.at(i)->mName != mName){
                    if(mMother->mChildren.at(i)->mFather == mFather && mMother->mChildren.at(i)->mMother == mMother){
                    test.insert(mMother->mChildren.at(i));
                    }
                }
                } 
            }

            
        }
        else if(smod == SMod::HALF){
            if(mFather != nullptr){
               for(size_t i=0; i<mFather->mChildren.size(); i++){
                if(mFather->mChildren.at(i)->mName != mName){
                     if((mFather->mChildren.at(i)->mFather == mFather && mFather->mChildren.at(i)->mMother != mMother) || (mFather->mChildren.at(i)->mFather != mFather && mFather->mChildren.at(i)->mMother == mMother)){
                    test.insert(mFather->mChildren.at(i));
                }
                }
               
                }
            }
            if(mMother != nullptr){
               for(size_t i=0; i<mMother->mChildren.size(); i++){
                if(mMother->mChildren.at(i)->mName != mName){
                    if((mMother->mChildren.at(i)->mFather == mFather && mMother->mChildren.at(i)->mMother != mMother) || (mMother->mChildren.at(i)->mFather != mFather && mMother->mChildren.at(i)->mMother == mMother)){
                        test.insert(mMother->mChildren.at(i));
                    }
                }
                }
            }
            
        }
        else{
            if(mMother != nullptr){
                for(size_t i=0; i<mMother->mChildren.size(); i++){
                    if(mMother->mChildren.at(i)->mName != mName){
                        if(mMother->mChildren.at(i)->mFather == mFather || mMother->mChildren.at(i)->mMother == mMother){
                        test.insert(mMother->mChildren.at(i));
                    }
                    }
                
                }
            }
            if(mFather != nullptr){
                for(size_t i=0; i<mFather->mChildren.size(); i++){
                    if(mFather->mChildren.at(i)->mName != mName){
                        if(mFather->mChildren.at(i)->mFather == mFather || mFather->mChildren.at(i)->mMother == mMother){
                        test.insert(mFather->mChildren.at(i));
                    }
                    }
                    
                }
           }
        }
    }

    return test;
}
std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> test;
    std::set<Person*> newList;
    test = this->siblings(pmod, smod);
    for(Person* person: test){
        if(person->gender() == Gender::FEMALE){
            newList.insert(person);
        }
    }
    return newList;
}
std::set<Person*> Person::sons(){
    std::set<Person*> test;
    for(size_t i=0; i<mChildren.size();i++){
        if(mChildren.at(i)->mGender == Gender::MALE){
            test.insert(mChildren.at(i));
        }
    }
    return test;
 }
std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> test;
   std::set<Person*> tempList;
   if(pmod == PMod::PATERNAL){
    if(mFather != nullptr){
        test = mFather->brothers(PMod::ANY, smod);
    }
   }
   else if(pmod == PMod::MATERNAL){
    if(mMother != nullptr){
        test = mMother->brothers(PMod::ANY, smod);
    }
   }
   else{
    if(mFather != nullptr){
        test = mFather->brothers(PMod::ANY, smod);
    }
    if(mMother != nullptr){
        tempList = mMother->brothers(PMod::ANY, smod);
    }
    test.merge(tempList);
   }
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