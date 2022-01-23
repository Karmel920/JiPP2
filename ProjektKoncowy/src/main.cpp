//
// Created by volie on 21.01.2022.
//

#include <iostream>
#include <string.h>
#include "Wallet.h"
#include "Account.h"
#include "Card.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/*
 * Information about program
 */
void help();

/**
 *
 * @tparam T typ danych
 * @param a vector
 * @return index of maximum element of vector
 */
template<typename T>
T myMax(vector<T> a) {
    T max = 0;
    for(int i = 1; i < a.size(); i++){
        if(a[max] < a[i])
            max = i;
    }
    return max;
}

int main(int argc, char *argv[]) {

    if (argc == 1) {
        cout << "NIE PODANO ARGUMENTOW" << endl << endl;
        help();
        return 0;
    }

    string curr;
    bool work;

    if (argc != 2 && strcmp(argv[1], "help")) {
        cout << "BLAD, zly badz zla ilosc parametrow" << endl << endl;
        help();
        return 0;
    } else if (!strcmp(argv[1], "help")) {
        help();
        return 0;
    }
    else if(!strcmp(argv[1], "PLN")) {
        curr = argv[1];
        work = true;
    }
    else if(!strcmp(argv[1], "USD")) {
        curr = argv[1];
        work = true;
    }
    try{
        curr = argv[1];
        if(curr != "PLN" && curr != "USD")
            throw "BLAD - ZLA WALUTA, pomoc po wpisaniu help";
    } catch(const char* msg) {
        cout << msg << endl << endl;
        return 1;
    }

    Wallet wallet;
    Account *konto;

    double kursUSD = 4.0;
    string currency;
    int ID;
    double groceries, leisure, transport, health, shopping, bills, expenses, income, balance;

    int nr_line = 0;
    fstream input;
    input.open("konto.txt", ios::in);
    if(input.is_open()) {
        string line;
        while(getline(input, line)){
            switch(nr_line) {
                case 0: currency = line; break;
                case 1: ID = atoi(line.c_str()); break;
                case 2: groceries = stod(line); break;
                case 3: leisure = stod(line); break;
                case 4: transport = stod(line); break;
                case 5: health = stod(line); break;
                case 6: shopping = stod(line); break;
                case 7: bills = stod(line); break;
                case 8: expenses = stod(line); break;
                case 9: income = stod(line); break;
                case 10: balance = stod(line); break;
            }
            nr_line++;
        }
        input.close();

        if(curr == "PLN" && currency == "USD") {
            groceries *= kursUSD;
            leisure *= kursUSD;
            transport *= kursUSD;
            health *= kursUSD;
            shopping *= kursUSD;
            bills *= kursUSD;
            expenses *= kursUSD;
            income *= kursUSD;
            balance *= kursUSD;
        } else if(curr == "USD" && currency == "PLN") {
            groceries /= kursUSD;
            leisure /= kursUSD;
            transport /= kursUSD;
            health /= kursUSD;
            shopping /= kursUSD;
            bills /= kursUSD;
            expenses /= kursUSD;
            income /= kursUSD;
            balance /= kursUSD;
        }

        konto = new Card(curr,ID,groceries,leisure,transport,health,shopping,bills,expenses,income,balance);
    } else {
        //cout << "Blad otwarcia pliku" << endl;
        konto = new Card(curr, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }

    wallet.addAccount(konto);

    vector<double> vecExpenses;

    cout << endl << "Konto otwarte[ID: " << konto->getId() << "]" << endl;
    cout << "Waluta: " << konto->getCurrency() << endl;

    while(work) {
        cout << endl << "MENU" << endl;
        cout << "1. Dodaj wydatki" << endl;
        cout << "2. Odejmij wydatki" << endl;
        cout << "3. Dodaj przychod" << endl;
        cout << "4. Odejmij przychod" << endl;
        cout << "5. Pokaz sume wydatkow" << endl;
        cout << "6. Pokaz sume przychodow" << endl;
        cout << "7. Pokaz balans konta" << endl;
        cout << "8. Pokaz najwiekszy wydatek" << endl;
        cout << "9. Pokaz procentowo wydatki" << endl;
        cout << "10. Zakoncz program" << endl;

        int wybor;
        cout << "Podaj opcje: " << endl;
        cin >> wybor;

        switch(wybor) {
            case 1: {
                double x;
                cout << endl << "Podaj o ile zwiekaszasz kategorie Jedzenie: ";
                cin >> x;
                konto->addGroceries(x);
                cout << endl << "Podaj o ile zwiekaszasz kategorie Rozrywka: ";
                cin >> x;
                konto->addLeisure(x);
                cout << endl << "Podaj o ile zwiekaszasz kategorie Transport: ";
                cin >> x;
                konto->addTransport(x);
                cout << endl << "Podaj o ile zwiekaszasz kategorie Zdrowie: ";
                cin >> x;
                konto->addHealth(x);
                cout << endl << "Podaj o ile zwiekaszasz kategorie Zakupy: ";
                cin >> x;
                konto->addShopping(x);
                cout << endl << "Podaj o ile zwiekaszasz kategorie Rachunki: ";
                cin >> x;
                konto->addBills(x);
                konto->setBalance();
                cout << endl;
            } break;
            case 2: {
                double x;
                cout << endl << "Podaj o ile zmniejszasz kategorie Jedzenie: ";
                cin >> x;
                konto->addGroceries(x);
                cout << endl << "Podaj o ile zmniejszasz kategorie Rozrywka: ";
                cin >> x;
                konto->addLeisure(x);
                cout << endl << "Podaj o ile zmniejszasz kategorie Transport: ";
                cin >> x;
                konto->addTransport(x);
                cout << endl << "Podaj o ile zmniejszasz kategorie Zdrowie: ";
                cin >> x;
                konto->addHealth(x);
                cout << endl << "Podaj o ile zmniejszasz kategorie Zakupy: ";
                cin >> x;
                konto->addShopping(x);
                cout << endl << "Podaj o ile zmniejszasz kategorie Rachunki: ";
                cin >> x;
                konto->addBills(x);
                konto->setBalance();
                cout << endl;
            } break;
            case 3: {
                double salary;
                cout << "Podaj o ile zwiekszasz przychod: ";
                cin >> salary;
                konto->addIncome(salary);
                konto->setBalance();
                cout << endl;
            } break;
            case 4: {
                double salary;
                cout << "Podaj o ile zmnniejszasz przychod: ";
                cin >> salary;
                konto->subtractIncome(salary);
                konto->setBalance();
                cout << endl;
            } break;
            case 5: {
                cout << "Suma wydatkow: " << konto->getExpenses() << endl;
            } break;
            case 6: {
                cout << "Suma przychodow: " << konto->getIncome() << endl;
            } break;
            case 7: {
                konto->setBalance();
                cout << "Balans konta: " << konto->getBalance() << endl;
            } break;
            case 8: {
                vecExpenses.push_back(konto->getGroceries());
                vecExpenses.push_back(konto->getLeisure());
                vecExpenses.push_back(konto->getTransport());
                vecExpenses.push_back(konto->getHealth());
                vecExpenses.push_back(konto->getShopping());
                vecExpenses.push_back(konto->getBills());

                double mymax = myMax(vecExpenses);
                cout << "Twoj najwiekszy wydatek: " << endl;
                switch(int(mymax)) {
                    case 0: cout << "Jedzenie: " << konto->getGroceries() << endl; break;
                    case 1: cout << "Rozrywka: " << konto->getLeisure() << endl; break;
                    case 2: cout << "Transport: " << konto->getTransport() << endl; break;
                    case 3: cout << "Zdrowie: " << konto->getHealth() << endl; break;
                    case 4: cout << "Zakupy: " << konto->getShopping() << endl; break;
                    case 5: cout << "Rachunki: " << konto->getBills() << endl; break;
                }
            } break;
            case 9: {
                cout << fixed << setprecision(2) << "Jedzenie: " << (konto->getGroceries()/konto->getExpenses()) * 100 << "%" << endl;
                cout << fixed << setprecision(2) << "Rozrywka: " << (konto->getLeisure()/konto->getExpenses()) * 100 << "%" << endl;
                cout << fixed << setprecision(2) << "Transport: " << (konto->getTransport()/konto->getExpenses()) * 100 << "%" << endl;
                cout << fixed << setprecision(2) << "Zdrowie: " << (konto->getHealth()/konto->getExpenses()) * 100 << "%" << endl;
                cout << fixed << setprecision(2) << "Zakupy: " << (konto->getShopping()/konto->getExpenses()) * 100 << "%" << endl;
                cout << fixed << setprecision(2) << "Rachunki: " << (konto->getBills()/konto->getExpenses()) * 100 << "%" << endl;
            } break;
            case 10: {
                work = false;
            } break;
            default: cout << "Nie ma takiej opcji w menu" << endl;
        }

    }

    fstream output;
    output.open("konto.txt", ios::out);
    if(output.is_open()) {
        output << konto->getCurrency() << endl;
        output << konto->getId() << endl;
        output << konto->getGroceries() << endl;
        output << konto->getLeisure() << endl;
        output << konto->getTransport() << endl;
        output << konto->getHealth() << endl;
        output << konto->getShopping() << endl;
        output << konto->getBills() << endl;
        output << konto->getExpenses() << endl;
        output << konto->getIncome() << endl;
        output << konto->getBalance() << endl;
        output.close();
    } else {
        cout << "Blad otwierania pliku" << endl;
        exit(1);
    }

    cout << "Zapisano dane, pogram konczy dzialanie" << endl;
    cout << "Balans wszystkich kont: ";
    wallet.printAllAccountsBalance();
    wallet.clearWallet();

    return 0;
}


void help() {
    cout << "PROGRAM DO ZARZADZANIA WYDATKAMI" << endl << endl;
    cout << "Podaj jeden arguemnt przy odpalaniu programu(waluta): " << endl;
    cout << "-Do wyboru PLN albo USD" << endl;
    cout << "Program zczytuje dane z pliku, ktory jest baza dla konta" << endl;
    cout << "Jezeli plik jeszcze nie istnieje, tworzy wyzerowane konto" << endl;
    cout << "Funkcje programu: " << endl;
    cout << "-Dodawanie/odejmowanie wydatkow/przychodow" << endl;
    cout << "-Wyswietlanie sumy wydatkow/przychodow oraz balansu" << endl;
    cout << "Na koniec dane zapisywane sa do bazy(pliku) konta" << endl;
}

