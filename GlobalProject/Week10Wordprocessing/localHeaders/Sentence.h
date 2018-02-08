#pragma once
#include "Word.h"
#include "WordNumber.h"
#include <list>

class Sentence
{
private:
    struct WordInSent{
        int begin;
        int end;
    };

protected:
    std::list<WordInSent> wordCounter;

protected:
    char* sentenceStr;
    int lenght;

public:
    explicit Sentence();
    Sentence(const Sentence&);
    Sentence(char);
    //takes C-string
    Sentence(char*);
    ~Sentence();

public:

    //By default it should be an empty pointer or pointer without dynamic allocation of memory
    //In another case print "false" to use pointer with dynamic allocation of memory
    int get(char*&, bool isCStr = true);
    char get(int);

    void set(const Sentence&);
    void set(char);
    void set(char*);
    void set(char*, int size);

public:
    Sentence& operator=(const Sentence&);
    Sentence& operator+=(const Sentence&);
    bool operator==(Sentence&);
    bool operator>(Sentence&);
    bool operator<(Sentence&);
    
public:
    friend std::ostream& operator<<(std::ostream&, const Sentence&);

public:
    int getLenght();
    void clear();

public:
    //takes C-strings
    int findWordLocal(char* Cstr, int startPos = 0);
    int findWordLocal(int size, char* str, int startPos = 0);
    int findWordLocal(Word word, int startPos = 0);

    int findWord(char* Cstr, int startPos = 0);
    int findWord(int size, char* str, int startPos = 0);
    int findWord(Word word, int startPos = 0);

    //takes C-strings
    bool deleteWord(char* Cstr, int startPos = 0);
    bool deleteWord(int size, char* str, int startPos = 0);
    bool deleteWord(Word word, int startPos = 0);

    //takes C-strings
    void insertWord(char* Cstr, int position = 0);
    void insertWord(int size, char* str, int position = 0);
    void insertWord(Word word, int startPos = 0);

    //replace word1 with word2
    bool changeWord(int size1, char* str1, int size2, char* str2, int startPos = 0);
    bool changeWord(Word str1, Word str2, int startPos = 0);

    int amountOfWords();
    int getWord(int number, char*& str);
    Word getWord(int number);

    bool swapWords(int wordNumber1, int wordNumber2);
    bool swapWordsByIndexs(int pos1, int pos2);
    
    void sortWords();
    void qsortWords();
    int findWordNumbers(WordNumber*&);
    int SortWordNumbers(WordNumber*&, int& sum);

private:
    void updateWordCounter();

protected:
    friend int checkIsSubstring(char* container, int lenFirst, char* pattern, int lenSecond);
    friend bool isPunctuationMark(char smb);
    friend bool isSeparatorSign(char smb);
    //We leave only one space instead of tab\tabs or more than one spaces
    friend int deleteSpaces(char*& firstStr, char* secondStr, int sizeOfSecond);
};