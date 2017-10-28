#include "../include/TackInclude.h"
#include "localHeaders/tack5functions.h"

#include <fstream>
#include <iostream>


void countDifferentNumbers(int naturalNumber)
{
    bool differentNumbers[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    if (naturalNumber == 0) //In case number is just a zero, we can't check its numerals by divising
    {
        differentNumbers[0] = true;
    }
    while (naturalNumber > 0)
    {
        int currentNumeral = naturalNumber % 10;
        naturalNumber /= 10;
        differentNumbers[currentNumeral] = true;
    }

    int numberDifferentNumerals = 0;
    for (int i = 0; i < 10; i++)
    {
        if (true == differentNumbers[i])
            numberDifferentNumerals++;
    }
    std::cout << numberDifferentNumerals << std::endl;
}

void integerArithmetic_1(std::ifstream& FIN)
{
    int numberOfTests;
    FIN.open("resources/integerArithmetic_1.txt");
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int naturalNumber;
        if (!FIN.eof()){
            FIN >> naturalNumber;
        }

        countDifferentNumbers(naturalNumber);

    }

}