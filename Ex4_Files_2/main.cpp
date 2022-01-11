#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
    string s, all = "", num;
    ifstream F;
    ofstream out;
    char r = '\r', n = '\n';
    try {
        F.open("C://University/2_course/3_semester/Data_structures_and_algoritms_II/Ex3_Files_1/Input.txt");
        throw "Error in open file for input!";
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    if (F.is_open()) {
        while (getline(F, s, r)) {
            all += s;
        }
    } else {  }

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
    cout << "Input: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << "\t" << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl << "Output in file output.txt ";
    try {
        out.open("Output.txt");
        if (out.is_open()) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++)
                    out << "\t" << arr[i][j] << " ";
                out << endl;
            }
        } else {
            throw "Error in open file for output!";
        }
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
}