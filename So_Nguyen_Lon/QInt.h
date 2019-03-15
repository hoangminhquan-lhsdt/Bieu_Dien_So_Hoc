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

	// input/output operators
	void ScanQInt();
	void PrintQInt();

	// assignment operators
	QInt operator=(const QInt & N);

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
	
	// bitshift operators
	QInt operator<<(int K);
	QInt operator>>(int K);
	QInt rol(int K);
	QInt ror(int K);

	// base conversion

	QInt BinToQInt(string x);
	QInt operator&(const QInt & N);
	QInt operator|(const QInt & N);
	QInt operator^(const QInt & N);
	QInt operator~();
	QInt operator=(const QInt & N);
	QInt operator<<(int x);
	QInt operator>>(int x);
	QInt rol(int x);
	QInt ror(int x);
};
string DecStrToBinStr(string x);
