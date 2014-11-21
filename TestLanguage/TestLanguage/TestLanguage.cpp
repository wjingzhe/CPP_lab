// TestLanguage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

void testVectorSwap()
{
	vector<string> a;
	a.push_back("I'm vl");

	vector<string> b;
	b.push_back("V2");
	b.push_back("I'm ！");

	auto c =  [](vector<string> temp) ->void
	{
		for_each(temp.begin(),temp.end(),[](string elem) ->void
		{
			cout<<elem.c_str()<<"\t";
		});
		cout<<endl;
	};

	c(a);
	c(b);
	//采用的使移动交换的形式，只是把底层的数据指针交换了。
	a.swap(b);
	c(a);
	c(b);
	//两种操作方式，另外一种则是(n，value)的形式，主要用来常量值，下面这种主要用于复制其他容器
	b.assign(a.begin(),a.end());
	c(a);
	c(b);
}

class A
{
public:
	void show()
	{
		cout<<"A"<<endl;
	}
};

class B : public A
{
public:
	void show(int )
	{
		cout<<"B"<<endl;
	}

};

template<typename T>
class C
{
public:
	template< typename Iter>
	void set(Iter begin);
};

//类成员模板
template<typename T>
template< typename Iter>
void C<T>::set(Iter begin)
{
	cout<<"ok"<<endl;
}



int _tmain(int argc, _TCHAR* argv[])
{
	
	testVectorSwap();

	B b;

	A& a = b;

	a.show();

	b.show(1);

	C<int>c;
	c.set(a);

	return 0;
}

