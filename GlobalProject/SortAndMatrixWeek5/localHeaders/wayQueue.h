#pragma once

#include <vector>

class wayQueue
{
private:
    struct cordinates{
        int y;
        int x;
        int order;
    };
    std::vector<cordinates> way;

public:
    wayQueue();

    void addBack(int y, int x, int order);
    bool getFirst(int& y, int& x, int& order);
    void clearQueue();
    bool isEmpty();
};

