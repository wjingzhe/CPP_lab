#include "stdafx.h"
#include "TextQuery.h"
using namespace std;

set<TextQuery::line_no> TextQuery::RunQuery(const std::string &temp)const
{
	map<string,set<line_no>>::const_iterator cit = m_wordMap.find(temp);
	if (cit==m_wordMap.end())
	{
		return set<line_no>();
	}
	else
	{
		return cit->second;
	}
}

string TextQuery::TextLine(TextQuery::line_no line) const
{
	if (line<m_sLineofText.size())
	{
		return m_sLineofText[line];
	}
	throw out_of_range("line number out of range");
}

void TextQuery::storeFile(ifstream &is)//store input file;
{
	string _stextLine;
	while (getline(is,_stextLine))
	{
		m_sLineofText.push_back(_stextLine);
	}
}


void TextQuery::build_map()//associated each word with a set line numbers
{
	for (line_no  lineNum = 0; lineNum != m_sLineofText.size(); ++lineNum)
	{
		istringstream line(m_sLineofText[lineNum]);
		string word;
		while (line>>word)
		{
			m_wordMap[word].insert(lineNum);
		}
	}
}