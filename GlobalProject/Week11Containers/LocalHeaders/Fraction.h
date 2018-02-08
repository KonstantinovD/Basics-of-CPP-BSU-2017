#pragma once
#include <istream>

class Fraction{

private:
    int integerPart;
    double decimalPart;

public:
    Fraction();
    Fraction(double);
    ~Fraction(){}
    Fraction(const Fraction&);

public:
    Fraction& operator=(const Fraction&);
    Fraction& operator+(const Fraction&);
    Fraction& operator-(const Fraction&);
    Fraction& operator*(const Fraction&);
    Fraction& operator+=(const Fraction&);
    bool operator>=(Fraction&);
    bool operator<=(Fraction&);

    friend std::istream& operator>>(std::istream& is, Fraction& fract);
    friend std::ostream& operator<<(std::ostream& streamOutput, const Fraction& fract);

};