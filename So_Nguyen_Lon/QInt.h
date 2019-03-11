#pragma once
#include <iostream>
using namespace std;


class QInt {
private:
	unsigned int data[4];
public:
	QInt();
	~QInt();
	friend istream& operator>>(istream & in, QInt & N);
	friend ostream& operator<<(ostream & out, const QInt & N);
	QInt operator+(const QInt & N);
	QInt operator-(const QInt & N);
	QInt operator<<(const int k);
	QInt(string x);
	string DecToBin();
	string Tra2(unsigned int a);
};

