#include "../../include/TackInclude.h"

#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <set>
#include <map>


void stlPractW2_2(std::ifstream& FIN){
    FIN.open("resources/stlPracrW2_2.txt");


    std::vector<std::string> vect;
    while (!FIN.eof()){
        std::string newWord;
        std::getline(FIN, newWord, ' ');
        vect.push_back(newWord);
    }

    std::sort(vect.begin(), vect.end());

    for (std::string str : vect) std::cout << str << " ";
    std::cout << std::endl;

    char firstSmb;
    std::cout << "input the start character: ";
    std::cin >> firstSmb;
    
    int i = 0;
    while (i < vect.size()){
        if (vect[i].size() > 0 && vect[i][0] == firstSmb){
            std::cout << vect[i] << " ";//print this word
            vect.erase(vect.begin() + i);
        }
        else{ i++; }
    }
    std::cout << "after deleting: ";
    for (std::string str : vect) std::cout << str << " ";
    std::cout << std::endl;

    std::set<std::string> uniqueWords(vect.begin(), vect.end());
    std::cout << "unique: ";
    for (std::string str : uniqueWords) std::cout << str << " ";
    std::cout << std::endl;

    std::map<std::string, int> wordMap;
    for (std::string str : vect){
        wordMap[str]++;
    }
    for (auto elem : wordMap){
        std::cout << elem.first << ": " << elem.second << " times ";
    }
    std::cout << std::endl;

}