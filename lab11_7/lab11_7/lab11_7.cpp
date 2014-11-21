// lab11_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

//#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	ios_base::fmtflags original_flags=cout.flags();//1
	cout<<812<<'|';
	cout.setf(ios_base::left,ios_base::adjustfield);//2
	cout.width(10);//3
	cout<<813<<815<<endl;
	cout.unsetf(ios_base::adjustfield);//4
	cout.precision(2);//两位有效数字
	cout.setf(ios_base::uppercase|ios_base::scientific);//5
	cout<<831.0<<'\n';
	cout.flags(original_flags);
//	cout<<813<<815<<endl;


}
