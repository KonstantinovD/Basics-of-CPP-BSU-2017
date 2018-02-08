#include "..\include\TackInclude.h"
#include <fstream>
#include <iostream>

#include "LocalHeaders\Series.h"
#include "LocalHeaders\Exponential.h"
#include "LocalHeaders\Liner.h"

static void workWithProgression(bool isLinear, std::ofstream& FOUT)
{
    double fVal, sVal;
    std::cout << "input first member of progression: ";
    std::cin >> fVal;
    std::cout << "input decrementant of progression: ";
    std::cin >> sVal;
    Series* mathSer;
    if (true == isLinear){
        mathSer = new Liner(fVal, sVal);
    }
    else{
        mathSer = new Exponential(fVal, sVal);
    }

    unsigned int element;
    std::cout << "input number of progression member: ";
    std::cin >> element;
    std::cout << mathSer->getElement(element) << std::endl;

    std::cout << "input member of linear progression to count progression sum from the first to this: ";
    std::cin >> element;
    std::cout << mathSer->seriesSum(element) << std::endl;

    

    std::cout << "To output progression to file, input number of progression member to stop on it: ";
    std::cin >> element;
    for (int i = 1; i <= element; i++){
        FOUT << mathSer->getElement(i) << " ";
    }

    delete mathSer;
}

void abstractVirtualWeek12_1(std::ifstream& FIN){
    std::ofstream FOUT;
    FOUT.open("resources/programOutput/Week12_1output1.txt");
    workWithProgression(true, FOUT);
    FOUT.close();
    FOUT.open("resources/programOutput/Week12_2output1.txt");
    workWithProgression(false, FOUT);
    FOUT.close();
}