#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;


class QInt {
private:
	unsigned int data[4];
public:
	QInt();
	QInt(string x);//Khởi tạo từ chuỗi Dec cả - và dương 
	~QInt();

	// input/output functions
	void ScanQInt();
	void PrintQInt();

	// arithmetic operators
	QInt operator+(const QInt & N);
	QInt operator-(const QInt & N);
	QInt operator*(const QInt & N);
	QInt operator/(const QInt & N);

	// relational operators
	bool operator>(const QInt & N);
	bool operator<(const QInt & N);
	bool operator>=(const QInt & N);
	bool operator<=(const QInt & N);
	bool operator==(const QInt & N);
	bool operator!=(const QInt &N);

	// bitwise operators
	QInt operator&(const QInt & N);
	QInt operator|(const QInt & N);
	QInt operator^(const QInt & N);
	QInt operator~();

	// assignment operators
	QInt operator=(const QInt & N);

	// bitshift operators
	QInt operator<<(int x);
	QInt operator>>(int x);
	QInt rol(int x);
	QInt ror(int x);

	// base conversions
	QInt BinToQInt(string x);
};
string DecStrToBinStr(string x);
