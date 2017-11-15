#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <math.h>

static int greatestCommonDivisor(int firstValue, int secondValue) {
    if (secondValue == 0)
        return abs(firstValue);
    return greatestCommonDivisor(secondValue, firstValue % secondValue);
}

static void findDecimal(int naturalNumber)
{
    if (naturalNumber < 1) {
        std::cout << "incorrect number" << std::endl;
        std::cout << std::endl;
    }


    for (int i = naturalNumber; i > 0; i--)
    {
        if (1 == greatestCommonDivisor(i, naturalNumber)){
            std::cout << i << "/" << naturalNumber << "   ";
        }
    }
    std::cout << std::endl << std::endl;
}


void integerArithmetic_3(std::ifstream& FIN)
{
    int numberOfTests;
    FIN.open("resources/integerArithmetic_3.txt");
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int naturalNumber;
        FIN >> naturalNumber;

        findDecimal(naturalNumber);
    }
}