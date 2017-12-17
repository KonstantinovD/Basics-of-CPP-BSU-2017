#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <string>

//If symbol is a numeral, or can be a part of number(like '-'), we return true
static bool compareElement(char symbol)
{
    if ((symbol >= '0'&&symbol <= '9') || (symbol == '-')) return true;
    return false;
}

//Ordinary convertion from symbol to numeral
static int convertSymbolToNumeral(char symbol)
{
    if (symbol >= '0' && symbol <= '9') return (symbol - '0');
    return -1;
}

//Add current number to array
static void fullArrWithInteger(std::string& str, int beginIterator, int endIterator, double* arrConstants, int& sizeArr)
{
    if (endIterator - beginIterator < 1 || endIterator - beginIterator == 1 && str[beginIterator] == '-') return; //number doesn't exist without numerals
    int i = beginIterator;
    bool isNegative = false;
    double tempVar = 0.0;

    if (str[i] == '-'){
        i++;
        isNegative = true;
    }

    while (i < endIterator)
    {
        tempVar *= 10;
        tempVar += convertSymbolToNumeral(str[i]);
        i++;
    }

    if (true == isNegative) tempVar *= (-1);

    arrConstants[sizeArr] = tempVar;
    sizeArr++;
}

//find numbers in string which consist of numerals and '-'
static void turnStrToInteger(std::string& str, int beginIterator, int endIterator, double* arrConstants, int& sizeArr)
{
   // int size = endIterator - beginIterator;

    if (endIterator - beginIterator < 1 || (endIterator - beginIterator == 1 && str[beginIterator] == '-')) return; //number doesn't exist without numerals


    for (int i = beginIterator+1; i < endIterator; i++){
        if (str[i] == '-'){

            fullArrWithInteger(str, beginIterator, i, arrConstants, sizeArr);
            turnStrToInteger(str, i, endIterator, arrConstants, sizeArr);
            return;
        }
    }

    fullArrWithInteger(str, beginIterator, endIterator, arrConstants, sizeArr);
}

//Look through the string and find appropriate lines of numbers (only numerals and '-')
static void readStr(std::string& str, double* arrConstants, int& sizeArr)
{
    int isRecordedNow = false;
    int startSymbol = 0; //We need to pass a start point of substring

    for (int i = 0; i < str.size(); i++)
    {
        if (compareElement(str[i]))
        {
            if (false == isRecordedNow) {
                startSymbol = i;
                isRecordedNow = true;
            }

            if (i + 1 >= str.size()){
                turnStrToInteger(str, startSymbol, i, arrConstants, sizeArr);
            }
        }
        else
        {
            if (true == isRecordedNow){
                turnStrToInteger(str, startSymbol, i, arrConstants, sizeArr);
                isRecordedNow = false;
            }
        }
    }
}






//Proccess the inputted line
static void constants10x(std::string& str10X)
{
    double* arrOfConstants10x = new double[(str10X.size() / 2) + 1];
    int sizeOfarr = 0;

    readStr(str10X, arrOfConstants10x, sizeOfarr);

    for (int i = 0; i < sizeOfarr; i++) std::cout << arrOfConstants10x[i] << " ";
    std::cout << std::endl;
    delete[] arrOfConstants10x;

}


void pointersToFuncWeek6_3string(std::ifstream& FIN)
{
    FIN.open("resources/pointersToFuncWeek6_3.txt");
    int numberOfTests = 0;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int lenghtOfString = 0;
        FIN >> lenghtOfString;
        FIN.get();

        std::string symbolStr;
        std::getline(FIN, symbolStr);

        constants10x(symbolStr);

    }
}