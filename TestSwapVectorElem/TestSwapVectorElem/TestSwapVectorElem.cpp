// TestSwapVectorElem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<functional>
#include<iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int *> vec;
	vec.push_back(new int(10));
	vec.push_back(new int(20));

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		std::cout<<*it<<":"<<**it<<std::endl;
	}

	int i =10,j =20;
	std::swap(i,j);

	std::cout<<i<<":"<<j<<std::endl;

	

	std::swap(*vec.begin(),*(vec.end()-1));

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		std::cout<<*it<<":"<<**it<<std::endl;
		delete *it;
	}

	

	return 0;
}

