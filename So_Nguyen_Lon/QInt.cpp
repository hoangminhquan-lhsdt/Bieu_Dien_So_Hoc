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

string QInt::BinToHex()
{
	int i;
	string re;
	for(i=0;i<4;i++)
		if (this->data[i] != 0)
		{
			re += Tra1016(this->data[i]);
		}
	return re;
}

string QInt::Tra1016(unsigned int a)
{
	int sodu;
	string tra;
	while (a != 0)
	{
		sodu = a % 16;
		switch (sodu)
		{
		case 10: tra.push_back('A'); break;
		case 11: tra.push_back('B'); break;
		case 12: tra.push_back('C'); break;
		case 13: tra.push_back('D'); break;
		case 14: tra.push_back('E'); break;
		case 15: tra.push_back('F'); break;
		default: tra.push_back(sodu + '0'); break;
		}
		a = a / 16;
	}
	reverse(tra.begin(), tra.end());
	return tra;
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



