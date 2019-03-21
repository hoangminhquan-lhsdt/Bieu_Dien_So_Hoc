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
	string phannguyen, phanthuc = "0";
	int i = 0;
	for (i; i < x.length(); i++)
	{
		if (x[i] == '.')// i sẽ tăng thêm 1 lần trc khi break
		{
			i++;
			break;
		}
		phannguyen += x[i];
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
		} while (phanthuc != "1" && count <= 112);
	}
	
	int exponent = 0;
	if (bin_nguyen.length() >= 2)
	{
		string temp;
		exponent = bin_nguyen.length() - 1;
		temp.append(bin_nguyen, 1, bin_nguyen.length() - 1);
		bin_thuc.insert(0, temp.c_str());
	}
	else// bin nguyen length ==1
	{
		if (bin_nguyen == "0")// về hình thức là dịch dấu phẩy sang phải
		{
			for (int i = 0; i < bin_thuc.length(); i++)
				if (bin_thuc[i] == '1')
				{
					exponent = i + 1;
					break;
				}
				//else bin_thuc.erase(i, 1);

			bin_thuc.erase(0,exponent);// xóa 'exponent' số đầu tiên
			exponent *= -1;// có dạng như: 2^-2, 2^-100..
		}
	}
	bin_nguyen.clear();// bin nguyen hết tác dụng

	if (bin_thuc.length() < 112)
		bin_thuc.insert(bin_thuc.end(), 112 - bin_thuc.length(), '0');
	else // dài quá 112 thì cắt bớt phía bên phải
		bin_thuc.resize(112);
	
	
	//cout << "e= " << exponent << endl;


	string expo = Tra2(exponent+16383);// quá k=16383
	if (expo.length() < 15)
		expo.insert(0, 15 - expo.length(), '0');
	string kq;
	kq += sign  + expo  + bin_thuc;

	for (int i = 0, j = 0; i < 4; i++, j += 32)
		this->data[i] = BinDec(kq.substr(j, 32));
}


Qfloat::~Qfloat()
{
}
