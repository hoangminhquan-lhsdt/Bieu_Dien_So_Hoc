#pragma once
#include <iostream>
#include "QInt.h"

using namespace std;

QInt::QInt()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 4;

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

void removezero(string &a) {
	int i = 0;
	while (a[0] == '0')
	{
		if (a.length()== 1)
		{
			return;

		}
		if (a[1] == '.')
			break;
		else
			a.erase(0, 1);
	}
	int n = a.length() - 1;
	if (a.find('.')!=-1)
		while (a[n] == '0')
		{
			if (a[n - 1] == '.')
			{
				a.erase(n);

				a.erase(n-1);
				break;
			}
			else {
				a.erase(n);
				n--;
			}
		}
}

int removedot(string &a) //Trả về số phần tử sau dấu chấm và xóa dấu
{
	int n = a.length(), i,  x = 0;
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

int Compare(string s1, string s2)
{
	string a = s1;
	string b = s2;
	//Shorten(a);
	//Shorten(b);
	if ((a[0] == '-'))
	{
		if (b[0] == '-')
		{
			string temp = a;
			a = b;
			b = a;
			a.erase(0, 1);
			b.erase(0, 1);
		}
		else
		{
			return -1;
		}
	}
	else
	{
		if (b[0] == '-')
		{
			return 1;
		}
	}

	int temp1 = a.find('.'), temp2 = b.find('.');

	if ((temp1 == -1) && (temp2 == -1))
	{
		int n1 = a.length(), n2 = b.length();
		if (n1 > n2)
		{
			for (int i = 1; i <= n1 - n2; i++)
				b = '0' + b;
		}
		else
		{
			for (int i = 1; i <= n2 - n1; i++)
				a = '0' + a;
		}
		return a.compare(b);
	}


	if (temp1 > temp2)
	{
		return 1;
	}
	if (temp1 < temp2)
	{
		return -1;
	}


	int n;
	bool temp = true;

	if (a.length() > b.length())
	{
		n = b.length();
		temp = false;
	}
	else n = a.length();

	for (int i = 0; i < n; i++)
	{
		if (a[i] < b[i])
		{
			return -1;
		}
		else if (a[i] > b[i])
		{
			return 1;
		}
	}
	if (a.length() == b.length())
	{
		return 0;
	}

	if (temp)
	{
		return -1;
	}
}
string Sum(string s1, string s2) // Số nguyên 
{
	string a = s1;
	string b = s2;
	char  sumchar;
	string c;
	int x1 = removedot(a), x2 = removedot(b), x3, x4, i;
	if (x1 > x2)
	{
		x3 = x1;
		x4 = x1 - x2;
		for (i = 1; i <= x4; i++)
		{
			b = b + '0';
			//chenkitutrongchuoi(b, strlen(b), '0');
		}
	}
	else {
		x3 = x2;
		x4 = x2 - x1;
		for (i = 1; i <= x4; i++)
		{
			a = a + '0';
			//chenkitutrongchuoi(a, strlen(a), '0');
		}
	}
	int count = 0, x, y, sum = 0;
	int y1 = checkstatusdigits(a), y2 = checkstatusdigits(b);
	int n1 = a.length(), n2 = b.length();
	if (n1 > n2)
	{
		for (i = 1; i <= n1 - n2; i++)
		{
			b = '0' + b;
			//chenkitutrongchuoi(b, 0, '0');
		}
	}
	else
	{
		for (i = 1; i <= n2 - n1; i++)
		{
			a = '0' + a;
			//chenkitutrongchuoi(a, 0, '0');
		}
	}
	// 
	int n = a.length();
	if (y1 == y2) // Cùng dấu 
	{
		for (i = 1; i <= n + 1; i++)
		{
			sum = count;
			if (n - i >= 0)
			{
				x = a[n - i] - '0';
				y = b[n - i] -'0';
				sum = sum + x + y;
			}
			count = sum / 10;
			sumchar = itoc(sum % 10);
			c = sumchar + c;
			//chenkitutrongchuoi(c, 0, sumchar);
		}
		removezero(c);
		if (y1 == 0)
			c = '-' + c;
			//chenkitutrongchuoi(c, 0, '-');
		insertdot(c, x3);
		removezero(c);
		return c;
	}
	else // Trái dấu
	{
		if (n1 > n2)
		{
			for (i = 1; i <= n; i++) // Đúng với |a|>|b| 
			{
				sum = count;
				if (n - i >= 0)
				{
					x = a[n - i] - '0';
					y = b[n - i] - '0';
					sum = sum + x - y;
				}
				if (sum < 0)
				{
					count = -1; //Mượn max bằng 1 , sum min=-10; I thought....
					sum += 10;
				}
				else
					count = 0;
				sumchar = itoc(sum % 10);
				c = sumchar + c;
				//chenkitutrongchuoi(c, 0, sumchar);
			}
			removezero(c);
			if (y1 == 0 && !(c[0] == '0'&& c.length() == 1))
				c = '-' + c;
				//chenkitutrongchuoi(c, 0, '-');
			insertdot(c, x3);
			removezero(c);
			return c;
		}
		else //a<b
		{
			a = '1' + a;
			//chenkitutrongchuoi(a, 0, '1');
			c = Subtract(a, b);
			if (a.length() == c.length())
			{
				c.erase(0, 1);
				//xoakitutrongchuoi(c, 0);
				removezero(c);
				if (y1 == 0 && !(c[0] == '0'&& c.length() == 1))
					c = '-' + c;
					//chenkitutrongchuoi(c, 0, '-');
				insertdot(c, x3);
				removezero(c);
				return c;
			}
			else //c[0]==0
			{
				string d;
				int j = c.length();
				for (i = 1; i <= j; i++)
					d = '0' + d;
					//chenkitutrongchuoi(d, 0, '0');
				d = '1' + d;
				//chenkitutrongchuoi(d, 0, '1');
				c = Subtract(d, c);
				if (y1 == 1 && !(c[0] == '0'&& c.length() == 1))
					c = '-' + c;
					//chenkitutrongchuoi(c, 0, '-');
				insertdot(c, x3);
				removezero(c);
				return c;
			}
		}
	}
}
string Subtract(string a,string b)
{
	if (b[0] == '-')
	{
		a.erase(0);
	}
	else
	{
		b.insert(b.begin(), '-');
	}
	string c = Sum(a, b);
	return c;
}

string Multiply(string a, string b)
{
	string c;
	char sumchar;
	int reb = 0, i, j, Sum = 0, x, y, n1, n2;
	n1 = a.length();
	n2 = b.length();

	int y1 = checkstatusdigits(a), y2 = checkstatusdigits(b);
	int x1 = removedot(a), x2 = removedot(b);
	for (i = 1; i < (n1 + n2); i++)
	{

		for (j = 0; j < i; j++)
		{
			if (((n1 + j - i) >= 0 && (n1 +j-i <= n1))&&((n2-j-1>=0)&&(n2-j-1<=n2)))
			{
				x = ctoi(a[n1+j-i]);
				y = ctoi(b[n2-j-1]);
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

string DivideInteger(string a,string b) //Chia lấy phần nguyên 
{

	string c, d;
	int i = 0, n, count = 0, x;
	n = a.length();
	c = '0' + c;
	while (i < n)
	{

		d.push_back(a[i]);

		x = Compare(d, b);
		if (x == -1)
		{
			if (d=="0" && a[i] == '0')
				c.push_back('0');
			else
				if (i == n - 1)
				{
					count = 0;
					while (x != -1)
					{
						d = Subtract(d, b);
						count++;
						x = Compare(d, b);
					}

					c.push_back(itoc(count));
				}
			i++;
			continue;
		}count = 0;
		while (x != -1)
		{
			d = Subtract(d, b);
			count++;
			x = Compare(d, b);

		}

		c.push_back(itoc(count));
		i++;
	}
	removezero(c);
	return c;
}

string DivideRemainder(string a,string b)
{
	return Subtract(a, Multiply(DivideInteger(a, b), b));
}

string Divide(string a, string b)
{
	int x1 = removedot(a), x2 = removedot(b);
	if (x1 > x2)
	{
		for (int i = 1; i <= x1 - x2; i++)
			b.insert(b.begin(), '0');
	}
	else
	{
		for (int i = 1; i <= x2 - x1; i++)
			a.insert(a.begin(), '0');
	}
	int y1 = checkstatusdigits(a), y2 = checkstatusdigits(b);
	if (b=="0")
	{
		return ("Error: So chia bang 0.");
	}
	string d;
	string c = DivideInteger(a, b);
	string e = DivideRemainder(a, b);
	int count = 0;
	while (e!="0" && count < 200)
	{
		e.push_back('0');
		d = DivideInteger(e, b);
		c = c + d;
		e = DivideRemainder(e, b);
		count++;
	}
	insertdot(c, count);

	if (y1 != y2 && !(c[0] == '0'&& c.length() == 1)) //trái dấu 
	{
		c.insert(c.begin(), '-');
	}
	removezero(c);
	return c;
}

string Exponential(string a, int n)
{
	string c = a;
	
	int i;
	
	if (n == 0)
		return (string)("1");
	for (i = 1; i < abs(n); i++)
		c = Multiply(c, a);
	if (n > 0)
		return c;
	else
		return Divide("1", c);
	//else
	//	return Divide((char*)("1"), c);
}

string QInt::BinToString()
{
	string ans;
	(*this).data[3] = 32;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{

			if((1 << 31 - j) & (*this).data[i])
			{
				ans = Sum(ans, Exponential("2",127 - 32*i-j));
			}
		}
	}
	return ans;
}

string BinToString()
{
	string ans;
	return string();
}
	
