#ifndef _COLLECTION_180215_PRACTICE_W3_
#define _COLLECTION_180215_PRACTICE_W3_

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <sstream>
#include <algorithm>

#include "../Flowerbed/Flowerbed.h"
#include "../ReadData/ReadData.h"
#include "../ReadData/ReadFromConsole/ReadFromConsole.h"
#include "../ReadData/ReadFromFile/ReadFromFile.h"

class Collection{
public:
    typedef std::vector<Flowerbed>::iterator iterator;

    iterator begin(){ return container.begin(); }
    iterator end(){ return container.end(); }

public:
    Collection();
    Collection(std::string file);
    Collection(const Collection&);
    ~Collection();


private:
    std::vector<Flowerbed> container;

private:
    Flowerbed parse(std::string);

private:
    int askUser();//ask user how many lines to read in case program reads from console
};



#endif