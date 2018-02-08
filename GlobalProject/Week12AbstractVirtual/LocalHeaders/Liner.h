#pragma once
#include "Series.h"
#include <istream>

class Liner: public Series{
public:
    Liner();
    Liner(double, double);

public:
    virtual double seriesSum(unsigned int i_elem);
    virtual double getElement(unsigned int i_elem);
    

};