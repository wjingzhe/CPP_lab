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
  cout<<"�������ļ�����"<<endl;
  //MessageBox("�������ļ�����ѡȡ�ļ���");
  return 0;
 }
 int num=1;
 fin.open(m_stFileName,ios::in);
 while(!fin.eof())
 {
  fin.getline(buf,2047);
  sout<<num<<"\t"<<buf<<endl;
  cout<<"���ڴ����"<<num<<"��"<<endl;
  num++;
  //m_stShow.Format("���ڴ����%3d��",num);
  //UpdateData(FALSE);
 }
 cout<<"����׼��������ļ�..."<<endl;
 //m_stShow="����׼��������ļ�...";
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
  cout<<"���������"<<num<<"��"<<endl;
  num++;
  //m_stShow.Format("���������%3d��",num);
  //m_ctrlPro.SetPos(num);
  //UpdateData(FALSE);
 }
 //m_ctrlPro.SetPos(0);
 fout.close(); 
 return 1;
}

