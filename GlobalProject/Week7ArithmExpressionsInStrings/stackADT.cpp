/*#include"localHeaders\stackADT.h"

template <typename T>
StackADT<T>::StackADT(){ top = 0; }

template <typename T>
StackADT<T>::StackADT(StackADT& obj){
    for (int i = 0; i < obj.top; i++)
    {
        dataArr[i] = obj.dataArr[i];
    }
    top = obj.top;
    std::cout <<" copy "<< std::endl;
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
}*/
