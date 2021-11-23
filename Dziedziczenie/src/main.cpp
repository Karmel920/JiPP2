//
// Created by volie on 22.11.2021.
//

#include <iostream>
#include "Figure.h"

using namespace std;

int main() {
    Square square1("SQUARE","BLUE",10);
    cout << "Pole kwadratu1: " << square1.getSurface() << "\nObwod kwadratu1: " << square1.getPerimeter() << endl;

    Rectangle rect1("kazik", "red", 5, 8);
    cout << "Pole rect1: " << rect1.getSurface() << "\nObwod rect1: " << rect1.getPerimeter() << endl;


    cout << endl << endl;
    Figure *circle = new Circle("franio","green",5);
    Figure *rectangle = new Rectangle("kamil","pink",5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
    return 0;
}
