#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(){
    reZ = 0.0;
    imZ = 0.0;
}

ComplexNumber::ComplexNumber(const ComplexNumber& obj){
    reZ = obj.reZ;
    imZ = obj.imZ;
}

ComplexNumber::ComplexNumber(double real, double image){
    reZ = real;
    imZ = image;
}


double ComplexNumber::getReZ(){ return reZ; }

double ComplexNumber::getImZ(){ return imZ; }


void ComplexNumber::setReZ(double real){ reZ = real; }

void ComplexNumber::setImZ(double image){ imZ = image; }


void ComplexNumber::assign(const ComplexNumber& obj){
    reZ = obj.reZ;
    imZ = obj.imZ;
}

void ComplexNumber::assign(double real, double image){
    reZ = real;
    imZ = image;
}

ComplexNumber ComplexNumber::operator=(const ComplexNumber& obj){
    reZ = obj.reZ;
    imZ = obj.imZ;
    return *this;
}


void ComplexNumber::add(const ComplexNumber& obj){
    reZ += obj.reZ;
    imZ += obj.imZ;
}

void ComplexNumber::add(double real, double image){
    reZ += real;
    imZ += image;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& obj){
    reZ += obj.reZ;
    imZ += obj.imZ;
    return *this;
}


bool ComplexNumber::compare(const ComplexNumber& obj){
    if (reZ == obj.reZ && imZ == obj.imZ) return true;
    else return false;
}

bool ComplexNumber::operator==(const ComplexNumber& obj){
    if (reZ == obj.reZ && imZ == obj.imZ) return true;
    else return false;
}

bool ComplexNumber::compareModule(const ComplexNumber& obj){
    if ((reZ*reZ + imZ*imZ) == (obj.reZ*obj.reZ + obj.imZ*obj.imZ)) return true;
    else return false;
}

bool compare(const ComplexNumber& obj1, const ComplexNumber& obj2){
    if (obj1.reZ == obj2.reZ && obj1.imZ == obj2.imZ) return true;
    else return false;
}

bool compareModule(const ComplexNumber& obj1, const ComplexNumber& obj2)
{
    if ((obj1.reZ*obj1.reZ + obj1.imZ*obj1.imZ) == (obj2.reZ*obj2.reZ + obj2.imZ*obj2.imZ)) return true;
    else return false;
}


void ComplexNumber::show(){ std::cout << reZ << "+(" << imZ << "i)" << std::endl; }