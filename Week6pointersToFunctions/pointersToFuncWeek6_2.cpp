#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>

//Inserting row to matrix
static int** insertRow(std::ifstream& FIN, int ** arr, int& sizeY, int sizeX)
{
    int numberOfRow = 0;
    FIN >> numberOfRow;

    if (numberOfRow < 0 || numberOfRow > sizeY) {
        int deleteWaste;
        for (int i = 0; i < sizeX; i++) FIN >> deleteWaste;
        return arr;
    }

    int** expandedArr = new int*[sizeY + 1];

    int subtractOne = 0;
    for (int i = 0; i < sizeY + 1; i++)
    {
        if (i == numberOfRow) {
            subtractOne = -1;
            continue;
        }
        expandedArr[i] = arr[i+subtractOne];
    }

    expandedArr[numberOfRow] = new int[sizeX];
    for (int j = 0; j < sizeX; j++) FIN >> expandedArr[numberOfRow][j];
    delete[] arr;

    sizeY++;
    return expandedArr;
}

//Deleting row from matrix
static int** deleteRow(std::ifstream& FIN, int ** arr, int& sizeY)
{
    int numberOfRow = 0;
    FIN >> numberOfRow;
    if (numberOfRow < 0 || numberOfRow > sizeY) return arr;
    if (sizeY - 1 <= 0) {
        sizeY=0;
        return nullptr;
    }

    int** decreasedArr = new int*[sizeY - 1];

    int subtractOne = 0;
    for (int i = 0; i < sizeY; i++)
    {
        if (i == numberOfRow) {
            subtractOne = -1;
            continue;
        }
        decreasedArr[i + subtractOne] = arr[i];
    }

    delete[] arr;
    sizeY--;
    return decreasedArr;
}


void pointersToFuncWeek6_2(std::ifstream& FIN)
{
    FIN.open("resources/pointersToFuncWeek6_2.txt");
    ////////////////////////////////////////////////
    /*
    About the content of test file .txt, which contains some tests: 
    Each test in file has:
    1)the size of matrix - 2 numbers
    2)of course, the matrix itself
    3)number of operations will be applied to the matrix
    Each operation has:
    4)value, which is less than 0 if it is deletion operation, and which is 0 or more if it is insertion operation (-100 and 100 for default)
    5)the number of row to delete or to insert string
    6)string of numbers in case it is insertion operation
    */
    ////////////////////////////////////////////////
    int numberOfTests = 0;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeY, sizeX;
        FIN >> sizeY >> sizeX;

        int** arr = new int*[sizeY];
        for (int i = 0; i < sizeY; i++)
        {
            arr[i] = new int[sizeX];
            for (int j = 0; j < sizeX; j++)
            {
                FIN >> arr[i][j];
            }
        }

        int sumOfOperations;//all insertings or erasings of strings
        FIN >> sumOfOperations;

        int isInsert = 0;
        for (int i = 0; i < sumOfOperations; i++)
        {
            FIN >> isInsert;
            if (isInsert >= 0) arr = insertRow(FIN, arr, sizeY, sizeX);
            else arr = deleteRow(FIN, arr, sizeY);
        }
        
        for (int k = 0; k < sizeY; k++){
            for (int t = 0; t < sizeX; t++)
                std::cout << arr[k][t] << " ";
            std::cout << std::endl;
        }
        
    }
}