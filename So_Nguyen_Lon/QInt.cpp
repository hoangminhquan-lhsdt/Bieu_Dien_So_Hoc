#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "QInt.h"

using namespace std;
string DecStrToBinStr(string x)
{
	string Result, Temp, p; //p thuong
	char buffer[10];
	while (x != "0")
	{
		Temp.clear();
		p.clear();
		Result = _itoa((x[x.length() - 1] - '0') % 2, buffer, 10) + Result;
		for (int i = 0; i < x.length(); i++)
		{
			Temp += x[i];
			p += _itoa(stoi(Temp) / 2, buffer, 10);
			Temp = _itoa(stoi(Temp) % 2, buffer, 10);
		}
		while (p[0] == '0' && p.length() != 1)
		{
			p.erase(0, 1);
		}
		x = p;
	}
	return Result;
}
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

QInt::QInt(string x)
{
	bool Temp;
	if (x[0] == '-')
	{
		Temp = true;
		x.erase(0, 1);
	}
	else
		Temp = false;
	
	(*this)=this->BinToQInt(DecStrToBinStr(x));
	if (Temp)
	{
		(*this) = ~(*this)+QInt("1");
	}
}
QInt::~QInt()
{
}

QInt QInt::operator+(const QInt & N)
{
	QInt Result;
	for (int i = 3; i >=0; i--)
	{
		Result.data[i] += this->data[i] + N.data[i];
		if ((Result.data[i] < this->data[i]|| Result.data[i] < N.data[i] )&& i!=0)
			Result.data[i - 1]++;
	}
	return Result;
}

QInt QInt::operator-(const QInt & N)
{
	QInt Temp=N;
	Temp = ~Temp + QInt("1");
	return (*this)+Temp;
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
	bool Temp=false;
	Result = (*this);
	if (Result.data[0] >= pow(2, 31))
	{
		Temp = true;
		Result.data[0] -= pow(2, 31);
	}
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
	if (Temp&&Result.data[0] < pow(2, 31))
		Result.data[0] += pow(2, 31);
	return Result;
}

QInt QInt::operator>>(int x)
{
	QInt Result;
	bool Temp=false;
	Result = (*this);
	if (Result.data[0] >= pow(2, 31))
	{
		Temp = true;
		Result.data[0] -= pow(2, 31);
	}
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
	if(Temp)
		Result.data[0] += pow(2, 31);
	return Result;
}

QInt QInt::rol(int x)
{
	QInt Result;
	bool Temp=false,Temp1;
	Result = (*this);
	if (Result.data[0] >= pow(2, 31))
	{
		Temp = true;
		Result.data[0] -= pow(2, 31);
	}
	for (int i = 0; i < x; i++)
	{
		Temp = false;
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
		if (Result.data[0] >= pow(2, 31))
			Result.data[3]++;
	}
	if (Temp&&Result.data[0] < pow(2, 31))
		Result.data[0] += pow(2, 31);
	return Result;
}
QInt QInt::ror(int x)
{
	QInt Result;
	bool Temp = false,Temp1;
	Result = (*this);
	if (Result.data[0] >= pow(2, 31))
	{
		Temp = true;
		Result.data[0] -= pow(2, 31);
	}
	for (int i = 0; i < x; i++)
	{
		Temp1 = false;
		for (int j = 3; j >= 0; j--)
		{
			if (Result.data[j] % 2 == 1)
			{
				if (j != 3)
					Result.data[j + 1] += pow(2, 31);
				else
					Temp1 = true;
			}
			Result.data[j] >>= 1;
		}
		if (Temp1)
			Result.data[0] += pow(2, 30);
	}
	if (Temp&&Result.data[0] < pow(2, 31))
		Result.data[0] += pow(2, 31);
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
