#include"student.h"
/*
*��¼�������������
*����top����ǰ�༶��¼����ı�ͷ
*/

void sort_record(STUD*top)
{
	if(count==0)
	{
		cout<<"û�пɹ�����ļ�¼��";
		return ;
	}
	STUD *p,*q;
	ASK(q);
	ASK(p);
	cout<<"��������ϣ����������ķ�ʽ��"<<endl;
	cout<<"1����ѧ�Ž�����������"<<endl;
	cout<<"2����ѧ�Ž��н�������"<<endl;
	cout<<"3�����ֽܷ�����������"<<endl;
	cout<<"4�����ֽܷ��н�������"<<endl;
	cout<<"5����ƽ���ֽ�����������"<<endl;
	cout<<"6����ƽ���ֽ��н�������"<<endl;
	cout<<"7������"<<endl;
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