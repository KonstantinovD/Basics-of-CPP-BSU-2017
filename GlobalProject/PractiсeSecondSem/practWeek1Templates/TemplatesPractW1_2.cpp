#include "../../include/TackInclude.h"
#include <iostream>
#include <algorithm>

#include "localHeaders\IntegerArray.h"

static void prntIntArr(IntegerArray& arr){
    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }std::cout << std::endl;
}

void templatesPractW1_2(std::ifstream& FIN){

    IntegerArray intar(3);
    prntIntArr(intar);

    intar[2] = 4;
    prntIntArr(intar);

    intar.insert(2, 44);
    prntIntArr(intar);

    IntegerArray::iterator iterObj = intar.begin();
    std::advance(iterObj, 2);
    std::cout << *(iterObj) << std::endl;

    for (int i = 0; i < intar.size(); i++){
        intar[i] = i + 1;
    }
    prntIntArr(intar);

    intar.push_front(70);
    prntIntArr(intar);

    intar.push_back(-43);
    prntIntArr(intar);

    intar.pop_back();
    prntIntArr(intar);
    intar.pop_back();
    prntIntArr(intar);

    intar.erase(2);
    prntIntArr(intar);

    intar.push_back(-40);
    intar.push_back(12);
    prntIntArr(intar);

    std::cout << "elements are: ";
    std::for_each(intar.begin(), intar.end(), [](int v){std::cout << v << " "; });
    std::cout << std::endl<<"there are ";
    int numberOfOdd = std::count_if(intar.begin(), intar.end(), [](int n){ return n % 2 == 0; });
    std::cout <<numberOfOdd<< " odd numbers" << std::endl;
}