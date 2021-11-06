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


class Cuboid {
private:
    double a;
    double b;
    double h;

public:
    Cuboid(double a, double b, double h);

    void surfaceArea();

    double getA();
    double getB();
    double getH();
};


class Sphere {
private:
    double r;

public:
    Sphere(double r);

    void volume();

    double getR();
};


class QuadraticFunc {
private:
    int a;
    int b;
    int c;

public:
    QuadraticFunc(int a, int b, int c);

    void showFunc();

    double getA();
    double getB();
    double getC();
};


class Student {
private:
    string name;
    string surname;
    int album;
    double questionsNumber;
    double answersNumber;

public:
    Student(string name, string surname, int album, double questionsNumber, double answersNumber);

    void correctAnswersPercent();

    string getName();
    string getSurname();
    int getAlbum();
    double getQuestionsNumber();
    double getAnswersNumber();
};


class Point {
public:
    double x;
    double y;

    Point(int x, int y);

    double lengthPoints(Point point);
};


class Figure {
public:
    int cuspNumber;
    int *cuspArray;

    Figure(int cuspNumber);

    void show_cusps();

    ~Figure();
};

#endif //JIPP2_MYFIRSTCLASS_H
