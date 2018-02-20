#include "../../include/TackInclude.h"
#include <list>
#include <algorithm>
#include <iostream>
#include <string>


void seqCont_S2Week1_2(std::ifstream &FIN){
    FIN.open("resources/seqCont_S2Week1_2.txt");

    std::list<std::string> words;
    while (!FIN.eof()){
        std::string newWord;
        std::getline(FIN, newWord, ' ');
        if(false == newWord.empty()) words.push_back(newWord);
    }//input from file
    words.sort();
    //sort(words.begin(), words.end(), [](std::string s1, std::string s2){return s1 < s2; });//sort list
    std::cout << "sorted list:" << std::endl;//and print it
    for (std::string str : words){
        std::cout << str << " ";
    } std::cout << std::endl<<std::endl;
    //input letter and print words which starts from it
    char letter = ' ';
    std::cout << "input a letter: ";
    std::cin >> letter;
    std::cout << "words which starts from "<<letter<<":" << std::endl;
    for (std::string str : words){
        if (str[0] == letter) std::cout << str << " ";
    }std::cout << std::endl;
    //delete words
    std::list<std::string>::iterator p1 = find_if(words.begin(), words.end(), [letter](std::string str){return str[0] == letter; });
    std::list<std::string>::iterator p2 = find_if_not(p1, words.end(), [letter](std::string str){return str[0] == letter; });
    words.erase(p1, p2);
    //print altered list
    std::cout << "list after removing the elements:" << std::endl;
    for (std::string str : words){
        std::cout << str << " ";
    } std::cout << std::endl << std::endl;


}