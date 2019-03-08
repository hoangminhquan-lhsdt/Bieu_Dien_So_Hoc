#pragma once
#include <iostream>
#include "QInt.h"

using namespace std;

QInt::QInt()
{
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
