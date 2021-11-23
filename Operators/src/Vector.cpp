//
// Created by volie on 15.11.2021.
//

#include "Vector.h"

Vector::Vector() {}

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::length() {
    return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector &rhs) {
    return {x + rhs.x, y + rhs.y};
}

void Vector::print() {
    cout << x << " " << y << endl;
}

Vector Vector::operator-(const Vector &rhs) {
    return {x - rhs.x, y - rhs.y};
}

double Vector::operator*(const Vector &rhs) {
    return x*rhs.x+y*rhs.y;
}

Vector Vector::operator*(const double &rhs) {
    return {x*rhs, y*rhs};
}

bool Vector::operator==(const Vector &rhs) {
    if(x == rhs.x && y == rhs.y)
        return true;
    else
        return false;
}


