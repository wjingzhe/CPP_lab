#pragma once
#include <iostream>
#include <algorithm>
#include <list>

template <typename Type>
class Queue;
template <typename Type>
std::ostream & operator << (std::ostream & os,const Queue<Type> &q);

template <typename Type>
class Queue
{
	template <typename T>
	friend std::ostream & operator<< (std::ostream & os,const Queue<Type> &q);

public:
	Queue(void){};
	~Queue(void)
	{
		items.clear();
	}

	Queue(const Queue & Q):items(Q.items) {}

	template <class Iter>
	Queue(Iter begin,Iter end):items(begin,end) {}
	
	Queue & operator = (const Queue &other)
	{
		items.clear();
		items(other.items);
		return * this;
	}

	Type &front()
	{
		return items.front();
	}
	const Type &front()const
	{
		return items.front();
	}

	Type & back()
	{
		return items.back();
	}

	const Type & back()const
	{
		return items.back();
	}


	template <class Iter>
	void assign(Iter begin,Iter end)
	{
		items.assign(begin,end);
	}

	void push_back(const Type &elemt)
	{
		items.push_back(elemt);
	}

	void pop_front()
	{
		items.erase(items.begin());
	}


	bool empty()const
	{
		return items.empty();
	}


private:


private:
	std::list<Type> items;
	
	

};



template<typename Type>
std::ostream & operator<< (std::ostream & os,const Queue<Type> &q)
{
	os<<"<";
	typename std::list<Type>::const_iterator beg = q.items.begin();
	while (beg != q.items.end())
	{
		os<<*beg<<" ";
		++beg;
	}

	os<<">";
	return os;
}