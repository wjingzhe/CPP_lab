// atomic_lock_flag_p202_6-3-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <atomic>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <vector>


using std::cout;
using std::cin;
using std::endl;

std::atomic_flag lock = ATOMIC_FLAG_INIT;
class TestLockInit
{
public:
	TestLockInit();
	~TestLockInit();

	static TestLockInit * TestLockInit::getInstance(void);



	void display(void)
	{
		//自旋尝试加锁
		while (lock.test_and_set(std::memory_order_acquire))
		{
			
		}
		cout<<"-----"<<++i<<endl;
		//释放互斥锁
		lock.clear(std::memory_order_release);
	}

private:
	static TestLockInit * s_pTestLockInit;
	static std::atomic_flag lock;
	std::atomic<int>i;
};

TestLockInit * TestLockInit::s_pTestLockInit = nullptr;
std::atomic_flag TestLockInit::lock = ATOMIC_FLAG_INIT;

TestLockInit * TestLockInit::getInstance(void)
{
	if (s_pTestLockInit==nullptr)
	{
		//自旋尝试加锁
		while (lock.test_and_set(std::memory_order_acquire))
		{
			cout<<"??????????????"<<endl;
		}
		//执行初始化
		if (s_pTestLockInit==nullptr)
		{
			s_pTestLockInit = new TestLockInit();
		}

		//释放互斥锁
		lock.clear(std::memory_order_release);
	}
	return s_pTestLockInit;
}

TestLockInit::TestLockInit():i(10)
{

}

TestLockInit::~TestLockInit()
{
}

void f(int n)
{
	while (lock.test_and_set(std::memory_order_acquire))
	{
		std::cout<<"Waiting from thread "<<n<<std::endl;
	}
	cout<< "Thred "<< n << " Starts working"<<endl;
	TestLockInit::getInstance()->display();

}


void g(int n)
{
	cout<< "Thread "<<n<< " is going to start."<<endl;
	lock.clear();
	cout<< "Thread "<<n<<" Starts working" <<endl;
	TestLockInit::getInstance()->display();

	
}
void h(void)
{
	auto a = std::bind(&TestLockInit::display,TestLockInit::getInstance());
	a();
}

int _tmain(int argc, _TCHAR* argv[])
{
	lock.test_and_set();//设为默认状态；

	/*std::thread t1(f,1);
	std::thread t2(g,2);

	t1.join();

	Sleep(100);
	t2.join();*/


	std::vector<std::thread> vthread;

	for (int i = 0; i < 10; ++i)
	{
		vthread.push_back(
			std::move(
				std::thread(h)
				)
			);
	}


	for(std::thread & th :vthread)
	{
		th.join();
	}

	return 0;
}

