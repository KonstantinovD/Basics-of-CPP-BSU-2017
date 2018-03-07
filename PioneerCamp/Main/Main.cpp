#include <cstdio>
#include <iostream>

#include "../Camp/Camp.h"

int main(){

    try{
        Camp camp;
        camp.sortChildrenByAge();
        camp.findAverageAge();
        camp.findGroupsForEachChild();
        camp.findGroupWithMaxMembers();
        camp.updateCampGroupsData();
    }
    catch (std::string ex){
        std::cout << ex << std::endl;
    }

    system("pause");
    return 0;
}