#include "SetContainer.h"
#include <assert.h>
#include <istream>
#include <algorithm>



SetContainer::SetContainer(int val){
    assert(val > 0);
    size = val;
    if (size > MAX_SET_SIZE) size = MAX_SET_SIZE;
    set = new char[size];
    for (int i = 0; i < size; i++) set[i] = '\0';
}



SetContainer::SetContainer(const SetContainer& cont){
    this->set = new char[cont.size];
    size = cont.size;
    for (int i = 0; i < size; i++) this->set[i] = cont.set[i];
}



char SetContainer::operator[](int i)
{
    assert(i >= 0 && i < size);
    return (set[i]);
}



bool SetContainer::assign(int index, char smb){
    assert(index >= 0 && index < size);

    for (int i = 0; i < index; i++){
        if (smb == set[i]) return false;
    }
    for (int i = index + 1; i < size; i++){
        if (smb == set[i]) return false;
    }
    set[index] = smb;
    return true;
}



bool SetContainer::operator==(const SetContainer& cont){
    if (size != cont.size) return false;
    std::sort(set, set + size);
    std::sort(cont.set, cont.set + size);

    for (int i = 0; i < size; i++){
        if (set[i] != cont.set[i]) return false;
    }
    return true;
}



SetContainer SetContainer::operator*(const SetContainer& cont){
    int resSize = 0;
    int maxSize = 0;
    if (size > cont.size) maxSize = size;
    else maxSize = cont.size;

    char* crossArr = new char[maxSize];//будем записывать туда все переменные

    std::sort(set, set + size-1);
    std::sort(cont.set, cont.set + cont.size - 1);
    int iter1 = 0, 
        iter2 = 0;

    while (iter1 < size && iter2 < cont.size){
        if (set[iter1] == cont.set[iter2]){
            crossArr[resSize] = set[iter1];
            resSize++;
            iter1++;
            iter2++;
        }
        else{
            if (set[iter1] < cont.set[iter2]){
                iter1++;
            }
            else{
                iter2++;
            }
        }
    }
    SetContainer resSet(resSize);

    for (int i = 0; i < resSize; i++){
        resSet.assign(i, crossArr[i]);
    }
    delete[] crossArr;
    return resSet;
}



SetContainer SetContainer::operator+(const SetContainer& cont){
    int resSize = size;
    char* unionArr = new char[size + cont.size];//будем записывать туда все переменные

    SetContainer crossSet = (*this * cont);

    for (int i = 0; i < size; i++){
        unionArr[i] = set[i];
    }
    crossSet.size;

    int isNoFounded = true;
    for (int i = 0; i < cont.size; i++)//Ищем во 2-м элементы, не входящие в пересечение
    {
        isNoFounded = true;
        for (int j = 0; j < crossSet.getSize(); j++)
        {
            if (cont.set[i] == crossSet[j])
            {
                isNoFounded = false;
                break;
            }
        }
        if (true == isNoFounded){
            unionArr[resSize] = cont.set[i];
            resSize++;
        }
    }

    SetContainer resSet(resSize);
    for (int i = 0; i < resSize; i++){
        resSet.assign(i, unionArr[i]);
    }
    delete[] unionArr;
    return resSet;
}



SetContainer SetContainer::operator-(const SetContainer& cont){
    int resSize = 0;
    char* subtractArr = new char[size];//будем записывать туда все переменные

    SetContainer crossSet = (*this * cont);

    for (int i = 0; i < size; i++){
        if (false == crossSet.isContains(set[i])){
            subtractArr[resSize] = set[i];
            resSize++;
        }
    }
    SetContainer resSet(resSize);
    for (int i = 0; i < resSize; i++){
        resSet.assign(i, subtractArr[i]);
    }
    delete[] subtractArr;
    return resSet;
}

bool SetContainer::operator<(const SetContainer& cont){
    if (size < cont.size) return false;
    std::sort(set, set + size);
    std::sort(cont.set, cont.set + cont.size);

    int iter1 = 0,
        iter2 = 0;

    while (set[iter1] <= cont.set[iter2] && iter1 < size && iter2 < cont.size){
        if (set[iter1] < cont.set[iter2]) {
            iter1++;
            continue;
        }
        if (set[iter1] == cont.set[iter2]){
            iter1++;
            iter2++;
        }
    }
    if (iter2 == cont.size) return true;
    else return false;
}

SetContainer& SetContainer::operator=(SetContainer& cont){
    delete[] this->set;
    this->set = new char[cont.size];
    this->size = cont.size;

    for (int i = 0; i < size; i++){
        set[i] = cont.set[i];
    }
    return *this;
}





std::istream& operator>>(std::istream& is, SetContainer& cont)
{
    int sizeSubArr = 0;
    char tempSmbFolder = ' ';
    for (int i = 0; i < cont.size; i++){ 
        is >> tempSmbFolder;
        if (false == cont.isContains(tempSmbFolder)){
            cont.set[sizeSubArr] = tempSmbFolder;
            sizeSubArr++;
        }
    }
    return is;
}



std::ostream& operator<<(std::ostream& streamOutput, SetContainer& cont){
    for (int i = 0; i < cont.size; i++) 
        streamOutput << cont.set[i] << " ";
    return streamOutput;
}

