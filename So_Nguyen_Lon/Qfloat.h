#include <iostream>
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
string ThapPhan(string x);
int ReExpo(string x, int &k);
string QuadPres(string nhiphan);
string QuadExpo(int number);
string Tra2(int a);