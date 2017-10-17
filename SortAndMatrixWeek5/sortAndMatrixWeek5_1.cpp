#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <vector>

static void sortVector(std::vector<int>& arr) //Bubble sort with flag (memory if we had made at least 1 swap)
{
    int i = 0;
    bool isChangeExist = true;

    while (isChangeExist)
    {
        isChangeExist = false;
        for (int j = 0; j < arr.size()-1-i; j++)
        {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isChangeExist = true;
            }
        }
        i++;
    }
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

        sortVector(arrayForSort);

        for (int i = 0; i < sizeOfArray; i++) std::cout<< arrayForSort[i]<<" ";
        std::cout << std::endl;
    }
}

