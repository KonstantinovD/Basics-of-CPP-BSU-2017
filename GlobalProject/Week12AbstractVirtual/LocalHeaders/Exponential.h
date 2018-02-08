#pragma once
#include "Series.h"

class Exponential: public Series
{
public:
    Exponential();
    Exponential(double, double);

public:
    virtual double seriesSum(unsigned int i_elem);
    virtual double getElement(unsigned int i_elem);

};