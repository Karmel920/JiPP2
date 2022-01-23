//
// Created by volie on 21.01.2022.
//

#ifndef JIPP2_ACCOUNT_H
#define JIPP2_ACCOUNT_H

#include <iostream>

using namespace std;

class Account {
private:
    int id;

public:
    /**
     * Konstruktor z jednym parametrem id
     * @param id [int] id konta
     */
    Account(int id);
    //Account(string type);

    /**
    * Setter do ustawienia wydatkow
    * @param groceries [double] kategoria jedzenie
    * @param leisure [double] kategoria rozrywka
    * @param transport kategoria transport
    * @param health [double] kategoria zdrowie
    * @param shopping [double] kategoria zakupy
    * @param bills [double] kategoria rachunki
    */
    virtual void setExpenses(double groceries, double leisure, double transport, double health, double shopping, double bills) = 0;

    /**
     * Setter do ustawiania dochodu
     * @param salary [double] dochod
     */
    virtual void setIncome(double salary) = 0;

    /**
     * Setter do ustawiania balansu konta
     */
    virtual void setBalance() = 0;


    /**
     * Getter do uzyskania waluty konta
     * @return currency [string]
     */
    virtual string getCurrency() = 0;

    /**
     * Getter do uzyskania kategorii jedzenie
     * @return groceries [double]
     */
    virtual double getGroceries() = 0;

    /**
     * Getter do uzyskania kategorii rozrywka
     * @return leisure [double]
     */
    virtual double getLeisure() = 0;

    /**
     * Getter do uzyskania kategorii transport
     * @return transport [double]
     */
    virtual double getTransport() = 0;

    /**
     * Getter do uzyskania kategorii zdrowie
     * @return health [double]
     */
    virtual double getHealth() = 0;

    /**
     * Getter do uzyskania kategorii zakupy
     * @return shopping [double]
     */
    virtual double getShopping() = 0;

    /**
     * Getter do uzyskania kategorii rachunki
     * @return bills [double]
     */
    virtual double getBills() = 0;

    /**
     * Getter do uzyskania wydatkow konta
     * @return expenses [double]
     */
    virtual double getExpenses() = 0;

    /**
     * Getter do uzyskania dochodu konta
     * @return income [double]
     */
    virtual double getIncome() = 0;

    /**
     * Getter do uzyskania balansu konta
     * @return balance [double]
     */
    virtual double getBalance() = 0;


    /**
     * Funkcja dodajaca param x do kategorii jedzenie
     * @param x [double]
     */
    virtual void addGroceries(double x) = 0;

    /**
     * Funkcja dodajaca param x do kategorii rozrywka
     * @param x [double]
     */
    virtual void addLeisure(double x) = 0;

    /**
     * funkcja dodajaca param x do kategorii transport
     * @param x [double]
     */
    virtual void addTransport(double x) = 0;

    /**
     * funkcja dodajaca param x do kategorii zdrowie
     * @param x [double]
     */
    virtual void addHealth(double x) = 0;

    /**
     * funkcja dodajaca param x do kategorii zakupy
     * @param x [double]
     */
    virtual void addShopping(double x) = 0;

    /**
     * funkcja dodajaca param x do kategorii rachunki
     * @param x [double]
     */
    virtual void addBills(double x) = 0;

    /**
     * funkcja dodajaca param x do dochodu konta
     * @param x [double]
     */
    virtual void addIncome(double x) = 0;

    /**
     * funkcja dodajaca param x do dochodu konta
     * @param x [int]
     */
    virtual void addIncome(int x) = 0;


    /**
     * funkcja odejmujaca param x od kategorii zakupy
     * @param x [double]
     */
    virtual void subtractGroceries(double x) = 0;

    /**
     * funkcja odejmujaca param x od kategorii rozrywka
     * @param x [double]
     */
    virtual void subtractLeisure(double x) = 0;

    /**
     * funkcja odejmujaca param x od kategorii transport
     * @param x [double]
     */
    virtual void subtractTransport(double x) = 0;

    /**
     * funkcja odejmujaca param x od kategorii zdrowie
     * @param x [double]
     */
    virtual void subtractHealth(double x) = 0;

    /**
     * funkcja odejmujaca param x od kategorii zakupy
     * @param x [double]
     */
    virtual void subtractShopping(double x) = 0;

    /**
     * funkcja odejmujaca param x od kategorii rachunki
     * @param x [double]
     */
    virtual void subtractBills(double x) = 0;

    /**
     * funkcja odejmujaca param x od dochodu konta
     * @param x [double]
     */
    virtual void subtractIncome(double x) = 0;

    /**
     * Getter do uzyskania id konta
     * @return id [int]
     */
    int getId();

    /**
     * Destruktor
     */
    ~Account();
};


#endif //JIPP2_ACCOUNT_H
