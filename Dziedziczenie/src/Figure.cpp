//
// Created by volie on 22.11.2021.
//

#include "Figure.h"

Figure::Figure(string name, string color) : name(name), color(color){}


double Square::getSurface() {
    return a*a;
}

double Square::getPerimeter() {
    return a*4;
}

Square::Square(string name, string color, double a) : Figure(name,color), a(a) {}

double Square::getArea() {
    return a*a;
}

Rectangle::Rectangle(string name, string color, double a, double b) : Figure(name,color), a(a), b(b) {}

double Rectangle::getSurface() {
    return a*b;
}

double Rectangle::getPerimeter() {
    return 2*a+2*b;
}

double Rectangle::getArea() {
    return a*b;
}

Circle::Circle(string name, string color, double r) : Figure(name,color), r(r) {}

double Circle::getArea() {
    return 3.14*r*r;
}
