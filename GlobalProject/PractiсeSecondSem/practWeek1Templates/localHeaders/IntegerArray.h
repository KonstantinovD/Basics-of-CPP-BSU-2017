#pragma once

#include <iterator>
#include <list>
#include <assert.h>

class IntegerArray{

private:
    std::list<int> cont;
    std::list<int>::iterator _iter;
    std::list<int>::iterator _modifyIt;

public:
    //define own "iterator"
    typedef std::list<int>::iterator iterator;

    //begin\end functions
    iterator begin(){ return cont.begin(); }
    iterator end(){ return cont.end(); }

public:
    explicit IntegerArray(int value = 0);

    IntegerArray(const IntegerArray& obj);

    void insert(int position, int value);

    void erase(int position);

    void push_back(int value);

    void pop_back();

    void push_front(int value);

    int& operator[](int index);

    int size(){ return cont.size(); }

};