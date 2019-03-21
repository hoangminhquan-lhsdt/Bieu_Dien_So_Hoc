#include "Qfloat.h"



Qfloat::Qfloat()
{
	for (int i = 0; i < 4; i++)
		this->data[i] = 0;
}

void Qfloat::ScanQfloat()
{
	string x;
	char sign = '0';
	cout << "Enter a real number:";
	cin >> x;
	if (x[0] == '-')
	{
		sign = '1';
		x.erase(0, 1);
	}
	string phannguyen, phanthuc="0" ;
	int i = 0;
	for (i; i < x.length(); i++)
	{
		if (x[i] == '.')// i sẽ tăng thêm 1 lần trc khi break
		{
			i++;
			break;
		}phannguyen += x[i];
	}
	for (i; i < x.length(); i++)
		phanthuc += x[i];// phần thực lưu trữ dạng 0123456789 thay vì 0.123456789

	string bin_nguyen = DecStrToBinStr(phannguyen);
	string bin_thuc;
	if (phanthuc != "0")
	{
		int count=0;
		do {
			phanthuc =  Multiply(phanthuc,"2");
			while (phanthuc[phanthuc.length()-1] == '0')
			{
				phanthuc.erase(phanthuc.length()-1,1);
			}
			if (phanthuc[0] == '0')
				bin_thuc += '0';
			else {
				bin_thuc += '1';
				if (phanthuc == "1")
					break;
				phanthuc[0] = '0';
			}
			count++;
		} while (phanthuc != "1"&& count <=112);
	}
	int exponent = 0;
	//cout << binNguyen << "." << binThuc << endl;
	if (bin_nguyen.length() >= 2)
	{
		string temp;
		exponent = bin_nguyen.length() - 1;
		temp.append(bin_nguyen, 1, bin_nguyen.length() - 1);
		bin_thuc.insert(0, temp.c_str());
		bin_nguyen.clear();
	}

	if (bin_thuc.length() < 112)
		bin_thuc.insert(bin_thuc.end(), 112 - bin_thuc.length(), '0');
	char buffer[10];
	string expo = DecStrToBinStr(_itoa(exponent+127,buffer,10));
	if (expo.length() < 15)
		expo.insert(expo.begin(), 15 - expo.length(), '0');
	string kq;
	kq += sign;
	kq += ' ' + expo + ' ';
	kq += bin_thuc;
	cout << kq << endl;
	//cout << bin_nguyen << "   " << bin_thuc << endl;
}


Qfloat::~Qfloat()
{
}
