#include "..\include\TackInclude.h"
#include <fstream>
#include <iostream>

#include "LocalHeaders\Array.h"
#include "LocalHeaders\Polinom.h"



void abstractVirtualWeek12_2(std::ifstream& FIN){
    

    Polinom polOne(13, 3);
    polOne[4] = 5;
    polOne[7] = 5;

    Polinom polTwo(0, 0);
    for (int i = 0; i < polTwo.getDegree(); i++){
        std::cout << polTwo[i] << " ";
    }
    std::cout << std::endl;

    polTwo = polOne;
    for (int i = 0; i <= polTwo.getDegree(); i++){
        std::cout << polTwo[i] << " ";
    }
    std::cout << std::endl;

    Polinom polThree(13, 0);
    polThree[11] = -3;
    polThree[12] = -3;

    polTwo = polThree;
    std::cout<<polThree.getDegree()<<std::endl;
    for (int i = 0; i <= polTwo.getDegree(); i++){
        std::cout << polTwo[i] << " ";
    }
    std::cout << std::endl;
    


    FIN.open("resources/abstractVirtualWeek12_2.txt");
    int numberOfTests;
    FIN >> numberOfTests;
    

    for (int i = 0; i < numberOfTests; i++)
    {
        int sizeP1, sizeP2;
        FIN >> sizeP1 >> sizeP2;

        Polinom polyFirst(sizeP1),
            polySecond(sizeP2);

        for (int i = sizeP1-1; i >= 0; i--){
            FIN>>polyFirst[i];
        }
        for (int i = sizeP2-1; i >= 0; i--){
            FIN >> polySecond[i];
        }
        std::cout << "deg of first: " << polyFirst.getDegree() << " deg of second: " << polySecond.getDegree() << std::endl;

       
        Polinom polyThird(polyFirst);
        std::cout << "first polinom is" << std::endl;
        for (int i = polyThird.getDegree(); i >= 0; i--){
            std::cout << polyThird[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "is first == second? " << (polyFirst == polySecond) << " is first == first? " << (polyFirst == polyFirst) << std::endl;

        std::cout <<"first + second is:" << std::endl;
        polyThird += polySecond;
        for (int i = polyThird.getDegree(); i >= 0; i--){
            std::cout << polyThird[i] << " ";
        }
        std::cout << std::endl;

        polyThird = polyFirst;

        std::cout << "first - second is:" << std::endl;
        polyThird -= polySecond;
        for (int i = polyThird.getDegree(); i >= 0; i--){
            std::cout << polyThird[i] << " ";
        }
        std::cout << std::endl;

        double xVal;
        std::cout << "input x to calculate the first: ";
        std::cin >> xVal;
        std::cout << polyFirst.calculate(xVal)<<std::endl;
        std::cout << "input x to calculate the second: ";
        std::cin >> xVal;
        std::cout << polySecond.calculate(xVal) << std::endl;
    }
}