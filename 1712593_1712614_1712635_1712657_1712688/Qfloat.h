#pragma once
#include "Source.h"

class Qfloat
{
private:
	unsigned int data[4];
public:
	// Các hàm khởi tạo //

	// Khởi tạo mặc định với giá trị = 0
	Qfloat();
	// Khởi tạo từ chuỗi mang giá trị của hệ cơ số truyền vào
	Qfloat(string x, int mode);
	// Khởi tạo từ chuỗi nhị phân 128bit
	Qfloat(const Qfloat & src);
	// Hàm hủy mặc định
	~Qfloat();


	// Đọc input do người dùng nhập
	void ScanQfloat();
	// Xuất giá trị QInt ra màn hình
	void PrintQfloat();


	// Toán tử gán bằng
	Qfloat & operator=(const Qfloat & src);


	// Các hàm chuyển cơ số //

	// Chuyển từ chuỗi nhị phân thành Qfloat thập phân
	Qfloat BinToDec(string bit);
	// Chuyển từ Qfloat thành chuỗi nhị phân
	string DecToBin();
	// Chuyển từ Qfloat thành chuỗi thập phân
	string QfloatToDec();
};

