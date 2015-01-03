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
	virtual void printB(int i)
	{
		cout<<"------B"<<i<<endl;
	}
private:	
	


	

};

B::B()
{
}

B::~B()
{
}

class C :virtual public Node
{

};


class D:public B,public C
{
public:
	virtual void displayD()
	{
		;
	}
	D():Node(),B(),C()
	{

	}
	virtual ~D(){};
public:

};


class D2:public C,public B
{
public:
	virtual void displayD21()
	{
		cout<<d2i<<endl;
	}
	
	D2():Node(),B(),C()
	{

	}
	virtual ~D2(){};
	virtual void displayD22()
	{
		cout<<d2i<<endl;
	}
public:
	int d2i;
};

class D3:public D2
{
public:
	D3();
	~D3();
	virtual void displayD3()
	{
		cout<<d2i<<endl;
	}
private:

};

D3::D3()
{
}

D3::~D3()
{
}

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

class memory
{
public:
	int i;
	int j;
};

int _tmain(int argc, _TCHAR* argv[])
{

	cout<<std::pow(-2,2)<<endl;
	/*thread t1(process);
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

	cout<<"sizeof:"<<sizeof(int)<<","<<sizeof(long)<<","<<sizeof(float)<<","<<sizeof(double);*/

	memory m;
	auto pMI = &m.i;
	auto pMJ = &m.j;

	B b1;

	D bb;
	D2 d2;
	D3* d3 = new D3();
	d2.displayD22();
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

