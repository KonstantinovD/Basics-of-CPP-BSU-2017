#pragma once
#include <istream>

class SetContainer
{
protected:
    char* set;
    int size;
    static const int MAX_SET_SIZE = 256;



public:
    SetContainer(int val);
    SetContainer(const SetContainer&);
    ~SetContainer(){ if(set!=nullptr) delete[] set; }
    char operator[](int i);
    

public:
    bool assign(int index, char smb);

public:
    SetContainer& operator=(SetContainer& container);
    friend std::istream& operator>>(std::istream& is, SetContainer& cont);
    friend std::ostream& operator<<(std::ostream& streamOutput, SetContainer& cont);

public:
    SetContainer operator*(const SetContainer&);
    SetContainer operator+(const SetContainer&);
    SetContainer operator-(const SetContainer&);
    bool operator<(const SetContainer&);
    bool operator==(const SetContainer&);

public:
    int getSize(){ return size; }
    bool isContains(char smb){
        for (int i = 0; i < size; i++){
            if (set[i] == smb) return true;
        }
        return false;
    }
};