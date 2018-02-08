#pragma once
#include "Array.h"

class Polinom: public Array{
public:
    const static int MAX_ARRAY_SIZE = 100;

private:
    int degree;
protected:
    void updateDegree();//Iterate array from the last element

public:
    Polinom(int size, int initialValue = 0);
    Polinom(const Polinom&);

    Polinom& operator=(const Polinom&);
    Polinom& operator+=(const Polinom&);
    Polinom& operator-=(const Polinom&);
    bool operator==(Polinom&);

    double calculate(double x);

public:
    int& operator[](int i);
    int getSize(){ return size; }
    int getDegree();


};