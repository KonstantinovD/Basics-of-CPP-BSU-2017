#pragma once
#include <list>

#include "Sentence.h"

class Text: public Sentence{
private:
    std::list<std::pair<int, int>> sentBegins;

public:
    Text() : Sentence(){}
    //takes C-string
    Text(char*);
    Text(char*, int);
    Text(char);
    Text(const Text&);
    ~Text(){}

    void push_back(const Sentence&);
    void sortWords();
    
private:
    bool isEndOfSentence(int index);

    void updateSentBegins();

    

public:
    int findSentWithCommonWords();
};