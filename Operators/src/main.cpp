//
// Created by volie on 15.11.2021.
//

#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    Vector v1(3, 7), v2(5,10);
    Vector v3 = v1.operator+(v2);
    Vector v4 = v1 - v2;
    double iloczyn_skal = v1 * v2;
    Vector v5 = v1 * 4;
    bool isEqual = v1 == v2;


    v3.print();
    v4.print();
    cout << iloczyn_skal << endl;
    v5.print();
    cout << isEqual << endl;

    return 0;
}