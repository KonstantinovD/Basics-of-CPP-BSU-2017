#include "../include/TackInclude.h"

#include <fstream>
#include <math.h>
#include <iostream>
#include <cstdlib>

#include "localHeaders/stackADT.h"


static int priority(char operation)
{
    switch (operation)
    {
    case '(':{ return 1; }
    case '+': case '-':{ return 2; }
    case '*': case '/': { return 3; }
    case ')':{ return 0; }
    }
}

static void updateValuesStack(StackADT<int>& values, char operation)//Execute current operation with 2 upper values
{
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

static int convertToPoland(char* exp, int size)
{
    StackADT<char> opers;
    StackADT<int> values;

    if (false == (exp[0] == '(' || (exp[0] >= '0' && exp[0] <= '9'))){
        std::cout << "Incorrect input, task hasn't been executed ";
        return -1;
    }

    
    char lowerProritetOperand = '+';

    int signedNumber = 1;
    char* passNumber = new char[1];
    bool isProcessNumber = false;
    int currentValue = 0;
    int counterOfOperations = 1;
    for (int i = 0; i < size; i++)
    {
        if (isdigit(exp[i])){//reading number
            isProcessNumber = true;
            currentValue *= 10;
            passNumber[0] = exp[i];
            currentValue += atoi(passNumber);
        }
        else{
            if (isProcessNumber == true){//If we had read number just, push it into stack
                currentValue *= signedNumber;
                signedNumber = 1;
                values.push(currentValue);
                currentValue = 0;
                isProcessNumber = false;
                counterOfOperations = 0;
                
            }
            counterOfOperations++;//counter is used for discovering unary + or -, in case we have bracket, counter doesn't rise, because there can be a lot of brackets
            if (counterOfOperations > 1){//If we have a sing + or - before the number
                if (exp[i] == '+') continue;
                if (exp[i] == '-') {
                    signedNumber *= (-1);
                    continue;
                }
            }
            if (true == opers.isEmpty() || priority(exp[i]) > priority(opers.get()) || exp[i] == '(') {
                opers.push(exp[i]);
                if (exp[i] == '(') counterOfOperations--;
            }
            else{
                if (exp[i] == ')'){
                    while (opers.get() != '(')
                    {
                        updateValuesStack(values, opers.pop());
                    }
                    opers.pop();
                    counterOfOperations--;
                }
                else{
                    lowerProritetOperand = opers.pop();
                    opers.push(exp[i]);
                    updateValuesStack(values, lowerProritetOperand);
                }
            }

        }
    }
    if (isProcessNumber == true) { //We can to have the value at the end, but we don't have any operand to stop reading value ant push it into stack
        currentValue *= signedNumber;
        values.push(currentValue);
    }

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


