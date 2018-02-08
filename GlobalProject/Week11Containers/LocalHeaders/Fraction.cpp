#include "Fraction.h"
#include <istream>


Fraction::Fraction(double number)
{
    integerPart = (int)number;
    decimalPart = number - integerPart;
}

Fraction::Fraction(){
    integerPart = 0;
    decimalPart = 0.0;
}

Fraction::Fraction(const Fraction& fract){
    integerPart = fract.integerPart;
    decimalPart = fract.decimalPart;
}

std::istream& operator>>(std::istream& is, Fraction& fract)
{
    is >> fract.decimalPart;
    fract.integerPart = fract.decimalPart;
    fract.decimalPart -= fract.integerPart;
    return is;
}

std::ostream& operator<<(std::ostream& streamOutput, const Fraction& fract){
    streamOutput << (fract.decimalPart + fract.integerPart);
    return streamOutput;
}

Fraction& Fraction::operator=(const Fraction& fract){
    decimalPart = fract.decimalPart;
    integerPart = fract.integerPart;
    return *this;
}

Fraction& Fraction::operator+(const Fraction& fract){
    double common = (decimalPart + fract.decimalPart + integerPart + fract.integerPart);
    Fraction res(common);
    return res;
}

Fraction& Fraction::operator-(const Fraction& fract){
    double common = (decimalPart - fract.decimalPart + integerPart - fract.integerPart);
    Fraction res(common);
    return res;
}

Fraction& Fraction::operator*(const Fraction& fract){
    double common = (decimalPart + integerPart) *(fract.decimalPart + fract.integerPart);
    Fraction res(common);
    return res;
}

Fraction& Fraction::operator+=(const Fraction& fract){
    decimalPart += fract.decimalPart;
    integerPart += fract.integerPart;
    if (decimalPart > 1){
        integerPart += (int)decimalPart;
        decimalPart -= (int)decimalPart;
    }
    return *this;
}

bool Fraction::operator>=(Fraction& fract){
    if ((decimalPart + integerPart) >= (fract.decimalPart + fract.integerPart)) return true;
    else return false;
}

bool Fraction::operator<=(Fraction& fract){
    return (fract >= *this);
}