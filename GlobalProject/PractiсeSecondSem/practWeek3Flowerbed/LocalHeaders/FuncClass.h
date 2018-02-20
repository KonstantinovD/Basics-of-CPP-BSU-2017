#ifndef _FUNCCLASS_180215_PRACTICE_W3_
#define _FUNCCLASS_180215_PRACTICE_W3_

#include "Flowerbed/Flowerbed.h"
//class for (6)
class FuncClass{
private:
    static int flowerSum;
public:
    FuncClass(){}
    FuncClass(const FuncClass& obj){}

    void operator()(Flowerbed & fl) { 
        if (fl.shape == "round"){
            flowerSum += fl.flowers.size();
        }
    }

    static int getSum(){
        return flowerSum; }

    //void resetSum(){ flowerSum = 0; }
};

#endif