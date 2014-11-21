// TestIterator_p427.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iterator>
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <fstream>
#include <cassert>

template<typename IN>
void display(const IN &t_deque,std::ostream_iterator<int> &out_it)
{
	std::copy(t_deque.begin(),t_deque.end(),out_it);//使用copy实现输出，3th parameter 输出

	//*out_it = 3;
	std::cout<<std::endl;//刷新一下输出缓冲区
}

//为什么我不std引入进来？因为每个组件的所在的头文件我必须要特别清楚，这样有助于系统的记忆其功能,确认的时候可以排除拼写错误
int _tmain(int argc, _TCHAR* argv[])
{
	std::ostream_iterator<int> out_it(std::cout," ");//" "输出空格后缀，区分两个int型数据

	int ia[] = {0,1,2,3,4,5,6,7};

	std::deque<int> t_deque(ia,ia+8);

	display(t_deque,out_it);


	std::copy(ia+1,ia+2,std::front_inserter(t_deque));//输入迭代器锁定的范围是数字1，插入在t_deque的前面,注意，只有sequence container才有push_front操作，要确认传参正确。

	display(t_deque,out_it);


	//暂时忘记编译器是否在编译器检测容器类型，来测试一下
	//std::map<int,int> t_a();动态解释不通过，可能跟effective stl 6 中提到的分析机制有关，待续
	std::map<int,int> t_a;

	for (int i = 0; i < 5; ++i)
	{
		t_a.insert(std::pair<int,int>(i,i));
	};

	std::map<int,int>t_b;//这个会生成警告C4930,然后无法使用动态提示

	//std::copy(t_a.begin(),t_a.end(),std::front_inserter(t_b)); 果然，编译错误：error C2039: “push_front”: 不是“std::map<_Kty,_Ty>”的成员


	std::copy(ia+4,ia+5,std::back_inserter(t_deque));//背后插入插入4； 
	display(t_deque,out_it);


	{	
		auto it = std::find(t_deque.begin(),t_deque.end(),5);

		if (it==t_deque.end())
		{
			assert("the num isn't in !! why?");
		}


		std::copy(ia+0,ia+3,std::inserter(t_deque,it));//在5之前插入0,1,2.之后it不可用，使用命名空间，这样子不会出现野指针
	}

	display(t_deque,out_it);

	std::copy(t_deque.rbegin(),t_deque.rend(),out_it);//rbegin是end()-1,rend()则是begin()-1，stl的逆转时整个世界思维的逆转
	std::cout<<std::endl;

	std::fstream in_file("data.txt");
	if (in_file.bad())
	{
		assert("cann't open data.txt");
	}

	/*int temp ;
	in_file>>temp;

	std::cout<<temp<<std::endl;*/

	std::istream_iterator<int> in_it(in_file),eos;  // 定义istream_iterator时不为它指定istream对象，它即代表了end-of-file(文件尾)。

	std::copy(in_it,eos,std::inserter(t_deque,t_deque.begin()));

	display(t_deque,out_it);

	in_file.close();

	return 0;
}

