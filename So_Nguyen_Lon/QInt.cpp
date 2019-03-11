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

QInt::QInt(string x)
{
	string Temp;
	int count = 0;
	for (int i = 0; i < 4; i++)
		data[i] = 0;
	while (x.length() >= 32&&count <4)
	{
		Temp = x.substr(x.length() - 32);
		x.erase(x.length() - 32);
		this->data[3-count] = BinDec(Temp) + this->data[3 - count];
		count++;
	}
	this->data[3 - count] = BinDec(x) + this->data[3 - count];
	
}

QInt QInt::operator&(const QInt & N)
{
	QInt X;
	int i;
	for (i = 0; i < 4; i++)
		X.data[i] = this->data[i] & N.data[i];
	return X;
}

istream & operator>>(istream & in, QInt & N)
{
	return in;
}

ostream & operator<<(ostream & out, const QInt & N)
{
	int i;
	for (i = 0; i < 4; i++)
		cout << N.data[i]<<endl;
	return out;
}
