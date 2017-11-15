#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <vector>

static void sortVector(std::vector<int>& arr, int begin, int end) //Quick sort
{
    int borderL = begin,
        borderR = end;


    int middleElem = arr[(begin + end) / 2];
    int tempSwapElem;

    while (borderL <= borderR)
    {
        while (arr[borderL] < middleElem) borderL++;
        while (arr[borderR] > middleElem) borderR--;

        if (borderL <= borderR){
            tempSwapElem = arr[borderL];
            arr[borderL] = arr[borderR];
            arr[borderR] = tempSwapElem;

            borderL++;
            borderR--;
        }
    }

    if (begin < borderR) sortVector(arr, begin, borderR);
    if (end > borderL) sortVector(arr, borderL, end);

}

void sortAndMatrixWeek5_1(std::ifstream& FIN)
{

    FIN.open("resources/sortAndMatrixWeek5_1.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray;
        FIN >> sizeOfArray;
        if (sizeOfArray < 1) continue;

        std::vector<int> arrayForSort(sizeOfArray);

        for (int i = 0; i < sizeOfArray; i++){ FIN >> arrayForSort[i]; }

        sortVector(arrayForSort, 0, arrayForSort.size()-1);

        for (int i = 0; i < sizeOfArray; i++) std::cout<< arrayForSort[i]<<" ";
        std::cout << std::endl;
    }
}

