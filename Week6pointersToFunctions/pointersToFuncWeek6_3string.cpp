/*
#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

//If symbol is a numeral, or can be a part of number(like '-'), we return true
static bool compareElement(char symbol)
{
    char allSymb[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-' };
    for (int i = 0; i < 11; i++)
    {
        if (allSymb[i] == symbol) return true;
    }
    return false;
}

//Ordinary convertion from symbol to numeral
static int convertSymbolToNumeral(char symbol)
{
    char numerals[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = 0; i < 10; i++)
        if (numerals[i] == symbol) return i;
    return -1;
}

//Add current number to array
static void fullArrWithInteger(std::string, , double* arrConstants, int& sizeArr)
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

//find numbers in string which consist of numerals and '-'
static void turnStrToInteger(char* str, int size, double* arrConstants, int& sizeArr)
{
    if (1 == size && str[0] == '-') return; //number doesn't exist without numerals


    for (int i = 1; i < size; i++){
        if (str[i] == '-'){
            fullArrWithInteger(str, i, arrConstants, sizeArr);
            turnStrToInteger(str + i, size - i, arrConstants, sizeArr);
            return;
        }
    }

    fullArrWithInteger(str, size, arrConstants, sizeArr);
}

//Look through the string and find appropriate lines of numbers (only numerals and '-')
static void readStr(std::string &str, double* arrConstants, int& sizeArr)
{
    int isRecordedNow = false;//is we find an appropriate substring and we are finding now its end
    int beginningString = 0; //current element of string to pass it as a beginning of substring

    for (int i = 0; i < str.size(); i++)
    {
        if (compareElement(str[i]))
        {
            if (false == isRecordedNow) {
                newStr = str + i;
                isRecordedNow = true;
            }
            sizeOfNewStr++;

            if (i + 1 >= str.size()){
                turnStrToInteger(str, beginningString, arrConstants, sizeArr);
            }
        }
        else
        {
            if (true == isRecordedNow){
                turnStrToInteger(str, beginningString, arrConstants, sizeArr);
                isRecordedNow = false;
                sizeOfNewStr = 0;
            }
        }
    }
}






//Proccess the inputted line
static void constants10x(std::string &str10X)
{
    double* arrOfConstants10x = new double[(str10X.size() / 2) + 1];
    int sizeOfarr = 0;

    readStr(str10X, arrOfConstants10x, sizeOfarr);

    for (int i = 0; i < sizeOfarr; i++) std::cout << arrOfConstants10x[i] << " ";
    std::cout << std::endl;
    delete[] arrOfConstants10x;

}


void pointersToFuncWeek6_3(std::ifstream& FIN)
{
    FIN.open("resources/pointersToFuncWeek6_3.txt");
    int numberOfTests = 0;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int lenghtOfString = 0;
        FIN >> lenghtOfString;
        if (lenghtOfString < 1) continue;

        std::string symbolStr; //(lenghtOfString);
        std::getline(FIN, symbolStr);

        //for (int i = 0; i < lenghtOfString; i++) FIN >> symbolStr[i];

        constants10x(symbolStr);
    }
}
*/