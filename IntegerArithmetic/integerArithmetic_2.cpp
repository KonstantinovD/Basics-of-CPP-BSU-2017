#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>

bool isAntrophomorph(unsigned int number)//Check is our number is antrophomorph
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


void integerArithmetic_2(std::ifstream& FIN, int valueFor5Tack)
{
    int numberOfTests = 0;

    if (valueFor5Tack != -1)
    {
        numberOfTests = 1;
    }
    else
    {
        FIN.open("integerArithmetic_2.txt");
        FIN >> numberOfTests;
    }


    for (int i = 0; i < numberOfTests; i++)
    {
        unsigned int naturalNumber;

        if (valueFor5Tack != -1)
        {
            naturalNumber = valueFor5Tack;
        }
        else
        {
            FIN >> naturalNumber;
        }
        if (naturalNumber >= 0 && naturalNumber < sqrt(4000000000))
        {
            for (unsigned int i = 1; i < naturalNumber; i++)
            {
                if (true == isAntrophomorph(i)) std::cout << i << " ";
            }
            std::cout << std::endl;
        }
        else std::cout << "Incorrect number" << std::endl;
    }
}