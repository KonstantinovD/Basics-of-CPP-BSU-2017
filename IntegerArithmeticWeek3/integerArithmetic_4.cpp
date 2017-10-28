#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <math.h>

static bool isPerfect(int number)
{
    int resultSum = 1;

    int root = sqrt(number);

    for (int i = 2; i < root; i++)
    {
        if (number % i == 0)
        {
            resultSum += i;
            resultSum += number / i;
        }
    }

    if (number / root == root && number % root == 0)  resultSum += root;

    if (resultSum == number) return true;
    else return false;
}

void findPerfectNumbers(int naturalNumber)
{
    if (naturalNumber > 0)
    {
        for (int i = 1; i <= naturalNumber; i++)
        {
            if (true == isPerfect(i)) std::cout << i << " ";
        }
        std::cout << std::endl;

    }
    else std::cout << "Incorrect number" << std::endl;
}

void integerArithmetic_4(std::ifstream& FIN)
{

    int numberOfTests;
    FIN.open("resources/integerArithmetic_4.txt");
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int naturalNumber;
        FIN >> naturalNumber;

        findPerfectNumbers(naturalNumber);
    }
}