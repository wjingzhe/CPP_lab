// functor-adapter_p431.cpp : 定义控制台应用程序的入口点。
//


#include <algorithm>//元素操作算法
#include <functional> //函数配接器，bind、compose、negate
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

