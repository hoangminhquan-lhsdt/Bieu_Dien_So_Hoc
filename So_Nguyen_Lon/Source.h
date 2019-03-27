#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;

int ctoi(char x);
int BinDec(string x);
string DecStrToBinStr(string x);
string Tra2(unsigned int a);
string Tra2(int a);
string Tra1016(unsigned int a);
int ctoi(char a);
char itoc(int a);
int removedot(string &a);
void insertdot(string &a, int x);
int Compare(string s1, string s2);
string Sum(string a, string b);
string Subtract(string a, string b);
string Multiply(string s1, string s2);
string DivideInteger(string a, string b);
string DivideRemainder(string a, string b);
string Divide(string a, string b);
string Exponential(string s1, int n);
string HexToBin(const string & x);
int checkstatusdigits(string &a);
void removezero(string & a);
bool checkBase10(const string &x);

string HaiMuN_Am(int n);

bool smallerThan(string a, string b);

string Sub(string a, string b);

bool isExeption(string bit);

void Round(string & dec);
