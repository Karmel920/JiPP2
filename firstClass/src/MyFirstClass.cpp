//
// Created by volie on 25.10.2021.
//

#include "../include/MyFirstClass.h"
#include <math.h>

void MyFirstClass::readAnswer() {
    cin >> answer;
}

void MyFirstClass::printQuestion() {
    cout << question << endl;
}

void MyFirstClass::askUser() {
    printQuestion();
    readAnswer();
}

MyFirstClass::MyFirstClass(string firstName, string secondName, string question, short points)
: secondName(secondName), question(question), points(points)
{
    this->firstName = firstName;
}

string MyFirstClass::getQuestion() {
    return question;
}

void MyFirstClass::setPoints(short points) {
    this->points = points;
}



Cuboid::Cuboid(double a, double b, double h) : a(a), b(b), h(h) {}

void Cuboid::surfaceArea() {
    double surface = 2*a*b+2*b*h+2*a*h;
    cout << "\nPole powierzchni bryly: " << surface << endl;
}

double Cuboid::getA() {
    return a;
}

double Cuboid::getB() {
    return b;
}

double Cuboid::getH() {
    return h;
}



Sphere::Sphere(double r) : r(r) {}

void Sphere::volume() {
    double volume = (4./3) * 3.14 * r * r * r;
    cout << "\nObjetosc kuli: " << volume << endl;
}

double Sphere::getR() {
    return r;
}



QuadraticFunc::QuadraticFunc(int a, int b, int c) : a(a), b(b), c(c) {}

void QuadraticFunc::showFunc() {
    cout << "\nf(x) = " << a << "x^2 + " << b << "x + " << c << endl;
}

double QuadraticFunc::getA() {
    return a;
}

double QuadraticFunc::getB() {
    return b;
}

double QuadraticFunc::getC() {
    return c;
}



Student::Student(string name, string surname, int album, double questionsNumber, double answersNumber)
: name(name), surname(surname), album(album), questionsNumber(questionsNumber), answersNumber(answersNumber){}

void Student::correctAnswersPercent() {
    double percent = (answersNumber/questionsNumber) * 100;
    cout << "\nProcent dobrych odpowiedzi: " << percent << "%\n";
}

string Student::getName() {
    return name;
}

string Student::getSurname() {
    return surname;
}

int Student::getAlbum() {
    return album;
}

double Student::getQuestionsNumber() {
    return questionsNumber;
}

double Student::getAnswersNumber() {
    return answersNumber;
}


Point::Point(int x, int y) : x(x), y(y) {}

double Point::lengthPoints(Point point) {
    return sqrt(pow(this->x-point.x,2)+pow(this->y-point.y,2));
}

Figure::Figure(int cuspNumber) : cuspNumber(cuspNumber) {
    cuspArray  = new int[cuspNumber];
    for(int i = 0; i < cuspNumber; i++)
        cuspArray[i] = i;

    cout << "=> Konstruktor wywolany!" << endl;
}

void Figure::show_cusps() {
    for(int i = 0; i < cuspNumber; i++)
        cout << endl << cuspArray[i];
}

Figure::~Figure() {
    cout << "=> Destruktor wywolany!" << endl;
}
