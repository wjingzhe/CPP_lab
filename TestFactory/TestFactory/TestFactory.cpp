// TestFactory.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Factory.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Factory * fac = new ConcreteFactory();

	Product * p = fac->CreateProduct();

	fac->CreateProduct();

	return 0;
}

