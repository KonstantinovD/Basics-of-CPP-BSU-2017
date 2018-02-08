#pragma once
#include "symbol.h"
#include <ostream>

#include "task10functions.h"

class Word{
protected:
    char* wordStr;
    int lenght;

public:
    explicit Word();
    Word(const Word&);
    Word(char);
    Word(char*);
    Word(char*, int);
    ~Word();
    
public:
    //By default it should be an empty pointer or pointer without dynamic allocation of memory
    //In another case print "false" to use pointer with dynamic allocation of memory
    int get(char*&, bool isCStr = true);
    char get(int);

    void set(const Word&);
    void set(char);
    void set(char*);
    void set(char*, int);

public:
    bool isPalindrom();
    Word& operator=(Word&);
    bool operator==(Word&);
    bool operator<(Word&);
    bool operator>(Word&);
    bool isWordNumber();//If word is nullptr, returns false
public:
    friend std::ostream& operator<<(std::ostream&, const Word&);
public:
    int getLenght();
    void clear();

private:
    bool compareElement(char);
};

