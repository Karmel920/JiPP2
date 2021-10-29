//
// Created by volie on 25.10.2021.
//

#ifndef JIPP2_MYFIRSTCLASS_H
#define JIPP2_MYFIRSTCLASS_H

#include <iostream>

using namespace std;


class MyFirstClass {
private:
    string firstName;
    string secondName;
    string question;
    string answer;
    short points;

    void readAnswer();

public:
    MyFirstClass(string firstName, string secondName, string question, short points);

    void printQuestion();

    void askUser();

    string getQuestion();

    void setPoints(short points);
};


#endif //JIPP2_MYFIRSTCLASS_H
