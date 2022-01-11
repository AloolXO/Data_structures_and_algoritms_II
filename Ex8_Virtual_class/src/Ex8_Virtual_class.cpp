//============================================================================
// Name        : Ex8_Virtual_class.cpp
// Author      : AloolXO
// Version     :
// Copyright   : Ex8 Virtual class
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Vehicles.h"
#include "Car.h"
#include "Truck.h"

int main() {
    string b, c;
    int s, sP;
    float l;
    bool ch;
    cout << "\n¬ведите бренд, нагрузку, цвет, количество сид€чих и сто€чих мест в автомобиле через пробел: " << endl; cin >> b >> l >> c >> s >> sP;
    Car car(b, c, s, sP, l);
    car.showCar();
    cout << "\n¬ведите бренд, максимальную нагрузку и цвет грузовика через пробел: " << endl; cin >> b >> l >> c;
    Truck truck(b, c, l);
    truck.showTruck();
    cout << "\n¬ы хотите изменить максимальную нагрузку на грузовик ?" << endl; cin >> ch;
    if (ch) {
        cout << "\n¬ведите новое значение: " << endl;
        cin >> l;
        truck.setLoad(l);
        truck.showTruck();
    }
}
