#include "Array.h"
#include <cassert>

Array::Array(int sizeArr, int initialValue)
{
    assert(sizeArr >= 0);
    if (sizeArr > MAX_ARRAY_SIZE) sizeArr = MAX_ARRAY_SIZE;
    this->size = sizeArr;
    for (int i = 0; i < size; i++) container[i] = initialValue;
}

Array::Array(const Array& obj)
{
    size = obj.size;
    for (int i = 0; i < size; i++) container[i] = obj.container[i];
}

int& Array::operator[](int i){
    assert(i >= 0 && i < size);
    return container[i];
}

void Array::add(const Array& obj){
    if (size < obj.size){
        for (int i = size; i < obj.size; i++) container[i] = 0;
        size = obj.size;
    }
    for (int i = 0; i < obj.size; i++) container[i] += obj.container[i];
}

Array& Array::operator=(const Array& obj){
    size = obj.size;
    for (int i = 0; i < size; i++) container[i] = obj.container[i];
    return *this;
}

