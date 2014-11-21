// 11_12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

//11_12.cpp
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

template<class T>
inline T fromString(const string &str)
{
	istringstream is(str);
	T v;
	is>>v;
	return v;
}

int main()
{
	int v1=fromString<int>("5");
	cout<<v1<<endl;
	double v2=fromString<double>("1.2");
	cout<<v2<<endl;
	return 0;
}
