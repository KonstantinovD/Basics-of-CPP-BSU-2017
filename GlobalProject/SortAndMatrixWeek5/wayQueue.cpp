#include "localHeaders/wayQueue.h"

#include <iostream>

wayQueue::wayQueue(){};

void wayQueue::addBack(int cordY, int cordX, int order){
    cordinates tempToInsert;
    tempToInsert.x = cordX;
    tempToInsert.y = cordY;
    tempToInsert.order = order;
    way.push_back(tempToInsert);
}

bool wayQueue::getFirst(int& cordY, int& cordX, int& order){
    if (way.size() > 0)
    {
        cordX = way[0].x;
        cordY = way[0].y;
        order = way[0].order;
        way.erase(way.begin());
        return true;
    }
    else{
        cordX = 0;
        cordY = 0;
        return false;
    }
}

void wayQueue::clearQueue()
{
    while (way.size() > 0)
        way.pop_back();
}

bool wayQueue::isEmpty()
{
    if (way.size() < 1) return true;
    else return false;
}