#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <math.h>

int greatestCommonDivisor(int firstValue, int secondValue) {
    if (secondValue == 0)
        return abs(firstValue);
    return greatestCommonDivisor(secondValue, firstValue % secondValue);
}


void integerArithmetic_3(std::ifstream& FIN, int valueFor5Tack)
{

    int numberOfTests;
    if (valueFor5Tack != -1)
    {
        numberOfTests = 1;
    }
    else
    {
        FIN.open("integerArithmetic_3.txt");
        FIN >> numberOfTests;
    }
    for (int i = 0; i < numberOfTests; i++)
    {
        int naturalNumber;
        if (valueFor5Tack != -1)
        {
            naturalNumber = valueFor5Tack;
        }
        else
        {
            FIN >> naturalNumber;
        }
        if (naturalNumber < 1) {
            std::cout << "incorrect number" << std::endl;
            std::cout << std::endl;
            continue;
        }


        for (int i = naturalNumber; i > 0; i--)
        {
            if (1 == greatestCommonDivisor(i, naturalNumber)){
                std::cout << i << "/" << naturalNumber << "   ";
            }
        }
        std::cout << std::endl << std::endl;
    }
}