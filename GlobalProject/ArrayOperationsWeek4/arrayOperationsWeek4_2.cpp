#include "../include/TackInclude.h"

#include <iostream>
#include <fstream>
#include <vector>

static void sortArr(std::vector<int>& arr)
{
    int tempVar = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i; j > 0 && arr[j - 1] < arr[j]; j--)
        {
            tempVar = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tempVar;
        }
    }
}

void arrayOperationsWeek4_2(std::ifstream& FIN)
{
    FIN.open("resources/arrayOperationsWeek4_2.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray = 0;
        FIN >> sizeOfArray;

        if (sizeOfArray < 3){
            std::cout << "incorrect size of array" << std::endl;
            int waste;
            for (int i = 0; i < sizeOfArray; i++) FIN >> waste;//Throw away elements of inappropriate array
        }
        else
        {
            std::vector<int> arrInteger(sizeOfArray);

            for (int i = 0; i < sizeOfArray; i++) FIN >> arrInteger[i];

            sortArr(arrInteger);

            if ((arrInteger[0] * arrInteger[1] * arrInteger[2]) >= (arrInteger[0] * arrInteger[sizeOfArray - 1] * arrInteger[sizeOfArray - 2])){
                std::cout << arrInteger[0] << " " << arrInteger[1] << " " << arrInteger[2] << std::endl;
            }
            else{
                std::cout << arrInteger[0] << " " << arrInteger[sizeOfArray - 1] << " " << arrInteger[sizeOfArray - 2] << std::endl;
            }
        }
    }

}
