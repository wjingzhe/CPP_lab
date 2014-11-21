#include"student.h"

STUD*input(STUD *top)//插入新记录
{
	STUD *old,*star;
	ASK(star);
	if(top!=NULL)
	{
		old = top;
		while(old->next!=NULL)
		{
			old = old->next;
		}//while
	}//if
	else //将新增的第一条记录赋给top
	{
		top = old = star;
	}

	//输入新纪录
	cout<<"请输入数据"<<endl;
	while(true)
	{
		cout<<"姓名:";
		cin>>star->name;
		cout<<"学号：";
		cin>>star->number;
		cout<<"性别：";
		cin>>star->sex;
		cout<<"班级：";
		cin>>star->classno;
		cout<<"计算机：";
		cin>>star->score[0];
		cout<<"数学：";
		cin>>star->score[1];
		cout<<"英语：";
		cin>>star->score[2];
		star->sum = star->score[0]+star->score[1]+star->score[2];
		star->average = star->sum/3;
		star->next = NULL;
		count++;
		if(top!=star)//非表头插在表尾
		{
			old->next = star;
			old = star;
		}//if
		cout<<"是否继续输入一下？(Y//N)"<<endl;
		cin>>cchar;
		if((cchar=='Y')||(cchar=='y')||(cchar=='\0'))
		{
			ASK(star);
		}else
		{
			break;
		}
	}//while

	savedTag = 1;//记录改动，未保存
	old->next = NULL;
	return top;
}//input

/*
*显示信息函数
*参数top：当前班级记录链表的表头
*/
void display(STUD *top)
{
	STUD *p;
	if(top==NULL)
	{
		cout<<endl<<"现在没有记录"<<endl;
		return;
	}
	p = top;
	cout<<endl;
	cout<<"现在共有"<<count<<"条记录："<<endl;
	cout<<"学号\t姓名\t性别\t班级\t计算机\t数学\t英语\t总分\t平均分\n";
	while(p!=NULL)
	{
		cout<<p->number<<"\t"<<p->name<<"\t"<<p->sex<<"\t"<<p->classno<<"\t"<<p->score[0]<<"\t"<<p->score[1]<<"\t"<<p->score[2]<<"\t"<<p->sum<<"\t"<<p->average<<endl;
		p = p->next;
	}
}