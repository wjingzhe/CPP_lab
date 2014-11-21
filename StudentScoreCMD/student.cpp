#include"student.h"
#include<windows.h>
int count = 0;
int savedTag = 0;
char fname[20];
char tempStr[20];
char tempFile[20] = "stu.txt";
void main()
{
	handle_menu(NULL);
}//main

//�˵�������

void handle_menu(STUD *top)
{
	while(true)
	{
		cout<<endl;
		cout<<"\t********************************************************"<<endl;
		cout<<"\t*                      ����һ��                        *"<<endl;
		cout<<"\t*                �򵥵�ѧ����Ϣ����ϵͳ                *"<<endl;
		cout<<"\t*            ���Զ�ѧ����Ϣ���м򵥵Ĺ���              *"<<endl;
		cout<<"\t*                   ��ӭʹ�ñ�ϵͳ                     *"<<endl;
		cout<<"\t********************************************************"<<endl;
		switch(menu_select())
		{
		case '1':
			top = input(top);//1�����Ӽ�¼
			break;

		case '2':
			display(top);//2����ʾ��¼
			break;

		case '3':	//3��save
			save(top);
			break;

		case '4'://4��load
			if(savedTag==1)
			{
				cout<<"ԭ���İ༶��Ϣ�ѸĶ����Ƿ񱣴棿(Y/N)"<<endl;
				cin>>cchar;
				if(cchar=='Y'||cchar=='y'||cchar=='\0')
					save(top);
			}
			free_nodes(top);
			top = load();
			break;

		case '5'://5��ɾ��
			top = delete_record(top);
			break;

		case '6'://6���½��༶
			top = new_addclass(top);
			break;

		case '7'://��ѯ
			find_record(top);
			break;

		case '8'://����
			sort_record(top);
			break;

		case '9':
			quit(top);
			break;
		}//switch
		Sleep(2000);
		system("cls");
	}//while
}//handle_menu

int menu_select() //�˵�ѡ����menu_select
{
	cout<<endl;
	cout<<"1�����Ӽ�¼"<<endl;
	cout<<"2����ʾ��¼"<<endl;
	cout<<"3�������¼"<<endl;
	cout<<"4����ȡ��¼"<<endl;
	cout<<"5��ɾ����¼"<<endl;
	cout<<"6���½��༶"<<endl;
	cout<<"7����ѯ��¼"<<endl;
	cout<<"8����¼����"<<endl;
	cout<<"9����������"<<endl;
	cout<<endl<<"������ֶ�Ӧ����ѡ��1-9��";
	while(true)
	{
		cin>>cchar;
		if(cchar<'1'||cchar>'9')
			cout<<endl<<"�������������ѡ��1-9��";
		else
			break;
	}//while

	return cchar;
}//menu_select

/************************************
*�ͷ���topΪͷ��������ڴ�ռ�
*����top����ǰ�༶ѧ����Ϣ����ı�ͷ
*************************************/

void free_nodes(STUD *top)
{
	STUD *p = top;
	STUD *old = p;
	while(p)
	{
		old = p;
		p = p->next;
		free(old);
	}
	count = 0;
}//free_nodes

/************************************
*�������У��˳�
*����top����ǰ�༶ѧ����Ϣ����ı�ͷ
*************************************/
void quit(STUD *top)
{
	if(savedTag == 1)//�ѸĶ���δ����
	{
		cout<<"��¼�ѸĶ����Ƿ񱣴棿��Y/N��";
		cin>>cchar;
		if(cchar=='Y'||cchar=='y'||cchar=='\0')
			save(top);
	}
	cout<<"�˳��������ټ���"<<endl;
	free_nodes(top);
	exit(0);
}//quit

/************************************
*�½��༶
*����top����ǰ�༶ѧ����Ϣ����ı�ͷ
*�����½��༶��ѧ����Ϣ����ı�ͷ
*************************************/
STUD *new_addclass(STUD *top)
{
	if(savedTag==1)
	{
		cout<<"ԭ���İ༶��Ϣ�ѸĶ����Ƿ񱣴棿(Y/N)"<<endl;
		cin>>cchar;
		if(cchar=='Y'||cchar=='y'||cchar=='\0')
			save(top);
	}
	free_nodes(top);//�ͷ�ԭ���༶��Ϣռ�õ��ڴ�
	top = NULL;
	top = input(top);//�����µļ�¼
	return top;
}