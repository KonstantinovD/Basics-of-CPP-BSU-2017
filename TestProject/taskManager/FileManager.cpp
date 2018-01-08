#include <fstream>
#include <iostream>

#include "FileManager.h"
#include "TaskInclude.h"




void mainLoop()
{
    std::ifstream FIN;
    int isContinueExecution = 1;
    int tackNumber;

    while (true)
    {
        std::cout << "Input the necessary task(or 0 to exit): ";
        std::cin >> tackNumber;

        switch (tackNumber)
        {
        case 0:{exit(0); }
        case 1:{ task1(); break; }
        case 2:{ task2(); break; }
        case 3:{ task3(); break; }
        case 4:{ task4(); break; }
        case 5:{ task5(); break; }
        case 6:{ task6(); break; }
        case 7:{ task7(); break; }
        case 8:{ task8(); break; }
        case 9:{ task9(); break; }
        case 10:{ task10(); break; }
        case 11:{ task11(); break; }
        default: break;
        }
    }

}