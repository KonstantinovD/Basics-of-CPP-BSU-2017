#include "../include/TackInclude.h"

#include <fstream>
#include <iostream>

#include "localHeaders\ComplexNumber.h"


static void testComplexNumberClass(std::ifstream& FIN){
    ComplexNumber complexFirst, complexSecond;

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;//border line between the tests
    std::cout << "check default constr(print complexFirst): ";
    complexFirst.show();

    double reZ1 = 0,
        reZ2 = 0,
        imZ1 = 0,
        imZ2 = 0;
    FIN >> reZ1 >> imZ1 >> reZ2 >> imZ2;
    complexFirst.assign(reZ1, imZ1);
    complexSecond.setReZ(reZ2);
    complexSecond.setImZ(imZ2);

    //show both inputted complex 
    std::cout << "complexFirst: ";
    complexFirst.show();
    std::cout << "complexSecond: ";
    std::cout << complexSecond.getReZ() << "+(" << complexSecond.getImZ()<<"i)" << std::endl;

    //create new object of class, test assigning and constructor with ComplexNumber parameter
    ComplexNumber complexThird(complexFirst);
    std::cout << "complexThird with value of complexFirst: ";
    complexThird.show();
    complexThird.assign(complexSecond);
    std::cout << "complexThird with value of complexSecond: ";
    complexThird.show();

    //Add complexFirst to complexThird twice, doing it differently (add and '+')
    complexThird.add(complexFirst);
    std::cout << "complexThird: ";
    complexThird.show();
    complexThird = complexThird + complexFirst;
    std::cout << "complexThird: ";
    complexThird.show();

    //compare complexFirst and complexSecond by default and by module
    if (complexFirst == complexSecond) std::cout << "complexFirst == complexSecond" << std::endl;
    else std::cout << "complexFirst != complexSecond" << std::endl;
    if (true == complexFirst.compareModule(complexSecond)) std::cout << "complexFirst == complexSecond by module" << std::endl;
    else std::cout << "complexFirst != complexSecond by module" << std::endl;
}


void classesWeek8_1(std::ifstream& FIN)
{
    FIN.open("resources/classesWeek8_1.txt");
    int numberOfTests = 0;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        testComplexNumberClass(FIN);
    }
}
