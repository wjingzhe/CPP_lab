// lab11_9_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
 char m_stFileName[256]; 
 char buf[2048];
 ifstream fin;
 ofstream fout;
 stringstream  sout;
 
 cin.getline(m_stFileName,255);
 if(strlen(m_stFileName)==0)
 {
  cout<<"请输入文件名！"<<endl;
  //MessageBox("请输入文件名或选取文件！");
  return 0;
 }
 int num=1;
 fin.open(m_stFileName,ios::in);
 while(!fin.eof())
 {
  fin.getline(buf,2047);
  sout<<num<<"\t"<<buf<<endl;
  cout<<"正在处理第"<<num<<"行"<<endl;
  num++;
  //m_stShow.Format("正在处理第%3d行",num);
  //UpdateData(FALSE);
 }
 cout<<"正在准备输出到文件..."<<endl;
 //m_stShow="正在准备输出到文件...";
 //UpdateData(FALSE);
 fin.close();
 
 //m_ctrlPro.SetRange(0,num);
 //m_ctrlPro.SetPos(0);
 
 num=1;
 fout.open(m_stFileName,ios::out);
 while(!sout.eof())
 {
  sout.getline(buf,2047);
  fout<<buf<<endl;
  cout<<"正在输出第"<<num<<"行"<<endl;
  num++;
  //m_stShow.Format("正在输出第%3d行",num);
  //m_ctrlPro.SetPos(num);
  //UpdateData(FALSE);
 }
 //m_ctrlPro.SetPos(0);
 fout.close(); 
 return 1;
}

