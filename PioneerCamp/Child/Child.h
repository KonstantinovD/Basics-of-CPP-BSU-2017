#ifndef _CHILD_TEST_070318_
#define _CHILD_TEST_070318_

#include <string>

class Child
{
private:
    std::string name;
    int age;
public:
    Child(std::string name, int age){
        this->age = age;
        this->name = name;
    }
    Child(const Child& ch){
        this->age = ch.age;
        this->name = ch.name;
    }

    void setName(std::string name){ this->name = name; }
    void setAge(int age){ this->age = age; }
    std::string& getName(){ return name; }
    int& getAge(){ return age; }
};


#endif