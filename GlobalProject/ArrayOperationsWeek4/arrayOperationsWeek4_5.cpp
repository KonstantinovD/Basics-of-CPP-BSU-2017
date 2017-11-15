#include "../include/TackInclude.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


static bool myfunction(int i, int j) { return (i<j); }//to sort vector

static int greatestComDiv(int first, int second)
{
    if (second == 0) return first;
    return greatestComDiv(second, first % second);
}
//Check three things:
//If all elements are unique, we can create arithmetic progression
//If all elements are similar, this is correct
//If no, but there are some similar elements, we can't create arithmetic progression
static bool isContainsUniqueElements(std::vector<int> arr)
{
    int i = 1;
    if (arr.empty()) return true;
    int uniqueElem = arr[0];

    bool isAllSimilar = true;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != uniqueElem){
            isAllSimilar = false;
            break;
        }
    }
    if (true == isAllSimilar){
        for (int i = 0; i < arr.size(); i++) std::cout << arr[i]<<" ";
        std::cout << std::endl;
        return false;
    }

    while (i < arr.size())
    {
        if (arr[i] != uniqueElem) {
            uniqueElem = arr[i];
            i++;
        }
        else {
            std::cout << "incorrect input" << std::endl;
            return false;
        }
    }
    return true;
}

void arrayOperationsWeek4_5(std::ifstream& FIN)
{
    FIN.open("resources/arrayOperationsWeek4_5.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray = 0;
        FIN >> sizeOfArray;
        std::vector<int> arithmProgress(sizeOfArray);
        //input and sort vecctor to better iterate it
        for (int i = 0; i < sizeOfArray; i++) FIN >> arithmProgress[i];
        std::sort(arithmProgress.begin(), arithmProgress.end(), myfunction);

        int differenceOfProgression = 1;
        if (sizeOfArray>2)  differenceOfProgression = greatestComDiv((arithmProgress[2] - arithmProgress[1]), (arithmProgress[1] - arithmProgress[0]));

        if (false == isContainsUniqueElements(arithmProgress)){
            continue;
        }

        for (int i = 0; i < sizeOfArray; i++)
        {
            for (int j = i + 2; j < sizeOfArray; j++)
            {
                int currentDifference = greatestComDiv(arithmProgress[j] - arithmProgress[i], arithmProgress[j - 1] - arithmProgress[i]);
                if (currentDifference % differenceOfProgression != 0) differenceOfProgression = greatestComDiv(currentDifference, differenceOfProgression);
            }
            if (differenceOfProgression == 1) break;
        }


        int k = 0;
        while (k < (arithmProgress.size() - 1))
        {
            while (arithmProgress[k + 1] - arithmProgress[k] > differenceOfProgression){
                arithmProgress.insert(arithmProgress.begin() + k + 1, (arithmProgress[k] + differenceOfProgression));
                k++;
            }
            k++;
        }

        //std::cout << "Difference is " << differenceOfProgression << std::endl;
        for (int i = 0; i < arithmProgress.size(); i++) std::cout << arithmProgress[i] << " ";
        std::cout << std::endl;
    }
}