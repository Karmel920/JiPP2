#include <iostream>
#include <string>
#include "calc.h"

using namespace std;

int main(int argc, char *argv[]){
    int result;
    string operation;

    operation = argv[1];

    if (operation.compare("add") == 0 && argc == 4) {
        result = add(atoi(argv[2]), atoi(argv[3]));
    } else if (operation.compare("subtract") == 0 && argc == 4) {
         result = subtract(atoi(argv[2]), atoi(argv[3]));
    } else if (operation.compare("volume") == 0 && argc == 6) {
         result = volume(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    } else if (operation.compare("help") == 0) {
        help();
        return 0;
    } else {
        cout << "BLAD, zly badz zla ilosc parametrow" << endl << endl;
        help();
        return 0;
    }

    cout << result;

    return 0;
}
