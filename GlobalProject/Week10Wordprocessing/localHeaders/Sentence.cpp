#include "Sentence.h"
#include <iostream>

static void errorReport(const char*);
static int deleteSpaces(char*&, char*, int);
static int checkIsSubstring(char*, int, char*, int);
bool isPunctuationMark(char);



Sentence::Sentence()
{
    lenght = 0;
    sentenceStr = nullptr;
}

Sentence::Sentence(const Sentence& phrase)//already formed phrase is correct, we don't need to check it
{
    lenght = phrase.lenght;
    if (lenght < 1){
        lenght = 0;
        sentenceStr = nullptr;
    }
    else{
        sentenceStr = new char[lenght];
        for (int i = 0; i < lenght; i++){
            sentenceStr[i] = phrase.sentenceStr[i];
        }
    }
}

Sentence::Sentence(char smb){
    sentenceStr = new char[1];
    sentenceStr[0] = smb;
    lenght = 1;
}

Sentence::Sentence(char* str){
    if (strlen(str)<1){
        lenght = 0;
        sentenceStr = nullptr;
    }
    else lenght = deleteSpaces(sentenceStr, str, strlen(str));
}

Sentence::~Sentence(){
    if (sentenceStr != nullptr) delete[] sentenceStr;
}

int Sentence::get(char*& str, bool isCStr){
    Word serviceBuff;
    serviceBuff.set(sentenceStr, lenght);
    return serviceBuff.get(str, isCStr);
}

char Sentence::get(int index){
    try{
        if (index < 0 || index >= lenght) throw "ERROR: index is out of array";
        return sentenceStr[index];
    }
    catch (const char* message){
        errorReport(message);
    }
}

void Sentence::set(const Sentence& phrase){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    lenght = phrase.lenght;
    if (lenght < 1){
        lenght = 0;
        sentenceStr = nullptr;
    }
    else{
        sentenceStr = new char[lenght];
        for (int i = 0; i < lenght; i++){
            sentenceStr[i] = phrase.sentenceStr[i];
        }
    }
}

void Sentence::set(char smb){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    lenght = 1;
    sentenceStr = new char[1];
    sentenceStr[0] = smb;
}

void Sentence::set(char* phrase){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    lenght = deleteSpaces(sentenceStr, phrase, strlen(phrase));
}

void Sentence::set(char* phrase, int size){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    lenght = deleteSpaces(sentenceStr, phrase, size);
}


Sentence& Sentence::operator=(const Sentence& phrase){
    if (sentenceStr == phrase.sentenceStr) return *this;

    if (lenght > 0){ delete[] sentenceStr; }
    lenght = phrase.lenght;
    sentenceStr = new char[phrase.lenght];
    for (int i = 0; i < lenght; i++){
        sentenceStr[i] = phrase.sentenceStr[i];
    }
    return *this;
}

Sentence& Sentence::operator+=(const Sentence& phrase){
    try{
        char* mergeArr = new char[lenght + phrase.lenght];

        for (int i = 0; i < lenght; i++) mergeArr[i] = sentenceStr[i];
        for (int i = 0; i < phrase.lenght; i++) mergeArr[i + lenght] = phrase.sentenceStr[i];

        delete[] sentenceStr;
        sentenceStr = mergeArr;
        lenght = lenght + phrase.lenght;
        return *this;
    }
    catch (...){
        std::cout << "UNEXPECTED ERROR(in method Sentence::operator+= )" << std::endl;
    }
}

bool Sentence::operator==(Sentence& phrase)
{
    Word serviceBuffFirst, serviceBuffSecond;
    serviceBuffFirst.set(sentenceStr, lenght);
    serviceBuffSecond.set(phrase.sentenceStr, phrase.lenght);

    return serviceBuffFirst == serviceBuffSecond;
}

bool Sentence::operator>(Sentence& phrase)
{
    Word serviceBuffFirst, serviceBuffSecond;
    serviceBuffFirst.set(sentenceStr, lenght);
    serviceBuffSecond.set(phrase.sentenceStr, phrase.lenght);

    return serviceBuffFirst > serviceBuffSecond;
}

bool Sentence::operator<(Sentence& phrase)
{
    return phrase > *this;
}

std::ostream& operator<<(std::ostream& streamOutput, const Sentence& phrase){
    for (int i = 0; i < phrase.lenght; i++){
        streamOutput << phrase.sentenceStr[i];
    }
    return streamOutput;
}


int Sentence::getLenght(){
    return lenght;
}

void Sentence::clear(){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    sentenceStr = nullptr;
    lenght = 0;
}

//functions of processing the words


int Sentence::findWord(char* word, int position){
    return findWord(strlen(word), word, position);
}

int Sentence::findWord(int size, char* word, int position){
    try{
        if (position < 0 || position >= lenght) return -1;
        if (size > lenght - position) return -1;
        int localPos = checkIsSubstring(sentenceStr + position, lenght - position, word, size);
        return localPos;
    }
    catch (...){
        std::cout << "UNEXPECTED ERROR in Sentence::findWord (index probably is out of array)" << std::endl;
        return -1;
    }
}



//additional functions

static void errorReport(const char* message){
    std::cerr << message;
    std::cerr << " Program will be closed\nInput any key to exit ";
    int waitForUser;
    //Sometimes we need to use "system("pause")", but it doesn't works in codeblock IDE, for instance; so it is better to use standart input stream
    std::cin >> waitForUser;
    exit(-1);
}

static int deleteSpaces(char*& firstStr, char* secondStr, int sizeOfSecond)//We leave only one space instead of tab\tabs or more than one spaces
{
    try{
        int substractedPoints = 0;
        bool isRepeated = false;
        for (int i = 0; i < sizeOfSecond; i++){
            if (secondStr[i] == ' ' || secondStr[i] == '\t'){
                if (isRepeated == true) substractedPoints++;
                isRepeated = true;
                continue;
            }
            isRepeated = false;
        }

        int resSize = sizeOfSecond - substractedPoints;
        firstStr = new char[resSize];

        isRepeated = false;
        int iter = 0;
        for (int i = 0; i < sizeOfSecond; i++){
            if (secondStr[i] == ' ' || secondStr[i] == '\t'){
                if (isRepeated == true){
                    continue;
                }
                isRepeated = true;
                firstStr[iter] = ' ';
                iter++;
                continue;
            }
            isRepeated = false;
            firstStr[iter] = secondStr[i];
            iter++;
        }
        return resSize;
    }
    catch (...){
        std::cout << "UNEXPECTED ERROR(in method Sentence::operator+= )\nProgram will be closed. Press any key to continue" << std::endl;
        int tempExcValue = 0;
        std::cin >> tempExcValue;
        exit(-1);
    }
}

static int checkIsSubstring(char* container, int lenFirst, char* pattern, int lenSecond){
    int iter = 0;
    int i = 0;
    bool isRecordedNow = false;
    int startPos = 0;

    while (i < lenFirst){
        if (container[i] != pattern[iter]){
            if (true == isRecordedNow){//if we have just read pattern
                isRecordedNow = false;//don't read pattern at all
                iter = 0;//wait for reading from the beginning of the pattern
            }
            i++;
        }
        else{
            if (isRecordedNow == false){//if we met the first symbol of pattern
                isRecordedNow = true;
                startPos = i;
            }
            iter++;//move to the new position of pattern to compare
            i++;
            if (iter == lenSecond){
                if ((i < lenFirst && false == isPunctuationMark(container[i]) ) || (startPos != 0 && false == isPunctuationMark(container[startPos-1]) ))//if we have found word in word
                {
                    isRecordedNow == false;
                    iter = 0;
                    continue;
                }

                return startPos;
            }
        }
    }
    return -1;
}

bool isPunctuationMark(char smb)
{
    switch (smb)
    {
    case '.': case ',': case '\"': case '!': case '?': case ':': case ';': case '(':case ')': case '-':case ' ': return true;
    }
    return false;
}