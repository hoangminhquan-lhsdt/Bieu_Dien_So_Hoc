#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;
// chuyển số nguyên kiểu ký tự về số nguyên int
int ctoi(char x);
// chuyển chuỗi nhị phân thành số nguyên int
int BinDec(string x);
// chuyển chuỗi số nguyên thập phân sang chuỗi nhị phân
string DecStrToBinStr(string x);
// chuyển số nguyên không âm về chuỗi nhị phân 
string Tra2(unsigned int a);
// chuyển số nguyên âm về chuỗi nhị phân 
string Tra2(int a);
// chuyển số nguyên không âm về chuỗi thập lục phân
string Tra1016(unsigned int a);
// chuyển số dạng int về số dạng ký tự 
char itoc(int a);
// Xóa dấu chấm và trả về vị trí của dấu chấm   
int removedot(string &a);
// Thêm dấu . vào chuỗi số tại vị trí x
void insertdot(string &a, int x);
// So sánh 2 chuỗi số thực x1 và x2, > trả về  1.  trả về 0, < trả về -1
int Compare(string s1, string s2);
// Cộng 2 chuỗi số thực
string Sum(string a, string b);
// Trừ 2 chuỗi số thực
string Subtract(string a, string b);
// Nhân 2 chuỗi số thực
string Multiply(string s1, string s2);
// Chia lấy phần nguyên 2 chuỗi số thực
string DivideInteger(string a, string b);
// Chia lấy phần dư 2 chuỗi số thực
string DivideRemainder(string a, string b);
// Chia 2 số thực
string Divide(string a, string b);
// Mũ nguyên của số thực
string Exponential(string s1, int n);
// Chuyển chuỗi thập lục phân về Nhị phân
string HexToBin(const string & x);
// Kiểm tra dấu của số thực dương trả về 1, âm trả về 0 và xóa dấu của số đi.
int checkstatusdigits(string &a);
// Rút gọn số thực
void removezero(string & a);
// Kiểm tra số thập phân
bool checkBase10(const string &x);
// Tính 2^n 
string HaiMuN_Am(int n);
// kiểm tra a<b ? 
bool smallerThan(string a, string b);
// Trừ 2 chuỗi số ?
string Sub(string a, string b);
// Kiểm tra trường hợp ngoại lệ cho Qfloat
int isExeption(string bit);