//
// Created by onetw on 08.10.2021.
//

#ifndef EX5_VERY_LONG_WHOLE_AND_CLASS_VLW_H
#define EX5_VERY_LONG_WHOLE_AND_CLASS_VLW_H



using namespace std;

class VLW {

    std::string s;
    vector<int> p_darr;
    int *Ex5_0_arr = new int[size(s)+1];
    int Ex5_1_count = 0;
    int n;

public:

    void output();
    void Ex5_0();
    void Ex5_1();
    void Ex5_2();

    VLW(std::string);
    ~VLW();

};

VLW::~VLW() {
    cout << "\tDeleting Very long whole (VLW)";
    delete [] Ex5_0_arr;
}

VLW::VLW(std::string str) {
    s = str;
    for (int i = 0; i < s.length() ; i++) {
        p_darr.push_back(s[i]-'0');
    }
}

void VLW::output() {
    cout << "\nVery long whole: " << endl;
    for (int i = 0; i < p_darr.size() ; i++)
        cout << p_darr[i] << " ";
    cout << endl;
}

void VLW::Ex5_0() {

    s[0] == '9' ? n = s.length()+1 : n = s.size();

    for(int i = 0; i < n; i++)
        Ex5_0_arr[i] = s[i]-'0';

    if (Ex5_0_arr[0] == 9){
        Ex5_0_arr[0] = 1;
        for (int i = 1; i < n; i++)
            Ex5_0_arr[i] = 0;
        goto end;
    }

    for (int i = n; i > 0; i--) {
        if(Ex5_0_arr[i-1] != 9){
            Ex5_0_arr[i-1] += 1;
            goto end;
        }
        else
            Ex5_0_arr[i-1] = 0;
    }
    end:
        cout << "\nAnswer for Ex.5-0 (variant for all students): " << endl;
        for (int i = 0; i < n ; i++)
            cout << Ex5_0_arr[i] << " ";
        cout << endl;
}

void VLW::Ex5_1() {

    for(int i = 0; i < size(s); i++){
        if (p_darr[i] == 2 && p_darr[i+1] == 2 && i+1 != size(s)-1){
            while (p_darr[i] == 2)
                i++;
            Ex5_1_count++;
        }
    }

    cout << "\nAnswer for Ex.5-1 (variant №15): " << endl;
    cout << Ex5_1_count << endl;
}

void VLW::Ex5_2() {
    if (size(s) <= 20) {
        vector<int> result;
        unsigned long long int n=0;
        for(int i=0; i < size(s); i++)
        {
            if ( s[i] != '0') {
                n *= 10;
                n += (s[i] - '0');
            } else {
                n *= 10;
            }
        }
        cout << "\n" << "\nAnswer for Ex.5-2 (variant №15): ";
        cout <<endl << n << " = 1";
        int i = 2;
        while (n > 1){
            if (n % i == 0){
                result.push_back(i);
                n /= i;
            }
            i++;
        }
        for (int i = 0; i < size(result); i++)
            cout << " * " << result[i];
        cout << endl;
    }
    else/*{
        vector<int> whole;
        vector<int> result;
        for(int i = 0; i < s.length(); i++)
            whole.push_back(s[i]);

    }*/
        cout << "Exit 1" << endl;

}

#endif //EX5_VERY_LONG_WHOLE_AND_CLASS_VLW_H