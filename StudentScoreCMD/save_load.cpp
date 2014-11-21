#include"student.h"
#include<fstream>
/*
*�ļ���ȡ��������
*����top����ǰ�༶��¼����ı�ͷ
*/

void save(STUD *top)
{
	STUD *p;
	ofstream ofs;
	if(top==NULL)
	{
		cout<<"û�м�¼�ɴ棡";
		return;
	}//if

	cout<<"������Ҫ��ȡ���ļ�����(ԭ�ļ���Ϊ��"<<tempFile<<"):";
	cin>>fname;
	if(strlen(fname)==0)
	{
		strcpy(fname,tempFile);
	}
	ofs.open(fname,ios_base::app|ios_base::binary);
	if (!ofs.is_open())
	{
		cout<<"���ܴ����ļ���"<<endl;
		return ;
	}

	cout<<endl<<"���ļ�...."<<endl;
	p = top;
	while(p!=NULL)
	{
		ofs.write(reinterpret_cast<char*>(p),LEN);
		p = p->next;
	}

	ofs.close();
	cout<<count<<"����¼�Ѿ������ļ�����������������"<<endl;
	savedTag = 0;
}//save

STUD *load()
{
	ifstream ifs;
	STUD *p,*old,*top;
	count = 0;
	cout<<"������Ҫ��ȡ���ļ�����(Ĭ���ļ���Ϊ��"<<tempFile<<"):";
	cin>>fname;
	strcpy(tempFile,fname);
	ifs.open(fname,ios_base::binary);
	if(!ifs.is_open())
	{
		cout<<"�򲻿��ļ���������ѡ��"<<endl;
		return NULL;
	}

	cout<<endl<<"��ȡ�ļ���..."<<endl;
	ASK(p);
	old = top = p;
	while(ifs.peek() != EOF)
	{
		ifs.read(reinterpret_cast<char*>(p),LEN);
		count++;
		ASK(p->next);
		old = p;
		p = p->next;
	}
	old->next = NULL;
	free(p);
	ifs.close();
	cout<<"��ȡ��"<<count<<"����¼"<<endl;
	if(count==0)
	{
		top = NULL;
	}
	return top;
}//load