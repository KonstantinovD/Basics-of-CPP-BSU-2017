#pragma once

#include <iostream>
#include <fstream>

void func_3(std::ifstream& FIN)
{
	FIN.open("test3.txt");
	int numberOfTests;
	FIN >> numberOfTests;

	for (int i = 0; i < numberOfTests; i++)
	{
		int naturalNumber=0;
		FIN >> naturalNumber;
		int resultSum = 0; //Sum of the numerals of number

		while (naturalNumber > 0)
		{
            resultSum += (naturalNumber % 10);
			naturalNumber /= 10;
		}

        std::cout << resultSum << std::endl;
	}
}