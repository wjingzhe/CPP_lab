#include"student.h"
/*
*删除指定记录
*参数top当前班级记录的表头
*返回删除记录的链表
*/

STUD *delete_record(STUD *top)
{
	if(count==0)
	{
		cout<<"记录为空，退出删除操作"<<endl;
		return top;
	}

	STUD *old,*star;
	cout<<"可以通过姓名或者学号删除"<<endl;
	cout<<"1、通过姓名"<<endl;
	cout<<"2、通过学号"<<endl;
	cin>>cchar;
	while(true)
	{
		
		if(cchar!='1'&&cchar!='2')
		{
			cout<<"输入错误。重选1-2:";
			cin>>cchar;
		}
		else
			break;
	}//while

	switch(cchar)
	{
	case '1':
		cout<<"请输入姓名:";
		break;

	case '2':
		cout<<"请输入学号:";
		
		break;
	}//switch
	cin>>tempStr;
	old = star = top;
	while(star!=NULL)
	{
		if((cchar=='1' && strcmp(tempStr,star->name)==0) || (cchar=='2' && strcmp(tempStr,star->number)==0))
		{
			if(star == top)
				top = star->next;
			else
				cout<<"将删除的信息如下"<<endl;

			cout<<"学号\t姓名\t性别\t班级\t计算机\t数学\t英语\t总分\t平均分\n";
			cout<<star->number<<"\t"<<star->name<<"\t"<<star->sex<<"\t"<<star->classno<<"\t"<<star->score[0]<<"\t"<<star->score[1]<<"\t"<<star->score[2]<<"\t"<<star->sum<<"\t"<<star->average<<endl;
			old->next = star->next;
			free(star);
			cout<<"Deletion finished.";//给出删除成功的信号
			--count;
			savedTag = 1;
			return top;
		}//if
		else
		{
			old = star;
			star = star->next;
		}
	}//while

	cout<<"没有找到相应的记录"<<endl;
	return top;
}//delete_record