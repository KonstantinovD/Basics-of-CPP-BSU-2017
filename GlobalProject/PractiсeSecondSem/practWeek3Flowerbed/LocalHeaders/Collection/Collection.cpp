#include "Collection.h"

Collection::Collection(){
    int numberOfClumbs = askUser();
    ReadFromConsole reader;
    std::string currentClumb = "";

    for (int i = 0; i < numberOfClumbs; i++){
        currentClumb = reader.readLine();
        container.push_back(parse(currentClumb));
    }

}

Collection::Collection(std::string filepath){
    ReadFromFile reader(filepath);
    std::string currentClumb = "";

    if (true == reader.isOpen()){
        while (!reader.eof()){
            currentClumb = reader.readLine();
            container.push_back(parse(currentClumb));
        }
    }
    else{//if file isn't open, read data from console
        std::cout << "ERROR: file couldn't be opened. Input data from console" << std::endl;
        ReadFromConsole clReader;//create a ConsoleReader
        int numberOfClumbs = askUser();
        for (int i = 0; i < numberOfClumbs; i++){
            currentClumb = clReader.readLine();
            container.push_back(parse(currentClumb));
        }
    }
}

Collection::Collection(const Collection& obj){
    container = std::vector<Flowerbed>(obj.container);
}

Collection::~Collection(){}

Flowerbed Collection::parse(std::string flowerbedData){
    Flowerbed newClumb;
    //int readTwice = 0;//variable to read 

    std::stringstream splitString(flowerbedData);
    std::string subStr = "";
    
    //read number of flowerbed and parse it
    std::getline(splitString, subStr, ' ');
    std::stringstream parseInt(subStr);
    parseInt >> newClumb.number;
    //read shape of flowerbed
    std::getline(splitString, subStr, ' ');
    std::transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
    newClumb.shape = subStr;

    while (std::getline(splitString, subStr, ' '))
    {
        newClumb.flowers.push_back(subStr);
    }
    return newClumb;
}

int Collection::askUser(){
    int numberOfClumbs = 0;//how many lines will be read from console
    std::cout << "Input number of strings to be keyed in: ";
    std::cin >> numberOfClumbs;
    std::cin.get();
    return numberOfClumbs;
}