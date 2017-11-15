#include "../include/TackInclude.h"

#include <iostream>
#include <fstream>
#include <vector>

static void sortArr(std::vector<int>& arr, int l, int R, bool isIncrease)//gnome sort
{
    int tempVar = 0;
    int j = 0;
    if (false == isIncrease){
        for (int i = l + 1; i <= R; i++){
            tempVar = arr[i];
            for (j = i; j > l && arr[j - 1] < arr[j]; j--){
                arr[j] = arr[j - 1];
            }
            arr[j] = tempVar;
        }
    }
    else{
        for (int i = l + 1; i <= R; i++){
            for (j = i; j > l && arr[j - 1] > arr[j]; j--){
                arr[j] = arr[j - 1];
            }
            arr[j] = tempVar;
        }
    }
}

void arrayOperationsWeek4_4(std::ifstream& FIN)
{
    FIN.open("resources/arrayOperationsWeek4_4.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray = 0;
        FIN >> sizeOfArray;

        if (sizeOfArray < 1){
            std::cout << "-1" << std::endl;
            return;
        }
        std::vector<int> arrInteger(sizeOfArray);

        bool isInit = false;
        int numberOfMinElement = 0;

        FIN >> arrInteger[0];
        int minElement = arrInteger[0];

        for (int i = 1; i < sizeOfArray; i++) {
            FIN >> arrInteger[i];
            if (arrInteger[i] < minElement){
                minElement = arrInteger[i];
                numberOfMinElement = i;
            }
        }

        sortArr(arrInteger, 0, numberOfMinElement - 1, false);
        sortArr(arrInteger, numberOfMinElement + 1, arrInteger.size() - 1, true);
        std::cout << "index of MIN elem: " << numberOfMinElement << std::endl;
        for (int i = 0; i < arrInteger.size(); i++){
            std::cout << arrInteger[i] << " ";
        }
        std::cout << std::endl;
    }

}