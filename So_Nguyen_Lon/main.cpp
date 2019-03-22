#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <map>
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

string Convert(Input_Struct in) {
	if (in.p[0] == 2 && in.p[1] == 10) {
		return QInt(in.s1, 2).QIntToDec();
	}
	else if (in.p[0] == 2 && in.p[1] == 16) {
		return QInt(in.s1, 2).QIntToHex();
	}

	else if (in.p[0] == 10 && in.p[1] == 2) {
		return QInt(in.s1, 10).QIntToBin();
	}
	else if (in.p[0] == 10 && in.p[1] == 16) {
		return QInt(in.s1, 10).QIntToHex();
	}

	else if (in.p[0] == 16 && in.p[1] == 2) {
		return QInt(in.s1, 16).QIntToBin();
	}
	else {
		return QInt(in.s1, 16).QIntToDec();
	}
}

int main(int argc, char* argv[]) {
	/*string operators[17] = { "+", "-", "*", "/", "<", ">", "==", "<=", ">=", "&", "|", "^", "~", "<<", ">>", "rol", "ror" };

	fstream f;
	f.open("output.txt", ios::out);

	vector<Input_Struct> Req_List;
	if (argc == 1) {  // tham số duy nhất là tên file thực thi -> đọc từ input.txt
		Req_List = Doc_File();
		if (Req_List.size() == 0) {
			cout << "Loi: khong doc duoc file input.txt\n";
			return 0;
		}
	}
	else  // Nhiều tham số -> chạy bằng tham số dòng lệnh
		Req_List.push_back(Doc_Terminal(argc, argv));


	for (int k = 0; k < Req_List.size(); k++) {
		if (Req_List[k].p[1] == 0) {
			QInt num1(Req_List[k].s1, Req_List[k].p[0]), num2(Req_List[k].s2, Req_List[k].p[0]);
			int i = 0;
			for (i; i < 18; i++) {
				if (Req_List[k].op == operators[i])
					break;
			}
			QInt result;
			switch (i+1) {
				case 1: {
					result = num1 + num2;
					break;
				}
				case 2: {
					result = num1 - num2;
					break;
				}
				case 3: {
					result = num1 * num2;
					break;
				}
				case 4: {
					result = num1 / num2;
					break;
				}
				case 5: {
					if (num1 < num2) cout << "True";
					else cout << "False";
					break;
				}
				case 6: {
					if (num1 > num2) cout << "True";
					else cout << "False";
					break;
				}
				case 7: {
					if (num1 == num2) cout << "True";
					else cout << "False";
					break;
				}
				case 8: {
					if (num1 <= num2) cout << "True";
					else cout << "False";
					break;
				}
				case 9: {
					if (num1 >= num2) cout << "True";
					else cout << "False";
					break;
				}
				case 10: {
					result = num1 & num2;
					break;
				}
				case 11: {
					result = num1 | num2;
					break;
				}
				case 12: {
					result = num1 ^ num2;
					break;
				}
				case 13: {
					//result = num1 ~ num2;
					break;
				}
				case 14: {
					result = num1 << stoi(num2.QIntToDec());
					break;
				}
				case 15: {
					result = num1 >> stoi(num2.QIntToDec());
					break;
				}
				case 16: {
					result = num1.rol(stoi(num2.QIntToDec()));
					break;
				}
				case 17: {
					result = num1.ror(stoi(num2.QIntToDec()));
					break;
				}
			}
			switch (Req_List[k].p[0]) {
				case 2: {
					cout << result.QIntToBin() << endl;
					f << result.QIntToBin() << endl;
					break;
				}
				case 10: {
					cout << result.QIntToDec() << endl;
					f << result.QIntToDec() << endl;
					break;
				}
				case 16: {
					cout << result.QIntToHex() << endl;
					f << result.QIntToHex() << endl;
					break;
				}
			}
		}
		else {
			string out = Convert(Req_List[k]);
			cout << out << endl;
			f << out << endl;
		}
	}


	f.close();
	*/

	QInt A("1"), B("2"), C;
	C = A << B;

	system("pause");
	return 0;
}

