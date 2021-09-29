//============================================================================
// Name        : Ex1_Sentences_from_words.cpp
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
#include <stdio.h>
#include <vector>

using namespace std;

/*struct  Turnover {
    string sentens_1;
    string sentens_2;
};*/

int countWords(string x) {
    int Num = 0;
    char prev = ' ';
    for (unsigned int i = 0; i < x.size(); i++) {
        if (x[i] != ' ' && prev == ' ') Num++;
        prev = x[i];
    }
    return Num;
}

void removeDupWord(string str) {
   string word = "";
   for (auto x : str) {
       if (x == ' ' || x == ',' || x == '.' || x == 'Ц') {
           cout << word << endl;
           word = "";
       }
       else {
    	   word = word + x;
       }
   }
   //cout << word << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	string s1, s2;
	cout << "»сходный текст находитьс€ в файле Input.txt" << endl;
	ifstream F;
	F.open("C://University/2_course/3_semester/Data_structures_and_algoritms_II/Ex1_Sentences_from_words/input.txt");
	if (F.is_open())
	{
		while (getline(F, s1))
		{
			cout << s1 << endl;
			break;
		}
		while (getline(F, s2)){
			cout << s2 << endl;
		}
	}
	/*struct Turnover TwoSentens;
	TwoSentens.sentens_1=s1;
	TwoSentens.sentens_2=s2;*/

	/*string *sentens1 = new string[countWords(s1)];
	string *sentens2 = new string[countWords(s2)];*/

	//vector<string> sentens1;

	/*while(s1 != " "){
		int space_pos = s1.find(' ');
		if(space_pos != -1)
		{
			sentens1.push_back(s1.substr(0, space_pos));
			s1.erase(0, space_pos + 1);
		}
		else
		{
			sentens1.push_back(s1);
			s1.clear();
		}
	}

	for(int i = 0; i < sentens1.size(); i++)
	    cout << sentens1[i] << endl;*/
	removeDupWord(s1);
}
