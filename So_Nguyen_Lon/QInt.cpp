#pragma once
#include <iostream>
#include "QInt.h"

using namespace std;
int BinDec(string x)
{
	int s = 0, n = x.length();
	for (int i = 0; i < n; i++)
		s += (x[i]-'0')*pow(2, n - 1 - i);
	return s;
}
QInt::QInt()
{
	for (int i = 0; i < 4; i++)
		data[i] = 0;
}


QInt::~QInt()
{
}

QInt QInt::BinToQInt(string x)
{
	QInt Result; 
	string Temp;
	int count = 0;
	for (int i = 0; i < 4; i++)
		data[i] = 0;
	while (x.length() >= 32 && count < 4)
	{
		Temp = x.substr(x.length() - 32);
		x.erase(x.length() - 32);
		Result.data[3 - count] = BinDec(Temp) + Result.data[3 - count];
		count++;
	}
	Result.data[3 - count] = BinDec(x) + Result.data[3 - count];

	return Result;
}

istream & operator>>(istream & in, QInt & N)
{
	return in;
}

ostream & operator<<(ostream & out, const QInt & N)
{
	return out;
}
