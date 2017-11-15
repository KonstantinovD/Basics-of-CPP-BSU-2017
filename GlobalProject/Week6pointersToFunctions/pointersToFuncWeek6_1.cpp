#include "../include/TackInclude.h"

#include <fstream>
#include <math.h>
#include <iostream>


static bool isPrime(int value)//Check is value prime
{
    int squareRoot = sqrt(value);
    for (int i = 2; i <= squareRoot; i++)
    {
        if (0 == value % i) return false;
    }
    return true;
}

static int* findPrimeNumbers(int* arr, int& size)//Make a new array which consists of prime numbers of the initial one
{
    int secondSize = 0;
    int* newArr = new int[size]; //new array which is returned by function
    for (int i = 0; i < size; i++)
    {
        if (true == isPrime(arr[i])){
            newArr[secondSize] = arr[i];
            secondSize++;
        }
    }
    size = secondSize; //return size of new array as parameter
    return newArr;
}


static int* sortArray(int* arr, int& size) //Bubble sort with flag (memory if we had made at least 1 swap)
{
    int i = 0;
    bool isChangeExist = true;
    int* newArr = new int[size];
    for (int i = 0; i < size; i++) newArr[i] = arr[i];

    while (isChangeExist)
    {
        isChangeExist = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (newArr[j] > newArr[j + 1]) {
                int temp = newArr[j];
                newArr[j] = newArr[j + 1];
                newArr[j + 1] = temp;
                isChangeExist = true;
            }
        }
        i++;
    }
    return newArr;
}

static int* findMedian(int* arr, int& size)//find median of the array
{
    int* tempArr = sortArray(arr, size);
    size = tempArr[size / 2];
    delete[] tempArr;
    return nullptr;
}


static void inputAction(int* (**funcArr)(int*, int&), int* arr, int arraySize)//User inputs the necessary action
{


    int actionNumber = 0;
    int size = 0;
    while (true){
        std::cout << "input the number of action 1-3, or 0 to exit: ";
        std::cin >> actionNumber;
        if (0 == actionNumber) return;
        if (actionNumber < 1 || actionNumber > 3) continue;

        size = arraySize;
        switch (actionNumber)
        {
        case 1: {
            int* currArr = funcArr[0](arr, size);
            for (int i = 0; i < size; i++) std::cout << currArr[i] << " ";
            std::cout << std::endl;
            delete[] currArr;
            break;
        }
        case 2: {
            int* currArr = funcArr[1](arr, size);
            for (int i = 0; i < size; i++) std::cout << currArr[i] << " ";
            std::cout << std::endl;
            delete[] currArr;
            break;
        }
        case 3: {
            funcArr[2](arr, size);
            std::cout << "Median of array is " << size << std::endl;
            break;
        }

        }
    }
}


void pointersToFuncWeek6_1(std::ifstream& FIN)
{
    FIN.open("resources/pointersToFuncWeek6_1.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray;
        FIN >> sizeOfArray;
        if (sizeOfArray < 1) continue;
        int* inputArray = new int[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++) FIN >> inputArray[i];


        int* (*funcBlock[3])(int*, int&);

        funcBlock[0] = findPrimeNumbers;
        funcBlock[1] = sortArray;
        funcBlock[2] = findMedian;

        inputAction(funcBlock, inputArray, sizeOfArray);

        delete[] inputArray;
    }


}