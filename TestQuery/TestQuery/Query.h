#pragma once

#include "TextQuery.h"
#include <iostream>

class Query_base
{
private:

	friend class Query;
	
protected:
	virtual ~Query_base(void){};
	typedef TextQuery::line_no line_no;

private:

	virtual std::set<line_no> eval(const TextQuery &) const = 0;
	virtual std::ostream & display(std::ostream & out = std::cout) const = 0;
};

class Query
{
private:
	friend Query operator ~(const Query &);
	friend Query operator |(const Query & first,const Query & second);
	friend Query operator &(const Query & first,const Query & second);
	friend std::ostream & operator<<(std::ostream &os,const Query & query);

public:
	Query(const std::string & );
	//复制构造函数
	Query(const Query &c):m_pQureyBase(c.m_pQureyBase),m_pUse(c.m_pUse){++*m_pUse;};

	~Query(void);

	Query & operator = (const Query & other);

	//代理模式
	std::set<TextQuery::line_no> eval(const TextQuery & t) const{ return m_pQureyBase->eval(t);};
	std::ostream & display(std::ostream & os) const {return m_pQureyBase->display(os); };

	
private:

	Query(Query_base *queryBase):m_pQureyBase(queryBase),m_pUse(new std::size_t(1)){};
	
	void DecrUse()
	{
		if (--*m_pUse==0)
		{
			delete m_pQureyBase;
			delete m_pUse;
		}
	}
	
private:
	Query_base * m_pQureyBase;
	std::size_t * m_pUse;
};

class BinaryQuery :
	public Query_base
{
protected:
	BinaryQuery(const Query &left,const Query & right,std::string op):lhs(left),rhs(right),oper(op){};
	virtual~BinaryQuery(void){};
	std::ostream & display(std::ostream & os) const
	{
		return os<<"("<< lhs <<" "<< oper<<" "<<rhs<<")";
	}
	const Query lhs,rhs;
	const std::string oper;
};

class OrQuery :
	public BinaryQuery
{
	friend Query operator |(const Query & first,const Query & second);
	OrQuery(Query left,Query right):BinaryQuery(left,right,"|"){};
	std::set<line_no> eval(const TextQuery & file)const
	{
		std::set<line_no> right = rhs.eval(file);
		std::set<line_no> ret_Lines = lhs.eval(file);
		ret_Lines.insert(right.begin(),right.end());
		return ret_Lines;
	}
};

#include <algorithm>
class AndQuery :
	public BinaryQuery
{
	friend Query operator &(const Query & first,const Query & second);

	AndQuery(Query left,Query right):BinaryQuery(left,right,"&"){};

	std::set<line_no> eval(const TextQuery & file )const
	{
		std::set<line_no> left = lhs.eval(file),
			right = rhs.eval(file);
		std::set<line_no> ret_Lines;
		std::set_intersection(left.begin(),left.end(),right.begin(),right.end(),std::inserter(ret_Lines,ret_Lines.begin()));
		return ret_Lines;
	}
};

class NotQuery :
	public Query_base
{
	friend Query operator ~(const Query &);

	NotQuery(const Query q):query(q){};

	std::set<line_no> eval(const TextQuery & file)const
	{
		std::set<line_no> hasVal = query.eval(file);
		std::set<line_no>ret_lines;
		for (line_no n = 0; n != file.size(); ++n)
		{
			if (hasVal.find(n)==hasVal.end())
			{
				ret_lines.insert(n);
			}
		}
		return ret_lines;
	}

	std::ostream & display(std::ostream & os) const
	{
		return os<< "～("<<query<<")";
	}

	const Query query;
};

class WordQuery :
	public Query_base
{
	friend class Query;

	WordQuery(const std::string &s):query_word(s){};

	std::set<line_no> eval(const TextQuery & t)const
	{
		return t.RunQuery(query_word);
	}

	std::ostream & display(std::ostream & os) const
	{
		return os<<query_word;
	}

	std::string query_word;
};

inline Query operator ~(const Query &oper)
{
	return new NotQuery(oper);
}

inline Query operator |(const Query & first,const Query & second)
{
	return new OrQuery(first,second);
}
	

inline Query operator &(const Query & first,const Query & second)
{
	return new AndQuery(first,second);
}

inline std::ostream & operator<<(std::ostream &os,const Query & query)
{
	return query.display(os);
}