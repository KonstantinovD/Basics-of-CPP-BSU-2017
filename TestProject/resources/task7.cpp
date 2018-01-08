#include "..\taskManager\TaskInclude.h"
#include <iostream>



void task7(){

    double fdoub = 1.0;
    for (int i = 0; i < 7; i++){
        fdoub *= 1000;
    }

    std::cout << fdoub << std::endl;


    int a = (int)fdoub;
    std::cout << a << std::endl;

    fdoub *= -1;
    std::cout << fdoub << std::endl;
    a = (int)fdoub;
    std::cout << a << std::endl;
}