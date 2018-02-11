#include "../../include/TackInclude.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

static struct SStud{
    static const int nameSymbols = 20;

    char name[nameSymbols];
    int group;
    double ball;
    SStud(){
        for (int i = 0; i < nameSymbols; i++){
            name[i] = ' ';
        }
    }
};

static void printVect(std::vector<SStud> students){
    for (SStud st : students){
        std::cout << st.name << ", group: " << st.group << " ball: " << st.ball << std::endl;
    }
    std::cout << std::endl;
}


void stlPractW2_3(std::ifstream& FIN){
    FIN.open("resources/stlPracrW2_3.txt");

    std::vector<SStud> students;

    //the .txt file shouldn't be finished by the "\n", or the error will occur
    while (!FIN.eof()){
        SStud person;
        FIN.get(person.name, person.nameSymbols, ' ');
        FIN >> person.group;
        FIN >> person.ball;
        students.push_back(person);
        if (FIN.get() == -1) break;
    }

    double inputBall = 0.0;
    std::cout << "input the average ball you need(accurate to tenths): ";
    std::cin >> inputBall;
    std::cout << "there are " << std::count_if(students.begin(), students.end(), [inputBall](SStud pers){ return inputBall == pers.ball; }) << " students have this ball" << std::endl;

    int inputGroup = 0;
    std::cout << "input the group students from you need: ";
    std::cin >> inputGroup;

    for (SStud st : students){
        if (st.group == inputGroup){
            std::cout << st.name << std::endl;
        }
    }
    std::cout << std::endl;

    std::vector<SStud> secondStudents(students);
    std::reverse(secondStudents.begin(), secondStudents.end());
    std::cout << "reversed vector: " << std::endl;
    printVect(secondStudents);
    

    std::sort(students.begin(), students.end(), [](SStud p1, SStud p2){ 
        return(std::string(p1.name).compare(std::string(p2.name)) < 0);
    });
    std::cout << "vector sorted by name: " << std::endl;
    printVect(students);

    std::sort(students.begin(), students.end(), [](SStud p1, SStud p2)->bool{
        if (p1.group == p2.group)
            return(std::string(p1.name).compare(std::string(p2.name)) < 0);
        return(p1.group < p2.group);
    });
    std::cout << "vector sorted by group and name: " << std::endl;
    printVect(students);

    std::sort(students.begin(), students.end(), [](SStud p1, SStud p2){return(p2.ball < p1.ball);});
    std::cout << "vector sorted by average ball: " << std::endl;
    printVect(students);

}