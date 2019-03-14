#pragma once
#include "conio.h"
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
	bool operator!=
(const QInt &N);

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


int removedot(string &a);
void insertdot(string &a, int x);
string SumString(const string &a, const string &b);
string Multiply(string s1, string s2);

