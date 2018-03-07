#ifndef _CAMP_TEST_070318_
#define _CAMP_TEST_070318_

#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "../Child/Child.h"
#include "../Group/Group.h"

class Camp{
private:
    std::list<Group> groupList;
    std::list<Child> childList;

private:
    void init();//read data from files and open fileOutput
    void inputChildData(std::ifstream& FIN);
    void inputGroupData(std::ifstream& FIN);
    std::ofstream fileOutput;

public:
    Camp();
    Camp(const Camp& cmp){}//no copies
    void operator=(const Camp& cmp){}//no copies

    ~Camp();//closing ofstream

    void sortChildrenByAge();//task 4
    int findAverageAge();//task 4
    std::list<std::string> findListOfGroups(Child& child);//help func for task 5
    void findGroupsForEachChild();//task 5
    std::string findGroupWithMaxMembers();//task 6
    std::list<Child> updateGroupMembersData(Group& group);//help func for task 7
    std::list<std::pair<Group, std::list<Child>>> updateCampGroupsData(); //task 7
public:


};



#endif