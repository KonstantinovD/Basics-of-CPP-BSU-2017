#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#include "../Week10Wordprocessing/localHeaders/task10functions.h"

//If symbol is a numeral, or can be a part of number(like '-' / '.' in case of double), we return true
static bool compareElement(char symbol, bool isDouble)
{
    //if (true == isDouble) endOfSymb++; 
    if ((symbol >= '0'&&symbol <= '9') || (symbol == '-') || 
        ((true == isDouble) && (symbol == '.'))) //in case of double
        return true;
    return false;
}

//get numeral from symbol 
static int convertSymbolToNumeral(char symbol)
{
    if ((symbol >= '0'&&symbol <= '9')) return (symbol - '0');
    if (symbol == '.') return 10;
    std::cout << "!!BAD WORK, MISTAKES!!!" << std::endl;
}

//fulling array with integer numbers
static void fullArrWithInteger(char* str, int size, double* arrConstants, int& sizeArr) 
{
    if (1 == size && str[0] == '-') return; //number doesn't exist without numerals

    int i = 0;
    bool isNegative = false;
    double tempVar = 0.0;

    if (str[i] == '-'){
        i = 1;
        isNegative = true;
    }

    while (i < size)
    {
        tempVar *= 10;
        tempVar += convertSymbolToNumeral(str[i]);
        i++;
    }

    if (true == isNegative) tempVar *= (-1);

    arrConstants[sizeArr] = tempVar;
    sizeArr++;
}

//fulling array with double numbers
static void fullArrWithDouble(char* str, int size, double* arrConstants, int& sizeArr)
{
    if (1 == size && str[0] == '-') return; //number doesn't exist without numerals

    if (size < 1) return;
    if (size == 1 && str[0] == '.' || size == 2 && str[0] == '-' && str[1] == '.') return;

    bool pointIsFound = false;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '.'){
            if(false == pointIsFound) {
                pointIsFound = true;
                continue;
            }
            else{
                fullArrWithDouble(str, i, arrConstants, sizeArr);
                fullArrWithDouble(str + i, size - i, arrConstants, sizeArr);
                return;
            }
        }
    }

    int i = 0;
    bool isNegative = false;
    
    
    if (str[i] == '-'){
        i = 1;
        isNegative = true;
    }

    double tempVar = 0.0;
    int tempNumeral = 0;
    while (i < size)
    {
        tempNumeral = convertSymbolToNumeral(str[i]);
        if (tempNumeral == 10){
            i++;
            break;
        }
        tempVar *= 10;
        tempVar += tempNumeral;
        i++;
    }
    int numeralDegree = 0;
    double tempDoubleNumeral;
    while (i < size)
    {
        numeralDegree--;
        tempDoubleNumeral = (double)convertSymbolToNumeral(str[i]);
        tempVar += tempDoubleNumeral*pow(10, numeralDegree);
        i++;
    }

    if (true == isNegative) tempVar *= (-1);

    arrConstants[sizeArr] = tempVar;
    sizeArr++;
}

//find numbers in string which consist of numerals and '-' ('.' will be proccessed at the next step)
static void turnStrToNumber(char* str, int size, double* arrConstants, int& sizeArr, bool isDouble)
{
    if (1 == size && str[0] == '-') return; //number doesn't exist without numerals

    for (int i = 1; i < size; i++){
        if (str[i] == '-'){
            if (false == isDouble) fullArrWithInteger(str, i, arrConstants, sizeArr);
            else fullArrWithDouble(str, i, arrConstants, sizeArr);
            turnStrToNumber(str + i, size - i, arrConstants, sizeArr, isDouble);
            return;
        }
    }

    if (false == isDouble) fullArrWithInteger(str, size, arrConstants, sizeArr);
    else fullArrWithDouble(str, size, arrConstants, sizeArr);
}

//Looks through the string and find appropriate lines of numbers (only numerals and '-'/ and '.' in case of double)
void readStr(char* str, int size, double* arrConstants, int& sizeArr, bool isDouble)
{
    int isRecordedNow = false;
    char* newStr = str; //char* will be passed and converted to int
    int sizeOfNewStr = 0;

    bool(*compare)(char);


    for (int i = 0; i < size; i++)
    {
        if (compareElement(str[i], isDouble))
        {
            if (false == isRecordedNow) {
                newStr = str + i;
                isRecordedNow = true;
            }
            sizeOfNewStr++;

            if (i + 1 >= size){
                //for (int i = 0; i < sizeOfNewStr; i++) std::cout << newStr[i] << " ";
                //std::cout << " ---     ";
                turnStrToNumber(newStr, sizeOfNewStr, arrConstants, sizeArr, isDouble);
            }
        }
        else
        {
            if (true == isRecordedNow){
                //for (int i = 0; i < sizeOfNewStr; i++) std::cout << newStr[i] << " ";
                //std::cout << " -!-     ";
                turnStrToNumber(newStr, sizeOfNewStr, arrConstants, sizeArr, isDouble);
                isRecordedNow = false;
                sizeOfNewStr = 0;
            }
        }
    }
}






//Proccess the inputted line
static void constants10x(char* str10X, int& size, bool isDouble)
{
    double* arrOfConstants10x = new double[(size / 2) + 1];
    int sizeOfarr = 0;

    readStr(str10X, size, arrOfConstants10x, sizeOfarr, isDouble);

    for (int i = 0; i < sizeOfarr; i++) std::cout << arrOfConstants10x[i] << " ";
    std::cout << std::endl;
    delete[] arrOfConstants10x;

}



void pointersToFuncWeek6_4(std::ifstream& FIN)
{
    FIN.open("resources/pointersToFuncWeek6_4.txt");
    int numberOfTests = 0;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int isIntegerInput = 0;
        bool isDouble = false;
        FIN >> isIntegerInput;
        if (isIntegerInput >= 0) isDouble = false;
        else isDouble = true;


        int lenghtOfString = 0;
        FIN >> lenghtOfString;
        if (lenghtOfString < 1) continue;

        char* symbolStr = new char[lenghtOfString];

        for (int i = 0; i < lenghtOfString; i++) FIN >> symbolStr[i];

        constants10x(symbolStr, lenghtOfString, isDouble);

        delete[] symbolStr;
    }
}