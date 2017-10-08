#include <fstream>
#include <iostream>

#include "FileManager.h"
#include "TackInclude.h"


const int NUMBER_OF_PROJECTS = 2;

struct projectNameNumber
{
    char* name;
    int tacks;
};
projectNameNumber projectsNames[]{ {"week 3 Integer arithmetic", 5}, { "week 4 Array operations", 5 }};


int chooseTack(int maxTackNumber)
{
    int tackNumberToReturn;
    std::cout << "Input tne number of the necessary tack to execute it or \"0\" to finish work: ";
    std::cin >> tackNumberToReturn;

    if (tackNumberToReturn >= 0 && tackNumberToReturn <= maxTackNumber)
    {
        return tackNumberToReturn;
    }
    else return -1;
}


void mainLoop()
{
    std::ifstream FIN;
    int isContinueExecution = 1;

    while (isContinueExecution > 0)
    {
        std::cout << "Input the number of the project: " << std::endl;//Show all available projects to user
        for (int i = 0; i < NUMBER_OF_PROJECTS; i++)
        {
            std::cout << i + 1 << ": " << projectsNames[i].name << std::endl;
        }
        std::cout << std::endl;

        int numberOfTack;//input number of tack
        std::cin >> numberOfTack;
        if (numberOfTack > NUMBER_OF_PROJECTS || numberOfTack < 1){ //in case input is incorrect, we continue loop
            std::cout << "Such project isn't exist" << std::endl;
            continue;
        }

        switch (numberOfTack)
        {
        case 1:{

//#ifdef INTEGER_ARIPHMETIC
            while (true)
            {
                int crucialValue = chooseTack(projectsNames[numberOfTack - 1].tacks);
                if (-1 == crucialValue) break;//incorrect input of the tack, ;

                switch (crucialValue)//Perform current tack
                {
                case 1: { integerArithmetic_1(FIN); break; }
                case 2: { integerArithmetic_2(FIN); break; }
                case 3: { integerArithmetic_3(FIN); break; }
                case 4: { integerArithmetic_4(FIN); break; }
                case 5: { integerArithmetic_5(FIN); break; }
                default: break;
                }

                FIN.close();
            }
            break;
//#endif
        }
        case 2:{


            while (true)
            {
                int crucialValue = chooseTack(projectsNames[numberOfTack - 1].tacks);
                if (-1 == crucialValue) break;//incorrect input of the tack, ;

                switch (crucialValue)//Perform current tack
                {
                case 1: { arrayOperationsWeek4_1(FIN); break; }
                case 2: { arrayOperationsWeek4_2(FIN); break; }
                case 3: { arrayOperationsWeek4_3(FIN); break; }
                case 4: { arrayOperationsWeek4_4(FIN); break; }
                case 5: { arrayOperationsWeek4_5(FIN); break; }
                default: break;
                }

                FIN.close();
            }
            break;


        }
        default: break;
        }



        //So, does user want to continue execution of GlobalProject?
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "Do You want to continue? Input 1 or more if yes, 0 or less if no" << std::endl;
        std::cin >> isContinueExecution;
        std::cout << std::endl << std::endl << std::endl;
    }


}