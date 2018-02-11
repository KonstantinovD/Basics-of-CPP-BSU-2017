#include "../../include/TackInclude.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void stlPractW2_1(std::ifstream& FIN){
    FIN.open("resources/stlPracrW2_1.txt");


    std::vector<int> vect;
    int takenInt;
    while (!FIN.eof()){
        FIN >> takenInt;
        vect.push_back(takenInt);
    }

    std::cout<<"max element is: "<<*std::max_element(vect.begin(), vect.end())<<std::endl;
    std::cout << "input a number to count how many times it appears in vector: ";
    std::cin >> takenInt;
    std::cout << takenInt << ": " << std::count(vect.begin(), vect.end(), takenInt) << " times" << std::endl;
    std::cout << "there are " << std::count_if(vect.begin(), vect.end(), [&takenInt](int n){return n > takenInt; }) << " numbers which are greater than" << takenInt << std::endl;
    std::cout << "there are " << vect.size() << " elements in vector";
    int sum = std::accumulate(vect.begin(), vect.end(), 0);
    std::cout << "their sum is " << sum << std::endl;
    std::cout << "middle ariphm. is " << ((double)sum)/vect.size() << std::endl;
}

