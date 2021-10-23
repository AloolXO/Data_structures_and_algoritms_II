//
// Created by onetw on 14.10.2021.
//
#pragma once
#ifndef EX6_CLASSES_INHERITANCE_TRUCK_H
#define EX6_CLASSES_INHERITANCE_TRUCK_H

#include "Vehicles.h"

class Truck : public Vehicles {
public:

    Truck(string, string, float);
    ~Truck();

    void showTruck();

};

Truck::Truck(string b, string c, float l) : Vehicles(b, c, l) {
}

Truck::~Truck() {}

void Truck::showTruck() {
    cout << "\nДанные о грузовике: " << endl;
    Truck::showInfo();
}

#endif //EX6_CLASSES_INHERITANCE_TRUCK_H
