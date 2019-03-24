#pragma once
#include "Source.h"
class Qfloat
{
private:
	unsigned int data[4];
public:
	Qfloat();
	Qfloat(string x, int mode);
	Qfloat(const Qfloat & src);
	void ScanQfloat();
	void PrintQfloat();
	Qfloat BinToDec(string bit);
	string DecToBin();
	Qfloat & operator=(const Qfloat & src);
	~Qfloat();

};

