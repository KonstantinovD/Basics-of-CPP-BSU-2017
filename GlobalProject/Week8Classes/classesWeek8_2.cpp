#include "../include/TackInclude.h"


#include <fstream>
#include <iostream>

#include "localHeaders/ComplexNumber.h"
#include "../Week7ArithmExpressionsInStrings/localHeaders/stackADT.h"

static void stackForComplexNumbers(std::ifstream& FIN){//using stackADT with ComplexNumber class
    int numberOfPushedComplex = 0;
    FIN >> numberOfPushedComplex;

    StackADT<ComplexNumber> stackComplex;
    ComplexNumber storageNumber;
    double inputReZ = 0.0,
        inputImZ = 0.0;
    

    for (int i = 0; i < numberOfPushedComplex; i++)
    {
        FIN >> inputReZ >> inputImZ;
        storageNumber.assign(inputReZ, inputImZ);//initialise the current complex

        stackComplex.push(storageNumber);//push the current complex
    }

    std::cout << "---------------------" << std::endl;//border line between the tests
    for (int i = 0; i < numberOfPushedComplex; i++)
    {
        storageNumber.assign(stackComplex.pop());
        storageNumber.show();
    }
}

void classesWeek8_2(std::ifstream& FIN)
{
    FIN.open("resources/classesWeek8_2.txt");
    int numberOfTests = 0;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        stackForComplexNumbers(FIN);
    }
}