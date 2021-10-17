#include "calc.h"
#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int volume(int a, int b, int h, int H)
{
    return ((a+b)/2)*h*H;
}

void help()
{
    cout << "Simple calculatur" << endl;
    cout << endl << "Dzialania:" << endl << "add [a] [b]" << endl << "Dodawanie dwóch liczb ([a] i [b]) calkowitych." << endl;
    cout << endl <<"subtract [a] [b]" << endl << "Odejmowanie dwoch liczb ([a] i [b]) calkowitych." << endl;
    cout << endl << "volume [a] [b] [h] [H]" << endl << "Objetosc graniastoslupa o podstawie trapezu" << endl;
    cout << endl << "help" << endl << "Dokumentacja i info o bledach" << endl;
}