#include"student.h"
/*
*ɾ��ָ����¼
*����top��ǰ�༶��¼�ı�ͷ
*����ɾ����¼������
*/

STUD *delete_record(STUD *top)
{
	if(count==0)
	{
		cout<<"��¼Ϊ�գ��˳�ɾ������"<<endl;
		return top;
	}

	STUD *old,*star;
	cout<<"����ͨ����������ѧ��ɾ��"<<endl;
	cout<<"1��ͨ������"<<endl;
	cout<<"2��ͨ��ѧ��"<<endl;
	cin>>cchar;
	while(true)
	{
		
		if(cchar!='1'&&cchar!='2')
		{
			cout<<"���������ѡ1-2:";
			cin>>cchar;
		}
		else
			break;
	}//while

	switch(cchar)
	{
	case '1':
		cout<<"����������:";
		break;

	case '2':
		cout<<"������ѧ��:";
		
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
				cout<<"��ɾ������Ϣ����"<<endl;

			cout<<"ѧ��\t����\t�Ա�\t�༶\t�����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n";
			cout<<star->number<<"\t"<<star->name<<"\t"<<star->sex<<"\t"<<star->classno<<"\t"<<star->score[0]<<"\t"<<star->score[1]<<"\t"<<star->score[2]<<"\t"<<star->sum<<"\t"<<star->average<<endl;
			old->next = star->next;
			free(star);
			cout<<"Deletion finished.";//����ɾ���ɹ����ź�
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

	cout<<"û���ҵ���Ӧ�ļ�¼"<<endl;
	return top;
}//delete_record