// TestSizeofBits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

#include "testNamespace.h"
#include<thread>
#include<atomic>

#include <map>
#include <include/vector>
#include <ok/vector>
#include <vector>
class  testSize
{
};

class Node
{
public:
	Node();
	virtual ~Node();
	int ai;

	virtual void print()
	{
		std::cout<<"------Node:"<<ai<<endl;
	}
private:
	int aj;
};

Node::Node()
{
	ai = 1,aj =2;
}

Node::~Node()
{
}

class B:virtual public Node
{
public:
	B();
	virtual ~B();
	//using Node::ai;
private:	
	/*void print(int i)
	{
		cout<<"------B"<<i<<endl;
	}*/


	

};

B::B()
{
}

B::~B()
{
}

class C :virtual public Node
{
public:
	C();
	virtual ~C();

private:

};

C::C()
{
}

C::~C()
{
}

class D:public B,public C
{
public:

	D():Node(),B(),C()
	{

	}
	virtual ~D(){};
public:

};

class testFunc
{
	testFunc & operator*()
	{
		cout<<"testFunc："<<__FUNCTION__<<endl;
	}
};

void show(Node * p)
{
	cout<<"Show Node"<<endl;
}

void show(C * p)
{
	cout<<"Show C"<<endl;
}


class testThread
{
private:
	int n;
public:
	static void run(void * pThis)
	{
		testThread * self = static_cast<testThread*>(pThis);
		self->process();
	}

	void process()
	{
		cout<<"testThread:"<<__FUNCTION__<<"is running"<<endl;
	}
};

void process()
{
	cout<<"testThread:"<<__FUNCTION__<<"\tis running"<<endl;
}


atomic_llong total = {0};

void funcCount(int)
{
	for (long long i = 0; i <100000000LL ; i++)
	{
		total+=i;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	thread t1(process);
	t1.join();

	thread t2(funcCount,0);
	thread t3(funcCount,0);
	t2.join();
	t3.join();

	cout<<total<<endl;


	cout<<" "<<testSome <<endl;
	int a[100];
	int *b = a;

	struct data
	{
		char c;
		int a[100];
	};

	struct MyStruct
	{
		data a;
		double b;
		float c;
	};

	MyStruct c;

	cout<<"sizeof:class:"<<sizeof(testSize)<<endl;

	cout<<"sizeof:"<<sizeof(data)<<endl;

	cout<<"sizeof MyStruct:"<<sizeof(MyStruct)<<endl;

	cout<<"sizeof MyStruct.data:"<<sizeof(c.a)<<endl;

	cout<<"sizeof:"<<sizeof(a)<<","<<sizeof(b)<<endl;

	cout<<"sizeof:"<<sizeof(int)<<","<<sizeof(long)<<","<<sizeof(float)<<","<<sizeof(double);

	D bb;
	bb.print();

	show(&bb);

	map<D*,bool> p;
	auto t = new map<D*,bool>();
	delete t;

	print3();

	print4();

	/*vector<int> arrInt(10);

	arrInt[0] = 1;

	cout<<arrInt[0]<<endl;*/


	print();

	return 0;
}

