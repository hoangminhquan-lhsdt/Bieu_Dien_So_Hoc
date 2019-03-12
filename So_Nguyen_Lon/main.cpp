#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "QInt.h"

using namespace std;


int main() {

    QInt N("5"),M("1"),Q;
	//M = ~N+QInt("1");
	Q = N - M;
	//cout << DecStrToBinStr("1234235235235244534636546")<<endl;
	system("pause");
	return 0;
}