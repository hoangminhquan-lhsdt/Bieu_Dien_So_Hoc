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

QInt QInt::operator&(const QInt & N)
{
	QInt X;
	int i;
	for (i = 0; i < 4; i++)
		X.data[i] = this->data[i] & N.data[i];
	return X;
}

QInt QInt::operator|(const QInt & N)
{
	QInt X;
	int i;
	for (i = 0; i < 4; i++)
		X.data[i] = this->data[i] | N.data[i];
	return X;
}

QInt QInt::operator^(const QInt & N)
{
	QInt X;
	int i;
	for (i = 0; i < 4; i++)
		X.data[i] = this->data[i] ^ N.data[i];
	return X;
}

QInt QInt::operator~()
{
	QInt X;
	X = (*this);
	int i,j;
	for (i = 0; i < 4; i++)
	{
		for (j = 31; j >= 0; j--)
			X.data[i] = X.data[i] ^ (1 << (32 - j - 1));
		
	}
	return X;
}

QInt QInt::operator<<(int x)
{
	QInt Result;
	Result = (*this);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Result.data[j] >= pow(2, 31))
			{
				Result.data[j] -= pow(2, 31);
				if (j != 0)
					Result.data[j - 1] += 1;
			}
			Result.data[j] <<= 1;
		}
	}
	return Result;
}

QInt QInt::operator>>(int x)
{
	QInt Result;
	Result = (*this);
	for (int i = 0; i < x; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (Result.data[j] %2==1)
			{
				if (j != 3)
					Result.data[j +1] += pow(2,31);
			}
			Result.data[j] >>= 1;
		}
	}
	return Result;
}

QInt QInt::operator=(const QInt & N)
{
	for (int i = 0; i < 4; i++)
	{
		(*this).data[i] = N.data[i];
	}
	return(*this);
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
