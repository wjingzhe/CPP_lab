#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <algorithm>

namespace Framis
{

	using std::cout;
	using std::endl;
	using std::ofstream;
	using std::size_t;


	class Framis
	{
	public:
		enum 
		{
			PoolSize = 10
		};

		//static Framis * getInstance()
		//{
		//	if (s_pInstance ==nullptr)
		//	{
		//		s_pInstance = new Framis();
		//		
		//	}
		//	return s_pInstance;
		//}

		

		Framis();
		~Framis();
		
		 //局部重载
		void * operator new(size_t count) throw(std::bad_alloc);

		void operator delete(void * p);

		void * operator new[](size_t count);

		void operator delete[](void * p);

		static void clearAll();

	private:
		
		void destroyClass();

	private:
	
		//匿名枚举，上层空间可访问
		enum 
		{
			sz = 10
		};
		char data[sz];
		static bool s_data_map[PoolSize];
		static Framis * pPool;
		static Framis * s_pInstance; 
		static size_t counts;
		static ofstream outFile; 
	};

	size_t Framis::counts = 0;

	ofstream Framis::outFile("Framis.out"); 

	Framis * Framis::s_pInstance = nullptr;

	bool Framis::s_data_map[PoolSize] = { false, false, false, false, false, false, false, false, false, false };

	Framis * Framis::pPool = new Framis[PoolSize];//10（char）* PoolSize（10）+上尾缀长度 = 104.

	Framis::Framis()
	{

		if (outFile.good())
		{
			outFile<<"Famis()\n";
		}
	}

	Framis::~Framis()
	{
		destroyClass();
	}

	void * Framis::operator new(size_t count) throw(std::bad_alloc)
	{
		if (s_pInstance->outFile.bad()||s_pInstance->outFile.fail())
		{
			s_pInstance->outFile.close();
			s_pInstance->outFile.clear();
			s_pInstance->outFile.open("Framis.out", std::iostream::app);
		}

		assert(count>0,"alloc this size of memory should be greater than 0");
		void * p = nullptr;
		for (size_t i = 0;i < PoolSize; ++i)
		{	
			if (!s_data_map[i])
			{
				s_data_map[i] = true;
				p = &pPool[i];

				cout << "New  " << p << endl;
				////原地构造，多余的操作，实际上编译器在之后会自己默认调用相应的构造函数
				//::new(p)Framis();

				cout << "Famis():" << counts << endl;
				return p;
			}
		};


		if (p==nullptr)
		{
			cout<<"Out of memory"<<endl;
		}
		if (outFile.good())
		{
			outFile<<"Out of memory\n";
		}
		throw std::bad_alloc();
	}

	void Framis::operator delete(void * p)
	{
		cout << "Delete " << p << endl;
		if (p==nullptr)
		{
			return;
		}
		Framis*	q = reinterpret_cast<Framis*>(p);

		size_t index = ((Framis*)q - pPool) / sizeof(Framis);

		s_data_map[index] = true;
		//多余操作
		//q->destroyClass();
	}




	void Framis::destroyClass()
	{
		cout<<"~Famis()"<<endl;
		if (outFile.good())
		{
			outFile<<"~Famis()\n";
		}
		size_t index = (this - pPool) / sizeof(Framis);

		s_data_map[index] = false;

	}

	void * Framis::operator new[](size_t count)
	{
		counts += count;
		cout << "\t sizeof the memory: "<<count << endl;
		//void *p = malloc(count);
		void *p = ::operator new(count);  //::operator new(count) 可以用free释放，但是debug模式结束时会有内存报错的问题，直接运行就没有，不排除有泄露
		cout << p << ":" << reinterpret_cast<Framis*>(p)+count << "\t is malloced" << endl;
		return p;
	}

	void Framis::operator delete[](void * p)
	{
		cout << p << "\t is deleted" << endl;
		//free(p);
		::operator delete(p);
	}

	void Framis::clearAll()
	{

		delete[] pPool;
		pPool = nullptr; 
		s_pInstance->outFile.flush();
		s_pInstance->outFile.clear();
		s_pInstance->outFile.close();
		std::memset(s_data_map,false,PoolSize);
	}


	void testFramis()
	{//这一个例子有内存泄露，仅仅是测试用
		Framis * f[Framis::PoolSize];
		try{
			for(auto i = f;i!=f+Framis::PoolSize;++i){
				*i = new Framis();
			};
			new Framis();
		}catch(std::bad_alloc)
		{
			std::cerr<<"the pool is ran out,Out of memory!"<<endl;
		}

		delete f[9];
		
		
		
		Framis * p = new Framis[10];
		delete[]p;

	}

}