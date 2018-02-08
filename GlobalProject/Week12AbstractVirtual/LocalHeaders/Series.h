#pragma once

class Series{
protected:
    double fmember;
    double changVal;

public:
    Series(){
        fmember = 0;
        changVal = 0;
    };
    Series(double val1, double val2){
        fmember = val1;
        changVal = val2;
    }

public:
    virtual double seriesSum(unsigned int i_elem) = 0;
    virtual double getElement(unsigned int i_elem) = 0;

public:
    void setFMemb(double val){
        fmember = val;
    }
    void setChVal(double val){
        changVal = val;
    }
};

