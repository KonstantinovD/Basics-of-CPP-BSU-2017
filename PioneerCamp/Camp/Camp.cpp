#include "Camp.h"

Camp::Camp(){
    try{
        init();
    }
    catch (std::string ex){ throw ex; }
}



void Camp::init(){
    fileOutput.open("resources/Output/CampOutput.txt");
    if (!fileOutput.is_open()) throw std::string("ERROR: no output file exist");

    std::ifstream childsInput("resources/CampData/Childs.txt");
    if (!childsInput.is_open()) throw std::string("ERROR: no child file exist");
    std::ifstream groupsInput("resources/CampData/Groups.txt");
    if (!groupsInput.is_open()) throw std::string("ERROR: no group file exist");

    inputChildData(childsInput);
    inputGroupData(groupsInput);
}


void Camp::inputChildData(std::ifstream& FIN){
    std::string fileStr;
    std::string subStr = "";//substring for splitting

    std::string childName;
    int childAge;
    while (std::getline(FIN, fileStr)){//read lines of text

        std::stringstream splitString(fileStr);
        if (std::getline(splitString, subStr, ' ')){
            childName = subStr;
        }
        if (std::getline(splitString, subStr, ' ')){
            std::istringstream buffer(subStr);
            buffer >> childAge;
            childList.push_back(Child(childName, childAge));
        }
    }
    //delete duplicate childs
    childList.unique([](Child ch1, Child ch2){ return ch1.getName() == ch2.getName(); });
}

void Camp::inputGroupData(std::ifstream& FIN){
    std::string fileStr;
    std::string subStr = "";//substring for splitting

    std::string groupName;
    int borderAge;
    while (std::getline(FIN, fileStr)){//read lines of text

        std::stringstream splitString(fileStr);
        if (std::getline(splitString, subStr, ' ')){
            groupName = subStr;
        }
        if (std::getline(splitString, subStr, ' ')){
            std::istringstream buffer(subStr);
            buffer >> borderAge;
            groupList.push_back(Group(groupName, borderAge));
        }
        while (std::getline(splitString, subStr, ' ')){
            groupList.back().push_back(subStr);
        }
    }
    //delete duplicate childs
    groupList.unique([](Group gr1, Group gr2){ return gr1 == gr2; });
}

Camp::~Camp(){
    if (fileOutput.is_open()){
        fileOutput.close();
    }
}

void Camp::sortChildrenByAge(){
    childList.sort([](Child ch1, Child ch2){ return ch1.getAge() < ch2.getAge(); });

    fileOutput << "TASK 4.1 sortChildrenByAge:" << std::endl;
    for (Child ch : childList){
        fileOutput << ch.getName() << ", " << ch.getAge() << std::endl;
    }
    fileOutput << std::endl;
}

int Camp::findAverageAge(){
    int sum = 0;
    for (Child ch : childList){
        sum += ch.getAge();
    }
    double averageAge = (sum / (double) childList.size());

    fileOutput << "TASK 4.2 findAverageAge:" << std::endl;
    fileOutput << averageAge << std::endl;
    fileOutput << std::endl;

    return averageAge;
}

std::list<std::string> Camp::findListOfGroups(Child& child){
    std::list<std::string> localGroups;

    for (Group gr : groupList){
        for_each(gr.begin(), gr.end(), [&child, &localGroups, &gr](std::string str){
            if (child.getName() == str){
                localGroups.push_back(gr.getGroupName());
            }
        });
            
    }
    return localGroups;
}

void Camp::findGroupsForEachChild(){
    std::list<std::pair<Child, std::list<std::string>>> childAndGroups;
    for (Child ch : childList){
        std::list<std::string> localGroups = findListOfGroups(ch);
        childAndGroups.push_back(std::make_pair(ch, localGroups));
    }

    fileOutput << "TASK 5 findGroupsForEachChild:" << std::endl;
    for (std::pair<Child, std::list<std::string>> pr : childAndGroups){
        fileOutput << pr.first.getName() << ", " << pr.first.getAge() << ": ";
        for (std::string str : pr.second){
            fileOutput << str << " | ";
        }
        fileOutput << std::endl;
    }
    fileOutput << std::endl;
}

std::string Camp::findGroupWithMaxMembers(){
    int maxNumberOfMembers = 0;
    std::list<Group>::iterator it;
    std::list<Group>::iterator it_result = groupList.begin();
    if (groupList.empty()) return "";
    for (it = groupList.begin(); it != groupList.end(); it++){
        if (it->getNumberOfChildren() > maxNumberOfMembers){
            maxNumberOfMembers = it->getNumberOfChildren();
            it_result = it;
        }
    }
    fileOutput << "TASK 6 findGroupWithMaxMembers:" << std::endl;
    fileOutput << it_result->getGroupName() << std::endl;
    fileOutput << std::endl;

    return it_result->getGroupName();
}

std::list<Child> Camp::updateGroupMembersData(Group& group){
    std::list<Child> res_list;
    std::list<Child>::iterator it_child_begin = childList.begin();
    std::list<Child>::iterator it_child_end = childList.end();

    for_each(group.begin(), group.end(), [&group, &res_list, &it_child_begin, &it_child_end](std::string str){
        std::list<Child>::iterator it;
        for (it = it_child_begin; it != it_child_end; it++){
            if (it->getName() == str){
                if (!(it->getAge() < group.getAgeLowerBorder())) {
                    res_list.push_back(*it);
                    break;
                }
            }
        }
    }
    );
        
    return res_list;
}

std::list<std::pair<Group, std::list<Child>>> Camp::updateCampGroupsData(){
    std::list<std::pair<Group, std::list<Child>>> updatedListOfMembers;
    for (Group gr : groupList){
        std::list<Child> membersOfGroup = updateGroupMembersData(gr);
        updatedListOfMembers.push_back(std::make_pair(gr, membersOfGroup));
    }
    fileOutput << "TASK 7 updateCampGroupsData:" << std::endl;
    for (std::pair<Group, std::list<Child>> pr : updatedListOfMembers){
        fileOutput << pr.first.getGroupName() << ": ";
        for (Child ch : pr.second){
            fileOutput << ch.getName() << ", " << ch.getAge() << "|";
        }fileOutput << std::endl;
    }
    fileOutput << std::endl;

    return updatedListOfMembers;
}