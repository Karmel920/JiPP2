//
// Created by volie on 22.11.2021.
//

#ifndef JIPP2_FIGURE_H
#define JIPP2_FIGURE_H

#include <iostream>

using namespace std;

class Figure {
private:
    string name;
    string color;

public:
    Figure(string name, string color);

    virtual double getArea() = 0;
};

class Square : public Figure {
private:
    double a;

public:
    Square(string name, string color, double a);

    double getSurface();
    double getPerimeter();
    double getArea();
};

class Rectangle : public Figure {
private:
    double a, b;

public:
    Rectangle(string name, string color, double a, double b);

    double getSurface();
    double getPerimeter();

    double getArea();
};

class Circle : public Figure {
private:
    double r;
public:
    Circle(string name, string color, double r);

    double getArea();
};


#endif //JIPP2_FIGURE_H
