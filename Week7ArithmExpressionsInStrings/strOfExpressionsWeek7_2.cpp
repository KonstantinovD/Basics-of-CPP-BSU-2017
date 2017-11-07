#include "../include/TackInclude.h"

#include <fstream>
#include <math.h>
#include <iostream>
#include <cstdlib>

#include "localHeaders\stackADT.h"

int priority(char operation)
{
    switch (operation)
    {
    case '(':{ return 1; }
    case '+': case '-':{ return 2; }
    case '*': case '/': { return 3; }
    case ')':{ return 0; }
    }
}

void updateValuesStack(StackADT<int>& values, char operation)
{
    //Maybe I chould have made the checking is stack isn't empty between b and a 
    int b = values.pop(),
        a = values.pop(),
        res = 0;

    switch (operation)
    {
    case '+': { res = a + b; break; }
    case '-': { res = a - b; break; }
    case '*': { res = a * b; break; }
    case '/': { res = a / b; break; }
    }

    values.push(res);
}

int convertToPoland(char* exp, int size)
{
    StackADT<char> opers;
    StackADT<int> values;

    bool isProcessNumber = false;
    int currentValue = 0;

    char* passNumber = new char[1];

    int poppedOper = '+';

    for (int i = 0; i < size; i++)
    {
        if (isdigit(exp[i])){
            isProcessNumber = true;
            currentValue *= 10;
            passNumber[0] = exp[i];
            currentValue += atoi(passNumber);
        }
        else{
            if (isProcessNumber == true){
                values.push(currentValue);
                currentValue = 0;
                isProcessNumber = false;
            }
            if (true == opers.isEmpty() || priority(exp[i]) > priority(opers.get())||exp[i] == '(') opers.push(exp[i]);//'*' compares to '(' and all crashed
            else{
                if (exp[i] == ')'){
                    while (opers.get() != '(')
                    {
                        updateValuesStack(values, opers.pop());
                    }
                    opers.pop();
                }
                else{
                    poppedOper = opers.pop();
                    opers.push(exp[i]);
                    updateValuesStack(values, poppedOper);
                }
            }
        }
    }
    if (isProcessNumber == true) values.push(currentValue); //We can to have the value at the end

    while (false == opers.isEmpty())
    {
        updateValuesStack(values, opers.pop());
    }

    delete[] passNumber;

    return values.pop();
}


void strOfExpressionsWeek7_2(std::ifstream& FIN)
{
    FIN.open("resources/strOfExpressionsWeek7_2.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfStr = 0;
        FIN >> sizeOfStr;
        char* expression = new char[sizeOfStr];

        for (int i = 0; i < sizeOfStr; i++) FIN >> expression[i];

        std::cout << convertToPoland(expression, sizeOfStr) << std::endl;

        delete[] expression;
    }

}


