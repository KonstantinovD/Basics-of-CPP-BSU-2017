#pragma once
#include "QueueOOP.h"
#include <iostream>

//function print information to the user
static void errorReport(const char* message){
    std::cerr << message;
    std::cerr << " Program will be closed\nInput any key to exit ";
    int waitForUser;
    //Sometimes we need to use "system("pause")", but it doesn't works in codeblock IDE, for instance; so it is better to use standart input stream
    std::cin >> waitForUser;
    exit(-1);
}


template <typename T>
class ListOOP : protected QueueOOP<T>
{
protected:
    int size;
    DataUnit<T>* start;//to have an access to the last element
public:
    ListOOP();
    ListOOP(const ListOOP&);//incorrect
    ~ListOOP(){};
public:
    int getSize();
    void append(T&);
    void insert(int, T&);
    T pop(int index = -1);
    T& get(int index = -1);
protected:
    void getElement(DataUnit<T>* &iterateObject, int index)
    {
        iterateObject = top;
        int iterateIndex = 0;
        while (iterateIndex < index){
            iterateIndex++;
            iterateObject = iterateObject->pointer;
        }
    }
//public:
    //friend void sort(ListOOP&, bool*(T&, T&));
};

template <typename T>
ListOOP<T>::ListOOP() : QueueOOP(){
    size = 0;
    start = nullptr;
}

template <typename T>
ListOOP<T>::ListOOP(const ListOOP& obj) : QueueOOP(obj)
{//incorrect
    size = obj.size;

    start = top;
    if (top != nullptr){
        while (start->pointer != nullptr){
            start = start->pointer;
        }
    }
}

template <typename T>
int ListOOP<T>::getSize(){
    return size;
}

template <typename T>
void ListOOP<T>::append(T& obj){
    if (top == nullptr){
        addBack(obj);
        start = top;
    }
    else{
        start->pointer = new DataUnit<T>;
        start->pointer->value = obj;
        start->pointer->pointer = nullptr;
        start = start->pointer;
    }
    size++;
}

template <typename T>
void ListOOP<T>::insert(int index, T& obj){
    try{
        if (index<0 || index>size) throw "\nERROR: ListOOP subscript out of range";

        

        if (index == 0) {//No elements before the first, so, we can't redirect any reference
            addBack(obj);
            size++;
            return;
        }
        if (index == size){//The same like in case index == 0
            append(obj);
            return;
        }

        DataUnit<T>* iterateObject;
        getElement(iterateObject, index - 1);
        
        DataUnit<T>* insertedObject = new DataUnit<T>;
        insertedObject->value = obj;
        insertedObject->pointer = iterateObject->pointer;
        iterateObject->pointer = insertedObject;
        size++;
    }
    catch (const char* message){ errorReport(message); }
}

template <typename T>
T ListOOP<T>::pop(int index = -1){
    if (index == -1) index = 0;
    try{
        if (index < 0 || index >= size) throw "\nERROR: ListOOP subscript out of range\n";


        if (index == 0) {//No elements before the first, so, we can't redirect any reference
            size--;
            return StackOOP<T>::pop();
        }


        DataUnit<T>* iterateObject;
        getElement(iterateObject, index-1);

        //initializing temporary element to return
        T tempObj = iterateObject->pointer->value;
        

        DataUnit<T>* tempPonter = iterateObject->pointer;


        

        //in case element is the last, we can't redirect its pointer to any element, because it is nullptr
        if (index == size - 1) {
            start = iterateObject;
            iterateObject->pointer = nullptr;
            //start = &iterateObject;
        }
        else{
            iterateObject->pointer = iterateObject->pointer->pointer;
        }

        size--;

        delete tempPonter;
        
        return tempObj;
    }
    catch (const char* message){ errorReport(message); }
}

template <typename T>
T& ListOOP<T>::get(int index = -1){
    if (index == -1) index = 0;
    try{
        if (index<0 || index>=size) throw "\nERROR: ListOOP subscript out of range";

        DataUnit<T>* iterateObject = nullptr;
        getElement(iterateObject, index);

        return iterateObject->value;
    }
    catch (const char* message){ errorReport(message); }
}

/*
template <typename T>
void sort(ListOOP<T>& obj, bool*(T&, T&)){

}*/