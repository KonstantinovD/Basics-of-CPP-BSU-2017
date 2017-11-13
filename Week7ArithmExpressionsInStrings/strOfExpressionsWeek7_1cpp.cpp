#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>

#include "localHeaders\stackADT.h"

static bool isExpressionCorrect(char* str, int size)//Check the correction of the bracket sequence
{
    StackADT<char> bracketStack;
    char compareSymbol = '?';

    for (int i = 0; i < size; i++)
    {
        if (str[i] == '{' || str[i] == '[') bracketStack.push(str[i]);
        if (str[i] == '}' || str[i] == ']'){
            compareSymbol = '?'; //if stack doesn't return any symbol, we will compare this with closing bracket
            compareSymbol = bracketStack.pop();
            if (str[i] == '}' && compareSymbol != '{') return false;
            if (str[i] == ']' && compareSymbol != '[') return false;
        }
    }
    if (!bracketStack.isEmpty()) return false;//If not all opening bracked have the closing for it
    else return true;
}

void strOfExpressionsWeek7_1(std::ifstream& FIN)
{
    FIN.open("resources/strOfExpressionsWeek7_1.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfStr = 0;
        FIN >> sizeOfStr;
        char* expression = new char[sizeOfStr];

        for (int i = 0; i < sizeOfStr; i++) FIN >> expression[i];

        if (true == isExpressionCorrect(expression, sizeOfStr)) std::cout << "Expression is correct" << std::endl;
        else std::cout << "Expression is incorrect" << std::endl;

        delete[] expression;
    }

}