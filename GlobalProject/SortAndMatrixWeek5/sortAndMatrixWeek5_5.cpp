#include "../include/TackInclude.h"


#include <fstream>
#include <iostream>
#include <vector>

static int* isAcontainsBFirst(int* arrA, int* arrB, int size1, int size2)//Is B a subrow of A
{
    if (size1 < size2 || size2 <= 0) return nullptr;

    int i = 0,
        j = 0,
        counter = 0;

    while (size1 - i >= size2)
    {
        if (arrA[i] == arrB[j])//If elements are similar
        {
            counter++;//increase current lenght of subarray
            j++;
            if (counter == size2)
                return arrA + i - (size2 - 1);//current element is the last, so, we subtract a size of subarray and add 1
                //to have an access to the first
        }
        else{
            j = 0;
            counter = 0;
        }
        i++;
    }
    return nullptr;
}

static void bubbleSort(int* arr, int size) //Bubble sort with flag (memory if we had made at least 1 swap)
{
    int i = 0;
    bool isChangeExist = true;

    while (isChangeExist)
    {
        isChangeExist = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isChangeExist = true;
            }
        }
        i++;
    }
}

static bool isAcontainsBSecond(int* arrA, int* arrB, int size1, int size2)//Is B a subarray of A
{
    if (size1 < size2 || size2 <= 0) return false;

    int j = 0;

    bubbleSort(arrA, size1);
    bubbleSort(arrB, size2);

    for (int i = 0; i < size1; i++)
    {
        if (arrA[i] < arrB[j]) return false;
        else if (arrA[i] == arrB[j]){
            j++;
            if (j >= size2) return true;
        }
    }
    return false;
}

void sortAndMatrixWeek5_5(std::ifstream& FIN)
{
    FIN.open("resources/sortAndMatrixWeek5_5.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray1 = 0,
            sizeOfArray2 = 0;
        FIN >> sizeOfArray1 >> sizeOfArray2;
        if (sizeOfArray1 < 1) continue;
        int* arrA = new int[sizeOfArray1];
        int* arrB = new int[sizeOfArray2];

        for (int i = 0; i < sizeOfArray1; i++){ FIN >> arrA[i]; }
        for (int i = 0; i < sizeOfArray2; i++){ FIN >> arrB[i]; }
        
        int* subarray = isAcontainsBFirst(arrA, arrB, sizeOfArray1, sizeOfArray2);
        if (subarray == nullptr) std::cout << "Subrow(1): A isn't contain B" << std::endl;
        else{
            std::cout << "(1): ";
            for (int i = 0; i < sizeOfArray2; i++) std::cout << *(subarray + i) << " ";
            std::cout << std::endl;
        }

        if (true == isAcontainsBSecond(arrA, arrB, sizeOfArray1, sizeOfArray2)) std::cout << "Subarray(2): A contains B" << std::endl;
        else std::cout << "Subarray(2): A isn't contain B" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        delete[] arrA;
        delete[] arrB;
    }
}