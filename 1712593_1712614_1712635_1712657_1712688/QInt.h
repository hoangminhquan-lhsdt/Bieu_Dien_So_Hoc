#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "Source.h"

using namespace std;

class QInt {
private:
	unsigned int data[4];
public:
	// Các hàm khởi tạo //

	// Khởi tạo mặc định với giá trị = 0
	QInt();
	// Khởi tạo từ chuỗi nhị phân 128bit
	QInt(string x);
	// Khởi tạo từ chuỗi mang giá trị của hệ cơ số truyền vào
	QInt(string x, int mode);
	// Hàm hủy mặc định
	~QInt();


	// Đọc input do người dùng nhập
	void ScanQInt();
	// Xuất giá trị QInt ra màn hình
	void PrintQInt();


	// Các toán tử tính toán //

	// Cộng
	QInt operator+(const QInt & N);
	// Trừ
	QInt operator-(const QInt & N);
	// Nhân
	QInt operator*(const QInt & N);
	// Chia
	QInt operator/(const QInt & N);


	// Các toán tử so sánh //

	// Lớn hơn
	bool operator>(const QInt & N);
	// Bé hơn
	bool operator<(const QInt & N);
	// Lớn hơn hoặc bằng
	bool operator>=(const QInt & N);
	// Lớn hơn hoặc bằng
	bool operator<=(const QInt & N);
	// So sánh bằng
	bool operator==(const QInt & N);
	// So sánh khác
	bool operator!=(const QInt &N);


	// Các toán tử logic //

	// AND
	QInt operator&(const QInt & N);
	// OR
	QInt operator|(const QInt & N);
	// XOR
	QInt operator^(const QInt & N);
	// NOT
	QInt operator~();

	// Toán tử gán bằng
	QInt & operator=(const QInt & N);


	// Các toán tử dịch bit //

	// Dịch bit sang trái
	QInt operator<<(int x);
	QInt operator<<(QInt x);

	// Dịch bit sang phải
	QInt operator>>(int x);
	QInt operator>>(QInt x);

	// Xoay bit sang trái
	QInt rol(int x);

	// Xoay bit sang phải
	QInt ror(int x);


	// Các hàm chuyển cơ số //

	// Chuyển từ chuỗi nhị phân thành QInt
	QInt BinToQInt(string x);
	// Chuyển từ QInt thành chuỗi nhị phân
	string QIntToBin();
	// Chuyển từ QInt thành chuỗi thập lục phân
	string QIntToHex();
	// Chuyển từ QInt thành chuỗi thập phân
	string QIntToDec();
};

