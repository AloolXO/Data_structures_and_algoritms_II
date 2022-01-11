//============================================================================
// Name        : Ex5_TRY-CATCH.cpp
// Author      : Artem Leunenko
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
    string s, all = "", num;
    ifstream F;
    char r = '\r', n = '\n';
    try {
        F.open("C:\\University\\2_course\\3_semester\\Data_structures_and_algoritms_II\\Ex5_TRY-CATCH\\Input.txt");
    } catch (const exception &exception) {
        cout << " caught: " << exception.what() << '\n';
    }
    if (F.is_open()){
        try {
            while (getline(F, s, r)) {
                all += s;
            }
        } catch (const exception &exception) {
            cout << " caught: " << exception.what() << '\n';
        }
    }
    double arr[5][5];
    int l = all.length(), t = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) {
            while (t < l) {
                if (all[t] == ';') {
                    t++;
                    break;
                } else if (all[t] == '\n') {
                    t += 2;
                    break;
                } else {
                    num += all[t];
                    t++;
                }
            }
            arr[i][j] = stod(num);
            num = "";
        }
    }
    cout << "Изначальная матрица из файла Input.txt: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << "\t" << arr[i][j] << " ";
        cout << endl;
    }
    double arrT[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            arrT[i][j] = arr[j][i];
        }
    }
    cout << endl << "Транспонированная матрица: " << endl;
    try {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
                cout << "\t" << arrT[i][j] << " ";
            cout << endl;
        }
    } catch (const exception &exception) {
        cout << " caught: " << exception.what() << '\n';
    }
}
