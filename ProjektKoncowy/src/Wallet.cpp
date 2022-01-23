//
// Created by volie on 21.01.2022.
//

#include "Wallet.h"


Wallet::Wallet() {
    //this->accounts.emplace_back("Card");
}


void Wallet::addAccount(Account *Acc) {
    this->accounts.push_back(Acc);
}

void Wallet::deleteAccount() {
    this->accounts.pop_back();
}

void Wallet::clearWallet() {
    this->accounts.clear();
}

void Wallet::printAllAccountsBalance() {
    double balance = 0;
    vector<Account *>::iterator x;
    for(x = accounts.begin(); x != accounts.end(); x++)
        balance += (*x)->getBalance();
    cout << balance << endl;
}
