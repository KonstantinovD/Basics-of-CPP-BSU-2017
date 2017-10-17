#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

static void constants10x(int size)
{
    bool isFoundSymbol = false;

    char allSymb[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
    int symbolCode[10];
    for (int i = 0; i < 10; i++) {
        symbolCode[i] = int(allSymb[i]);
    }
    std::cout << std::endl;
    std::sort(symbolCode, symbolCode+10);

    for (int i = 0; i < size; i++)
    {
        
    }
}


void pointersToFuncWeek6_3(std::ifstream& FIN)
{
    FIN.open("resources/pointersToFuncWeek6_3.txt");
    int numberOfTests = 0;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int lenghtOfString = 0;
        FIN >> lenghtOfString;
        if (lenghtOfString < 1) continue;

        char* symbolStr = new char[lenghtOfString];

        constants10x(lenghtOfString);

        delete[] symbolStr;
    }
}