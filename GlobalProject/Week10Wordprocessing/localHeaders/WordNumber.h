#pragma once
#include "Word.h"

#include "task10functions.h"

class WordNumber: public Word
{
protected:
    int value;

public:
    explicit WordNumber();
    WordNumber(const WordNumber&);
    WordNumber(char);
    WordNumber(char*);
    ~WordNumber(){}

public:
    int get(char*);
    void set(const WordNumber&);
    void set(char);
    void set(char*);

public:
    int getNumber();
    void setNumber(int);

public:
    WordNumber& operator=(const WordNumber&);
    WordNumber& operator+(const WordNumber&);
    WordNumber operator-(const WordNumber&);
    WordNumber operator*(const WordNumber&);
    WordNumber operator/(const WordNumber&);

};