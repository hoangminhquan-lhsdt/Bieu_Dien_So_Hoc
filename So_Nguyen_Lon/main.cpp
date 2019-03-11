#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//#include "QInt.h"

using namespace std;

struct Input_Struct {
	int p[2];
	string s1;
	char op;
	string s2;
};

Input_Struct Doc_Terminal(char* argv[], int argc) {
	Input_Struct ti;
	ti.p[0] = atoi(argv[1]);
	ti.p[1] = 0;
	if (argc == 4) {
		ti.p[1] = atoi(argv[2]);
		ti.s1 = argv[3];
	}
	if (argc == 5) {
		ti.s1 = argv[2];
		ti.op = *argv[3];
		ti.s2 = argv[4];
	}
	return ti;
}

// read 
Input_Struct Doc_File() {
	Input_Struct ti;
	
	fstream f;
	f.open("input.txt", ios::in);

	int p[2];
	string line;
	getline(f, line);

	cout << line;

	return ti;
}

int main(char* argv[], int argc) {
	if (argc == 1)
		Input_Struct ti = Doc_File();
	else
		Input_Struct ti = Doc_Terminal(argv, argc);

	system("pause");
	return 0;
}