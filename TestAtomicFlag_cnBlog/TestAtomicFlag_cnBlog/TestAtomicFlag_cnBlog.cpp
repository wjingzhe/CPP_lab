// TestAtomicFlag_cnBlog.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>              // std::cout
#include <atomic>                // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>                // std::thread, std::this_thread::yield
#include <vector>                // std::vector

std::atomic<bool> ready(false);    // can be checked without being set
std::atomic_flag winner = ATOMIC_FLAG_INIT;    // always set when checked

void count1m(int id)
{
    while (!ready) {
        std::this_thread::yield();
    } // �ȴ����߳������� ready Ϊ true.

    for (int i = 0; i < 1000000; ++i) {
    } // ����.

    // ���ĳ���߳�����ִ��������ļ������̣�������Լ��� ID.
    // �˺������߳�ִ�� test_and_set �� if ����ж�Ϊ false��
    // ��˲���������� ID.

	//�������ɶ�ͬһ������ķ���
	/*while (winner.test_and_set(std::memory_order_acquire))
	{

	}
	
	std::cout << "thread #" << id << " won!\n";
	winner.clear(std::memory_order_release);*/

	//��������Ψһ�Բ��ɸ�����Դ
	 if (!winner.test_and_set()) 
	 {
        std::cout << "thread #" << id << " won!\n";
    }
	
};

int main()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million...\n";
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(count1m, i));
    ready = true;

    for (auto & th:threads)
        th.join();

    return 0;
}

