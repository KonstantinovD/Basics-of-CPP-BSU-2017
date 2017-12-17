#pragma once

#include <cstring>
#include <ctype.h>

class Symbol{
protected:
    char character;
public:
    explicit Symbol();
    Symbol(const Symbol&);
    Symbol(char);
    Symbol(char*);
    ~Symbol(){};

public:
    char get();
    void set(const Symbol&);
    void set(char);
    void set(char*);

public:
    bool isNumeral();
    Symbol& operator=(Symbol);
    bool operator==(Symbol);
};