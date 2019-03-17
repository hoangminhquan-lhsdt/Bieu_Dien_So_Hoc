#include <iostream>
#include "Source.h"
using namespace std;

class Qfloat
{
private:
	unsigned int data[4];
public:
	Qfloat();
	Qfloat(string x);
	~Qfloat();
	friend ostream& operator<<(ostream& os, const Qfloat d);
};
