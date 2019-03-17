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
	string a1, a2, ketqua;
	int i, temp;
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
		a2.insert(0, "0");
		a1 = DecStrToBinStr(a1);
		a2 = ThapPhan(a2);
		ketqua += a1 + '.' + a2;
	}
	else
		ketqua = DecStrToBinStr(x);
	//chuyển qua floating point gồm tách ra để trả expo và mantissa
	a1 = QuadPres(ketqua);//trả về chuỗi fraction
	i = ReExpo(ketqua, temp);//trả về giá trị quá k 
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
