// functor-adapter_p431.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <algorithm>//元素操作算法
#include <functional> //函数配接器，bind、compose、negate
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

bool print(int i)
{
	std::cout<< i << " ";
	return true;
}

class Int
{
public:
	explicit Int(int i):m_i(i){};
	~Int();

	void print1(void) const
	{
		cout<<"["<<m_i<<"]";
	}

private:
	int m_i;
};


  
typedef std::function<void ()> fp;  
  
class A  
{  
public:  
    virtual void f()  
    {  
        std::cout<<"A::f()"<<endl;  
    }  
  
    void init()  
    {  
        //std::bind可以表现出多态行为  
        fp f=std::bind(&A::f,this);  
        f();  
    } 
	bool print(int i)
	{
		std::cout<< i << "：";
		return true;
	}

	inline bool operator() (int i)
	{
		std::cout<< i << "/";
		return true;
	}
	

};  


class B:public A  
{  
public:  
    virtual void f()  
    {  
        cout<<"B::f()"<<endl;  
    }  
};  





int _tmain(int argc, _TCHAR* argv[])
{
	std::ostream_iterator<int> out_it(cout,",");//输出迭代器绑定到命令窗输出行中,每次输出填充一个,和print区别开来

	int ia[6] = {2,21,12,7,19,23};

	A* pa=new B;  
    pa->init(); 
	/*
	*   
	template<class _Ret,
	class _Rx,
	class _Farg0,
	class _Arg0> inline
	typename enable_if<!is_same<_Ret, _Rx>::value,
		_Bind<true, _Ret, _Pmd_wrap<_Rx _Farg0::*, _Rx, _Farg0>, _Arg0>
			>::type
		bind(_Rx _Farg0::* const _Pmd, _Arg0&& _A0)
	{	// bind a wrapped member object pointer
	return (_Bind<true, _Ret,
		_Pmd_wrap<_Rx _Farg0::*, _Rx, _Farg0>, _Arg0>(
		_Pmd_wrap<_Rx _Farg0::*, _Rx, _Farg0>(_Pmd),
			_STD forward<_Arg0>(_A0)));
	}
	*
	*
	*/
	std::function<bool(int)> printInt = std::bind(&B::print,pa,std::placeholders::_1);//
	std::function<bool(int)> printInt2 = std::bind(&A::print,pa,std::placeholders::_1);
	printInt(1000);
	printInt2(1002);
	
	
	typedef std::function<bool(int)> FP;

	FP t_fp = FP(print);

	t_fp(12);
	cout<<endl;


	
	//找出不小于12的数据
	std::vector<int> iv(ia,ia+6);
	std::copy_if(iv.begin(),iv.end(),out_it,std::not1(std::bind2nd(std::less<int>(),12)));

	//cout<< std::count_if(ia,ia+6,std::not1(std::bind(f1,12)) )<<endl;


	cout<<endl;

	int nums = std::count_if(
		iv.begin(),iv.end(),
		std::bind(
			std::logical_and<bool>(),
			std::bind(std::less<int>(),std::placeholders::_1,30),
			std::bind(std::greater<int>(),std::placeholders::_1,12)
			)
		);
	cout<<"(12,30):"<<nums<<endl;
	//在循环内部讲执行这样一句代码：_Pred(*first)。_Pred就是函数对象std::bind(std::less<int>(),std::placeholders::_1,12)产生的对象
	int nums2= std::count_if(iv.begin(),iv.end(),std::bind(std::less<int>(),std::placeholders::_1,12));
	cout<<"(-,12):"<<nums2<<endl;



	//使用迭代器输出所以数据
	std::copy(iv.begin(),iv.end(),out_it);
	cout<<endl;
	
	//使用函数指针输出
	std::for_each(iv.begin(),iv.end(),print);//类中的函数对象保存在某个位置，我要阅读其他书籍才知道。函数对象指的一个仿函数对象，函数指针就是函数名，待续
	cout<<endl;

	//使用仿函数对象输出,需要通过指针处理，因为stl函数库的定义使用的模板，不进行类型检查（同时ide也无法完成成员提醒，因为未特化不存在改类型类型相关的代码），
	//只要存在operator()重载即可通过编译。如果使用pa传值，内部调用的.操作符，没有进行重载，会编译报错。
	std::for_each(iv.begin(),iv.end(),(*pa));
	cout<<endl;


	delete pa;

	return 0;
}

