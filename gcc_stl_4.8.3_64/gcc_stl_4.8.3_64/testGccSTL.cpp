#include <algorithm>//元素操作算法
#include <functional> //函数配接器，bind、compose、negate
#include <iostream>
#include <iterator>
#include <vector>
#include <bits/stl_algo.h>
using std::cout;
using std::cin;
using std::endl;

void print(int i)
{
	std::cout<< i << " ";
}

class Int
{
public:
	explicit Int(int i):m_i(i){};
	~Int();

	void print1() const
	{
		std::cout<<"["<<m_i<<"]";
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
};  
class B:public A  
{  
public:  
    virtual void f()  
    {  
        cout<<"B::f()"<<endl;  
    }  
};  


int main(int argc, char * argv[])
{
	std::ostream_iterator<int> out_it(std::cout," ");//输出迭代器绑定到命令窗输出行中,每次输出填充一个空格

	int ia[6] = {2,21,12,7,19,23};

	auto f1 = std::bind<bool>(std::less<int>(),std::placeholders::_1);//使用C++11新语法，以及占位符。重点不在于函数的设计，而在于语法特性的熟悉

	std::vector<int> iv(ia,ia+6);	

	//找出不小于12的数据
	std::copy_if(iv.begin(),iv.end(),out_it,std::not1(std::bind2nd(std::less<int>(),12)));

	//std::cout<< std::count_if(ia,ia+6,std::bind(f1,12))<<std::endl;
	
	return 0;
}