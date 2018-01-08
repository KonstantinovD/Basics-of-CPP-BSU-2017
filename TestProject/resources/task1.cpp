#include "..\taskManager\TaskInclude.h"
#include <iostream>
#include <string>

class firstA{
public:
    int valA;
    int valC;
    firstA(){ valA = 1; valC = 3; }
};

class secondB{
public:
    int valB;
    secondB(){ valB = 2; }
};

void task1(){

    firstA dog;
    secondB cat;

    firstA* ptrDog = &dog;
    secondB* ptrCat = &cat;

    std::cout<<ptrDog->valA <<" "<< ptrCat->valB<<std::endl;

    //ptrDog = &(firstA)cat;
    ptrDog = (firstA*)ptrCat;

    std::cout << ptrDog->valA <<std::endl; //return 2
    std::cout << ptrDog->valC << std::endl; //not initialized

    std::string str = "bobob";
    std::string* strPtr = &str;

    std::cout << *strPtr << std::endl;
    ptrDog = (firstA*)strPtr;

    std::cout << ptrDog->valA << std::endl;

    std::cout<< std::endl;
    std::cout << std::endl;
    ///
    double PI = 3.14159, *p1; float *p2;
    p1 = &PI;
    p2 = (float *)p1;
    std::cout << "adress p1= " << p1 << " stored *p1= " << *p1 << "\n";
    std::cout << "adress p2= " << p2 << " stored *p2= " << *p2 << "\n";

}