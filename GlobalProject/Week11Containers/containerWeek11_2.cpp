#include "../include/TackInclude.h"
#include "LocalHeaders\Fraction.h"
#include <iostream>

static int binarySearch(Fraction* arr, Fraction val, int size) //search the place of element to insert in into array
{
    if (size < 1)  return 0;

    int rBorder = size,
        lBorder = 0,
        middle = 0;

    while (lBorder < rBorder){
        middle = (lBorder + rBorder) / 2;
        if (!(arr[middle] >= val)) lBorder = middle + 1;
        else rBorder = middle;
    }
    return rBorder;

}

static void binarySelectSort(Fraction* arr, int size) //sorting array with the help of binary search
{
    int nextNumber = 0;
    for (int i = 1; i < size; i++)
    {
        nextNumber = binarySearch(arr, arr[i], i);
        Fraction insertedElement = arr[i];
        for (int j = i; j > nextNumber; j--) arr[j] = arr[j - 1];
        arr[nextNumber] = insertedElement;
    }
}




void containersWeek11_2(std::ifstream& FIN){
    int numberOfTests;
    FIN.open("resources/containerWeek11_2.txt");
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int numberOfFractions;
        FIN >> numberOfFractions;

        Fraction* arr = new Fraction[numberOfFractions];
        for (int i = 0; i < numberOfFractions; i++){
            FIN >> arr[i];
        }

        Fraction sum;
        for (int i = 0; i < numberOfFractions; i++){
            sum += arr[i];
        }
        std::cout << sum << std::endl;

        binarySelectSort(arr, numberOfFractions);
        for (int i = 0; i < numberOfFractions; i++){
            std::cout<< arr[i] << " ";
        }
        std::cout << std::endl;

        delete[] arr;
    }
    
}