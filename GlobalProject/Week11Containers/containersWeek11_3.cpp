#include "../include/TackInclude.h"
#include "LocalHeaders\Vect.h"
#include <iostream>














void containersWeek11_3(std::ifstream& FIN){
    int numberOfTests;
    FIN.open("resources/containerWeek11_3.txt");
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        Vectex<int> fd(4);
        for (int i = 0; i < fd.size; i++){
            fd[i] = i + 1;
        }
        for (int i = 0; i < fd.size; i++){
            std::cout << fd[i] << " ";
        }
        std::cout << std::endl;

        fd.push_front(17);
        for (int i = 0; i < fd.size; i++){
            std::cout << fd[i] << " ";
        }
        std::cout << std::endl;
        fd[0] = 10;
        for (int i = 0; i < fd.size; i++){
            std::cout << fd[i] << " ";
        }
        std::cout << std::endl;

        fd.pop_front();
        for (int i = 0; i < fd.size; i++){
            std::cout << fd[i] << " ";
        }
        std::cout <<std::endl<< "*****" << std::endl;
        while (fd.size > 0)
            std::cout << fd.pop_front() <<std::endl;

        std::cout<<fd.pop_front()<<std::endl;


        std::cout << std::endl;
    }

}