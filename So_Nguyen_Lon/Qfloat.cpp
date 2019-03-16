#define _CRT_SECURE_NO_WARNINGS
#include "Qfloat.h"
#include "QInt.h"


Qfloat::Qfloat()
{
	for (int i = 0; i < 4; i++)
		data[i] = 0;
}

Qfloat::Qfloat(string x)
{
	string a1,a2,ketqua;
	int i,temp;
	for (i = 0; i < 4; i++)
		this->data[i] = 0;
	// chuyển từ thập phân về nhị phân
	if (x[0] == '-')
	{
		ketqua += '1';
		x.erase(0, 1);
	}
	else
		ketqua += '0';
	int pos = 0;
	pos = x.find(".");
	if (pos != 0)
	{
		a1 = x.substr(0, pos);
		a2 = x.substr(pos);
		a2.insert(0,"0");
		a1 = DecStrToBinStr(a1);
		a2 = ThapPhan(a2);
		ketqua += a1 + '.' + a2;
	}
	else
		ketqua = DecStrToBinStr(x);
	//chuyển qua floating point gồm tách ra để trả expo và mantissa
	a1 = QuadPres(ketqua);//trả về chuỗi fraction
	i = ReExpo(ketqua,temp);//trả về giá trị quá k 
	a2 = QuadExpo(i);//trả về chuỗi quá k expo
	ketqua.erase(1, ketqua.length());
	ketqua += a1 + a2;
	this->data[0] = ketqua.length();
	//chuyển từ ketqua vào Qfloat và xóa các phần tử dư thừa và thêm nếu thiếu
}


Qfloat::~Qfloat()
{
}



ostream & operator<<(ostream & os, const Qfloat d)
{
	int i;
	for (i = 0; i < 4; i++)
		os << d.data[i] << endl;
	return os;
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
	int qua = 16383;
	int expodec = qua + number;
	string re = Tra2(expodec);
	if (re.length() < 15)
	{
		string moi(15 - re.length(), '0');
		re += moi;
	}
	return re;
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
