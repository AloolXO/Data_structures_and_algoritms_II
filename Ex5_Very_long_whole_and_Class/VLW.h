//
// Created by onetw on 08.10.2021.
//

#ifndef EX5_VERY_LONG_WHOLE_AND_CLASS_VLW_H
#define EX5_VERY_LONG_WHOLE_AND_CLASS_VLW_H

using namespace std;

class VLW {
public:

    void input();
    void output();
    void get_str();
    void Ex5_0();

    ~VLW();

private:

    std::string s;
    unsigned int *p_darr = new unsigned int[s.length()];
    unsigned int *Ex5_0_arr = new unsigned int[s.length()+1];

};

VLW::~VLW() {
    cout << "Deleting Very long whole (VLW)";
    delete [] p_darr;
}

void VLW::input() {
    for (int i = 0; i < s.length() ; i++) {
        p_darr[i] = (s[i]-'0');
    }
}

void VLW::output() {
    cout << "\nVery long whole: " << endl;
    for (int i = 0; i < s.length() ; i++)
        cout<<p_darr[i]<<" ";
    cout << endl;
}

void VLW::get_str() {
    cout << "Write the very long whole: ";
    cin >> s;
}

void VLW::Ex5_0() {
    Ex5_0_arr = p_darr;

    if (p_darr[0] = 9){
        Ex5_0_arr[0] = 1;
        for (int i = 1; i < s.length()+1; i++)
            Ex5_0_arr[i] = 0;
    }

    for (int i = s.length()+1; i >= 0; i--) {
        if(Ex5_0_arr[i] != 9){
            Ex5_0_arr[i]++;
            break;
        }
        else
            Ex5_0_arr[i] = 0;
    }
    cout << "\nAnswer for Ex.5-0 (variant for all students): " << endl;
    for (int i = 0; i < s.length()+1 ; i++)
        cout<<Ex5_0_arr[i]<<" ";
    cout << endl;
}

#endif //EX5_VERY_LONG_WHOLE_AND_CLASS_VLW_H
