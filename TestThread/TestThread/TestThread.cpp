// TestThread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<atomic>
#include <thread>
#include <iostream>
#include <Windows.h>


std::atomic<bool> a(true);

std::atomic_llong total = {0};

std::atomic_flag lock = ATOMIC_FLAG_INIT;//{0}

void funCount(int)
{
	if (a)
	{
		a=false;
		Sleep(400000);
	}
	for (long long i = 0; i <100000000LL; i++)
	{
		total+=i;
	}
}


void f(int n)
{
	while (lock.test_and_set(std::memory_order_acquire))
	{

	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	std::thread t1(funCount,0);
	
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<total.is_lock_free()<<std::endl;
	
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<total.is_lock_free()<<std::endl;
	std::thread t2(funCount,0);
	t2.detach();
	t1.detach();
	
	
	//
	//Sleep(4000);



	;

	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<total.is_lock_free()<<std::endl;
	
	//total.store(120);//访问当前值试试，形成互斥
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<total.is_lock_free()<<std::endl;

	
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<total.is_lock_free()<<std::endl;

	return 0;
}

