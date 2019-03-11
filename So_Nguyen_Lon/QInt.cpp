#pragma once
#include <iostream>
#include "QInt.h"

using namespace std;

QInt::QInt()
{
	for (int i = 0; i < 4; i++) {
		this->data[i] = 0;
	}
}


QInt::~QInt()
{
}


istream & operator>>(istream & in, QInt & N)
{

	return in;
}

ostream & operator<<(ostream & out, const QInt & N)
{
	return out;
}


QInt QInt::operator=(const QInt & N)
{
	return QInt();
}

QInt QInt::operator+(const QInt & N)
{
	return QInt();
}

QInt QInt::operator-(const QInt & N)
{
	return QInt();
}

QInt QInt::operator*(const QInt & N)
{
	return QInt();
}

QInt QInt::operator/(const QInt & N)
{
	return QInt();
}

bool QInt::operator>(const QInt & N)
{
	return false;
}

bool QInt::operator<(const QInt & N)
{
	return false;
}

bool QInt::operator>=(const QInt & N)
{
	return false;
}

bool QInt::operator<=(const QInt & N)
{
	return false;
}

bool QInt::operator==(const QInt & N)
{
	return false;
}

QInt QInt::operator&(const QInt & N)
{
	return QInt();
}

QInt QInt::operator|(const QInt & N)
{
	return QInt();
}

QInt QInt::operator^(const QInt & N)
{
	return QInt();
}

QInt QInt::operator~()
{
	return QInt();
}

QInt QInt::operator<<(int K)
{
	return QInt();
}

QInt QInt::operator>>(int K)
{
	return QInt();
}

QInt QInt::rol(int K)
{
	return QInt();
}

QInt QInt::ror(int K)
{
	return QInt();
}
