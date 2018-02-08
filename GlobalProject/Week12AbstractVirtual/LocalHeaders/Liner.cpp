#include "Liner.h"
#include <assert.h>

Liner::Liner(): Series() {}
Liner::Liner(double v1, double v2) : Series(v1, v2) {}

double Liner::seriesSum(unsigned int i_elem){
    double lmember = getElement(i_elem);
    return(i_elem * ((fmember + lmember) / 2));
}

double Liner::getElement(unsigned int i_elem){
    assert(i_elem > 0);
    return (fmember + changVal*(i_elem - 1));
}
