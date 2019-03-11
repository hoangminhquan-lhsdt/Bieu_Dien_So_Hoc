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
	delete[] this->data;
}

void QInt::ScanQInt()
{
}

void QInt::PrintQInt()
{
}
/*
QInt QInt::operator=(const QInt & N)
{
}

QInt QInt::operator+(const QInt & N)
{
}

QInt QInt::operator-(const QInt & N)
{
}

QInt QInt::operator*(const QInt & N)
{
}

QInt QInt::operator/(const QInt & N)
{
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
}

QInt QInt::operator|(const QInt & N)
{
}

QInt QInt::operator^(const QInt & N)
{
}

QInt QInt::operator~()
{
}

QInt QInt::operator<<(int K)
{
}

QInt QInt::operator>>(int K)
{
}

QInt QInt::rol(int K)
{
}

QInt QInt::ror(int K)
{
}
*/