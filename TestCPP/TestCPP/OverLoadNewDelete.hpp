#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>


using std::cout;
using std::endl;

class MyClass
{
public:
	MyClass();
	~MyClass();
	static int i;
	int j;
};



int MyClass::i = 0;

MyClass::MyClass():j(1)
{
	++i;
	cout<<"Construct MyClass"<<endl;
}

MyClass::~MyClass()
{
	--i;
	cout<<"Destruct MyClass"<<endl;
}


//首先尝试重载全局new 和delete 操作，不完成类型的初始化，但是发现实际上C++编译器已经调用了默认的初始化函数
void * operator new(size_t sz)
{
	//
	cout<<"Operator new : "<<sz<<" Bytes"<<endl;
	void * m = malloc(sz);


	if (m== nullptr || m == NULL)
	{
		cout<<"Out of memory";
	}

	return m;
}


void *operator new[](size_t sz)
{
	//
	cout<<"Operator new[] : "<<sz<<" Bytes"<<endl;
	void * m = malloc(sz+1);


	if (m== nullptr || m == NULL)
	{
		cout<<"Out of memory";
	}

	return m;
}

template <typename T>
void operator delete(T * p)
{
	cout<<"Operator delete : "<<p<<" Bytes"<<endl;
	return free(p);
}



template <typename T>
void * operator new[](size_t count)
{
	//cout << "\t sizeof the memory: " << endl;
	////void *p = malloc(count);
	//void *p = :: new Framis[count / sizeof(Framis)];
	//cout << p << ":" << reinterpret_cast<Framis*>(p)+count << "\t is malloced" << endl;
	//return p;
}

template <typename T>
void operator delete[](T * p)
{
	::delete[] p;
	cout << p << "\t is malloced" << endl;
}


void testNewAndDelete()
{
		//内存的默认值，int型数据未被初始化或使用默认的初始化函数，实际上malloc函数的实现
	int * p = new int;
	cout<<*p<<endl;
	delete p;
	p = nullptr;

	//显示调用了int的初始化方式
	int * q = new int(47);
	cout<<*q<<endl;
	delete q;
	q = nullptr;

	//内存的默认值，float型数据未被初始化或使用默认的初始化函数，实际上malloc函数的实现
	float * p3 = new float;
	cout<<*p3<<endl;
	delete p3;
	p = nullptr;

	MyClass * p2 = new MyClass;
	cout<<p2->j<<endl;
	cout<<p2->i<<endl;
	delete p2;
	cout<<p2->i<<endl;
	p2 = nullptr;
	//delete (void*)p2;

	MyClass * p4 = new MyClass[10];
	cout<<p4->j<<endl;
	cout<<p4->i<<endl;
	delete[] p4;
	cout<<p4->i<<endl;
	p2 = nullptr;
	//delete (void*)p2;
}
