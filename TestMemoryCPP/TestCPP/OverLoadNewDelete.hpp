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


//���ȳ�������ȫ��new ��delete ��������������͵ĳ�ʼ�������Ƿ���ʵ����C++�������Ѿ�������Ĭ�ϵĳ�ʼ������
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
		//�ڴ��Ĭ��ֵ��int������δ����ʼ����ʹ��Ĭ�ϵĳ�ʼ��������ʵ����malloc������ʵ��
	int * p = new int;
	cout<<*p<<endl;
	delete p;
	p = nullptr;

	//��ʾ������int�ĳ�ʼ����ʽ
	int * q = new int(47);
	cout<<*q<<endl;
	delete q;
	q = nullptr;

	//�ڴ��Ĭ��ֵ��float������δ����ʼ����ʹ��Ĭ�ϵĳ�ʼ��������ʵ����malloc������ʵ��
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
