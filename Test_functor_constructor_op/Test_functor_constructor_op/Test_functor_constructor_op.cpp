// Test_functor_constructor_op.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class fun1
{
public:
	fun1(int a)
	{
		cout<<"a = "<<a<<endl;
	};
	~fun1(){};

	void operator()(int b)
	{
		cout<<"b = "<<b<<endl;
		fun1(2);
	}
private:

};

class testNamespaceOp
{
public:
	testNamespaceOp(){};
	~testNamespaceOp(){};
public:
	int i;
};


void display(void)
{
	cout<<"-------------"<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	auto temp = fun1(1);
	temp(2);
	//temp::fun1(3); �Ƿ����������캯��ֻ�����༰���������е��û���ʹ��new�ؼ������ڴ���������ر����������á�
	//�����fun1��ָ���������޷�����()����������Ϊ����ָ�����ͣ������Ƕ���ԭ��ָ��û��()��������

	void (*p)(void);
	p = display;

	//pΪԭ��ָ�룬����Ϊ����������
	cout<<"p = "<<p<<"--*p"<<*p<<"--&p:"<<&p<<endl;
	//C++�в�û����ȷ�İѺ�������������Ŀǰ�һ�û����inside C++ model,��ʱ������������һ�������ͨ����������һ��ȫ�ֺ��������󣬾���ȡַ�ͽ����ò����������Ϊ������ڡ�
	cout<<"display = "<<display<<"--*display:"<<*display<<"--&display:"<<&display<<endl;

	//
	testNamespaceOp:: a = &testNamespaceOp::i;
	

	return 0;
}

