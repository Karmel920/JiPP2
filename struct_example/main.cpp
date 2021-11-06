//
// Created by volie on 06.11.2021.
//

#include <iostream>
#include <string>

using namespace std;

struct samochod {
    string marka;
    string model;
    int rok_produkcji;
    string kolor;
    int wys = 1;
};

void show_make(struct samochod woz[], int liczba_aut);
int show_oldest(struct samochod woz[], int liczba_aut);


int main() {
    int liczba_aut = 5, index;

    samochod woz[] = {{"Audi","A4",1998,"srebrny"},
                      {"BMW","M4",2018,"zloty"},
                      {"Renault","Clio",1999,"czerwony"},
                      {"Puegot","206",2005,"pomaranczowy"},
                      {"Ford","Focus RS",2016,"niebieski"}};

    show_make(woz, liczba_aut);

    index = show_oldest(woz, liczba_aut);
    cout << "\nNajstarszy samochod: " << woz[index].marka << " " << woz[index].model << " " << woz[index].rok_produkcji << " " << woz[index].kolor;

    return 0;
}

void show_make(struct samochod woz[], int liczba_aut) {

    int licznik;

    for(int i = 0; i < liczba_aut; i++) {
        if(woz[i].wys) {
            licznik = 1;
            for (int j = 0; j < liczba_aut; j++) {
                if (i != j) {
                    if (woz[i].marka == woz[j].marka) {
                        licznik += 1;
                        woz[j].wys = 0;
                    }
                }
            }
            cout << "Liczba aut marki " << woz[i].marka << " : " << licznik << endl;
        }
    }
}

int show_oldest(struct samochod woz[], int liczba_aut) {

    int i = 0;
    for(int j = 1; j < liczba_aut; j++) {
        if(woz[i].rok_produkcji > woz[j].rok_produkcji)
            i = j;
    }
    return i;
}