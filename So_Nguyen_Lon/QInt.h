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
	friend istream& operator>>(istream & in, QInt & N);
	friend ostream& operator<<(ostream & out, const QInt & N);
	QInt operator+(const QInt & N);
	QInt operator-(const QInt & N);
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
