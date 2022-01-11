#include <iostream>
#include <vector>
#include <valarray>

#include "VLW.h"

using namespace std;

int main() {
    string s;
    cout << "Введите длинное целое положительное число: "; cin >> s;
    VLW number(s);
    number.output();
    number.Ex5_0();
    number.Ex5_1();
    number.Ex5_2();
    return 0;
}
