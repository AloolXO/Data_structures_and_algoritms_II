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
	lst.push_back("�������");
	lst.push_back("��");
	lst.push_back("�����");
	lst.push_back("��������");
	lst.push_back("���������");
	lst.push_back("���������");
	lst.push_back("�������");

	for (int i = 0; i < lst.GetSize(); i++)
	        cout << lst[i] << " ";

	cout << "\nInput word for search last mane: "; cin >> w;
	lst.Finder(w);
}
