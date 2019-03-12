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

int ctoi(char a) //Digit from 0-9 only
{
	return int(a) - 48;
}
char itoc(int a) //Digit from 0-9 only
{
	return char(a + 48);
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
		sum = ctoi(a[a.size()-1 - i]) + ctoi(b[b.size()-1 - i]);
		if (sum > 10)
		{
			count = sum % 10;
			sum /= 10;
		}
		ans.push_back(itoc(sum));
	}

	if (a.size() < b.size())
	{
		for (int i = 0; i < b.size() - n; i++)
		{
			ans.push_back(b[b.size() - n - i]);
		}
	}
	else
	{
		for (int i = 0; i < a.size() - n; i++)
		{
			ans.push_back(a[a.size() - n - i - 1]);
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;

}


string QIntToString(const QInt &N)
{
	return string();


}
	


