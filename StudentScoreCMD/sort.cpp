#include"student.h"
/*
*记录的排序操作函数
*参数top：当前班级记录链表的表头
*/

void sort_record(STUD*top)
{
	if(count==0)
	{
		cout<<"没有可供排序的记录！";
		return ;
	}
	STUD *p,*q;
	ASK(q);
	ASK(p);
	cout<<"请输入您希望进行排序的方式："<<endl;
	cout<<"1、按学号进行升序排序："<<endl;
	cout<<"2、按学号进行降序排序："<<endl;
	cout<<"3、按总分进行升序排序："<<endl;
	cout<<"4、按总分进行降序排序："<<endl;
	cout<<"5、按平均分进行升序排序："<<endl;
	cout<<"6、按平均分进行降序排序："<<endl;
	cout<<"7、返回"<<endl;
	cin>>cchar;
	if(cchar<'1'||cchar>'6') return ;
	for(p = top;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q = q->next)
		{
			if((cchar=='1' && strcmp(p->number,q->number)>0)||
				(cchar=='2' && strcmp(p->number,q->number)<0)||
				(cchar=='3' && p->sum>q->sum)||
				(cchar=='4' && p->sum<q->sum)||
				(cchar=='5'&& p->average>q->average)||
				(cchar=='6'&&p->average<q->average))
			{
				swap_record(p,q);
				savedTag = 1;
			}//if
		}//for_q
	}//for-p
}//sort

void swap_record(STUD *p,STUD*q)
{ //copy p to tmps
	STUD*tmps;
	ASK(tmps);
	strcpy(tmps->number,p->number);
	strcpy(tmps->name,p->name);
	strcpy(tmps->sex,p->sex);
	tmps->classno = p->classno;
	tmps->score[0] = p->score[0];
	tmps->score[1] = p->score[1];
	tmps->score[2] = p->score[2];
	tmps->sum = p->sum;
	tmps->average = p->average;

	//copy q to p
	strcpy(p->number,q->number);
	strcpy(p->name,q->name);
	strcpy(p->sex,q->sex);
	p->classno = q->classno;
	p->score[0] = q->score[0];
	p->score[1] = q->score[1];
	p->score[2] = q->score[2];
	p->sum = q->sum;
	p->average = q->average;

	//copy tmps to q
	strcpy(q->number,tmps->number);
	strcpy(q->name,tmps->name);
	strcpy(q->sex,tmps->sex);
	q->classno = tmps->classno;
	q->score[0] = tmps->score[0];
	q->score[1] = tmps->score[1];
	q->score[2] = tmps->score[2];
	q->sum = tmps->sum;
	q->average = tmps->average;
}