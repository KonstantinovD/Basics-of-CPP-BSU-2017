#include "..\taskManager\TaskInclude.h"

#include <iostream>
class figure {
protected:
    double x, y;
public:
    void set_dim(double i, double j) {
        x = i;
        y = j;
    }
    virtual void show_area() {
        std::cout << "No area computation defined ";
        std::cout << "for this class. \n";
    }
};
class triangle : public figure {
public:
    void show_area() {
        std::cout << "Triangle with height ";
        std::cout << x << " and base " << y;
        std::cout << " has an area of ";
        std::cout << x * 0.5 * y << ". \n";
    }
};
class square : public figure {
public:
    void show_area() {
        std::cout << "Square with dimensions ";
        std::cout << x << "x" << y;
        std::cout << " has an area of ";
        std::cout << x * y << ". \n";
    }
};
void task3()
{
    figure *p; /* создание указателя базового типа */
    triangle t; /* создание объектов порожденных типов */
    square s;
    p = &t;
    p->set_dim(10.0, 5.0);
    p->show_area();
    p = &s;
    p->set_dim(10.0, 5.0);
    p->show_area();
}