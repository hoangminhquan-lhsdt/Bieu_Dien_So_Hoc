#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;

int ctoi(char x);
int BinDec(string x);
string DecStrToBinStr(string x);
string Tra2(unsigned int a);
string Tra1016(unsigned int a);
int ctoi(char a);
char itoc(int a);
int removedot(string &a);
void insertdot(string &a, int x);
string Sum(string s1, string s2);
string Subtract(string a, string b);
void removezero(string & a);
string Multiply(string a, string b);
string Exponential(string s1, int n);
string HexToBin(const string & x);
string Divide(string a, string b);
string DivideInteger(string a, string b);
int Compare(string s1, string s2);
string DivideRemainder(string a, string b);
int checkstatusdigits(string &a);
bool checkBase10(const string &x);
string Tra2(int a);
string BinToHex(string bit);
string HaiMuN_Am(int n);
bool smallerThan(string a, string b);
// n<0
string Sub(string a, string b);