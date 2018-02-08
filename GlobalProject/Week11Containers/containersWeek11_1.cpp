#include "../include/TackInclude.h"
#include "LocalHeaders\SetContainer.h"

#include <iostream>


void containersWeek11_1(std::ifstream& FIN){
    int numberOfTests;
    FIN.open("resources/containerWeek11_1.txt");
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {


        SetContainer set1(5), set2(4);
        
        set1.assign(0, 'a');
        set1.assign(1, 'b');
        set1.assign(2, 'f');
        set1.assign(3, '!');
        set1.assign(4, 'r');

        for (int i = 0; i < set1.getSize(); i++){
            std::cout << set1[i] << " ";
        }
        std::cout << '\n';

        std::cin >> set2;
        std::cout << set2 << std::endl;

        SetContainer set3(1);
        set3 = set1*set2;
        std::cout << set3 << std::endl;

        std::cout << (set1*set2) << std::endl;
        std::cout << set1+set2 << std::endl;
        std::cout << set1 - set2 << std::endl;


        SetContainer setFirst(5), setSecond(4), setThird(6);

        setThird.assign(0, 't');
        setThird.assign(1, 'h');
        setThird.assign(2, 'i');
        setThird.assign(3, 'n');
        setThird.assign(4, 'g');
        setThird.assign(5, 's');

        setFirst.assign(0, 't');
        setFirst.assign(1, 'i');
        setFirst.assign(2, 'n');
        setFirst.assign(3, 'g');
        setFirst.assign(4, 'a');

        setSecond.assign(0, 's');
        setSecond.assign(1, 'i');
        setSecond.assign(2, 'n');
        setSecond.assign(3, 'g');

        std::cout << setSecond << std::endl;

        std::cout << (setThird<setFirst) << std::endl;
        std::cout << (setThird<setSecond) << std::endl;

    }


}