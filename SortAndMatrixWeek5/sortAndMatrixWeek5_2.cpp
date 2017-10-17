#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <vector>

static int findMin(std::vector<int> arr, int lBorder, int rBorder)
{
    if (arr.size() != 0 && rBorder < arr.size() && lBorder>=0)
    {
        int minElement = arr[lBorder];
        int numberOfMin = lBorder;
        for (int i = lBorder+1; i <= rBorder; i++)
        {
            if (arr[i] < minElement){
                numberOfMin = i;
                minElement = arr[i];
            }
        }
        return numberOfMin;
    }
    return -1;
}

static void sortVector(std::vector<int>& arr)
{
    int currentElem = 0;
    for (int i = 0; i < arr.size()-1; i++)
    {
        currentElem = findMin(arr, i, arr.size() - 1);
        if (-1 != currentElem)
        {
            int temp = arr[i]; 
            arr[i]= arr[currentElem];
            arr[currentElem] = temp;
        }
        else{
            std::cout << "!!!LOGIC ERROR!!!" << std::endl;
            break;
        }
    }
}

void sortAndMatrixWeek5_2(std::ifstream& FIN)
{
    FIN.open("resources/sortAndMatrixWeek5_2.txt");
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

        for (int i = 0; i < sizeOfArray; i++) std::cout << arrayForSort[i] << " ";
        std::cout << std::endl;
    }
}
