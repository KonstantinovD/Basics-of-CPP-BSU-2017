#include "Sentence.h"
#include <iostream>
#include <algorithm>

static void errorReport(const char*);
static int deleteSpaces(char*&, char*, int);
static int checkIsSubstring(char*, int, char*, int);
bool isPunctuationMark(char);



Sentence::Sentence()
{
    lenght = 0;
    sentenceStr = nullptr;
    updateWordCounter();
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
    updateWordCounter();
}

Sentence::Sentence(char smb){
    sentenceStr = new char[1];
    sentenceStr[0] = smb;
    lenght = 1;
    updateWordCounter();
}

Sentence::Sentence(char* str){
    if (strlen(str)<1){
        lenght = 0;
        sentenceStr = nullptr;
    }
    else lenght = deleteSpaces(sentenceStr, str, strlen(str));
    updateWordCounter();
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
    updateWordCounter();
}

void Sentence::set(char smb){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    lenght = 1;
    sentenceStr = new char[1];
    sentenceStr[0] = smb;
    updateWordCounter();
}

void Sentence::set(char* phrase){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    lenght = deleteSpaces(sentenceStr, phrase, strlen(phrase));
    updateWordCounter();
}

void Sentence::set(char* phrase, int size){
    if (sentenceStr != nullptr) delete[] sentenceStr;
    lenght = deleteSpaces(sentenceStr, phrase, size);
    updateWordCounter();
}


Sentence& Sentence::operator=(const Sentence& phrase){
    if (sentenceStr == phrase.sentenceStr) return *this;

    if (lenght > 0){ delete[] sentenceStr; }
    lenght = phrase.lenght;
    sentenceStr = new char[phrase.lenght];
    for (int i = 0; i < lenght; i++){
        sentenceStr[i] = phrase.sentenceStr[i];
    }
    updateWordCounter();
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
        updateWordCounter();
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
    wordCounter.clear();
}

//functions of processing the words


int Sentence::findWordLocal(char* word, int position){
    return findWordLocal(strlen(word), word, position);
}

int Sentence::findWordLocal(int size, char* word, int position){
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

int Sentence::findWordLocal(Word word, int startPos){
    char* wordStr = nullptr;
    int wordSize = word.get(wordStr, false);

    //in this case wordSise takes a position of founded word
    wordSize = findWordLocal(wordSize, wordStr, startPos);
    if (wordStr != nullptr) delete[] wordStr;
    return wordSize;
}

int Sentence::findWord(char* word, int position){
    return findWordLocal(word, position) + position;
}

int Sentence::findWord(int size, char* word, int position){
    return findWordLocal(size, word, position) + position;
}

int Sentence::findWord(Word word, int position){
    return findWordLocal(word, position) + position;
}

bool Sentence::deleteWord(char* word, int startPos){
    return deleteWord(strlen(word), word, startPos);
}

bool Sentence::deleteWord(int size, char* word, int startPos){
    int position = findWordLocal(size, word, startPos);
    if (position == -1) return false;

    position = position + startPos;

    char* decreasedStr = new char[lenght - size];
    for (int i = 0; i < position; i++){
        decreasedStr[i] = sentenceStr[i];
    }

    //func to save sign
    if (position != 0 && (position + size) < lenght){
        if (false == isSeparatorSign(sentenceStr[position + size])){
            decreasedStr[position - 1] = sentenceStr[position + size];
            sentenceStr[position + size] = ' ';
        }
    }

    int iter = position + size;
    while (iter < lenght){
        decreasedStr[position] = sentenceStr[iter];
        iter++;
        position++;
    }
    delete[] sentenceStr;
    lenght = deleteSpaces(sentenceStr, decreasedStr, lenght - size);
    updateWordCounter();
    return true;
}

bool Sentence::deleteWord(Word word, int startPos){
    char* wordStr = nullptr;
    int wordSize = word.get(wordStr, false);
    bool res = deleteWord(wordSize, wordStr, startPos);
    if (wordStr != nullptr) delete[] wordStr;
    return res;
}

void Sentence::insertWord(char* word, int startPos){
    insertWord(strlen(word), word, startPos);
}

void Sentence::insertWord(int size, char* word, int startPos){

    if (startPos != lenght && startPos != 0){
        if (startPos > lenght || startPos < 0) return;
        if (false == isPunctuationMark(sentenceStr[startPos])) return;
    }

    char* expandedStr = new char[lenght + size + 1];


    for (int i = 0; i < startPos; i++){
        expandedStr[i] = sentenceStr[i];
    }


    

    int iter = size + startPos;
    int position = 0;

    if (startPos != 0){
        expandedStr[startPos] = ' ';//insert space before the new word
        for (int i = 0; i < size; i++){
            expandedStr[startPos + 1 + i] = word[i];
        }
        position = iter + 1;
        iter = startPos;
    }
    else{
        
        for (int i = 0; i < size; i++){
            expandedStr[startPos + i] = word[i];
        }
        position = iter + 1;
        iter = startPos;
        expandedStr[position - 1] = ' ';//insert space after the new word
    }
    
    while (iter < lenght){
        expandedStr[position] = sentenceStr[iter];
        iter++;
        position++;
    }
    delete[] sentenceStr;
    lenght = deleteSpaces(sentenceStr, expandedStr, lenght + size + 1);
    updateWordCounter();
}

void Sentence::insertWord(Word word, int startPos){
    char* wordStr = nullptr;
    int wordSize = word.get(wordStr, false);
    insertWord(wordSize, wordStr, startPos);
    if (wordStr != nullptr) delete[] wordStr;
}

bool Sentence::changeWord(int size1, char* word1, int size2, char* word2, int startPos){
    int position = findWordLocal(size1, word1, startPos);
    if (position == -1) return false;
    else position += startPos;

    deleteWord(size1, word1, startPos);
    if (position == 0) position++;
    insertWord(size2, word2, position - 1);///
    updateWordCounter();
    return true;
}

bool Sentence::changeWord(Word str1, Word str2, int startPos){
    char* wordStr1 = nullptr;
    char* wordStr2 = nullptr;
    int size1 = str1.get(wordStr1, false);
    int size2 = str2.get(wordStr2, false);

    bool res = changeWord(size1, wordStr1, size2, wordStr2, startPos);
    if (wordStr1 != nullptr) delete[] wordStr1;
    if (wordStr2 != nullptr) delete[] wordStr2;
    return res;
}

void Sentence::updateWordCounter(){
    int begin = 0;
    bool isRecordedNow = false;
    wordCounter.clear();

    for (int i = 0; i < lenght; i++){
        if (false == isPunctuationMark(sentenceStr[i])){
            if (false == isRecordedNow){
                isRecordedNow = true;
                begin = i;
            }
        }
        else{
            if (true == isRecordedNow){
                isRecordedNow = false;
                wordCounter.push_back(WordInSent{ begin, i - 1 });
            }
        }
    }
    if (isRecordedNow == true){
        wordCounter.push_back(WordInSent{ begin, lenght-1 });
    }
}

int Sentence::amountOfWords(){
    return wordCounter.size();
}

int Sentence::getWord(int number, char*& str){
    if (number < 1 || number > wordCounter.size()) return -1;

    std::list<WordInSent>::iterator it = wordCounter.begin();

    for (int i = 0; i < (number-1); i++){ it++; }

    int size = it->end - it->begin + 1;
    int begin = it->begin;

    str = new char[size];
    for (int i = 0; i < size; i++){
        str[i] = sentenceStr[begin + i];
    }
    return size;
}

Word Sentence::getWord(int number){
    if (number < 0 || number > wordCounter.size()) return -1;

    std::list<WordInSent>::iterator it = wordCounter.begin();

    for (int i = 0; i < number-1; i++){ it++; }

    int size = it->end - it->begin + 1;
    Word receivedWord(sentenceStr + it->begin, size);
    return receivedWord;
}

bool Sentence::swapWords(int wordNumber1, int wordNumber2){
    if(wordNumber1 < 1 || wordNumber1 > wordCounter.size() || wordNumber2 < 1 || wordNumber2 > wordCounter.size()) return false;
    if (wordNumber1 == wordNumber2) return true;

    if (wordNumber1 > wordNumber2){
        int temp = wordNumber1;
        wordNumber1 = wordNumber2;
        wordNumber2 = temp;
    }
    Word word1 = getWord(wordNumber1),
        word2 = getWord(wordNumber2);

    std::list<WordInSent>::iterator it = wordCounter.begin();
    int start1, start2;

    for (int i = 0; i < wordNumber1-1; i++) it++;
    start1 = it->begin;
    for (int i = wordNumber1-1; i < wordNumber2 - 1; i++) it++;
    start2 = it->begin;

    changeWord(word2, word1, start2);
    changeWord(word1, word2, start1);
    return true;
}

bool Sentence::swapWordsByIndexs(int pos1, int pos2){
    if (pos1 < 0 || pos1 >= lenght || pos2 < 0 || pos2 >= lenght) return false;

    std::list<WordInSent>::iterator it = wordCounter.begin();
    int wordNumb1 = -1,
        wordNumb2 = -1;

    for (int i = 0; i < wordCounter.size(); i++){
        if (it->begin <= pos1 && it->end >= pos1) wordNumb1 = i + 1;
        if (it->begin <= pos2 && it->end >= pos2) wordNumb2 = i + 1;
        it++;
    }
    if (wordNumb1 == -1 || wordNumb2 == -1) return false;

    swapWords(wordNumb1, wordNumb2);

    return true;
}

void Sentence::sortWords(){

    int j = 0;
    for (int i = 1; i <= wordCounter.size(); i++){
        j = i;
        while (j > 1 && getWord(j) < getWord(j - 1)){
            swapWords(j - 1, j);
            j--;
        }
    }
}


int Sentence::findWordNumbers(WordNumber*& arr){
    int amountWordNumber = 0;
    for (int i = 1; i <= wordCounter.size(); i++){
        if (getWord(i).isWordNumber() == true) amountWordNumber++;
    }
    arr = new WordNumber[amountWordNumber];
    amountWordNumber = 0;
    for (int i = 1; i <= wordCounter.size(); i++){
        if (getWord(i).isWordNumber() == true){
            arr[amountWordNumber].set(getWord(i));
            amountWordNumber++;
        }
    }
    return amountWordNumber;
}

int Sentence::SortWordNumbers(WordNumber*& arr, int& sum){
    int size = findWordNumbers(arr);

    int j = 0;
    WordNumber swapBuff;
    int res = 0;
    for (int i = 0; i < size; i++){
        j = i;
        res += arr[j].getNumber();
        while (j > 0 && arr[j] < arr[j-1]){
            swapBuff = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = swapBuff;
            j--;
        }
    }
    sum = res;
    return size;
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

//doesn't delete the first string
int deleteSpaces(char*& firstStr, char* secondStr, int sizeOfSecond)//We leave only one space instead of tab\tabs or more than one spaces
{
    if (sizeOfSecond < 1){
        firstStr = nullptr;
        return 0;
    }
    try{
        char* bufferStr = new char[sizeOfSecond];
        for (int i = 0; i < sizeOfSecond; i++){
            bufferStr[i] = secondStr[i];
        }

        int substractedPoints = 0;
        bool isSeparatorAppears = false;
        bool isPunctuationAppears = false;

        if (true == isPunctuationMark(bufferStr[0])) isSeparatorAppears = true;

        for (int i = 0; i < sizeOfSecond; i++)
        {
            if (true == isPunctuationMark(bufferStr[i]) && false == isSeparatorSign(bufferStr[i])){
                if (true == isSeparatorAppears){
                    substractedPoints++;
                    bufferStr[i] = ' ';
                    continue;
                }
                if (true == isPunctuationAppears){
                    substractedPoints++;
                    bufferStr[i] = ' ';
                    //isSeparatorAppears = true;
                    continue;
                }
                isPunctuationAppears = true;
                continue;
            }
            if (true == isSeparatorSign(bufferStr[i])){
                bufferStr[i] = ' ';
                if (true == isSeparatorAppears){
                    substractedPoints++;
                    continue;
                }
                isSeparatorAppears = true;
                continue;
            }
            isSeparatorAppears = false;
            isPunctuationAppears = false;
        }


        int resSize = sizeOfSecond - substractedPoints;
        firstStr = new char[resSize];

        bool isRepeated = false;
        int iter = 0;
        if (true == isPunctuationMark(bufferStr[0])) isRepeated = true;

        for (int i = 0; i < sizeOfSecond; i++){
            if (true == isSeparatorSign(bufferStr[i])){
                if (isRepeated == true){
                    continue;
                }
                isRepeated = true;
                firstStr[iter] = ' ';
                iter++;
                continue;
            }
            isRepeated = false;
            firstStr[iter] = bufferStr[i];
            iter++;
        }
        delete[] bufferStr;
        return resSize;
    }
    catch (...){
        std::cout << "UNEXPECTED ERROR(in method Sentence::operator+= )\nProgram will be closed. Press any key to continue" << std::endl;
        int tempExcValue = 0;
        std::cin >> tempExcValue;
        exit(-1);
    }
}

int checkIsSubstring(char* container, int lenFirst, char* pattern, int lenSecond){
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
                    isRecordedNow = false;
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
    case '.': case ',': case '\"': case '!': case '?': case ':': case ';': case '(': case ')': case '-':case ' ': case '\t': return true;
    }
    return false;
}

bool isSeparatorSign(char smb)
{
    switch (smb)
    {
    case ' ': case '\t': case '\n': return true;
    }
    return false;
}