//
// Created by volie on 08.11.2021.
//

#include <iostream>
#include "Point.h"
#include "Vehicle.h"

using namespace std;

class TestClass {
private:
    const int t = 0;

public:
    TestClass(const int t) : t(t) {
    }
};

int main() {

    Vehicle v1("RWW 1334", "Strzala", 5, "Renault", "Hatchback");
    v1.showInfo();
    v1.setPassenger(0, "Janusz");
    v1.setPassenger(3, "Grazyna");
    v1. showInfo();

    cout << "\n Kopiowanie do v2:\n";
    Vehicle v2 = v1;
    v2.showInfo();

    v1.setPassenger(2, "Karola");

    cout << "\nv1: \n";
    v1.showInfo();
    cout << "\nv2: \n";
    v2.showInfo();

    v1.setName("Ogien na tloki");
    cout << endl << endl << "Po zmianie nazwy\n";
    v1.showInfo();



//    {
//        Point p1("P1"), p2(5, 5, "P2");
//
//        cout << "Initial values" << endl;
//        p1.printData();
//        p2.printData();
//
//        cout << endl << "Create copy of point" << endl;
//        Point p1c = p1, p2c = p2;
//        //Update copied points names
//        p1c.setName("P1c");
//        p2c.setName("P2c");
//
//        cout << "Values after copying" << endl;
//        p1.printData();
//        p2.printData();
//        p1c.printData();
//        p2c.printData();
//
//        cout << endl << "Update P1 and P2 x and y (increase 10)" << endl;
//        p1.setX(10);
//        p1.setY(10);
//        p2.setX(15);
//        p2.setY(15);
//
//        cout << "Values after update values" << endl;
//        p1.printData();
//        p2.printData();
//        p1c.printData();
//        p2c.printData();
//    }


    cout << "\n\nEnd program" << endl;


    return 0;
}

