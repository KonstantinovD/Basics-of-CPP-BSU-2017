#include <fstream>
#include <iostream>

#include "include/FileManager.h"
#include "include/TackInclude.h"




struct projectNameNumber
{
    char* name;
    int tacks;
};
const int NUMBER_OF_PROJECTS = 5;
projectNameNumber projectsNames[]{ {"week 3 Integer arithmetic: 5 tacks", 5}, { "week 4 Array operations: 5 tacks", 5 }, { "week 5 Sort and matrix: 6 tacks", 6 }, { "week 6 Pointers to functions and strings: 4 tacks", 4 }, {"week 7 Arithmetic expressions and stack: 3 tacks", 3}};


static int chooseTack(int maxTackNumber)
{
    int tackNumberToReturn = 0;
   
    while (true)
    {
        std::cout << "Input tne number of the necessary tack to execute it or \"0\" to finish work: ";
        std::cin >> tackNumberToReturn;

        if (tackNumberToReturn > 0 && tackNumberToReturn <= maxTackNumber)
        {
            return tackNumberToReturn;
        }
        if(tackNumberToReturn == 0) return -1;
        std::cout << "Such tack isn't exist" << std::endl;
    }
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
        case 3:{


            while (true)
            {
                int crucialValue = chooseTack(projectsNames[numberOfTack - 1].tacks);
                if (-1 == crucialValue) break;//incorrect input of the tack, ;

                switch (crucialValue)//Perform current tack
                {
                case 1: { sortAndMatrixWeek5_1(FIN); break; }
                case 2: { sortAndMatrixWeek5_2(FIN); break; }
                case 3: { sortAndMatrixWeek5_3(FIN); break; }
                case 4: { sortAndMatrixWeek5_4(FIN); break; }
                case 5: { sortAndMatrixWeek5_5(FIN); break; }
                case 6: { sortAndMatrixWeek5_6(FIN); break; }
                default: break;
                }

                FIN.close();
            }
            break;


        }
        case 4:{


            while (true)
            {
                int crucialValue = chooseTack(projectsNames[numberOfTack - 1].tacks);
                if (-1 == crucialValue) break;//incorrect input of the tack, ;

                switch (crucialValue)//Perform current tack
                {
                case 1: { pointersToFuncWeek6_1(FIN); break; }
                case 2: { pointersToFuncWeek6_2(FIN); break; }
                case 3: { pointersToFuncWeek6_3(FIN); break; }
                case 4: { pointersToFuncWeek6_4(FIN); break; }
                default: break;
                }

                FIN.close();
            }
            break;


        }
        case 5:{


            while (true)
            {
                int crucialValue = chooseTack(projectsNames[numberOfTack - 1].tacks);
                if (-1 == crucialValue) break;//incorrect input of the tack, ;

                switch (crucialValue)//Perform current tack
                {
                case 1: { strOfExpressionsWeek7_1(FIN); break; }
                //case 2: { strOfExpressionsWeek7_2(FIN); break; }
                //case 3: { strOfExpressionsWeek7_3(FIN); break; }
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