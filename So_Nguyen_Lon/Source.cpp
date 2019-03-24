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

void removezero(string &a) {
	int i = 0;
	while (a[0] == '0')
	{
		if (a.length() == 1)
		{
			return;

		}
		if (a[1] == '.')
			break;
		else
			a.erase(0, 1);
	}
	int n = a.length() - 1;
	if (a.find('.') != -1)
		while (a[n] == '0')
		{
			if (a[n - 1] == '.')
			{
				a.erase(n);

				a.erase(n - 1);
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
	int n = a.length(), i, x = 0;
	for (i = n - 1; i >= 0; i--)
	{
		if (a[i] == '.')
		{
			a.erase(i, 1
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
				y = b[n - i] - '0';
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
string Subtract(string a, string b)
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
			if (((n1 + j - i) >= 0 && (n1 + j - i <= n1)) && ((n2 - j - 1 >= 0) && (n2 - j - 1 <= n2)))
			{
				x = ctoi(a[n1 + j - i]);
				y = ctoi(b[n2 - j - 1]);
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
	removezero(c);
	return c;
}

string DivideInteger(string a, string b) //Chia lấy phần nguyên 
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
			if (d == "0" && a[i] == '0')
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

string DivideRemainder(string a, string b)
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
	if (b == "0")
	{
		return ("Error: So chia bang 0.");
	}
	string d;
	string c = DivideInteger(a, b);
	string e = DivideRemainder(a, b);
	int count = 0;
	while (e != "0" && count < 200)
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

string ThapPhan(string x)
{
	string re;
	int i, du = 0, dem = 0;
	string c(x.length(), '0');
	c[1] = '.';
	while (x != c && dem != 112)
	{
		for (i = x.length() - 1; i >= 0; i--)
		{
			if (i == 1)continue;
			if (dem == 112)break;
			int temp = (x[i] - '0') * 2 + du;
			if (temp >= 10)
			{
				x[i] = (temp - 10) + '0';
				du = 1;
			}
			else
			{
				x[i] = temp + '0';
				du = 0;
			}
		}
		if (x[0] == '1')
		{
			re.push_back('1');
			x[0] = '0';
		}
		else if (x[0] == '0')
			re.push_back('0');
		dem++;
	}
	return re;
}

int ReExpo(string x, int &k)
{
	int fi = x.find(".");
	int i;
	for (i = 1; i < x.length(); i++)
		if (1 == x[i] - '0')
			break;
	k = i;
	int kq = fi - i;
	if (kq < 0)
		return kq;
	else
		return kq - 1;
}

string QuadPres(string nhiphan)
{
	int k;
	int i = ReExpo(nhiphan, k);
	string fraction = nhiphan.substr(k + 1);
	if (i > 0)
	{
		i = fraction.find(".");
		fraction.erase(fraction.begin() + i);
	}
	return fraction;
}

string QuadExpo(int number)
{
	
	int qua = 16383; // 2^14-1
	int expodec = qua + number;
	string re = Tra2(expodec);
	if (re.length() < 15)
	{
		string moi(15 - re.length(), '0');
		re = moi + re;
	}
	return re;
}
