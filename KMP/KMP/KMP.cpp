// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/*
	j=-1作为默认起始状态，若用stl中的iterator则起始位置应该为begin()-1;
*/
void getNextVal(const string t,int * nextVal)
{
	int i = 0;
	nextVal[0] = -1;
	int j = -1;
	int size = static_cast<signed int>(t.length());
	while (i<size)
	{
		if (j==-1 || t.c_str()[i]==t.c_str()[j])
		{
			++i;++j;

			if (t.c_str()[i]!=t.c_str()[j])
			{
				nextVal[i] = j;
			}
			else
			{
				nextVal[i] = nextVal[j];
			}
			
		}
		else
		{
			j = nextVal[j];
		}
	}
	int temp[10];
	for (int i = 0; i < size; i++)
	{
		temp[i] = nextVal[i];
	}
}//getNextVal

/*
	区别于类C语言算法教程的写法，因适应于C下表从0开始，故0也可能是正确位置，不能作为不匹配的返回值，故传一个引用参数targetIndex作为结果
	若偏移下标为-1，则主串需要向后移动，而j置为起始位置0；
*/
bool Index_KMP(const string &s,const string &t,int &targetIndex,int beginPos = 0)
{

	int * nextVal = new int[t.length()+1];
	int i = beginPos;int j = -1;

	getNextVal(t,nextVal);

	//signed和unsigned转化问题，要认真处理
	int s_size = static_cast<signed int>(s.length());
	int t_size = static_cast<signed int>(t.length());

	while (i<s_size && j<t_size)
	{
		if (j == -1 || s.c_str()[i]==t.c_str()[j])
		{
			++i;
			++j;
		}
		else
		{
			j = nextVal[j];
		}
	}
	delete[] nextVal;
	if (j>=t_size)
	{
		
		targetIndex = i - t.length();
		cout<<"\n"<<i<<"\t"<<j<<"\t"<<targetIndex;
		return true;
	}
	else
	{
		cout<<"False"<<"\n"<<i<<"\t"<<j<<"\t"<<targetIndex;
		return false;
	}
}//Index_KMP

int _tmain(int argc, _TCHAR* argv[])
{
	string s = string("acabaabaababcdaabcabcacaabc");
	string t("abcdaabcab");
	int index = 0;
	Index_KMP(s,t,index);
	cin>>index;
	return 0;
}

