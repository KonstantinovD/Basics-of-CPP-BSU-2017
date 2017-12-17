#pragma once

const int MAX_SIZE = 100;

template <typename T>
class StackADT
{
private:
    T dataArr[MAX_SIZE];
    int top;

public:
    StackADT();
    ~StackADT(){};//destructor
    StackADT(const StackADT& obj);//Copy constructor
    void push(T value);
    T pop();
    T get();
    bool isEmpty();
};


template <typename T>
StackADT<T>::StackADT(){ top = 0; }

template <typename T>
StackADT<T>::StackADT(const StackADT& obj){
    for (int i = 0; i < obj.top; i++)
    {
        dataArr[i] = obj.dataArr[i];
    }
    top = obj.top;
}

template <typename T>
bool StackADT<T>::isEmpty()
{
    if (0 == top) return true;
    return false;
}

template <typename T>
void StackADT<T>::push(T value)
{
    if (top < MAX_SIZE){
        dataArr[top] = value;
        top++;
    }
}

template <typename T>
T StackADT<T>::pop()
{
    if (top >= 1) {
        top--;
        return dataArr[top];
    }
}

template <typename T>
T StackADT<T>::get()
{
    if (top >= 1) {
        return dataArr[top-1];
    }
}

