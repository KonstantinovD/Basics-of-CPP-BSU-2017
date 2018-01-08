#include <iostream>
#include "..\taskManager\TaskInclude.h"

void task10()
{
    int var = 10;
    char a = NULL;
    var = NULL;
    if (var == NULL) std::cout << "Nothing in var" << std::endl;
    std::cout << var << std::endl;
    std::cout << a << std::endl;
    std::cout << (a == '\0') << std::endl;


}