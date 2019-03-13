#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "QInt.h"

using namespace std;


int main() {

	int x=-2, y, z;
	x = 1 | (-2);
    QInt N("2"),M("1"),Q;
	Q = N + M;
	////M = ~N+QInt("1");
	//Q = N.rol(1);
	////cout << DecStrToBinStr("1234235235235244534636546")<<endl;
	system("pause");
	return 0;
}