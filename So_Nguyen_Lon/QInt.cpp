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

		(*this) = this->BinToQInt(DecStrToBinStr(x));
		if (Temp)
		{
			(*this) = ~(*this) + QInt("1");
		}
}



QInt::QInt(string x, int mode)
{
	if (mode == 2)
	{
		string Temp;
		int count = 0;
		for (int i = 0; i < 4; i++)
			data[i] = 0;
		while (x.length() >= 32 && count < 4)
		{
			Temp = x.substr(x.length() - 32);
			x.erase(x.length() - 32);
			this->data[3 - count] = BinDec(Temp) + this->data[3 - count];
			count++;
		}
		this->data[3 - count] = BinDec(x) + this->data[3 - count];
	}
	if(mode==10) //String Dec to QInt
	{
		bool Temp;
		if (x[0] == '-')
		{
			Temp = true;
			x.erase(0, 1);
		}
		else
			Temp = false;

		(*this) = this->BinToQInt(DecStrToBinStr(x));
		if (Temp)
		{
			(*this) = ~(*this) + QInt("1",10);
		}
	}
	if (mode == 16)
	{
		(*this) = this->BinToQInt(HexToBin(x));
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
	Temp = ~Temp + QInt("1", 10);
	return (*this)+Temp;
}

QInt QInt::operator/(const QInt & N)
{
	QInt A,X=N;
	QInt src = *this;
	bool SignA=false,SignB=false;
	if (src > QInt("0", 10))
	{

		A = QInt("0", 10);
	}
	else
		A = QInt("-1", 10);
	if (src >= QInt("0", 10))
		SignA=true;
	if (X >= QInt("0", 10))
		SignB = true;
	int k = 128;
	while (k > 0) {
		A = A << 1;
		int temp = (src.data[0] >> 31) & 1;
		src = src << 1;
		if (temp == 1)
			A = A + QInt("1", 10);
		if (SignA)
		{
			
			if (SignB)
			{
				A = A - X;
				if (A < QInt("0", 10))
				{
					A = A + X;
				}
				else
					src = src + QInt("1", 10);
			}
			else
			{
				A = A + X;
				if (A < QInt("0", 10))
				{
					A = A - X;
				}
				else
					src = src + QInt("1", 10);
			}
		}
		else
		{
			if (SignB)
			{
				A = A + X;
				if (A > QInt("0", 10))
				{
					A = A - X;
				}
				else
					src = src + QInt("1", 10);
			}
			else
			{
				A = A - X;
				if (A > QInt("0", 10))
				{
					A = A + X;
				}
				else
					src = src + QInt("1", 10);
			}
		}
		k--;
	}
	if (SignA != SignB)
		src = QInt("0", 10) - src;
	return src;
}

QInt QInt::operator*(const QInt & N)
{
	QInt X=N, Y;
	bool Temp = false;
	if (X < QInt("0", 10))
	{
		X = QInt("0", 10) - X;
		Temp = true;
	}
	QInt Result; // 1011 * 101
	int count = 0;
	while (X != QInt("0", 10)&&X!=QInt("-1", 10))
	{
		if (X.data[3] % 2 == 1)
			Y = (*this);
		else
			Y = QInt("0", 10);
		X = X >> 1;
		Y = Y << count;
		Result = Result + Y;
		count++;
	}
	if (Temp)
		Result = QInt("0", 10) - Result;
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

QInt QInt::operator<<(QInt x)
{
	return (*this) << atoi(x.QIntToDec().c_str());
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

QInt QInt::operator>>(QInt x)
{
	return (*this) >> atoi(x.QIntToDec().c_str());
}

QInt QInt::rol(int x)
{
	QInt Result;
	Result = (*this);
	bool Temp;
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
				else
					Temp = true;
			}
			Result.data[j] <<= 1;
		}
		if (Temp)
			Result.data[3]++;
	}
	return Result;
}

QInt QInt::ror(int x)
{
	QInt Result;
	bool Temp = false;
	Result = (*this);
	for (int i = 0; i < x; i++)
	{
		Temp = false;
		for (int j = 3; j >= 0; j--)
		{
			if (Result.data[j] % 2 == 1)
			{
				if (j != 3)
					Result.data[j + 1] += pow(2, 31);
				else
					Temp = true;
			}
			Result.data[j] >>= 1;
		}
		if (Temp)
			Result.data[0] += pow(2, 31);
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



string QInt::QIntToBin()
{
	string nhan;
	int i;
	for (i = 0; i < 4; i++)
	{
		nhan += Tra2(this->data[i]);
	}
	return nhan;
}

string QInt::QIntToHex()
{
	int i;
	string re;
	for (i = 0; i < 4; i++)
		if (this->data[i] != 0)
		{
			re += Tra1016(this->data[i]);
		}
	return re;
}

string QInt::QIntToDec()
{
	string ans;
	string test = "2";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if ((1 << 31 - j) & (*this).data[i])
			{
				ans = Sum(ans, Exponential("2", 127 - 32 * i - j));
			}
		}
	}
	return ans;
}

void QInt::ScanQInt()
{
	string x;
	cout << "Enter a number: ";  cin >> x;
	while (checkBase10(x) == false)
	{
		cout << "Re-enter the number: "; cin >> x;
	}
	//x="-340282366920938463463374607431768211455";
	bool negative = false;
	if (x[0] == '-')
	{
		x.erase(0, 1);
		negative = true;
	}
	string bin = DecStrToBinStr(x);
	(*this) = BinToQInt(bin);
	if (negative)
	{
		QInt bu2("1");
		(*this) = ~(*this) + bu2;
	}
	/* for (int i = 0; i < 4; i++)
		 cout << this->data[i] << " ";*/
}

void QInt::PrintQInt()
{
	QInt res = (*this);
	string bin;
	bool negative = false;
	string temp = Tra2(this->data[0]);
	if (temp[0] == '1')// số âm
		negative = true;

	if (negative)
	{
		res = ~((*this) - QInt("1"));
	}
	bin = res.QIntToBin();
	string kq = "0";
	for (int i = bin.length() - 1, j = 0; i >= 0; i--, j++)
	{
		if (bin[i] == '1')
			kq = Sum(kq, Exponential("2", j));
	}
	if (negative)
		kq.insert(kq.begin(), '-');
	cout << kq << endl;
}
