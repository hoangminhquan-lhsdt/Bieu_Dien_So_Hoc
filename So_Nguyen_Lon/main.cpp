#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include"Source.h"
#include "QInt.h"
#include "Qfloat.h"
using namespace std;

struct Input_Struct {
	int p[2];
	string s1;
	string op;
	string s2;
};

Input_Struct Doc_Terminal(int argc, char* argv[]) {
	Input_Struct in;
	in.p[0] = atoi(argv[1]);
	in.p[1] = 0;
	if (argc == 4) {
		in.p[1] = atoi(argv[2]);
		in.s1 = argv[3];
	}
	if (argc == 5) {
		in.s1 = argv[2];
		in.op = *argv[3];
		in.s2 = argv[4];
	}
	return in;
}

Input_Struct Doc_Input_Dong(string &str) {
	vector<int> Space_Positions;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			Space_Positions.push_back(i);
	}

	Input_Struct in;
	if (Space_Positions.size() == 2) {
		in.p[0] = atoi(str.substr(0, Space_Positions[0]).c_str());
		in.p[1] = atoi(str.substr(Space_Positions[0] + 1, Space_Positions[1] - Space_Positions[0] - 1).c_str());
		in.s1 = str.substr(Space_Positions[1] + 1, str.length() - Space_Positions[1] - 1);
	}
	else {
		in.p[0] = atoi(str.substr(0, Space_Positions[0]).c_str());
		in.p[1] = 0;
		in.s1 = str.substr(Space_Positions[0] + 1, Space_Positions[1] - Space_Positions[0] - 1).c_str();
		if (Space_Positions[2] - Space_Positions[1] == 2)
			in.op.push_back(str[Space_Positions[1] + 1]);
		else {
			in.op.push_back(str[Space_Positions[1] + 1]);
			in.op.push_back(str[Space_Positions[2] - 1]);
		}
		in.s2 = str.substr(Space_Positions[2] + 1, str.length() - Space_Positions[2] - 1);
	}
	return in;
}

vector<Input_Struct> Doc_File() {
	vector<Input_Struct> Req_List;

	fstream f;
	f.open("input.txt", ios::in);
	Input_Struct in;
	string temp;
	while (f) {
		if (f.eof()) break;
		getline(f, temp);
		in = Doc_Input_Dong(temp);
		Req_List.push_back(in);
	}

	return Req_List;
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		vector<Input_Struct> Req_List = Doc_File();
		for (int i = 0; i < Req_List.size(); i++) {
			cout << "Request " << i + 1 << ":\n";
			cout << Req_List[i].p[0] << " " << Req_List[i].p[1] << " " << Req_List[i].s1 << " " << Req_List[i].op << " " << Req_List[i].s2 << endl << endl;
		}
	}
	else
		Input_Struct ti = Doc_Terminal(argc, argv);

	/*QInt x;
	x.ScanQInt();
	x.PrintQInt();
	cout << "He 2: " << x.QIntToBin() << endl;
	cout << "He 16: " << x.QIntToHex() << endl;
	QInt y= x << 2;
	cout << "x << 2 = ";
	y.PrintQInt();*/
	/*QInt x("8793278316383117319", 10);
	cout << x.QIntToBin() << endl;
	*/
	string a = "888888888888888888888888", b = "999999999999999999999999";
	/*cout << Sub(a, b) << endl;
	cout << Subtract(a, b) << endl;
	cout << Subtract("18", "12") << endl;
	cout << Divide("1", "512") << endl;*/
	////string c = HaiMuN_Am(-9);
	//cout << c;
	//cout << HaiMuN_Am(-9) << endl;
	string x;
	cin >> x;
	Qfloat f(x,10);
	f.DecToBin();
	f.PrintQfloat();
	system("pause");

}

