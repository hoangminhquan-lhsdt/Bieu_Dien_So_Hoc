#pragma once
#include <iostream>
using namespace std;


class QInt {
private:
	unsigned int data[4];
public:
	QInt();
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

};
