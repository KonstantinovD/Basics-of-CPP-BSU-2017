#include "../include/TackInclude.h"
#include "localHeaders/wayQueue.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>





static int findMinElementOfMatrix(std::vector<std::vector<int>>& matrix)//Find min element to take mark for marking cells
{
    int ijMin = matrix[1][1];
    for (int i = 1; i < matrix.size()-1; i++)
    {
        for (int j = 1; j < matrix[i].size()-1; j++)
        {
            if (matrix[i][j] < ijMin) ijMin = matrix[i][j];
        }
    }

    //Now full all border cells with ijMin - 1 (to not add them to queue)
    for (int j = 0; j < matrix[0].size(); j++)
    {
        matrix[0][j] = ijMin - 1; //Full the top line
        matrix[matrix.size()-1][j] = ijMin - 1;//Full the bottom line
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i][0] = ijMin - 1; //Full the left line
        matrix[i][matrix[0].size()-1] = ijMin - 1;//Full the right line
    }//It helps me not to use complicated check of array indexs(is I refer to the out-of-range index)


    return ijMin;
}


//during searching available cells we need to interact with queue to add unmarked cells
static int addNewCellsToQueue(std::vector<std::vector<int>>& matrix,int& mark, wayQueue& queue)
{
    int x = 0,
        y = 0,
        order = 0;
    queue.getFirst(y, x, order);
    if (matrix[y][x - 1] > mark && matrix[y][x - 1] < matrix[y][x]){ queue.addBack(y, x - 1, order-1); }
    if (matrix[y][x + 1] > mark && matrix[y][x + 1] < matrix[y][x]){ queue.addBack(y, x + 1, order - 1); }
    if (matrix[y - 1][x] > mark && matrix[y - 1][x] < matrix[y][x]){ queue.addBack(y - 1, x, order - 1); }
    if (matrix[y + 1][x] > mark && matrix[y + 1][x] < matrix[y][x]){ queue.addBack(y + 1, x, order - 1); }
    matrix[y][x] = order;
    return (y * 100000 + x);
}

//during searching route we find cell which is more than current number at 1
static void nextCellStep(std::vector<std::vector<int>>& matrix, int &y, int& x, int newMinValue)
{
    int previousValue = matrix[y][x]; //We will change value of current cell, so we need to store its previous to compare with neighbours
    matrix[y][x] = newMinValue;  //We indicate route cells by newMinValue
    if (matrix[y][x - 1] - 1 == previousValue) { x -= 1; return; }
    if (matrix[y][x + 1] - 1 == previousValue) { x += 1; return; }
    if (matrix[y - 1][x] - 1 == previousValue) { y -= 1; return; }
    if (matrix[y + 1][x] - 1 == previousValue) { y += 1; return; }
    
}

static int findRemoteAndRoute(std::vector<std::vector<int>>& matrix, int y, int x, int mark) //We know the furthest cell, and now we find the way to the start cell
{
    int curY = y,
        curX = x;

    int newMinValue = matrix[y][x] - 1; //to indicate route cells

    while (matrix[curY][curX] < mark - 1){ //while we don't reach the start cell with the mark value
        nextCellStep(matrix, curY, curX, newMinValue);//We indicate route cells by newMinValue
    }
    matrix[curY][curX] = newMinValue;

    matrix[y][x] = newMinValue - 1; //We indicate the furthest cell by newMinValue-1
    return newMinValue;
}

static void printInitialMatrix(std::vector<std::vector<int>>& matrix)//Show initial matrix to compare with the result one
{
    for (int i = 1; i < matrix.size() - 1; i++)
    {
        for (int j = 1; j < matrix[0].size() - 1; j++)
        {
            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// Show result matrix to compare with the initial one
static void printResultMatrix(std::vector<std::vector<int>>& matrix, int routeValue, int mark)
{
    for (int i = 1; i < matrix.size() - 1; i++)
    {
        for (int j = 1; j < matrix[0].size() - 1; j++)
        {
            if (mark >= matrix[i][j]){
                if (matrix[i][j] <= routeValue){
                    if (matrix[i][j] == routeValue) std::cout << std::setw(3) << "X";
                    else std::cout << std::setw(3) << "R";
                }
                else std::cout << std::setw(3) << "1";
            }
            else {
                std::cout << std::setw(3) << "0";
            }
        }
        std::cout << std::endl;
    }
}

//Find all available cells, cords are used to set the first cell
static void threeGlobalFunctions(std::vector<std::vector<int>>& matrix, int cordY, int cordX)
{
    if (cordY<1 || cordX<1 || cordY > matrix.size() || cordX > matrix[0].size()) return;

    printInitialMatrix(matrix); //print initial matrix

    int mark = findMinElementOfMatrix(matrix) - 1;//Element is used to mark cells we had gone through
    wayQueue waterArea;

    waterArea.addBack(cordY, cordX, mark-1); //Value of the start cell is less than "mark", because "mark" is used to mark borders

    int theLastCord = 0;
    while (!waterArea.isEmpty()){
        theLastCord = addNewCellsToQueue(matrix, mark, waterArea);
    }
    int theFurthestX = theLastCord % 100000,
        theFurthestY = theLastCord / 100000;

    std::cout << std::endl << "cordinates of the furthest cell are: " << theFurthestY << " " << theFurthestX <<std::endl<< "R marks the furthest, X marks the route" << std::endl << std::endl;


    int routeValue = findRemoteAndRoute(matrix, theFurthestY, theFurthestX, mark);
    printResultMatrix(matrix, routeValue, mark);

    std::cout << std::endl<< " -------------------------------------------------------- "<<std::endl<<std::endl;


}





void sortAndMatrixWeek5_6(std::ifstream& FIN)
{
    FIN.open("resources/sortAndMatrixWeek5_6.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int nRows = 0,
            nColumns = 0,
            startY = 1,
            startX = 1;

        FIN >> nRows >> nColumns >> startY >> startX;
        if (nRows < 1 || nColumns < 1) return;

        std::vector<std::vector<int>> waterMatrix(nRows+2, std::vector<int>(nColumns+2));

        for (int i = 1; i < waterMatrix.size() - 1; i++)
        {
            for (int j = 1; j < waterMatrix[0].size() - 1; j++)
            {
                FIN >> waterMatrix[i][j];
            }
        }



        threeGlobalFunctions(waterMatrix, startY, startX);

    }
}