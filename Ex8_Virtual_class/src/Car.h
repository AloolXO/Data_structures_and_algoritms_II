//
// Created by onetw on 14.10.2021.
//
#pragma once
#ifndef EX6_CLASSES_INHERITANCE_CAR_H
#define EX6_CLASSES_INHERITANCE_CAR_H

#include "Vehicles.h"

class Car : public Vehicles {

    int seatPlace, standingPlaces;

public:

    Car(string, string, int, int, float);
    ~Car();

    void showCar();

};

Car::Car(string b, string c, int s, int sP, float l) : Vehicles(b, c, l) {
    seatPlace = s;
    standingPlaces = sP;
}

Car::~Car() {}

void Car::showCar() {
    Car::showInfo();
    cout << "\n���������� ������� ���� � ����������: " << seatPlace << endl;
    cout << "���������� ������� ���� � ����������: " << standingPlaces << endl;
}
#endif //EX6_CLASSES_INHERITANCE_CAR_H
