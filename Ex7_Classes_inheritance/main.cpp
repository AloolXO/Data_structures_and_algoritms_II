#include <iostream>

#include "Vehicles.h"
#include "Car.h"
#include "Truck.h"

int main() {
    string b, c;
    int s, sP;
    float l;
    bool ch;
    cout << "Введите сначала бренд, нагрузка, а затем цвет автотранспорта через пробел: "; cin >> b >> l >> c;
    Vehicles machine(b, c, l);
    machine.run();
    machine.showInfo();
    cout << "\nВведите бренд, нагрузку, цвет, количество сидячих и стоячих мест в автомобиле через пробел: " << endl; cin >> b >> l >> c >> s >> sP;
    Car car(b, c, s, sP, l);
    car.showCar();
    cout << "\nВведите бренд, максимальную нагрузку и цвет грузовика через пробел: " << endl; cin >> b >> l >> c;
    Truck truck(b, c, l);
    truck.showTruck();
    cout << "\nВы хотите изменить максимальную нагрузку на грузовик ?" << endl; cin >> ch;
    if (ch) {
        cout << "\nВведите новое значение: " << endl;
        cin >> l;
        truck.setLoad(l);
        truck.showTruck();
    }
}
