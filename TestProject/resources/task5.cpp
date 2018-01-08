#include "..\taskManager\TaskInclude.h"
#include <iostream>



class BaseA{
public:
    //The first class with vitrual func may be used as standart class in arrays
    //in case we don't make this func virtual, pointer to the BaseA will call only BaseA func
    //it is interesting that all the functions after that you can do not virtual, but it will be not obvious for another programmers
    virtual void baseFunc(){
        std::cout << "baseA func" << '\n';
    }
    BaseA(){};
    virtual ~BaseA(){ std::cout << "dectructor baseA" << std::endl; }

};

class DervA1: public BaseA
{
public:
    virtual void baseFunc(){
        std::cout << "dervA1 func" << '\n';
    }
    DervA1(){};
    ~DervA1(){ std::cout << "dectructor dervA1" << std::endl; }

};

class DervA2: public DervA1
{
public:
    virtual void baseFunc(){
        std::cout << "dervA2 func" << '\n';
    }
    DervA2(){};
    ~DervA2(){ std::cout << "dectructor dervA2" << std::endl; }

};





void task5(){

    //test ptrs
    BaseA obj0;
    DervA1 obj1;
    DervA2 obj2;

    BaseA* ptrBase;
    DervA1* ptrDerv1;

    ptrBase = &obj0;
    ptrBase->baseFunc();
    ptrBase = &obj1;
    ptrBase->baseFunc();
    ptrBase = &obj2;
    ptrBase->baseFunc();

    std::cout << std::endl;

    ptrBase = new DervA2;
    ptrBase->baseFunc();
    delete ptrBase;

    std::cout << std::endl;

    ptrDerv1 = new DervA2;
    ptrDerv1->baseFunc();
    delete ptrDerv1;

    std::cout << std::endl;


}