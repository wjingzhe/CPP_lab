// functor-adapter_p431.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <algorithm>//Ԫ�ز����㷨
#include <functional> //�����������bind��compose��negate
#include <iostream>
#include <iterator>
#include <vector>
#include <memory>


using std::cin;
using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
	

	
	std::istream_iterator<int> in_it(cin),eos;

	
	while (!(in_it==eos))
	{
		cout<<*in_it;
		cout<<endl;
		++in_it;
	}


	return 0;
}

