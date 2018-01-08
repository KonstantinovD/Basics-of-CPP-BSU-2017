#include "..\taskManager\TaskInclude.h"
#include <iostream>

void task6(){

    char* str = nullptr;
    str = "fullOfSymb";
    std::cout << str << std::endl;
    //delete[] str;
    str = new char[5];
    str[0] = 'f';
    str[1] = 'i';
    str[2] = 'r';
    str[3] = 's';
    str[4] = '\0';
    std::cout << str << std::endl;
    std::cout << strlen(str);

    //str = "first";

    //std::cout << str[2]<< str[1]<< std::endl;

    //delete[] str;

    int* integer = new int[3];

    integer[0] = 2;
    integer[0] = 3;
    integer[0] = 10;

    integer = new int[1];

    integer[0] = 17;

    delete[] integer;



    //std::cout << str[7] << strlen(str)<< std::endl;
}