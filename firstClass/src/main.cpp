//
// Created by volie on 25.10.2021.
//

#include <iostream>
#include "../include/MyFirstClass.h"

using namespace std;

int main() {
    MyFirstClass q1("Jan", "Kowalski", "Are you the best?", 10);

    q1.getQuestion();
    q1.askUser();
    q1.setPoints(10);

    return 0;
}