#include"student.h"

STUD*input(STUD *top)//�����¼�¼
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
	else //�������ĵ�һ����¼����top
	{
		top = old = star;
	}

	//�����¼�¼
	cout<<"����������"<<endl;
	while(true)
	{
		cout<<"����:";
		cin>>star->name;
		cout<<"ѧ�ţ�";
		cin>>star->number;
		cout<<"�Ա�";
		cin>>star->sex;
		cout<<"�༶��";
		cin>>star->classno;
		cout<<"�������";
		cin>>star->score[0];
		cout<<"��ѧ��";
		cin>>star->score[1];
		cout<<"Ӣ�";
		cin>>star->score[2];
		star->sum = star->score[0]+star->score[1]+star->score[2];
		star->average = star->sum/3;
		star->next = NULL;
		count++;
		if(top!=star)//�Ǳ�ͷ���ڱ�β
		{
			old->next = star;
			old = star;
		}//if
		cout<<"�Ƿ��������һ�£�(Y//N)"<<endl;
		cin>>cchar;
		if((cchar=='Y')||(cchar=='y')||(cchar=='\0'))
		{
			ASK(star);
		}else
		{
			break;
		}
	}//while

	savedTag = 1;//��¼�Ķ���δ����
	old->next = NULL;
	return top;
}//input

/*
*��ʾ��Ϣ����
*����top����ǰ�༶��¼����ı�ͷ
*/
void display(STUD *top)
{
	STUD *p;
	if(top==NULL)
	{
		cout<<endl<<"����û�м�¼"<<endl;
		return;
	}
	p = top;
	cout<<endl;
	cout<<"���ڹ���"<<count<<"����¼��"<<endl;
	cout<<"ѧ��\t����\t�Ա�\t�༶\t�����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n";
	while(p!=NULL)
	{
		cout<<p->number<<"\t"<<p->name<<"\t"<<p->sex<<"\t"<<p->classno<<"\t"<<p->score[0]<<"\t"<<p->score[1]<<"\t"<<p->score[2]<<"\t"<<p->sum<<"\t"<<p->average<<endl;
		p = p->next;
	}
}