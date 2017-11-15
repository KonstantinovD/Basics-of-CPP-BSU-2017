#include <fstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

void isContainsFigure(std::ifstream& FIN)
{
    float areaSquare, 
          areaCircle;

    FIN >> areaSquare;
    FIN >> areaCircle;

    if (areaSquare < 0.0 || areaCircle < 0.0)
    {
        std::cout << "Incorrect area" << std::endl << std::endl;
        return;
    }

    float radius = std::sqrt(areaCircle / M_PI);
    float squareSide = std::sqrt(areaSquare);

    if ((squareSide*std::sqrt(2)) <= (radius * 2))
        std::cout << "Foursquare is inside the circle" << std::endl;
    else if (squareSide >= (radius * 2))
    	      std::cout << "Circle is inside the foursquare" << std::endl;
	     else std::cout << "No one figure contain another" << std::endl;
	std::cout << std::endl;
}

void main()
{
	

	std::ifstream FIN;
	FIN.open("test1.txt");

	int numberOfTests;
        FIN >> numberOfTests;

        for (int i = 0; i < numberOfTests; i++)
        {
            if (!FIN.eof())
            {
                isContainsFigure(FIN);
	    }
	}
	system("pause");
}