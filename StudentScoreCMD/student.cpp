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

//菜单处理函数

void handle_menu(STUD *top)
{
	while(true)
	{
		cout<<endl;
		cout<<"\t********************************************************"<<endl;
		cout<<"\t*                      这是一个                        *"<<endl;
		cout<<"\t*                简单的学生信息管理系统                *"<<endl;
		cout<<"\t*            可以对学生信息进行简单的管理              *"<<endl;
		cout<<"\t*                   欢迎使用本系统                     *"<<endl;
		cout<<"\t********************************************************"<<endl;
		switch(menu_select())
		{
		case '1':
			top = input(top);//1、增加记录
			break;

		case '2':
			display(top);//2、显示记录
			break;

		case '3':	//3、save
			save(top);
			break;

		case '4'://4、load
			if(savedTag==1)
			{
				cout<<"原来的班级信息已改动，是否保存？(Y/N)"<<endl;
				cin>>cchar;
				if(cchar=='Y'||cchar=='y'||cchar=='\0')
					save(top);
			}
			free_nodes(top);
			top = load();
			break;

		case '5'://5、删除
			top = delete_record(top);
			break;

		case '6'://6、新建班级
			top = new_addclass(top);
			break;

		case '7'://查询
			find_record(top);
			break;

		case '8'://排序
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

int menu_select() //菜单选择函数menu_select
{
	cout<<endl;
	cout<<"1、增加记录"<<endl;
	cout<<"2、显示记录"<<endl;
	cout<<"3、保存记录"<<endl;
	cout<<"4、读取记录"<<endl;
	cout<<"5、删除记录"<<endl;
	cout<<"6、新建班级"<<endl;
	cout<<"7、查询记录"<<endl;
	cout<<"8、记录排序"<<endl;
	cout<<"9、结束运行"<<endl;
	cout<<endl<<"左边数字对应功能选择1-9：";
	while(true)
	{
		cin>>cchar;
		if(cchar<'1'||cchar>'9')
			cout<<endl<<"输入错误，请重新选择1-9：";
		else
			break;
	}//while

	return cchar;
}//menu_select

/************************************
*释放以top为头的链表的内存空间
*参数top：当前班级学生信息链表的表头
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
*结束运行，退出
*参数top：当前班级学生信息链表的表头
*************************************/
void quit(STUD *top)
{
	if(savedTag == 1)//已改动，未保存
	{
		cout<<"记录已改动，是否保存？（Y/N）";
		cin>>cchar;
		if(cchar=='Y'||cchar=='y'||cchar=='\0')
			save(top);
	}
	cout<<"退出操作，再见！"<<endl;
	free_nodes(top);
	exit(0);
}//quit

/************************************
*新建班级
*参数top：当前班级学生信息链表的表头
*返回新建班级的学生信息链表的表头
*************************************/
STUD *new_addclass(STUD *top)
{
	if(savedTag==1)
	{
		cout<<"原来的班级信息已改动，是否保存？(Y/N)"<<endl;
		cin>>cchar;
		if(cchar=='Y'||cchar=='y'||cchar=='\0')
			save(top);
	}
	free_nodes(top);//释放原来班级信息占用的内存
	top = NULL;
	top = input(top);//插入新的记录
	return top;
}