#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "QInt.h"
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
	unsigned int Temp;
	for (int i = 3; i >=0; i--)
	{
		Temp = Result.data[i];
		Result.data[i] += this->data[i] + N.data[i];
		if ((Result.data[i] < this->data[i]|| Result.data[i] < N.data[i]||(this->data[i]==N.data[i]&&Temp==1&&Result.data[i]== Temp + this->data[i] + N.data[i]))&& i!=0)
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

QInt QInt::operator/(const QInt & N)
{
	QInt A,X=N;
	QInt src = *this;
	bool SignA=false,SignB=false;
	if (src > QInt("0"))
	{

		A = QInt("0");	
	}
	else
		A = QInt("-1");
	if (src >= QInt("0"))
		SignA=true;
	if (X >= QInt("0"))
		SignB = true;
	int k = 128;
	while (k > 0) {
		A = A << 1;
		int temp = (src.data[0] >> 31) & 1;
		src = src << 1;
		if (temp == 1)
			A = A + QInt("1");
		if (SignA)
		{
			
			if (SignB)
			{
				A = A - X;
				if (A < QInt("0"))
				{
					A = A + X;
				}
				else
					src = src + QInt("1");
			}
			else
			{
				A = A + X;
				if (A < QInt("0"))
				{
					A = A - X;
				}
				else
					src = src + QInt("1");
			}
		}
		else
		{
			if (SignB)
			{
				A = A + X;
				if (A > QInt("0"))
				{
					A = A - X;
				}
				else
					src = src + QInt("1");
			}
			else
			{
				A = A - X;
				if (A > QInt("0"))
				{
					A = A + X;
				}
				else
					src = src + QInt("1");
			}
		}
		k--;
	}
	if (SignA != SignB)
		src = QInt("0") - src;
	return src;
}

QInt QInt::operator*(const QInt & N)
{
	QInt X=N, Y;
	bool Temp = false;
	if (X < QInt("0"))
	{
		X = QInt("0") - X;
		Temp = true;
	}
	QInt Result; // 1011 * 101
	int count = 0;
	while (X != QInt("0")&&X!=QInt("-1"))
	{
		if (X.data[3] % 2 == 1)
			Y = (*this);
		else
			Y = QInt("0");
		X = X >> 1;
		Y = Y << count;
		Result = Result + Y;
		count++;
	}
	if (Temp)
		Result = QInt("0") - Result;
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
	bool Temp = false;
	Result = (*this);
	if (Result.data[0] >= pow(2, 31))
	{
		Temp = true;
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
		if (Temp)
			Result.data[0] += pow(2, 31);
	}
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

bool QInt::operator>(const QInt & N)
{ 
	int SignA = this->data[0] >> 31 & 1;
	int SignB = N.data[0] >> 31 & 1;
	if (SignA < SignB)
		return true;
	if (SignA > SignB)
		return false;
	int x = 0;
	for (int i = 0; i < 4; i++)
	{
			if ((*this).data[i] < N.data[i])
			{
					return false;
			}
			if ((*this).data[i] == N.data[i])
				x++;
		
	}
	if (x == 4)
		return false;
	return true;
}

bool QInt::operator<(const QInt & N)
{
	int SignA = this->data[0] >> 31 & 1;
	int SignB = N.data[0] >> 31 & 1;
	if (SignA > SignB)
		return true;
	if (SignA < SignB)
		return false;
	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		if ((*this).data[i] > N.data[i])
		{
			return false;
		}
		if ((*this).data[i] == N.data[i])
			x++;

	}
	if (x == 4)
		return false;
	return true;
}

bool QInt::operator>=(const QInt & N)
{
	int SignA = this->data[0] >> 31 & 1;
	int SignB = N.data[0] >> 31 & 1;
	if (SignA < SignB)
		return true;
	if (SignA > SignB)
		return false;
	for (int i = 0; i < 4; i++)
	{
		if ((*this).data[i] < N.data[i])
		{
				return false;
		}
	}
	return true;
}	

bool QInt::operator<=(const QInt & N)
{
	int SignA = this->data[0] >> 31 & 1;
	int SignB = N.data[0] >> 31 & 1;
	if (SignA > SignB)
		return true;
	if (SignA < SignB)
		return false;
	for (int i = 0; i < 4; i++)
	{
		if ((*this).data[i] > N.data[i])
		{
				return false;
		}
	}
	return true;
}

bool QInt::operator==(const QInt & N)
{
	int SignA = this->data[0] >> 31 & 1;
	int SignB = N.data[0] >> 31 & 1;
	if (SignA != SignB)
		return false;
	for (int i = 0; i < 4; i++)
	{
		if ((*this).data[i] != N.data[i])
		{
			return false;
		}
	}
	return true;
}

bool QInt::operator!=(const QInt & N)
{
	int SignA = this->data[0] >> 31 & 1;
	int SignB = N.data[0] >> 31 & 1;
	if (SignA != SignB)
		return true;
	for (int i = 0; i < 4; i++)
	{
		if ((*this).data[i] != N.data[i])
		{
			return true;
		}
	}
	return false;
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



