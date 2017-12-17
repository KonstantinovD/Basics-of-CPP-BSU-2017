#include "Word.h"
#include <iostream>
#include <cstring>

#include "..\..\include\TackInclude.h"


static void errorReport(const char*);

Word::Word(){
    lenght = 0;
    wordStr = nullptr;
}

Word::Word(const Word& word){
    if (word.lenght < 1){
        lenght = 0;
        wordStr = nullptr;
    }
    else{
        wordStr = new char[word.lenght];
        lenght = word.lenght;
        for (int i = 0; i < lenght; i++)
            wordStr[i] = word.wordStr[i];
    }
}

Word::Word(char smb){
    lenght = 1;
    wordStr = new char[1];
    wordStr[0] = smb;
}

Word::Word(char* word){
    lenght = strlen(word);
    if (lenght > 0){
        wordStr = new char[lenght];
        for (int i = 0; i < lenght; i++){ wordStr[i] = word[i]; }
    }
    else{
        lenght = 0;
        wordStr = nullptr;
    }
}

Word::Word(char* word, int size){
    lenght = size;
    if (lenght > 0){
        wordStr = new char[lenght];
        for (int i = 0; i < lenght; i++){ wordStr[i] = word[i]; }
    }
    else{
        lenght = 0;
        wordStr = nullptr;
    }
}

Word::~Word(){
    if (lenght > 0){ delete[] wordStr; }
}

int Word::get(char*& word, bool isCStr){

    try{
        if (isCStr == false){
            if (word != nullptr) delete[] word;
            if (lenght < 1) {
                word = nullptr;
                return 0;
            }
            word = new char[lenght];
            for (int i = 0; i < lenght; i++){
                word[i] = wordStr[i];
            }
            return lenght;
        }
        else{
            if (lenght < 1) {
                word = "\0";
                return 0;
            }
            word = new char[lenght + 1];
            for (int i = 0; i < lenght; i++){
                word[i] = wordStr[i];
            }
            word[lenght] = '\0';
            return lenght;
        }
        
    }
    catch (...){
        std::cout << "ERROR: unable to get Word (in method int Word::get(char*) )" << std::endl;
        return -1;
    }
}

char Word::get(int index){
    try{
        if (index < 0 || index >= lenght) throw "ERROR: index is out of array";
        return wordStr[index];
    }
    catch (const char* message){
        errorReport(message);
    }
}

void Word::set(const Word& word){
    if (lenght > 0){ delete[] wordStr; }
    if (word.lenght < 1){
        lenght = 0;
        wordStr = nullptr;
    }
    else{
        wordStr = new char[word.lenght];
        for (int i = 0; i < lenght; i++)
            wordStr[i] = word.wordStr[i];
    }
}

void Word::set(char smb){
    if (lenght > 0){ delete[] wordStr; }
    wordStr = new char[1];
    wordStr[0] = smb;
    lenght = 1;
}

void Word::set(char* word){
    lenght = strlen(word);
    if (lenght > 0){
        if (lenght > 0){ delete[] wordStr; }
        wordStr = new char[lenght];
        for (int i = 0; i < lenght; i++){ wordStr[i] = word[i]; }
    }
    else{
        lenght = 0;
        wordStr = nullptr;
    }
}

void Word::set(char* word, int size){
    if (lenght > 0){ delete[] wordStr; }

    lenght = size;
    if (lenght > 0){
        wordStr = new char[lenght];
        for (int i = 0; i < lenght; i++){ wordStr[i] = word[i]; }
    }
    else{
        lenght = 0;
        wordStr = nullptr;
    }
}

bool Word::isPalindrom(){
    if (lenght < 1) return false;
    else{
        int leftBorder = 0,
            rightBorder = lenght - 1;
        while (rightBorder >= leftBorder){
            if (wordStr[leftBorder] != wordStr[rightBorder]) return false;
            rightBorder--;
            leftBorder++;
        }
        return true;
    }
}

Word& Word::operator=(Word& word){
    if (wordStr == word.wordStr) return *this;

    if (lenght > 0){ delete[] wordStr; }
    lenght = word.lenght;
    wordStr = new char[word.lenght];
    for (int i = 0; i < lenght; i++){
        wordStr[i] = word.wordStr[i];
    }
    return *this;
}

bool Word::operator==(Word& word){
    if (lenght != word.lenght) return false;
    for (int i = 0; i < lenght; i++){
        if (wordStr[i] != word.wordStr[i]) return false;
    }
    return true;
}

bool Word::isWordNumber(){
    double* arrNumber = new double[lenght/2 + 1];
    int sizeArrNumber = 0;
    readStr(wordStr, lenght, arrNumber, sizeArrNumber, false);
    if (sizeArrNumber != 1 || abs(arrNumber[0]) > INT_MAX) {
        delete[] arrNumber;
        return false;
    }
    delete[] arrNumber;
    return true;
}

bool Word::operator>(Word& word){
    if (lenght > word.lenght) return true;//If first word is longer than second
    if (lenght == word.lenght){
        for (int i = 0; i < lenght; i++){
            if (wordStr[i] != word.wordStr[i])
                return (wordStr[i] - word.wordStr[i]);
        }
    }
    return false;
}

bool Word::operator<(Word& word){
    return(word > *this);
}

std::ostream& operator<<(std::ostream& streamOutput, const Word& word){
    for (int i = 0; i < word.lenght; i++){
        streamOutput << word.wordStr[i];
    }
    return streamOutput;
}

int Word::getLenght(){ return lenght; }

void Word::clear(){
    lenght = 0;
    if (wordStr != nullptr) {
        delete wordStr;
        wordStr = nullptr;
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