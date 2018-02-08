#include "Exponential.h"
#include <math.h>
#include <assert.h>

Exponential::Exponential() : Series() {}
Exponential::Exponential(double v1, double v2) : Series(v1, v2) {}

double Exponential::seriesSum(unsigned int i_elem){
    return (fmember * ( (pow(changVal, (int)i_elem)-1) / (changVal-1) ));
}

double Exponential::getElement(unsigned int i_elem){
    assert(i_elem > 0);
    double multiplier = pow(changVal, (int)(i_elem - 1));
    return (fmember*multiplier);
}