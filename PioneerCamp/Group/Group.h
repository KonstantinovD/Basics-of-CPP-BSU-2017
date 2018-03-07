#ifndef _GROUP_TEST_070318_
#define _GROUP_TEST_070318_

#include <string>
#include <list>
#include <algorithm>

class Group{
private:
    std::string groupName;
    int ageLowerBorder;
    std::list<std::string> childNames;
public:
    typedef std::list<std::string>::iterator iterator;
    iterator begin(){ return childNames.begin(); }
    iterator end(){ return childNames.end(); }
    int getNumberOfChildren(){ return childNames.size(); }
    void push_back(std::string str){ childNames.push_back(str); }
    void erase(iterator it){ childNames.erase(it); }
public:
    Group(std::string gName, int ageLB = 0) : childNames(0)
    {
        this->groupName = gName;
        this->ageLowerBorder = ageLB;
    }
    Group(const Group& gr){
        this->groupName = gr.groupName;
        this->ageLowerBorder = gr.ageLowerBorder;
        childNames = gr.childNames;
    }

    void setGroupName(std::string name){ this->groupName = name; }
    void setAgeLowerBorder(int age){ this->ageLowerBorder = age; }
    std::string getGroupName(){ return groupName; }
    int getAgeLowerBorder(){ return ageLowerBorder; }

    bool operator ==(const Group &gr){
        if (groupName == gr.groupName){
            if (ageLowerBorder == gr.ageLowerBorder){
                if (childNames == gr.childNames){
                    return true;
                }
            }
        }
        return false;
    }
};




#endif