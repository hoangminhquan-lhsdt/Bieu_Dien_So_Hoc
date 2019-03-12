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

    QInt N,M;
	N=N.BinToQInt(DecStrToBinStr("9223372049740023808"));
	M = N >> 1;
	//cout << DecStrToBinStr("1234235235235244534636546")<<endl;
	system("pause");
	return 0;
}