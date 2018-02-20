#include "../../include/TackInclude.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>

#include "LocalHeaders\Collection\Collection.h"
#include "LocalHeaders\FuncClass.h"

static void askUser(Collection* &ptr){
    std::cout << "input 0 to read from file or 1 to read from console: ";
    int userChoice;
    while (true){
        std::cin >> userChoice;
        if (0 == userChoice || 1 == userChoice) break;
    }
    if (userChoice == 0){
        ptr = new Collection("resources/FlowerbedPractW3_1.txt");
        return;
    }
    ptr = new Collection;
    return;
}
static void printFlowerbed(Flowerbed fb){
    std::cout << fb.number << " " << fb.shape << ", flowers: ";
    for (std::string flower : fb.flowers) std::cout << flower << " ";
    std::cout << std::endl;
}

static void printColl(Collection::iterator begin, Collection::iterator end){
    Collection::iterator it;
    std::for_each(begin, end, printFlowerbed);
}
//func for (6)
static int countFl(Flowerbed & fl) {
    static int flowerSum = 0;
    if (fl.shape == "round") flowerSum += fl.flowers.size(); 
    return flowerSum;
}

void floweredbedPractW3_1(std::ifstream& FIN){

    Collection* flowerArr;

    //ask user how to input data
    //(1)
    askUser(flowerArr);

    //task 1 (2)
    std::sort(flowerArr->begin(), flowerArr->end(), [](Flowerbed fl1, Flowerbed fl2){ return fl1.shape < fl2.shape; });
    std::cout << "sorted by shape" << std::endl;
    printColl(flowerArr->begin(), flowerArr->end());

    //task 2 (3, 4)
    std::map<std::string, Flowerbed> mapFlow;
    std::for_each(flowerArr->begin(), flowerArr->end(), [&mapFlow](Flowerbed fl){ mapFlow.insert(std::make_pair(fl.shape, fl));});
    std::cout << "shapes of flowerbeds are: ";
    std::for_each(mapFlow.begin(), mapFlow.end(), [](std::pair<std::string, Flowerbed> pr){ std::cout << pr.first << " "; });
    std::cout << std::endl;
    //(5)
    if (flowerArr->begin() != flowerArr->end()){//if Collection isn't emply
        int maxNumberOfFlowers = 0;
        Flowerbed maxFlow = *flowerArr->begin();//current flowerbed with max number of flowers
        std::for_each(flowerArr->begin(), flowerArr->end(), [&maxNumberOfFlowers, &maxFlow](Flowerbed fl){ if (fl.flowers.size() > maxNumberOfFlowers){
            maxNumberOfFlowers = fl.flowers.size();
            maxFlow = fl;
        }});
        std::cout << "flowerbed with max number of flowers is: ";
        printFlowerbed(maxFlow);
        std::cout << "it has " << maxNumberOfFlowers << " flowers" << std::endl;    
    }

    //task 3 (6)
    int numberOfFlowers = 0;//lambda
    std::for_each(flowerArr->begin(), flowerArr->end(), [&numberOfFlowers](Flowerbed fl){ if (fl.shape == "round") numberOfFlowers += fl.flowers.size(); });
    std::cout << "lambda: " << numberOfFlowers << " flowers" << std::endl;
    numberOfFlowers = 0;//func
    std::for_each(flowerArr->begin(), flowerArr->end(), countFl);
    numberOfFlowers = countFl(Flowerbed());
    std::cout << "func: " << numberOfFlowers << " flowers" << std::endl;
    numberOfFlowers = 0;//func class isn't enable
    /*FuncClass fcl;
    std::for_each(flowerArr->begin(), flowerArr->end(), fcl);
    numberOfFlowers = FuncClass::getSum();
    std::cout << "func class: " << numberOfFlowers << " flowers" << std::endl;*/
}