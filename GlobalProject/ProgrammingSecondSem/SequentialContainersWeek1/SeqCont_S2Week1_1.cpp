#include "../../include/TackInclude.h"
#include <vector>
#include <algorithm>
#include <iostream>

static void fullAlph(std::vector<char>& vect){
    char letter = 'A';
    while (letter <= 'Z'){
        vect.push_back(letter);
        letter++;
    }
}


void seqCont_S2Week1_1(std::ifstream &FIN){
    std::vector<char> alphabet;
    fullAlph(alphabet);
    

    for (auto it = alphabet.begin(); it != alphabet.end(); it++){
        std::cout << *it << " ";
    }std::cout << std::endl;
    for (auto it = alphabet.end()-1; it != alphabet.begin(); it--){
        std::cout << *it << " ";
    }
    if(false == alphabet.empty()) std::cout << alphabet.front();
    std::cout<< std::endl;

}