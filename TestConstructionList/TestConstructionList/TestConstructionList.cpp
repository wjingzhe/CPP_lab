// TestConstructionList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(int i)
	{
		cout<<"�ӵ��Ľ���"<<ends;
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

