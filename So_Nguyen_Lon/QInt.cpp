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

int checkstatusdigits(string &a)
{
	if (a[0] == '-')
	{
		a.erase(0,1); // xóa dấu -
		return 0; // a ban đầu là số âm 
	}
	return 1; // số dương
}

int removedot(string &a) //Trả về số phần tử sau dấu chấm và xóa dấu
{
	int n = a.length(), i, j, x = 0;
	for (i = n - 1; i >= 0; i--)
	{
		if (a[i] == '.')
		{
			a.erase(i,1
);
			return x;
		}
		else
			x++;
	}
	return 0;

}

void insertdot(string &a, int x) //Chèn dấu chấm vào trước x số ( tính từ phải sang
{
	if (x == 0) return;
	int n = a.length();
	if (n == x)
	{
		a.insert(a.begin(), '.');
		a.insert(a.begin(), '0');
		return;
	}
	if (n > x)
	{
		a.insert(a.begin()+ n - x, '.');
	}
	if (n < x)
	{
		for (int i = n; i < x; i++)
			a.insert(a.begin(), '0');
		a.insert(a.begin(), '.');
		a.insert(a.begin(), '0');
	}
}

string Sum(string a,  string b)
{
	string ans;
	int sum=0, n = b.size(), count,n1=a.size(),n2=b.size();
	if (n1 > n2)
	{
		n = n1;
	}
	int x1 = removedot(a), x2 = removedot(b), x3, x4, i;
	if (x1 > x2)
	{
		x3 = x1;
		x4 = x1 - x2;
		for (i = 1; i <= x4; i++)
		{
			b.insert(b.begin()+b.length(),1,'0');
		}
	}
	else {
		x3 = x2;
		x4 = x2 - x1;
		for (i = 1; i <= x4; i++)
		{
			a.insert(a.begin() + a.length(), 1,'0');
		}
	}

	if (n1 > n2)
	{
		for (i = 1; i <=(n1 - n2); i++)
		{
			b.insert(b.begin(), '0');
		}
	}
	else
	{
		for (i = 1; i <= n2-n1; i++)
		{
			a.insert(a.begin(), '0');
		}
	}


	for (int i = 0; i < n; i++)
	{
		sum += ctoi(a[a.size()-1 - i]) + ctoi(b[b.size()-1 - i]);


		ans.push_back(itoc(sum%10));
		sum /= 10;
	}
	if (sum > 0)
	{
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

string Multiply(string s1, string s2)
{
	string c;
	char sumchar;
	int reb = 0, i, j, Sum = 0, x, y, n1, n2;
	n1 = s1.length();
	n2 = s2.length();

	int y1 = checkstatusdigits(s1), y2 = checkstatusdigits(s2);
	int x1 = removedot(s1), x2 = removedot(s2);
	for (i = 1; i < (n1 + n2); i++)
	{

		for (j = 0; j < i; j++)
		{
			if (((n1 + j - i) >= 0 && (n1 +j-i <= n1))&&((n2-j-1>=0)&&(n2-j-1<=n2)))
			{
				x = ctoi(s1[n1+j-i]);
				y = ctoi(s2[n2-j-1]);
				Sum += x * y;
			}
		}
		

		sumchar = itoc(Sum % 10);
		Sum /= 10;
		c.push_back(sumchar);
	}
	if (Sum > 0)
	{
		c.push_back(itoc(Sum));
	}
	reverse(c.begin(), c.end());
	insertdot(c, x1 + x2);

	if (y1 != y2 && (c!="0")) //trái dấu 
	{
		c.insert(c.begin(), '-');
	}
	return c;
}


string Exponential(string s1, int n)
{
	string c = s1;
	
	int i;
	
	if (n == 0)
		return (string)("1");
	for (i = 1; i < n; i++)
		c = Multiply(c, s1);
	if (n > 0)
		return c;
	//else
	//	return Divide((char*)("1"), c);
}

string QInt::BinToDec()
{
	string ans;
	string test = "2";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if ((1 << 31 - j) | (*this).data[i])
			{
				if ((i == 0) && (j == 0)) continue;
;				ans = Sum(ans, Exponential("2", 128 - 32 * i - j) );
			}
		}
	}
	return ans;
}
	
