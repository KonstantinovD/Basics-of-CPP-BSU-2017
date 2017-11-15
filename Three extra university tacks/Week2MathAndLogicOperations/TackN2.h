#pragma once

#include <iostream>
#include <fstream>


void func_2(std::ifstream& FIN)
{
	FIN.open("test2.txt");
	int numberOfTests;
	FIN >> numberOfTests;

	for (int i = 0; i < numberOfTests; i++)
	{
		float kilometersX = 0.0;
        float kilometersY = 0.0;
		if (!FIN.eof())
		{
            FIN >> kilometersX >> kilometersY;
		}

        if (kilometersX >= 0.0 && kilometersY >= 0.0)
		{
			int numberOfDay = 1;
            while (kilometersY > kilometersX)
			{
                numberOfDay++;
                kilometersX = kilometersX + (kilometersX / 10);
			}
            std::cout << numberOfDay << std::endl;
		}
		else std::cout << "incorect input" << std::endl;
		
	}

}