//============================================================================
// Name        : Lesson_16092021.cpp
// Author      : AloolXO
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

int countWords(string x) {
    int Num = 0;
    char prev = ' ';
    for (unsigned int i = 0; i < x.size(); i++) {
        if (x[i] != ' ' && prev == ' ') Num++;
        prev = x[i];
    }
    return Num;
}

void countWord(string s, char c){
	int k = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == c && s[i-1] == ' ')
			k++;
	if (k)
			//Количество слов, начинающихся на букву
	        cout << "Количество слов, начинающихся на букву " << c << ": " << k << endl;
	    else
	    	//Искомых слов не найдено!
	        cout << "Искомых слов не найдено!" << endl;
		//Процентное содержание слов на букву
	    cout << "Процентное содержание слов на букву " << c << ": " << (double)k*100/countWords(s) << " %" << endl;
}

int main(){
    setlocale(LC_ALL, "ru");
    char y = 'у', p= 'п';
    string s, word;
    cout << "Анализируемый текст приведен в файле For_lesson_16092021.txt" << endl;
    ifstream F;
    F.open("C://University/2_course/3_semester/Data_structures_and_algoritms_II/Lesson_16092021/input.txt");
    if (F.is_open())
    {
        while (getline(F, s))
        {
            cout << s << endl;
        }
    }
    F.close();
    stringstream str(s);
    cout << "Общее количество слов: " << countWords(s) << endl;

    countWord(s,y);
    countWord(s,p);

    cin.get();
    system("pause");
}
