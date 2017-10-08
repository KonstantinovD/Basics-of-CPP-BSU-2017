#include "../include/TackInclude.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


static bool myfunction(int i, int j) { return (i<j); }

static int greatestComDiv(int first, int second)
{
    if (second == 0) return first;
    return greatestComDiv(second, first % second);
}


void arrayOperationsWeek4_5(std::ifstream& FIN)
{
    FIN.open("arrayOperationsWeek4_5.txt");
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

        std::cout << "Difference is " << differenceOfProgression << std::endl;
        for (int i = 0; i < arithmProgress.size(); i++) std::cout << arithmProgress[i] << " ";
        std::cout << std::endl;
    }
}