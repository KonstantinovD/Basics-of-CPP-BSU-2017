#pragma once

#include <iterator>
#include <list>
#include <assert.h>

template <typename ct_type>
class TemplateArr{

private:
    typename std::list<ct_type> cont;
    typename std::list<ct_type>::iterator _iter;
    typename std::list<ct_type>::iterator _modifyIt;

public:
    //define own "iterator"
    typename typedef std::list<ct_type>::iterator iterator;

    //begin\end functions
    iterator begin(){ return cont.begin(); }
    iterator end(){ return cont.end(); }

public:
    explicit TemplateArr(int value = 0);

    explicit TemplateArr(int value, ct_type);

    TemplateArr(const TemplateArr& obj);

    void insert(int position, ct_type);

    void erase(int position);

    void push_back(ct_type value);

    void pop_back();

    void push_front(ct_type value);

    ct_type& operator[](int index);

    int size(){ return cont.size(); }

};


// constructor
template <typename ct_type>
TemplateArr<ct_type>::TemplateArr(int size){
    assert(size >= 0);

    cont = std::list<ct_type>(size);
}

//constructor with filler
template <typename ct_type>
TemplateArr<ct_type>::TemplateArr(int size, ct_type fill){
    assert(size >= 0);

    cont = std::list<ct_type>(size, fill);
}

//copy constructor
template <typename ct_type>
TemplateArr<ct_type>::TemplateArr(const TemplateArr<ct_type>& obj){
    this->cont = obj.cont;
}

//insert
template <typename ct_type>
void TemplateArr<ct_type>::insert(int position, ct_type value){
    assert(position >= 0 && position <= cont.size());

    _modifyIt = cont.begin();
    std::advance(_modifyIt, position);

    cont.insert(_modifyIt, value);
}

//erase
template <typename ct_type>
void TemplateArr<ct_type>::erase(int position){
    assert(position >= 0 && position < cont.size());

    _modifyIt = cont.begin();
    std::advance(_modifyIt, position);

    cont.erase(_modifyIt);
}

//push_back
template <typename ct_type>
void TemplateArr<ct_type>::push_back(ct_type value){
    cont.push_back(value);
}

//pop_back
template <typename ct_type>
void TemplateArr<ct_type>::pop_back(){
    cont.pop_back();
}

//push_front
template <typename ct_type>
void TemplateArr<ct_type>::push_front(ct_type value){
    cont.push_front(value);
}

//operator []
template <typename ct_type>
ct_type& TemplateArr<ct_type>::operator[](int index){
    assert(index >= 0 && index < cont.size());

    _iter = cont.begin();
    for (int i = 0; i < index; i++){
        _iter++;
    }
    return *(_iter);
}