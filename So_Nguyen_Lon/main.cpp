#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#include "QInt.h"

using namespace std;
string DecStrToBinStr(string x)
{
	string Result,Temp,p; //p thuong
	char buffer[10];
	while (x != "0")
	{
		Temp.clear();
		p.clear();
		Result = _itoa((x[x.length() - 1] - '0') % 2,buffer,10)+Result;
		for (int i = 0; i < x.length(); i++)
		{
			Temp += x[i];
			p += _itoa(stoi(Temp) / 2, buffer, 10);
			Temp = _itoa(stoi(Temp) % 2, buffer, 10);
		}
		while (p[0] == '0' && p.length() != 1)
		{
			p.erase(0,1);
		}
		x = p;
	}
	return Result;
}

int main() {

	//QInt N(DecStrToBinStr("4294967296"));
	//cout << DecStrToBinStr("1234235235235244534636546")<<endl;


	QInt Test("110100101010110101001010111110101010000101010101010011010101010100101");
	cout << Test << endl;
	string Nhan;
	Nhan = Test.DecToBin();
	cout << Nhan << endl;
	cout << "do dai chuoi: " << Nhan.length() << endl;

	Nhan = Test.BinToHex();
	cout << "Chuyen QInt 2 den 16:" << Nhan << endl;
	cout << "do dai cua chuoi: " << Nhan.length() << endl;
	//101010101010010110101010101011010011010


	system("pause");
	return 0;
}