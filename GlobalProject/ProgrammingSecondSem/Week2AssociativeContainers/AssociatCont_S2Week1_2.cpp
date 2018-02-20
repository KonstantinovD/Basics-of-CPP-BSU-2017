#include "../../include/TackInclude.h"
#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>


static struct Student
{
    std::string name;
    int groupNumber;
    std::vector<int> sessionMarks;
};

static void showStud(Student st){
        std::cout << st.name << ", group: " << st.groupNumber << ", session marks: ";
        for (int mark : st.sessionMarks) std::cout << mark << " ";
        std::cout << std::endl;
}

static void showUniversity(std::vector<Student> vect){
    for (Student st : vect){
        showStud(st);
    }std::cout << std::endl;
}


static bool studComparator(Student s1, Student s2){
    if (s1.groupNumber == s2.groupNumber){
        return s1.name < s2.name;
    }
    return s1.groupNumber < s2.groupNumber;
}

void associatCont_S2Week1_2(std::ifstream &FIN){

    FIN.open("resources/associatCont_S2Week2_1.txt");

    std::vector<Student> university;

    while (!FIN.eof()){
        Student person;
        FIN>>person.name;
        FIN >> person.groupNumber;

        int numberOfMarks;
        FIN >> numberOfMarks;
        for (int i = 0; i < numberOfMarks; i++){
            person.sessionMarks.push_back(0);
            FIN>>person.sessionMarks[person.sessionMarks.size() - 1];
        }
        university.push_back(person);
    }

    std::sort(university.begin(), university.end(), studComparator);
    std::cout << "sorted vector" << std::endl;
    showUniversity(university);

    std::string inpName;
    std::cout << "input the name of the student to delete him: ";
    std::cin >> inpName;
    std::vector<Student>::iterator it;
    std::vector<Student> removeVect(university);
    it = std::remove_if(removeVect.begin(), removeVect.end(), [inpName](Student st){ return st.name == inpName; });

    std::vector<Student>::iterator it2;
    for (it2 = removeVect.begin(); it2 != it; it2++){
        showStud(*it2);
    }std::cout << std::endl;

    std::map<std::string, Student> studMap;
    for (Student st : university){
        studMap[st.name] = st;
    }

    std::vector<Student>::iterator sessionNotPassed = university.begin();
    std::vector<Student>::iterator startFrom = university.begin();

    while (university.end() != (sessionNotPassed = std::find_if(startFrom, university.end(), [](Student st)->bool{
        for (int mark : st.sessionMarks){ if (mark < 4) return true; } return false; })))
    {
        showStud(*sessionNotPassed);
        (startFrom = sessionNotPassed)++;
    }
    
}