#pragma once
#include <iostream>
#include "QInt.h"

using namespace std;

QInt::QInt()
{
}


QInt::~QInt()
{
}

int ctoi(char x)
{
	return x - '0';
}

bool QInt::operator>(const QInt & N)
{
	for (int i = 0; i < 4; i++)
	{
		for (int u = 1; u < 31; u++)
		{
			if (((1 << 31 - u) | (*this).data[i]) <= ((1 << 31 - u) | N.data[i]))
			{
				return false;
			}
		}
	}
	return true;
}

bool QInt::operator<(const QInt & N)
{
	for (int i = 0; i < 4; i++)
	{
		for (int u = 1; u < 31; u++)
		{
			if (((1 << 31 - u) | (*this).data[i]) >= ((1 << 31 - u) | N.data[i]))
			{
				return false;
			}
		}
	}
	return true;
}

bool QInt::operator>=(const QInt & N)
{
	for (int i = 0; i < 4; i++)
	{
		for (int u = 1; u < 31; u++)
		{
			if (((1 << 31 - u) | (*this).data[i]) < ((1 << 31 - u) | N.data[i]))
			{
				return false;
			}
		}
	}
	return true;
}	

bool QInt::operator<=(const QInt & N)
{
	for (int i = 0; i < 4; i++)
	{
		for (int u = 1; u < 31; u++)
		{
			if (((1 << 31 - u) | (*this).data[i]) > ((1 << 31 - u) | N.data[i]))
			{
				return false;
			}
		}
	}
	return true;
}

bool QInt::operator==(const QInt & N)
{
	for (int i = 0; i < 4; i++)
	{
		for (int u = 1; u < 31; u++)
		{
			if (((1 << 31 - u) | (*this).data[i]) != ((1 << 31 - u) | N.data[i]))
			{
				return false;
			}
		}
	}
	return true;
}

bool QInt::operator!=(const QInt & N)
{
	for (int i = 0; i < 4; i++)
	{
		for (int u = 1; u < 31; u++)
		{
			if (((1 << 31 - u) | (*this).data[i]) == ((1 << 31 - u) | N.data[i]))
			{
				return false;
			}
		}
	}
	return true;
}

string SumString(const string &a, const string &b)
{
	string ans;
	int sum, n = b.size(), count;

	if (a.size() < b.size())
	{
		n=a.size();
	}
	for (int i = 0; i < n; i++)
	{
		sum = ctoi(a[a.size() - i]) + ctoi(b[b.size() - i]);
		if (sum > 10)
		{
			count = sum % 10;
			sum /= 10;
		}
	}
	return string();
}

string QIntToString(const QInt &N)
{
	return string();
}
	


