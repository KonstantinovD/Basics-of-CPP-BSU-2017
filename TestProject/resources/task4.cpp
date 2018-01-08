#include "..\taskManager\TaskInclude.h"

#include <iostream>
#include <string>

//http://alenacpp.blogspot.com.by/2005/09/const-2.html


class ConstClassExample{
public:
    const int A = 12;
    const double B;
    const double C = 234.12;
    static const double D;
    const std::string E = "some text";
    //const float F;         You can't declare const field without initializing it

    static int changedByConstFunc;
    int noChangedByIt;

public:
    void doNothing() const
    { 
        std::cout << "I do nothing" << std::endl; }

    const int & changeStatic(int value) const
    {
        //changedByConstFunc = value;

        doNothing(); //can call const func

        //noChangedByIt = value;         can't do it!!!

        return noChangedByIt;
    }

public:
    ConstClassExample() :B(-234.11){}

};

const double ConstClassExample::D = 12.0;

void task4(){

    ConstClassExample someObject;

    std::cout << someObject.A << " " << someObject.B << " " << someObject.C << " " << someObject.D << " " << someObject.E;

    someObject.noChangedByIt = 13;
    std::cout << someObject.changeStatic(35) << std::endl;



}