//
// Created by volie on 08.11.2021.
//

#ifndef JIPP2_VEHICLE_H
#define JIPP2_VEHICLE_H

#include <iostream>

using namespace std;

class Vehicle {
private:
    string registrationNumber;
    string name;
    int seats;
    string make;
    string type;
    string *arrayPassengers;

public:
    Vehicle(string registrationNumber, string name, int seats, string make, string type);

    Vehicle(Vehicle &vehicle);

    void showInfo();
    void setPassenger(int seatNumber, string passName);

    string getName();
    string getRegistrationNumber();
    string getMake();
    string getType();

    void setName(string namee);
    void setRegistrationNumber(string rnumber);
};


#endif //JIPP2_VEHICLE_H
