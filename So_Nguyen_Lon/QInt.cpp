#pragma once
#include <iostream>
#include <string>
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

QInt QInt::operator<<(const int k)
{

	return QInt();
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



string QInt::DecToBin()
{
	string nhan;
	int i;
	for (i = 0; i <4; i++)
	{
		nhan += Tra2(this->data[i]);
	}
	return nhan;
}

string QInt::Tra2(unsigned int a)
{
	int sodu;
	if (a == 0)
	{ 
		string tra(32, '0'); 
		return tra;
	}
	else
	{
		string tra;
		while (a != 0)
		{
			sodu = a % 2;
			tra.push_back(sodu + '0');
			a = a / 2;
		}
		if (tra.length() < 32)
		{
			string c(32 - tra.length(), '0');
			tra += c;
		}

			reverse(tra.begin(), tra.end());
		return tra;
	}
}

istream & operator>>(istream & in, QInt & N)
{

	return in;
}

ostream & operator<<(ostream & out, const QInt & N)
{
	int i;
	for (i = 0; i < 4; i++)
		cout << N.data[i] << endl;
	return out;
}



