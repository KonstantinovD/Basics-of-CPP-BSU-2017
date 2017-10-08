#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>

void integerArithmetic_1(std::ifstream& FIN, int valueFor5Tack)
{

    int numberOfTests;
    if (valueFor5Tack != -1)
    {
        numberOfTests = 1;
    }
    else
    {
        FIN.open("integerArithmetic_1.txt");
        FIN >> numberOfTests;
    }
    for (int i = 0; i < numberOfTests; i++)
    {
        bool differentNumbers[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        int naturalNumber;
        if (valueFor5Tack != -1)
        {
            naturalNumber = valueFor5Tack;
        }
        else
        {
            if (!FIN.eof()){
                FIN >> naturalNumber;
            }
        }


        if (naturalNumber == 0) //In case number is just a zero, we can't check its numerals by divisising
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

}