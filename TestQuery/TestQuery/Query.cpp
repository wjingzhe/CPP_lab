#include "stdafx.h"
#include "Query.h"


Query::~Query(void)
{
	DecrUse();
}

Query::Query(const std::string &s ):m_pQureyBase(new WordQuery(s)),m_pUse(new std::size_t(1))
{

}



inline Query & Query::operator = (const Query & other)
{
	++*other.m_pUse;
	DecrUse();
	m_pQureyBase = other.m_pQureyBase;
	m_pUse = other.m_pUse;
	return *this;
}