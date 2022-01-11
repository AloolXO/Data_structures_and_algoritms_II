//============================================================================
// Name        : Ex9_List.cpp
// Author      : AloolXO
// Version     :
// Copyright   : Ex9 List
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List.h"

using namespace std;

int main() {

	char w;

	List<string> lst;
	lst.push_back("яматури");
	lst.push_back("Ћи");
	lst.push_back("√уров");
	lst.push_back("√ати€тов");
	lst.push_back("ƒружинина");
	lst.push_back("¬асильева");
	lst.push_back("‘альков");

	for (int i = 0; i < lst.GetSize(); i++)
	        cout << lst[i] << " ";

	cout << "\nInput word for search last mane: "; cin >> w;
	lst.Finder(w);
}
