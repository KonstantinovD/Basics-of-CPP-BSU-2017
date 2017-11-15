#include "../include/TackInclude.h"


#include <fstream>
#include <iostream>
#include <vector>


static int binarySearch(std::vector<int> arr, int val, int size) //search the place of element to insert in into array
{
    if (size < 1)  return 0;

    int rBorder = size,
        lBorder = 0,
        middle = 0;

    while (lBorder < rBorder){
        middle = (lBorder + rBorder) / 2;
        if (arr[middle] < val) lBorder = middle + 1;
        else rBorder = middle;
    }
    return rBorder;

}

static void binarySelectSort(std::vector<int>& arr) //sorting array with the help of binary search
{
    int nextNumber = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        nextNumber = binarySearch(arr, arr[i], i);
        int insertedElement = arr[i];
        for (int j = i; j > nextNumber; j--) arr[j] = arr[j - 1];
        arr[nextNumber] = insertedElement;
    }
}

void sortAndMatrixWeek5_4(std::ifstream& FIN)
{
    FIN.open("resources/sortAndMatrixWeek5_4.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray;
        FIN >> sizeOfArray;
        if (sizeOfArray < 1) continue;
        std::vector<int> arrayForSort(sizeOfArray);

        for (int i = 0; i < sizeOfArray; i++){ FIN >> arrayForSort[i]; }

        binarySelectSort(arrayForSort);

        for (int i = 0; i < sizeOfArray; i++) std::cout << arrayForSort[i] << " ";
        std::cout << std::endl;
    }
}