#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;

// QInt
int ctoi(char x);
int BinDec(string x);
string DecStrToBinStr(string x);
string SumString(const string & a, const string & b);
string Tra2(unsigned int a);
string Tra1016(unsigned int a);
int ctoi(char a);
char itoc(int a);
int removedot(string &a);
void insertdot(string &a, int x);
string Sum(string a, string b);
string Multiply(string s1, string s2);
string Exponential(string s1, int n);
int checkstatusdigits(string &a);

// QFloat
string ThapPhan(string x);
int ReExpo(string x, int &k);
string QuadPres(string nhiphan);
string QuadExpo(int number);
string Tra2(int a);