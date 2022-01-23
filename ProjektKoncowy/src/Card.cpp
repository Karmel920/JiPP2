//
// Created by volie on 21.01.2022.
//

#include "Card.h"

Card::Card(string currency, int id) : Account(id), currency(currency){}

Card::Card(string currency, int id, double groceries, double leisure, double transport, double health, double shopping, double bills,
           double expenses, double income, double balance) : Account(id), currency(currency), groceries(groceries), leisure(leisure),
           transport(transport), health(health), shopping(shopping), bills(bills), expenses(expenses),
           income(income), balance(balance){}



void Card::setExpenses(double groceries, double leisure, double transport, double health, double shopping, double bills) {
    this->groceries = groceries;
    this->leisure = leisure;
    this->transport = transport;
    this->health = health;
    this->shopping = shopping;
    this->bills = bills;
    this->expenses = groceries + leisure +transport + health + shopping + bills;
}

void Card::setIncome(double salary) {
    this->income = salary;
}

void Card::setBalance() {
    this->balance = income - expenses;
}



string Card::getCurrency() {
    return this->currency;
}

double Card::getGroceries() {
    return this->groceries;
}

double Card::getLeisure() {
    return this->leisure;
}

double Card::getTransport() {
    return this->transport;
}

double Card::getHealth() {
    return this->health;
}

double Card::getShopping() {
    return this->shopping;
}

double Card::getBills() {
    return this->bills;
}

double Card::getExpenses() {
    return expenses;
}

double Card::getIncome() {
    return income;
}

double Card::getBalance() {
    return balance;
}



void Card::addGroceries(double x) {
    this->groceries += x;
    this->expenses += x;
}

void Card::addLeisure(double x) {
    this->leisure += x;
    this->expenses += x;
}

void Card::addTransport(double x) {
    this->transport += x;
    this->expenses += x;
}

void Card::addHealth(double x) {
    this->health += x;
    this->expenses += x;
}

void Card::addShopping(double x) {
    this->shopping += x;
    this->expenses += x;
}

void Card::addBills(double x) {
    this->bills += x;
    this->expenses += x;
}

void Card::addIncome(double x) {
    this->income += x;
}




void Card::subtractGroceries(double x) {
    this->groceries -= x;
    this->expenses -= x;
}

void Card::subtractLeisure(double x) {
    this->leisure -= x;
    this->expenses -= x;
}

void Card::subtractTransport(double x) {
    this->transport -= x;
    this->expenses -= x;
}

void Card::subtractHealth(double x) {
    this->health -= x;
    this->expenses -= x;
}

void Card::subtractShopping(double x) {
    this->shopping -= x;
    this->expenses -= x;
}

void Card::subtractBills(double x) {
    this->bills -= x;
    this->expenses -= x;
}

void Card::subtractIncome(double x) {
    this->income -= x;
}


Card &Card::operator+=(const double rhs) {
    this->income = this->income + rhs;
    return *this;
}

Card &Card::operator-=(const double rhs) {
    this->income = this->income - rhs;
    return *this;
}

void Card::addIncome(int x) {
    this->income += x;
    this->expenses += x;
}

Card::~Card() {
    //cout << "Obiekt usuniety";
}

















