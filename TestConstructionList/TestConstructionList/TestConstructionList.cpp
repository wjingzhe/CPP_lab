// TestConstructionList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(int i)
	{
		cout<<"坑爹的节奏"<<ends;
	};
	~MyClass();

private:

};


MyClass::~MyClass()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyClass a{1};
	return 0;
}

