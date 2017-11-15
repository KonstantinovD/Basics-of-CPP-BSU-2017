#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>
#include <vector>


static int countColumnSum(int **matrix, int size, int columnNumber)//Count sum of numbers in column
{
    int result = 0;
    if (columnNumber >= size||columnNumber < 0) return 0;

    for (int i = 0; i < size; i++)
    {
        result += matrix[i][columnNumber];
    }
    return result;
}

static int countRowSum(int **matrix, int size, int stringNumber)//Count sum of numbers in row
{
    int result = 0;
    if (stringNumber >= size || stringNumber < 0) return 0;

    for (int i = 0; i < size; i++)
    {
        result += matrix[stringNumber][i];
    }
    return result;
}

static bool isMagicSquare(int **matrix, int size)//Count sums of rows and columns and compare them
{
    if (size < 1) return false;//I think that zero matrix isn't a magic square at all

    int sum = countColumnSum(matrix, size, 0);
    if (sum != countRowSum(matrix, size, 0)) return false;

    for (int i = 1; i < size; i++){
        if (sum != countRowSum(matrix, size, i)) return false;
        if (sum != countColumnSum(matrix, size, i)) return false;
    }
    return true;
}

void sortAndMatrixWeek5_3(std::ifstream& FIN)
{
    FIN.open("resources/sortAndMatrixWeek5_3.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfMatrix;
        FIN >> sizeOfMatrix;
        if (sizeOfMatrix < 1) continue;

        int **matrix = new int* [sizeOfMatrix]; //creating dynamic 2d array...
        for (int i = 0; i < sizeOfMatrix; i++){
            matrix[i] = new int[sizeOfMatrix];
            for (int j = 0; j < sizeOfMatrix; j++) FIN >> matrix[i][j];
        }

        if (true == isMagicSquare(matrix, sizeOfMatrix)) std::cout << "This matrix is a magic square" << std::endl;
        else std::cout << "This matrix isn't a magic square" << std::endl;


        for (int i = 0; i < sizeOfMatrix; i++){ //and deleting it
            delete [] matrix[i];
        }
        delete[] matrix;
    }
}
