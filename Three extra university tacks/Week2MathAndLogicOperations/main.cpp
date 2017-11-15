#include <fstream>
#include <iostream>

#include "TackN1.h"
#include "TackN2.h"
#include "TackN3.h"
#include "TackN4.h"
#include "TackN5.h"

const int MAX_NUMBER_TACK = 5;

int chooseTack(std::ifstream& FIN)
{
	int tackNumberToReturn;
	std::cout << "Input tne number of the necessary tack to execute it or \"0\" to finish work: ";
	std::cin >> tackNumberToReturn;

	if (tackNumberToReturn >= 0 && tackNumberToReturn <= MAX_NUMBER_TACK)
	{
		return tackNumberToReturn;
	}
	else return -1;
}



void main()
{
	bool mainLoopContinue = true;
	std::ifstream FIN;


	while (true == mainLoopContinue)
	{
		int numberOfFunction = chooseTack(FIN);

		if (numberOfFunction == 0){
			mainLoopContinue = false;
			continue;
		}

		if (-1 != numberOfFunction)
		{
			std::cout << std::endl << "TACK " << numberOfFunction << std::endl;

			
			switch (numberOfFunction)
			{
			case 1: { func_1(FIN); break; }
			case 2: { func_2(FIN); break; }
			case 3: { func_3(FIN); break; }
			case 4: { func_4(FIN); break; }
			case 5: { func_5(FIN); break; }
			default: {break; }
			}
			
			//At the end of our iteration we close FIN for the next opening
			FIN.close();
		}

	}

	system("pause");
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                