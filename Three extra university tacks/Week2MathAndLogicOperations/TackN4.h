#pragma once

#include <iostream>
#include <fstream>

double countFaclorial(int N)
{
	int iterator = 1;
	double rezult = 1;
	while (iterator <= N)
	{
		rezult *= iterator;
		iterator++;
	}
	return rezult;
}

void func_4(std::ifstream& FIN)
{
	FIN.open("test4.txt");
	int numberOfTests;
	FIN >> numberOfTests;

	for (int i = 0; i < numberOfTests; i++)
	{
		int naturalNumber = 0;
		FIN >> naturalNumber;
		double decimalSum = 1;


		for (int i = 1; i <= naturalNumber; i++)
		{
            decimalSum += (double)(1.0 / countFaclorial(i));
		}


		std::cout << decimalSum << std::endl;

	}
}