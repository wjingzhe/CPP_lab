// TestThread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<atomic>
#include <thread>
#include <iostream>

std::atomic<int> a(10);

std::atomic_llong total = {0};

void funCount(int)
{
	for (long long i = 0; i <500000000LL; i++)
	{
		total+=i;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::thread t1(funCount,0);
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<a.is_lock_free()<<std::endl;
	std::thread t2(funCount,0);
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<a.is_lock_free()<<std::endl;
	t1.join();
	
	//t2.detach();

	;

	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<a.is_lock_free()<<std::endl;
	t2.detach();
	//total.store(120);//访问当前值试试，形成互斥
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<a.is_lock_free()<<std::endl;

	
	std::cout<<__FUNCTION__<<":"<<total<<"\t"<<a.is_lock_free()<<std::endl;

	return 0;
}

