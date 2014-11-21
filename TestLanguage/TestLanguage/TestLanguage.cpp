// TestLanguage.cpp : �������̨Ӧ�ó������ڵ㡣
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
	b.push_back("I'm ��");

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
	//���õ�ʹ�ƶ���������ʽ��ֻ�ǰѵײ������ָ�뽻���ˡ�
	a.swap(b);
	c(a);
	c(b);
	//���ֲ�����ʽ������һ������(n��value)����ʽ����Ҫ��������ֵ������������Ҫ���ڸ�����������
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

//���Աģ��
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

