// 8_3_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double r=0.0,double i=0.0):real(r),imag(i){}
	friend Complex operator+(const Complex &c1,const Complex &c2);
	friend Complex operator-(const Complex &c1,const Complex &c2);
	friend Complex operator<<(ostream &cout,const Complex &c);
private:
	double real;
	double imag;
};

Complex operator + (const Complex &c1,const Complex &c2)
{
	return Complex(c1.real+c2.real,c1.imag+c2.imag);
};
Complex operator - (const Complex &c1,const Complex &c2)
{
	return Complex(c1.real-c2.real,c1.imag-c2.imag);
};
ostream & operator << (ostream &out,const Complex &c)
{
	out<<"("<<c.real<<","<<c.real<<")";
	return out;
};

int main()
{
	Complex c1(5,4),c2(4,10),c3;
	cout<<"c1="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
	c3=c1-c2;
	cout<<"c3=c1-c2"<<c3<<endl;
	c3=c1+c2;
	cout<<"c3=c1+c2="<<c3<<endl;
	return 0;
}