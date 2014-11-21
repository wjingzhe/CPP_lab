// TestQueue_16th_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Queue.hpp"
using namespace std;
#include <vector>

#include "Handle.hpp"

template <typename Type>
extern ostream & operator<< <Type> (ostream & os,const Queue<Type> &q);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[11] = {0,1,2,3,4,5,6,7,8,9};
	Queue<int> tempQueue;
	for (int i = 0; i < 10; i++)
	{
		tempQueue.push_back(i);
	}
	cout<<tempQueue<<endl;
	cin>>a[10];

	vector<int> vArray(a,a+11);


	tempQueue.assign(vArray.begin(),vArray.end());
	cout<<tempQueue<<endl;

	int*p = new int(100);

	Handle<int> pInt = Handle<int>(p);

	char c;
	cin>>c;
	return 0;
}

