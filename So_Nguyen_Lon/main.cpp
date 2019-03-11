#include <iostream>
#include <string>
#include <vector>

#include "QInt.h"

using namespace std;

struct Terminal_Input {
	int p[2];
	string s1;
	char op;
	string s2;
};

Terminal_Input Doc_Input(char* argv[], int argc) {
	Terminal_Input ti;
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

int main(int argc, char* argv[]) {
	Terminal_Input ti = Doc_Input(argv, argc);
	if (argc == 5)
		cout << ti.p[0] << endl << ti.s1 << endl << ti.op << endl << ti.s2 << endl;
	else if (argc == 4)
		cout << ti.p[0] << endl << ti.p[1] << endl << ti.s1 << endl;
	system("pause");
	return 0;
}