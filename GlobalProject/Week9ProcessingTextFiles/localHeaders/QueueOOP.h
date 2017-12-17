#pragma once
#include "..\..\Week8Classes\localHeaders\StackOOP.h"

template<typename T>
class QueueOOP: protected StackOOP<T>
{
public:
    QueueOOP();
    QueueOOP(const QueueOOP<T>&);
    ~QueueOOP(){};
public:

    void addBack(T&);

    T getFirst();


    bool isEmpty(){
        return StackOOP<T>::isEmpty();
    }
};

template<typename T>
QueueOOP<T>::QueueOOP() : StackOOP(){}

template<typename T>
QueueOOP<T>::QueueOOP(const QueueOOP& obj) : StackOOP(obj){}

template<typename T>
void QueueOOP<T>::addBack(T& element){
    push(element);
}

template<typename T>
T QueueOOP<T>::getFirst(){
    if (false == isEmply()){
        if (top->pointer == nullptr){
            T tempForReturn = top->value;
            delete top;
            top = nullptr;
            return tempForReturn;
        }
        else{
            DataUnit<T>* first = top;
            while (first->pointer->pointer != nullptr){
                first = first->pointer;
            }
            T tempForReturn = first->pointer->value;
            delete first->pointer;
            first->pointer = nullptr;
            return tempForReturn;
        }

    }
}