#pragma once


template <typename T>
class DataUnit{
public:
    T value;
    DataUnit* pointer;
public:
    DataUnit(){
        pointer = nullptr;
    }
    DataUnit(const DataUnit& obj){
        pointer = obj.pointer;
        value = obj.value;
    }
    DataUnit operator=(const DataUnit& obj){
        pointer = obj.pointer;
        value = obj.value;
        return *this;
    }
};

template <typename T>
class StackOOP{
protected:
    DataUnit<T>* top;
public:
    StackOOP();
    ~StackOOP();
    StackOOP(const StackOOP&);
    void push(T&);
    T pop();
    T get();
    bool isEmply();
};

template <typename T>
StackOOP<T>::StackOOP(){
    top = nullptr;
}

template <typename T>
StackOOP<T>::~StackOOP(){
    DataUnit<T>* tempPtr;
    while(top != nullptr)
    {
        tempPtr = top;
        top = top->pointer;
        delete tempPtr;
    }
}

template <typename T>
StackOOP<T>::StackOOP(const StackOOP& obj){
    DataUnit<T>* tempTop = obj.top;
    int size = 0;
    while (tempTop != nullptr)
    {
        tempTop = tempTop->pointer;
        size++;
    }
    

    //like destructor, but object continue to exist
    DataUnit<T>* tempPtr;
    while (top != nullptr)
    {
        tempPtr = top;
        top = top->pointer;
        delete tempPtr;
    }

    if (size != 0){
        T* objectStorage = new T[size];
        tempTop = obj.top;

        for(int i = 0; i < size; i++){
            objectStorage[i] = tempTop->value;
            tempTop = tempTop->pointer;
        }

        for (int i = size-1; i > -1; i--){
            push(objectStorage[i]);
        }

    }
}

template <typename T>
void StackOOP<T>::push(T& element){
    DataUnit<T>* insertNew = new DataUnit<T>;
    insertNew->pointer = top;
    insertNew->value = element;
    top = insertNew;
}

template <typename T>
T StackOOP<T>::pop(){
    if (true != isEmply()){
        DataUnit<T>* tempTop = top;
        top = top->pointer;
        T poppedElement = tempTop->value;
        delete tempTop;
        return poppedElement;
    }
}

template <typename T>
T StackOOP<T>::get(){
    if (true != isEmply()){
        T poppedElement = top->value;
        return poppedElement;
    }
}

template <typename T>
bool StackOOP<T>::isEmply(){
    if (top == nullptr) return true;
    return false;
}