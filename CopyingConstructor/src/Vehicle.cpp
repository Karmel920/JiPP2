//
// Created by volie on 08.11.2021.
//

#include "Vehicle.h"

Vehicle::Vehicle(string registrationNumber, string name, int seats, string make, string type)
: registrationNumber(registrationNumber), name(name), seats(seats), make(make), type(type)
{
    arrayPassengers = new string[seats];
    for(int i = 0; i < seats; i++)
        arrayPassengers[i] = "Puste";
}

void Vehicle::showInfo() {
    cout << "\nNumer rejestracyjny: " << registrationNumber << endl;
    cout << "Nazwa: " << name << endl;
    cout << "Ilosc miejsc: " << seats << endl;
    cout << "Marka: " << make << endl;
    cout << "Typ: " << type << endl;
    cout << "\nLista miejsc:\n";
    for(int i = 0; i < seats; i++)
        cout << "Miejsce numer " << i << ": " << arrayPassengers[i] << endl;
}

void Vehicle::setPassenger(int seatNumber, string passName) {
    arrayPassengers[seatNumber] = passName;
}

Vehicle::Vehicle(Vehicle &vehicle) {
    registrationNumber = vehicle.registrationNumber;
    name = vehicle.name;
    seats = vehicle.seats;
    make = vehicle.make;
    type = vehicle.type;

    arrayPassengers = new string[seats];

    for(int i = 0; i < seats; i++)
        arrayPassengers[i] = vehicle.arrayPassengers[i];
}

string Vehicle::getName() {
    return name;
}

string Vehicle::getRegistrationNumber() {
    return registrationNumber;
}

string Vehicle::getMake() {
    return make;
}

string Vehicle::getType() {
    return type;
}

void Vehicle::setName(string namee) {
    name = namee;
}

void Vehicle::setRegistrationNumber(string rnumber) {
    registrationNumber = rnumber;
}


