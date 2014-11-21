// KMP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/*
	j=-1��ΪĬ����ʼ״̬������stl�е�iterator����ʼλ��Ӧ��Ϊbegin()-1;
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
	��������C�����㷨�̵̳�д��������Ӧ��C�±��0��ʼ����0Ҳ��������ȷλ�ã�������Ϊ��ƥ��ķ���ֵ���ʴ�һ�����ò���targetIndex��Ϊ���
	��ƫ���±�Ϊ-1����������Ҫ����ƶ�����j��Ϊ��ʼλ��0��
*/
bool Index_KMP(const string &s,const string &t,int &targetIndex,int beginPos = 0)
{

	int * nextVal = new int[t.length()+1];
	int i = beginPos;int j = -1;

	getNextVal(t,nextVal);

	//signed��unsignedת�����⣬Ҫ���洦��
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

