//
// Created by onetw on 14.10.2021.
//
#pragma once
#ifndef EX6_CLASSES_INHERITANCE_VEHICLES_H
#define EX6_CLASSES_INHERITANCE_VEHICLES_H

using namespace std;

class Vehicles {
private:

    string brand, color;
    bool went;

protected:
    float load;

public:

    Vehicles(string, string, float);
    ~Vehicles();
    void run();
    void showInfo();

    string getBrand() const { return brand; }
    string getColor() const { return color; }
    float  getLoad() const { return load; }
    void setLoad( float l ) { load = l; }
    bool getWent() const { return went; }

};

Vehicles::Vehicles(string b, string c, float l) {
    brand = b;
    color = c;
    load = l;
}

Vehicles::~Vehicles() {

}

void Vehicles::run() {
    went = true;
    cout << "\nАвтотранспорт начал движение." << endl;
}

void Vehicles::showInfo() {
    //output logo pyramid
    cout << "\nЛоготип: " << endl;
    int space, rows = 10;
    for(int i = 1, k = 0; i <= rows; ++i, k = 0) {
        for(space = 1; space <= rows-i; ++space)
            cout <<"  ";
        while(k != 2*i-1) {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }
    //show information about vehicles
    cout << "\nНазвание бренда автотранспорта: " << brand << endl;
	cout << "Цвет автотранспорта: " << color << endl;
	cout << "Максимальная нагрузка на автотранспортное средство составляет: " << load << endl;
}

#endif //EX6_CLASSES_INHERITANCE_VEHICLES_H
