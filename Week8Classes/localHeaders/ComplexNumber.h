#pragma once

#include <iostream>

class ComplexNumber{
private:
    double reZ;
    double imZ;


public:
    ComplexNumber();
    ComplexNumber(const ComplexNumber&);
    ComplexNumber(double, double);
    ~ComplexNumber(){ 
        //std::cout << "(***destructor is working***)" << std::endl; 
    }

    double getReZ();
    double getImZ();

    void setReZ(double);
    void setImZ(double);

    void assign(const ComplexNumber&);
    void assign(double, double);
    ComplexNumber operator=(const ComplexNumber&);

    void add(const ComplexNumber&);
    void add(double, double);
    ComplexNumber operator+(const ComplexNumber&);

    bool compare(const ComplexNumber&);
    bool operator==(const ComplexNumber&);
    bool compareModule(const ComplexNumber&);
    friend bool compare(const ComplexNumber&, const ComplexNumber&);
    friend bool compareModule(const ComplexNumber&, const ComplexNumber&);

    void show();
};

