#include "..\taskManager\TaskInclude.h"
#include <iostream>
#include <functional>
#include <list>

template<class T> 
class TooBig{
private:
    T n;
public:
    TooBig(const T& t) : n(t) {}
    bool operator()(const T& v){ return v > n; }
};


void task8(){
    TooBig<int> obj100(100);
    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };

    std::list<int> yada(vals, vals + 10);
    std::list<int> etcetera(yada);

    yada.remove_if(obj100);
    etcetera.remove_if(TooBig<int>(100));


    std::list<int>::iterator it;
    for (it = yada.begin(); it != yada.end(); it++){
        std::cout << *it << " ";
    }

}