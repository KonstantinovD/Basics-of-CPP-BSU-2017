#pragma once

#include <iostream>
#include <fstream>


void func_1(std::ifstream& FIN)
{
	FIN.open("test1.txt");
	int numberOfTests;
	FIN >> numberOfTests;

	for (int i = 0; i < numberOfTests; i++)
	{
		int naturalNumber = 0;
		if (!FIN.eof())
		{
			FIN >> naturalNumber;
		}
		if (naturalNumber > 0)
		{
			while (naturalNumber % 2 == 0)
			{
				naturalNumber = naturalNumber / 2;
			}
		}

		if (naturalNumber == 1) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}

}
