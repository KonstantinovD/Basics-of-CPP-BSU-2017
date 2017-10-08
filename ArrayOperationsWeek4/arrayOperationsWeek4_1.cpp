#include "../include/TackInclude.h"

#include <iostream>
#include <fstream>
#include <vector>

class ContainerForEvenNumbers
{
    struct ValueState
    {
        int value;
        bool state;
    };

    std::vector<ValueState> evenOddHolder;
    //If true, it means that value is odd, because 1 is an odd number

public:
    ContainerForEvenNumbers();

    void addValue(int& number);//Add value or change its state in case it is already exist in the holder 

    bool getOdd(int& result);
};

ContainerForEvenNumbers::ContainerForEvenNumbers(){}

void ContainerForEvenNumbers::addValue(int& number)
{
    for (int i = 0; i < evenOddHolder.size(); i++)
    {
        if (number == evenOddHolder[i].value){
            //change the state
            if (true == evenOddHolder[i].state) evenOddHolder[i].state = false;
            else evenOddHolder[i].state = true;
            return;
        }
    }

    ValueState temporaryStructForVector;
    temporaryStructForVector.value = number;
    temporaryStructForVector.state = true; //We add it at the first time, and we had met him only once, and 1 is an odd number
    evenOddHolder.push_back(temporaryStructForVector);
}

bool ContainerForEvenNumbers::getOdd(int& result)
{
    for (int i = 0; i < evenOddHolder.size(); i++)
    {
        if (evenOddHolder[i].state == true)
        {
            result = evenOddHolder[i].value;
            return true;
        }
    }

    std::cout << " incorrect input " << std::endl;
    return false;
}

void arrayOperationsWeek4_1(std::ifstream& FIN)
{
    FIN.open("arrayOperationsWeek4_1.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeOfArray = 0;
        FIN >> sizeOfArray;

        ContainerForEvenNumbers holder;

        for (int i = 0; i < sizeOfArray; i++)
        {
            int var;
            FIN >> var;
            holder.addValue(var);
        }
        int result = 0;
        if (holder.getOdd(result)){
            std::cout << result << std::endl;
        }
    }

}
