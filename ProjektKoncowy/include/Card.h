//
// Created by volie on 21.01.2022.
//

#ifndef JIPP2_CARD_H
#define JIPP2_CARD_H

#include <iostream>
#include "Account.h"

using namespace std;

class Card : public Account {
private:
    string currency;
    double groceries, leisure, transport, health, shopping, bills;
    double expenses, income, balance;

public:
    /**
     * Konstruktor z dwoma parametrami
     * @param currency [string] waluta konta
     * @param id [int] id konta
     */
    Card(string currency, int id);

    /**
     * Konstruktor ze wszystkimi parametrami
     * @param currency [string] waluta konta
     * @param id [int] id konta
     * @param groceries [double] kategoria jedzenie
     * @param leisure [double] kategoria rozrywka
     * @param transport [double] kategoria transport
     * @param health [double] kategoria zdrowie
     * @param shopping [double] kategoria zakupy
     * @param bills [double] kategoria rachunki
     * @param expenses [double] wydatki konta
     * @param income [double] dochod konta
     * @param balance [double] balans konta
     */
    Card(string currency, int id, double groceries, double leisure, double transport, double health, double shopping, double bills,
         double expenses, double income, double balance);

    void setExpenses(double groceries = 0, double leisure = 0, double transport = 0, double health = 0, double shopping = 0, double bills = 0);
    void setIncome(double salary);
    void setBalance();

    string getCurrency();
    double getGroceries();
    double getLeisure();
    double getTransport();
    double getHealth();
    double getShopping();
    double getBills();
    double getExpenses();
    double getIncome();
    double getBalance();

    void addGroceries(double x);
    void addLeisure(double x);
    void addTransport(double x);
    void addHealth(double x);
    void addShopping(double x);
    void addBills(double x);
    void addIncome(double x);
    void addIncome(int x);

    void subtractGroceries(double x);
    void subtractLeisure(double x);
    void subtractTransport(double x);
    void subtractHealth(double x);
    void subtractShopping(double x);
    void subtractBills(double x);
    void subtractIncome(double x);

    /**
     * Przeciazanie sluzace do zwiekszania dochodu o zadany parmetr
     * @param rhs double, liczba o ktora zwiekszamy dochod
     * @return zwraca obiekt Card, ze zwiekszonym dochodem
     */
    Card &operator+=(const double rhs);

    /**
     * Przeciazenie sluzace do zmniejszania dochodu o zadany parametr
     * @param rhs double, liczba o ktora zmniejszamy dochod
     * @return zwraca obiekt Card, ze zmniejszonym dochodem
     */
    Card &operator-=(const double rhs);

    /**
     * Destruktor
     */
    ~Card();
};

#endif //JIPP2_CARD_H
