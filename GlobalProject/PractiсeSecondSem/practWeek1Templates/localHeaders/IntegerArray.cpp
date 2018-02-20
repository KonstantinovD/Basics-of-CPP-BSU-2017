#include "IntegerArray.h"

//constructor
IntegerArray::IntegerArray(int value){
    assert(value >= 0);

    cont = std::list<int>(value, 0);
}

//copy constructor
IntegerArray::IntegerArray(const IntegerArray& obj){
    this->cont = obj.cont;
}

//insert
void IntegerArray::insert(int position, int value){
    assert(position >= 0 && position <= cont.size());

    _modifyIt = cont.begin();
    std::advance(_modifyIt, position);

    cont.insert(_modifyIt, value);
}

//erase
void IntegerArray::erase(int position){
    assert(position >= 0 && position < cont.size());

    _modifyIt = cont.begin();
    std::advance(_modifyIt, position);

    cont.erase(_modifyIt);
}

//push_back
void IntegerArray::push_back(int value){
    cont.push_back(value);
}

//pop_back
void IntegerArray::pop_back(){
    cont.pop_back();
}

//push_front
void IntegerArray::push_front(int value){
    cont.push_front(value);
}

//operator []
int& IntegerArray::operator[](int index){
    assert(index >= 0 && index < cont.size());
    
    _iter = cont.begin();
    for (int i = 0; i < index; i++){
        _iter++;
    }
    return *(_iter);
}