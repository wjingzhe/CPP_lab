// functor-adapter_p431.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <algorithm>//Ԫ�ز����㷨
#include <functional> //�����������bind��compose��negate
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
        //std::bind���Ա��ֳ���̬��Ϊ  
        fp f=std::bind(&A::f,this);  
        f();  
    } 
	bool print(int i)
	{
		std::cout<< i << "��";
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
	std::ostream_iterator<int> out_it(cout,",");//����������󶨵�����������,ÿ��������һ��,��print������

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


	
	//�ҳ���С��12������
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
	//��ѭ���ڲ���ִ������һ����룺_Pred(*first)��_Pred���Ǻ�������std::bind(std::less<int>(),std::placeholders::_1,12)�����Ķ���
	int nums2= std::count_if(iv.begin(),iv.end(),std::bind(std::less<int>(),std::placeholders::_1,12));
	cout<<"(-,12):"<<nums2<<endl;



	//ʹ�õ����������������
	std::copy(iv.begin(),iv.end(),out_it);
	cout<<endl;
	
	//ʹ�ú���ָ�����
	std::for_each(iv.begin(),iv.end(),print);//���еĺ������󱣴���ĳ��λ�ã���Ҫ�Ķ������鼮��֪������������ָ��һ���º������󣬺���ָ����Ǻ�����������
	cout<<endl;

	//ʹ�÷º����������,��Ҫͨ��ָ�봦����Ϊstl������Ķ���ʹ�õ�ģ�壬���������ͼ�飨ͬʱideҲ�޷���ɳ�Ա���ѣ���Ϊδ�ػ������ڸ�����������صĴ��룩��
	//ֻҪ����operator()���ؼ���ͨ�����롣���ʹ��pa��ֵ���ڲ����õ�.��������û�н������أ�����뱨��
	std::for_each(iv.begin(),iv.end(),(*pa));
	cout<<endl;


	delete pa;

	return 0;
}

