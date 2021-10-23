#include <iostream>
#include <vector>
#include <iomanip>

#include "VLW.h"

using namespace std;

int main() {
    string s1, s2;
    cin >> s1;
    VLW vlw1(s1);
    cout << vlw1 << endl;
    cout << vlw1++;
   /* cin >> s2;
    VLW vlw2(s2);
    cout << vlw2 << endl;
    cout << (vlw1==vlw2);*/
}
