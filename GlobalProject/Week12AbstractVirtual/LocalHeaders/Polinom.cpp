#include "Polinom.h"
#include <cassert>
#include <math.h>

void Polinom::updateDegree(){
    degree = size - 1;
    while (container[degree] == 0 && degree > 0){
        degree--;
    }
}

Polinom::Polinom(int sizePol, int initialValue) : Array(sizePol, initialValue)
{
    if (sizePol > MAX_ARRAY_SIZE) size = MAX_ARRAY_SIZE; //Max size of Array can be more than max size of Polynom
    updateDegree();
}

Polinom::Polinom(const Polinom& obj) : Array(obj.size, 0)
{
    degree = obj.degree;
    for (int i = 0; i <= degree; i++){
        container[i] = obj.container[i];
    }
}

Polinom& Polinom::operator=(const Polinom& obj){
    Array::operator=(obj);
    degree = obj.degree;
    return *this;
}

Polinom& Polinom::operator+=(const Polinom& obj){
    add(obj);
    return *this;
}

Polinom& Polinom::operator-=(const Polinom& obj){
    if (degree < obj.degree) degree = obj.degree;

    for (int i = 0; i <= obj.degree; i++){
        container[i] -= obj.container[i];
    }
    return *this;
}

bool Polinom::operator==(Polinom& obj){
    updateDegree();//degree updating is a quite labor-intensive operation, and I don't update it if it isn't necessaty
    obj.updateDegree();//So, both *this and obj can have non-updated degrees (after the operating -= or changing element by [], for example)

    if (degree == obj.degree){
        int deg = degree;
        while (deg >= 0){
            if (container[deg] != obj.container[deg]) return false;
            deg--;
        }
        return true;
    }
    return false;
}

double Polinom::calculate(double x){
    double res = container[0];
    updateDegree();

    for (int i = 1; i <= degree; i++){
        res += container[i] * pow(x, i);
    }
    return res;

}


int& Polinom::operator[](int i){
    assert(i >= 0 && i < size);
    return container[i];
}

int Polinom::getDegree(){
    updateDegree();
    return degree;
}