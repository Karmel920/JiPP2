//
// Created by volie on 21.01.2022.
//

#ifndef JIPP2_WALLET_H
#define JIPP2_WALLET_H

#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class Wallet {
private:
    vector<Account *> accounts;

public:
    /**
     * Constructor
     */
    Wallet();

    /**
     * Funkcja dodajaca obiekt Account do vectora w klasie Wallet
     * @param Acc
     */
    void addAccount(Account *Acc);

    /**
     * Funkcja usuwajaca obiekt Account z vectora w klasie Wallet
     */
    void deleteAccount();

    /**
     * Funkcja drukujaca balans wszystkich kont
     */
    void printAllAccountsBalance();

    /**
     * Funkcja czyszczaca vector w klasie Wallet
     */
    void clearWallet();
};

#endif //JIPP2_WALLET_H
