// TestQuery.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TextQuery.h"
#include<iostream>
#include<string>
using namespace std;
#include "Query.h"
typedef set<TextQuery::line_no> line_nums;


std::ifstream & OpenFile(std::ifstream & in,const std::string &fileName)
{
	in.close();
	in.clear();
	in.open(fileName.c_str());
	return in;
}

string make_plural(std::set<TextQuery::line_no>::size_type count,string str1,const string & str2)
{
	if(count>=2)
	{
		str1.append(str2);
	}
	return str1;
}

void PrintResults(const std::set<TextQuery::line_no>& locs,const std::string& sought,const TextQuery&file)
{
	line_nums::size_type size = locs.size();
	cout<<"\n"<<sought<<" occurs "<<size<<" "<<make_plural(size,"time","s")<<endl;

	
	for(line_nums::iterator it = locs.begin();it!=locs.end();++it)
	{
		try{

			cout<<"\t(line "<<(*it) + 1 << ")"<<file.TextLine(*it)<<endl;
		}
		catch(exception e)
		{
			cout<<"No suggestion";
		}
	}
}


void PrintResults(const std::set<TextQuery::line_no>& locs,const TextQuery&file)
{

	for(line_nums::iterator it = locs.begin();it!=locs.end();++it)
	{
		try{

			cout<<"\t(line "<<(*it) + 1 << ")"<<file.TextLine(*it)<<endl;
		}
		catch(exception e)
		{
			cout<<"No suggestion";
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inFile;
	string fileName;
	cout<<"pLease inout FileName"<<endl;
	cin>>fileName;
	if (!OpenFile(inFile,fileName))
	{
		cerr<<"No input file!"<<endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.ReadFile(inFile);

	//while (true)
	//{
	//	cout<<"enter word to look for,or q to quit:";
	//	string s;
	//	cin>>s;
	//	if (!cin||s=="q")
	//	{
	//		break;
	//	}
	//	set<TextQuery::line_no> locs = tq.RunQuery(s);
	//	PrintResults(locs,s,tq);
	//}
	//
	//string s;
	//ofstream outFile("2.txt",iostream::ate);
	//for (vector<string>::iterator it = tq.GetText().begin(); it < tq.GetText().end(); ++it)
	//{
	//	outFile<<*it;
	//	outFile<<"\n";
	//}
	//outFile.flush();
	//outFile.close();
	
	typedef set<TextQuery::line_no> line_nums;
	Query q = ~(Query("fiery") & Query("bird") | Query("wind"));

	const line_nums & locs(q.eval(tq));
	
	PrintResults(locs,tq);
	

	string s;
	cin>>s;
	return 0;
}

