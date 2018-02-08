#include "WordNumber.h"

#include <iostream>

#include "..\..\include\TackInclude.h"



static void errorReport(const char*);
static void readNumberFromString(int, char*, int&);

WordNumber::WordNumber() : Word() {
    value = 0;
}

//the absolute value of WordNumber should be less or equals to the max value of integer type
WordNumber::WordNumber(const WordNumber& wordNmb) : Word(wordNmb) {
    readNumberFromString(lenght, wordStr, value);
}
WordNumber::WordNumber(char smb) : Word(smb) {
    readNumberFromString(lenght, wordStr, value);
}
//the absolute value of WordNumber should be less or equals to the max value of integer type
WordNumber::WordNumber(char* str) : Word(str) {
    readNumberFromString(lenght, wordStr, value);
}

int WordNumber::get(char* word){
    return Word::get(word);
}

//the absolute value of WordNumber should be less or equals to the max value of integer type
void WordNumber::set(const WordNumber& word)
{
    Word::set(word);
    value = word.value;
}
void WordNumber::set(char smb){
    Word::set(smb);
    readNumberFromString(lenght, wordStr, value);
}
//the absolute value of WordNumber should be less or equals to the max value of integer type
void WordNumber::set(char* word){
    Word::set(word);
    readNumberFromString(lenght, wordStr, value);
}
//the absolute value of Word should be less or equals to the max value of integer type
void WordNumber::set(Word& word)
{
    if (true == word.isWordNumber()){
        Word::set(word);
        readNumberFromString(lenght, wordStr, value);
    }   
}

int WordNumber::getNumber(){
    return value;
}

void WordNumber::setNumber(int number){
    value = number;

    lenght = 0;
    if(wordStr != nullptr)
        delete[] wordStr;

    int numberOrderCounter = value;
    while (numberOrderCounter > 0){
        numberOrderCounter /= 10;
        lenght++;
    }

    wordStr = new char[lenght];
    for (int i = (lenght-1); i > -1; i--){
        wordStr[i] = (number % 10 + '0');
        number /= 10;
    }
}

WordNumber& WordNumber::operator=(const WordNumber& word){
    this->Word::operator=((Word)word);
    this->value = word.value;

    return *this;
}

//does nothing in case absolute value of result is more than max value of integer type
WordNumber& WordNumber::operator+(const WordNumber& word){
    WordNumber res;
    double checkBorders = value + word.value;
    if (abs(checkBorders) <= INT_MAX){
        res.setNumber(value + word.value);
    }
    else{
        res.setNumber(value);
    }
    return res;
}

//does nothing in case absolute value of result is more than max value of integer type
WordNumber WordNumber::operator-(const WordNumber& word){
    WordNumber res;
    double checkBorders = value - word.value;
    if (abs(checkBorders) <= INT_MAX){
        res.setNumber(value - word.value);
    }
    else{
        res.setNumber(value);
    }
    return res;
}

//does nothing in case absolute value of result is more than max value of integer type
WordNumber WordNumber::operator*(const WordNumber& word){
    WordNumber res;
    double checkBorders = value * word.value;
    if (abs(checkBorders) <= INT_MAX){
        res.setNumber(value * word.value);
    }
    else{
        res.setNumber(value);
    }
    return res;
}


WordNumber WordNumber::operator/(const WordNumber& word){
    try{
        if (word.value == 0) throw "ERROR: division by zero(str-number, task 10)";
        WordNumber res;
        res.setNumber(value / word.value);
        return res;
    }
    catch (const char* message){
        errorReport(message);
    }
}

static void errorReport(const char* message){
    std::cerr << message;
    std::cerr << " Program will be closed\nInput any key to exit ";
    int waitForUser;
    //Sometimes we need to use "system("pause")", but it doesn't works in codeblock IDE, for instance; so it is better to use standart input stream
    std::cin >> waitForUser;
    exit(-1);
}

static void readNumberFromString(int lenght, char* wordStr, int& value){
    double* arrNumber = new double[lenght / 2 + 1];
    int sizeArrNumber = 0;
    readStr(wordStr, lenght, arrNumber, sizeArrNumber, true);
    try{
        if (sizeArrNumber != 1) {
            delete[] arrNumber;
            throw "ERROR: incorrect input of str-number(str-number, task 10)";
        }
        if (abs(arrNumber[0]) <= INT_MAX){
            value = arrNumber[0];
            delete[] arrNumber;
        }
        else throw "ERROR: value is bigger than max avaluable for str-number(equals to max integer value)";
        
    }
    catch (const char* message){
        errorReport(message);
    }
    catch (...){ std::cout << "Undefined error (str-number, task 10)" << std::endl; }
}