// Iterator-adapter_p427.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include <iterator>
#include <deque>
#include <set>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::flush;

int _tmain(int argc, _TCHAR* argv[])
{
	std::ostream_iterator<int> out_it(std::cout," ");

	int ia[6] = {0,1,2,3,4,5};

	std::deque<int> id(ia,ia+6);
	std::multiset<int> is(id.begin(),id.end());
	std::vector<int> iv(is.begin(),is.end());
	std::list<int> il(iv.begin(),iv.end());

	std::copy(id.begin(),id.end(),out_it);//最后调用的是函数的赋值操作符，也就是说所有的输出迭代器都可以使用。
	cout<<endl;

	std::insert_iterator<std::multiset<int>> is_it(is,is.begin());
	//std::insert_iterator<std::multiset<int>> is_it(is,is.end()); 无论什么位置，set系列的容器是使用红黑树实现，总是有序的。所以只要有insert操作的容器都可以

	//前置输出
	std::copy(id.begin(),id.end(),is_it);
	std::copy(is.begin(),is.end(),out_it);//最后调用的是函数的赋值操作符，也就是说所有的输出迭代器都可以使用。
	cout<<endl;
	
	is.insert(10);
	std::insert_iterator<std::vector<int>> iv_it(iv,iv.begin());//永远在vector最初元素0的前面插入数据，因为是一个锁定直线刚开始传值的begin，而不是动态begin，在插入之后insert_iterator会执行++操作执行0；
	std::copy(is.begin(),is.end(),iv_it);//copy开始调用赋值操作
	std::copy(iv.begin(),iv.end(),out_it);
	cout<<endl;
	
	std::front_insert_iterator<decltype(il)> il_it(il); //永远调用push_front去执行插入，没有位置限制，形成了倒序插入
	std::copy(is.begin(),is.end(),il_it);
	std::copy(il.begin(),il.end(),out_it);
	cout<<endl;
	
	//覆盖式. 5 = 0+6-1,4,3,2,1,0.如果用正序的迭代器，效果还是前面一样，是从id.end-1开始递减值begin的数据段去覆盖iv.offet-1到iv.begin的数据段
	//但是我想呈现一种逆序数据的覆盖，所以使用reserve_iterator。
	//std::copy_backward(id.rbegin(),id.rend(),iv.begin()+id.size());//copy_backward指的是target iterator使用backward,不是insert reserved.相应的我要处理一下。
	std::copy(id.rbegin(),id.rend(),iv.begin());//++变--,但是iv是不变化的
	std::copy(iv.begin(),iv.end(),out_it);
	cout<<endl;




	return 0;
}

