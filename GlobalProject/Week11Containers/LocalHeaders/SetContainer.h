#pragma once

class SetContainer
{
private:
    int reserved;

protected:
    char* set;
    int size;
    static const int MAX_SET_SIZE = 256;

protected:
    void add(char smb){
        if (size < reserved){
            set[size] = smb;
            size++;
        }
        else{

        }
    }

};