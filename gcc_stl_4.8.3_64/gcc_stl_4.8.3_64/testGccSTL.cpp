#include <algorithm>//Ԫ�ز����㷨
#include <functional> //�����������bind��compose��negate
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
        //std::bind���Ա��ֳ���̬��Ϊ  
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
	std::ostream_iterator<int> out_it(std::cout," ");//����������󶨵�����������,ÿ��������һ���ո�

	int ia[6] = {2,21,12,7,19,23};

	auto f1 = std::bind<bool>(std::less<int>(),std::placeholders::_1);//ʹ��C++11���﷨���Լ�ռλ�����ص㲻���ں�������ƣ��������﷨���Ե���Ϥ

	std::vector<int> iv(ia,ia+6);	

	//�ҳ���С��12������
	std::copy_if(iv.begin(),iv.end(),out_it,std::not1(std::bind2nd(std::less<int>(),12)));

	//std::cout<< std::count_if(ia,ia+6,std::bind(f1,12))<<std::endl;
	
	return 0;
}