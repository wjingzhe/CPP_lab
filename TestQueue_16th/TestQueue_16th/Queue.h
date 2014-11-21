#pragma once
#include <iostream>
#include <algorithm>

template <typename Type>
class Queue;
template<typename Type>
std::ostream & operator<< (std::ostream & os, const Queue<Type> &q);

template <typename Type>
class QueueItem
{
private:
	friend class Queue<Type>;
	friend std::ostream & operator<< <Type>(std::ostream & os, const Queue<Type> &q);
	QueueItem(const Type &element):item(element),next(nullptr) {};
	Type item;
	QueueItem * next;
};

template <typename Type>
class Queue
{
	friend std::ostream & operator<< <Type>(std::ostream & os, const Queue<Type> &q);

public:
	Queue(void):m_pHead(nullptr),m_pTail(nullptr){};
	~Queue(void)
	{
		destroy();
	}

	Queue(const Queue & Q):m_pHead(nullptr),m_pTail(nullptr)
	{
		copy_elems(Q);
	}

	template <class Iter>
	Queue(Iter begin,Iter end):m_pHead(nullptr),m_pTail(nullptr)
	{
		copy_elems(begin,end);
	}
	
	Queue & operator = (const Queue &other)
	{
		copy_elems(other);
		return *this;
	}

	Type &front()
	{
		return m_pHead->item;
	}
	const Type &front()const
	{
		return m_pHead->item;
	}

	Type & back()
	{
		return m_pTail->item;
	}

	const Type & back()const
	{
		return m_pTail->item;
	}

	template <class Iter>
	void assign(Iter begin,Iter end)
	{
		destroy();
		copy_elems(begin,end);
	}

	bool empty()const
	{
		return m_pHead==nullptr;
	}

	void push_back(const Type &elemt);
	void pop_front();

private:
	void destroy();
	void copy_elems(const Queue &Q);
	template <class Iter>
	void copy_elems(Iter begin,Iter end);

private:
	QueueItem<Type> * m_pHead;
	QueueItem<Type> * m_pTail;
	
	

};


template <typename Type>
void Queue<Type>::push_back(const Type &elemt)
{
	QueueItem<Type> * p = new QueueItem<Type>(elemt);
	if(!m_pHead)
	{
		m_pHead = p;
		m_pTail = p;
	}
	else
	{
		m_pTail->next = p;
		m_pTail = p;
	}
}

template <typename Type>
void Queue<Type>::pop_front()
{
	if (m_pHead)
	{
		QueueItem<Type> * p  = m_pHead;
		m_pHead = m_pHead->next;
		delete p;
	}
	 

}

template <typename Type>
void Queue<Type>::destroy()
{
	while (!empty())
	{
		pop_front();
	}
	m_pHead = nullptr;
	m_pTail = nullptr;
}

template <typename Type>
void Queue<Type>::copy_elems(const Queue<Type> &Q)
{
	std::for_each(
		Q.m_pHead,Q.m_pTail,
		[=](QueueItem<Type> i)
		{
			this->push_back(i.item);
		}
	)
}

template <class Type> template <class Iter>
void Queue<Type>::copy_elems(Iter begin,Iter end)
{

	std::for_each(
		begin,
		end,
		[this](decltype(*begin) i)
		{
			this->push_back(i);
		}
	);

	/*for (; begin != end; ++begin)
	{
		this->push_back(*begin);
	}*/
}

template<typename Type>
std::ostream & operator<< (std::ostream & os,const Queue<Type> &q)
{
	os<<"<";
	QueueItem<Type> *p;
	for (p = q.m_pHead; p!=nullptr ; p = p->next)
	{
		os<<p->item<<" ";
	}
	os<<">";
	return os;
}