// TestFactory.cpp : �������̨Ӧ�ó������ڵ㡣
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

