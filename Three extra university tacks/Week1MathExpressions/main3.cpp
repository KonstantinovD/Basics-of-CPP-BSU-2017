#include <fstream>
#include <iostream>
#include <math.h>

void findTheMax(int sizeOfInput, std::ifstream& FIN)
{
    int currentNumber = 0;
    int maxValue = 0;
    bool initialisingIsMade = false; //We can't compare anything if currentNumber doesn't contain the previous value

    for (int i = 0; i < sizeOfInput; i++)
    {
        if (!FIN.eof())
        {
            FIN >> currentNumber;
            if (false == initialisingIsMade)
            {
                if (currentNumber % 2 == 0)
                {
                    initialisingIsMade = true;
                    maxValue = currentNumber;
                }
            }
            else{
                if (currentNumber>maxValue && currentNumber % 2 == 0) maxValue = currentNumber;
            }
	}
    }
    if (true == initialisingIsMade) std::cout << maxValue << std::endl;
    else std::cout << "not found" << std::endl;
    std::cout << std::endl;
}


void main()
{

    std::ifstream FIN;
    FIN.open("test3.txt");
    int numberOfTests;
    FIN >> numberOfTests;

	

    for (int i = 0; i < numberOfTests; i++)
    {
        findTheMax(4, FIN);
    }
    system("pause");
}