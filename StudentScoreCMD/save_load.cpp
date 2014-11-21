#include"student.h"
#include<fstream>
/*
*文件存取操作函数
*参数top：当前班级记录链表的表头
*/

void save(STUD *top)
{
	STUD *p;
	ofstream ofs;
	if(top==NULL)
	{
		cout<<"没有记录可存！";
		return;
	}//if

	cout<<"请输入要读取的文件名：(原文件名为："<<tempFile<<"):";
	cin>>fname;
	if(strlen(fname)==0)
	{
		strcpy(fname,tempFile);
	}
	ofs.open(fname,ios_base::app|ios_base::binary);
	if (!ofs.is_open())
	{
		cout<<"不能存入文件！"<<endl;
		return ;
	}

	cout<<endl<<"存文件...."<<endl;
	p = top;
	while(p!=NULL)
	{
		ofs.write(reinterpret_cast<char*>(p),LEN);
		p = p->next;
	}

	ofs.close();
	cout<<count<<"条记录已经存入文件，请您继续操作。"<<endl;
	savedTag = 0;
}//save

STUD *load()
{
	ifstream ifs;
	STUD *p,*old,*top;
	count = 0;
	cout<<"请输入要读取的文件名：(默认文件名为："<<tempFile<<"):";
	cin>>fname;
	strcpy(tempFile,fname);
	ifs.open(fname,ios_base::binary);
	if(!ifs.is_open())
	{
		cout<<"打不开文件，请重新选择"<<endl;
		return NULL;
	}

	cout<<endl<<"读取文件中..."<<endl;
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
	cout<<"读取了"<<count<<"条记录"<<endl;
	if(count==0)
	{
		top = NULL;
	}
	return top;
}//load