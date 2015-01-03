// Test_functor_constructor_op.cpp : 定义控制台应用程序的入口点。
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
	//temp::fun1(3); 非法操作，构造函数只能在类及其派生类中调用或者使用new关键字在内存分配操作相关被编译器调用。
	//如果是fun1的指针类型是无法调用()操作符，因为它是指针类型，而不是对象，原生指针没有()操作符。

	void (*p)(void);
	p = display;

	//p为原生指针，类型为函数名对象
	cout<<"p = "<<p<<"--*p"<<*p<<"--&p:"<<&p<<endl;
	//C++中并没有明确的把函数名当做对象，目前我还没看完inside C++ model,暂时将函数名当成一个类对象，通过隐射生成一个全局函数名对象，具有取址和解引用操作，结果均为函数入口。
	cout<<"display = "<<display<<"--*display:"<<*display<<"--&display:"<<&display<<endl;

	//
	testNamespaceOp:: a = &testNamespaceOp::i;
	

	return 0;
}

