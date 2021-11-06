//
// Created by volie on 25.10.2021.
//

#include <iostream>
#include <cstdlib>
#include "../include/MyFirstClass.h"

using namespace std;

int main() {
    MyFirstClass q1("Jan", "Kowalski", "Are you the best?", 10);

//    q1.askUser();
//    q1.setPoints(10);

    Cuboid cuboid1(10,8,14);
    cuboid1.surfaceArea();
    cout << cuboid1.getA() << endl;

    Sphere sphere1(9);
    sphere1.volume();

    QuadraticFunc f1(3,12,7);
    f1.showFunc();
    cout << f1.getB() << endl;

    Student s1("Kamil", "Slimak", 138928, 20, 9);
    s1.correctAnswersPercent();

    Figure figura1(1024);
    system("PAUSE");


    Point p1(1,1);
    Point p2(3,3);
    cout << "\n\nOdleglosc miedzy pkt:" << p1.lengthPoints(p2);

    return 0;
}