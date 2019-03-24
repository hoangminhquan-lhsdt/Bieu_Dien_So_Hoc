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

Input_Struct Doc_Input_Dong(string &str) {
	vector<int> Space_Positions;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			Space_Positions.push_back(i);
	}

	Input_Struct in;
	if (Space_Positions.size() == 2) {  // 2 dấu cách tức đây là phép convert
		in.p[0] = atoi(str.substr(0, Space_Positions[0]).c_str());
		in.p[1] = atoi(str.substr(Space_Positions[0] + 1, Space_Positions[1] - Space_Positions[0] - 1).c_str());
		in.s1 = str.substr(Space_Positions[1] + 1, str.length() - Space_Positions[1] - 1);
	}
	else {  // trường hợp còn lại là 3 dấu cách, tức đây là một biểu thức
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

vector<Input_Struct> Doc_File(char* argv[]) {
	vector<Input_Struct> Req_List;

	fstream f;
	f.open(argv[1], ios::in);
	Input_Struct in;
	string temp;
	while (f) {
		if (f.eof()) break;
		getline(f, temp);
		in = Doc_Input_Dong(temp);
		Req_List.push_back(in);
	}

	f.close();
	return Req_List;
}

string ConvertQInt(Input_Struct in) {
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

string ConvertQfloat(Input_Struct in) {
	if (in.p[0] == 2 && in.p[1] == 10) {
		return "A";
	}
	else
		return "A";
}

void XuLyQInt(fstream &f, vector<Input_Struct> &Req_List) {
	// danh sách các operators
	string operators[17] = { "+", "-", "*", "/", "<", ">", "==", "<=", ">=", "&", "|", "^", "~", "<<", ">>", "rol", "ror" };

	for (int k = 0; k < Req_List.size(); k++) {
		if (Req_List[k].p[1] == 0) {  // kiểm tra liệu có p thứ 2 hay không, nếu không có tức request là một biểu thức,
									  // nếu có thì đây là một phép đổi

			QInt num1(Req_List[k].s1, Req_List[k].p[0]), num2(Req_List[k].s2, Req_List[k].p[0]);
			int i = 0;
			for (i; i < 18; i++) {
				if (Req_List[k].op == operators[i])
					break;
			}

			QInt result;
			switch (i + 1) {
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

			switch (Req_List[k].p[0]) {  // kiểm tra và đổi kết quả thành chuỗi để xuất
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

		else //Phép đổi 
		{ 
			string out = ConvertQInt(Req_List[k]);
			cout << out << endl;
			f << out << endl;
		}
	}
}

void XuLyQfloat(fstream &f, vector<Input_Struct> &Req_List) {
	for (int k = 0; k < Req_List.size(); k++) {
		string out = ConvertQfloat(Req_List[k]);
		cout << out << endl;
		f << out << endl;
	}
}

int main(int argc, char* argv[]) {
	/*
	fstream f;

	vector<Input_Struct> Req_List;
	Req_List = Doc_File(argv);
	if (Req_List.size() == 0) {
		cout << "Loi: khong doc duoc file " << argv[1] << endl;
		return 0;
	}
	f.open(argv[2], ios::out);

	if (*argv[3] == '1')
		XuLyQInt(f, Req_List);
	else
		XuLyQfloat(f, Req_List);
		*/
	//QInt X("-1", 10);
	Qfloat A("0.5",10);
	//A.PrintQfloat();
	//f.close();
	//cout << Multiply("123", "0");
	system("pause");
	return 0;
}

