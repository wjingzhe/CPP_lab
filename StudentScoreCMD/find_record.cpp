#include"student.h"
/*
*查询指定记录
*参数top当前班级记录的表头
无返回值
*/

void find_record(STUD *top)
{
	if(count==0)
	{
		cout<<"记录是空表，退出查询操作"<<endl;
		return ;
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
			cout<<"输入错误。重选1-2";
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
	old = star = top;
	while(star!=NULL)
	{
		if((cchar=='1' && strcmp(tempStr,star->name)==0) || (cchar=='2' && strcmp(tempStr,star->number)==0))
		{
			
			cout<<"查询的完整信息如下"<<endl;
			cout<<"学号\t姓名\t性别\t班级\t计算机\t数学\t英语\t总分\t平均分\n";
			cout<<star->number<<"\t"<<star->name<<"\t"<<star->sex<<"\t"<<star->classno<<"\t"<<star->score[0]<<"\t"<<star->score[1]<<"\t"<<star->score[2]<<"\t"<<star->sum<<"\t"<<star->average<<endl;
			return ;
		}//if
		else
		{
			old = star;
			star = star->next;
		}
	}
	cout<<"没有找到相应的记录";
	return ;

}//find_recoedd