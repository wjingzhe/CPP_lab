#pragma once

#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <sstream>


class TextQuery
{

public:
	typedef std::vector<std::string>::size_type line_no;

	void ReadFile(std::ifstream &is)
	{
		storeFile(is);
		build_map();
	}
	std::set<line_no> RunQuery(const std::string &)const;
	std::string TextLine(line_no) const;
	line_no size() const
	{
		return m_sLineofText.size();
	}

	std::vector<std::string> GetText() const
	{
		return m_sLineofText;
	}
private:
	std::vector<std::string> m_sLineofText;
	void storeFile(std::ifstream &is);//store input file;
	void build_map();//associated each word with a set line numbers
	
	std::map<std::string,std::set<line_no>> m_wordMap;
};


