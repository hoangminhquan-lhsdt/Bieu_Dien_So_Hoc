#include "Source.h"
#include "QInt.h"

int ctoi(char x)
{
	return x - '0';
}

int BinDec(string x)
{
	int s = 0, n = x.length();
	for (int i = 0; i < n; i++)
		s += (x[i] - '0')*pow(2, n - 1 - i);
	return s;
}

string DecStrToBinStr(string x)
{
	if (x == "0")
	{
		return x;
	}
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

string Tra2(unsigned int a)
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

string Tra1016(unsigned int a)
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

char itoc(int a)
{
	return char(a + 48);
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
			a.erase(i, 1);
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
		a.insert(a.begin() + n - x, '.');
	}
	if (n < x)
	{
		for (int i = n; i < x; i++)
			a.insert(a.begin(), '0');
		a.insert(a.begin(), '.');
		a.insert(a.begin(), '0');
	}
}

string Sum(string a, string b)
{
	string ans;
	int sum = 0, n = b.size(), count, n1 = a.size(), n2 = b.size();
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
			b.insert(b.begin() + b.length(), 1, '0');
		}
	}
	else {
		x3 = x2;
		x4 = x2 - x1;
		for (i = 1; i <= x4; i++)
		{
			a.insert(a.begin() + a.length(), 1, '0');
		}
	}
	if (n1 > n2)
	{
		for (i = 1; i <= (n1 - n2); i++)
		{
			b.insert(b.begin(), '0');
		}
	}
	else
	{
		for (i = 1; i <= n2 - n1; i++)
		{
			a.insert(a.begin(), '0');
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum += ctoi(a[a.size() - 1 - i]) + ctoi(b[b.size() - 1 - i]);
		ans.push_back(itoc(sum % 10));
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
			if (((n1 + j - i) >= 0 && (n1 + j - i <= n1)) && ((n2 - j - 1 >= 0) && (n2 - j - 1 <= n2)))
			{
				x = ctoi(s1[n1 + j - i]);
				y = ctoi(s2[n2 - j - 1]);
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
	if (y1 != y2 && (c != "0")) //trái dấu 
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

string HexToBin(const string &x)
{
	string kq;
	string temp[] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] >= '0' && x[i] <= '9')
			kq += temp[x[i] - '0'];
		if (x[i] >= 'A' && x[i]<='F')
			kq += temp[x[i] - 'A' + 10];
	
	}
	cout << kq;
	return kq;
}

bool checkBase10(const string &x)
{

	int i = 0;
	if (x[i] == '-')
		i++;
	for (i; i < x.length(); i++)
		if (x[i] > '9' || x[i] < '0')
			return false;
	return true;
}
string Tra2(int a)
{
	string tra;
	int sodu;
	while (a != 0)
	{
		sodu = a % 2;
		tra.push_back(sodu + '0');
		a = a / 2;
	}
	reverse(tra.begin(), tra.end());
	return tra;
}


