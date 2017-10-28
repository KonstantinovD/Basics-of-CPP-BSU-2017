#include "../include/TackInclude.h"
#include "localHeaders/tack5functions.h"

#include <fstream>
#include <iostream>

static bool isAntrophomorph(unsigned int number)//Check is our number is antrophomorph
{
    int sqrNumber = number*number;

    while (number > 0)
    {
        if (number % 10 != sqrNumber % 10) return false;//compare the first numerals of two numbers
        number /= 10;
        sqrNumber /= 10;
    }
    return true;
}

void findAntrophomorphNumbers(unsigned int naturalNumber)
{
    if (naturalNumber >= 0 && naturalNumber < sqrt(UINT_MAX))
    {
        for (unsigned int i = 1; i < naturalNumber; i++)
        {
            if (true == isAntrophomorph(i)) std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    else std::cout << "Incorrect number" << std::endl;
}

void integerArithmetic_2(std::ifstream& FIN)
{
    int numberOfTests;
    FIN.open("resources/integerArithmetic_2.txt");
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        unsigned int naturalNumber;
        FIN >> naturalNumber;

        findAntrophomorphNumbers(naturalNumber);
    }
}