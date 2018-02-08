#pragma once

class Array{
public:
    static const int MAX_ARRAY_SIZE = 150;
    

protected:
    int container[MAX_ARRAY_SIZE];
    int size;
public:
    Array(int size, int initialValue = 0);
    Array(const Array&);
    int& operator[](int i);
    void add(const Array&);
    int getSize(){ return size; }

    Array& operator=(const Array&);
    
};