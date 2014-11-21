// TestFileIO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct SalaryInfo
{
	unsigned id;
	double salary;
};


int _tmain(int argc, _TCHAR* argv[])
{
	ofstream os("payRoll",ios_base::out|ios_base::binary);

	SalaryInfo data = {600001,8000};

	os.write(reinterpret_cast<char *>(&data),sizeof(SalaryInfo));

	os.close();

	ifstream is("payRoll",ios_base::in|ios_base::binary);

	if(is)
	{
		SalaryInfo employee2;
		is.read(reinterpret_cast<char*>(&employee2),sizeof(employee2));
		cout<<employee2.id<<" "<<employee2.salary;
		is.close();
	}
	else
	{
		cout<<"Error:can't open file 'payRoll'."<<endl;
	}

	char c;
	cin>>c;
	return 0;
}

