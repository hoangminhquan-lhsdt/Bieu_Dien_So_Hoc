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

string SumString(const string &a, const string &b)
{
	string ans;
	int sum, n = b.size(), count;

	if (a.size() < b.size())
	{
		n = a.size();
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