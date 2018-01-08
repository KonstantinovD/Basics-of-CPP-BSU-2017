#include "..\taskManager\TaskInclude.h"
#include <iostream>



void task2(){

    int arr[3] = { 1, 2, 3 };

    std::cout << *arr << '\n';        //arr[0]
    std::cout << *(arr + 1) << '\n';    //arr[1]
    std::cout << *(arr + 2) << '\n';    //arr[2]

    //std::cout << *(arr - 140) << '\n'; unitialized memory
    //std::cout << *(arr - 1458) << '\n';//why zero?
    //std::cout << *(arr - 1454234) << '\n';

}