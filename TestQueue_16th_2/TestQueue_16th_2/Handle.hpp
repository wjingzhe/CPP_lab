#pragma once

template <typename T>
class Handle
{
public:

	Handle(T *p = nullptr):Handle(p,new std::size_t(1))
	{
	}


	Handle(const Handle & h):Handle(h.m_pPtr,h.m_pUseCount)
	{
	}

	Handle & operator = (const Handle & other);


	T & operator *() throw (std::runtime_error);
	T * operator ->() throw (std::runtime_error);

	T & operator *() const throw (std::runtime_error);
	T * operator ->() const throw (std::runtime_error);

	~Handle(void)
	{
		rem_ref();
	}

private:
	Handle(T*p,size_t * use):m_pPtr(p),m_pUseCount(use)
	{
		if (m_pPtr==nullptr)
		{
			 delete m_pUseCount;
			 m_pUseCount = nullptr;
		}
		else
		{
			++(*m_pUseCount);
		}
	};

	void rem_ref()
	{
		if (--*m_pUseCount == 0)
		{
			delete m_pPtr;
			delete m_pUseCount;
			m_pPtr = nullptr;
			m_pUseCount = nullptr;
		}
	}

private:
	T * m_pPtr;
	size_t * m_pUseCount;

};


template <typename T>
Handle<T> & Handle<T>::operator = (const Handle<T> & other)
{
	++other.m_pUseCount;
	rem_ref();
	m_pPtr = other.m_pPtr;
	m_pUseCount = other.m_pUseCount;
	return *this;
}


template <typename T>
inline T & Handle<T>::operator *()
{
	if (m_pPtr!=nullptr)
	{
		return *m_pPtr;
	}
	else
	{
		throw std::runtime_error("dereference of unbound Handle");
	}
	
}

template <typename T>
inline T * Handle<T>::operator ->()
{
	if (m_pPtr!=nullptr)
	{
		return m_pPtr;
	}
	else
	{
		throw std::runtime_error("dereference of unbound Handle");
	}
}
	
template <typename T>
inline T & Handle<T>::operator *() const
{
	if (m_pPtr!=nullptr)
	{
		return *m_pPtr;
	}
	else
	{
		throw std::runtime_error("dereference of unbound Handle");
	}
}

template <typename T>
inline T * Handle<T>::operator ->() const
{
	if (m_pPtr!=nullptr)
	{
		return m_pPtr;
	}
	else
	{
		throw std::runtime_error("dereference of unbound Handle");
	}
}