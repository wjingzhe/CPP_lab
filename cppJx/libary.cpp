#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class Book;
ostream& operator<<(ostream & os, Book & book);
istream& operator>>(istream & is, Book & book);
void main_interface();
void choice_control();
class Book
{
public:
   Book();
   Book(int)
   {
   next=NULL;
   }
   void show();
   friend  ostream& operator<<(ostream & os, Book & book);
   friend  istream& operator>>(istream & is, Book & book);
public:
   string BookName;
   string BookClass;
   string BookID;
   string BookPrice;
   string BookPublishdate;
   string Lending;
public:
   Book *next;
};
Book::Book()
{
   cout<<" 书名：";
   cin>>BookName;
   cout<<" 类别：";
   cin>>BookClass;
   cout<<" 图书编号：";
   cin>>BookID;
   cout<<" 图书价格：";
   cin>>BookPrice;
   cout<<" 出版日期";
   cin>>BookPublishdate;
   cout<<" 是否借出？（1为借出，0为未借）";
   cin>>Lending;
   next=NULL;
}
void Book::show()
{
   cout<<setw(10)<<"书名"<< setw(10)<<"类别"<< setw(10)<< "编号"<< setw(10)<<"价格" << setw(15)<< "出版日期" << setw(15)<< " 是否借出？"<<endl;
   cout<<endl;
   cout<<*this<<endl;
}
ostream & operator << (ostream & os, Book & book)
{  os<<std::left<<setw(10)<<book.BookName<<setw(10)<<book.BookClass<<setw(10)<<book.BookID<<setw(10)<<book.BookPrice<<setw(15)<<book.BookPublishdate<<setw(15)<<book.Lending<<endl;
   os<<endl;
   return os;
}
istream & operator >> (istream &is, Book &book)
{
   is>>book.BookName>>book.BookClass>>book.BookID>>book.BookPrice>>book.BookPublishdate>>book.Lending;
	return is;
}

class Function
{
public:
	Function()
	{
		head=last=NULL;
	}
	~Function()
	{
		delete[] head;
	}
	
	void Insert();
	void Delete(string BookName);
	void Select(string BookName);
	void Display();
	void Write_file();
	void Read_file();
	static int flag;
public:
	Book *head,*last;
};
int Function::flag=0;

void Function::Insert()
{
	Book *p=new Book;
	if(head==NULL)
		head=last=p;
	else
	{
		last->next=p;
		last=p;
	}
	cout<<"成功插入图书信息!"<<endl;
}
void Function::Delete(string BookName)
{
	if(head==NULL)
	{
		cout<<"图书库中没有书!";
	}
	else
	{
		Book *p,*q=NULL;
		for(p=head;p&&(p->BookName!=BookName);q=p,p=p->next);
		if(p==head)
		{
			if(p->next)
			{
				head=p->next;
				p=NULL;
			}
			else 
			{
				head=last=p=NULL;
			}
		}
		else if(last==p)
		{
			last=q;
			last->next=NULL;
		}
		else
		{
			q->next=p->next;
			p=NULL;
		}
		cout<<"成功删除图书信息!";
	}
}
void Function::Select(string BookName)
{
	if(head==NULL)
	{
		cout<<"图书库中没有书!";
	}
	else
	{
		Book *p;
		
		for(p=head;p;p=p->next)
		{
			if(p->BookName==BookName)
			{
				p->show();
				break;
			}
		}
		if(p==NULL)
		{
			cout<<"错误查找!";
		}
	}
}
void Function::Display()
{
	if(head==NULL)
	{
		cout<<"图书库中没有书!";
	}
	else
	{
	    cout<<std::left<< setw(10)<<"书名"<< setw(10)<< "类别"<< setw(10)<< "编号"<< setw(10)<< "价格" << setw(15)<< "出版日期" << setw(15)<< "是否借出？"<<endl;
	    cout<<endl;
		Book *p=head;
		while(p)
		{
			cout<<*p;
			p=p->next;
		}
	}
}
void Function::Write_file()
{
	ofstream file;
	char filename[100];
	cout<<"请输入文件名称:"<<endl;
	cin>>filename;
	file.open(filename,ios::out);
	if(!file)
	{
		cout<<"sorry，无法打开文件!"<<endl;
		abort();
	}
	Book *p;
	file<<std::right<<setw(50)<<"lib systerm!"<<endl;
	file<<std::left<< setw(10)<<"书名"<< setw(10)<< "类别"<< setw(10)<< "编号"<< setw(10)<< "价格" << setw(15)<< "出版日期" << setw(15)<< " 是否借出？"<<endl;
    file<<endl;
	for(p=head;p;p=p->next)
	{
		file<<*p;
	}
	file.close();
}
void Function::Read_file()
{
	ifstream file;
	char filename[100];
	cout<<"请输入你想打开的文件名:"<<endl;
	cin>>filename;
	cout<<endl;
	file.open(filename,ios::in);
		if(!file)
		{
			cout<<"sorry，无法打开文件!"<<endl;
			abort();
		}
		file.getline(filename,100);
                              cout<<endl;
		while(!file.eof())
		{
			Book *p=new Book(1);
			file>>*p;
			if(p->BookName>"0")
			{
				cout<<*p;
			}
			cout<<endl;
		}
		
}
void main()
{
    main_interface();
    choice_control();
}

void main_interface()
{
   cout<<endl;
   cout<<"************欢迎登陆图书管理系统************"<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"          ********  1:创建图书库"<<endl;
   cout<<"          ********  2:新增"<<endl;
   cout<<"          ********  3:删除"<<endl;
   cout<<"          ********  4:查找"<<endl;
   cout<<"          ********  5:显示"<<endl;
   cout<<"          ********  6:写入文件"<<endl;
   cout<<"          ********  7:读出文件"<<endl;
   cout<<"          ********  8:保存更改并退出"<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"************欢迎登陆图书管理系统************"<<endl;
   cout<<endl;
   cout<<"请输入1-8选择你想要的功能："<<endl;
}
void choice_control()
{
   int choice=9;
   string BookName;
   Function *tem=NULL;
   while(choice!=8)
   {
     cout<<"请输入1-8的数字:";
	 cin>>choice;
	 if(choice<0&&choice>9)
	 {
	   cout<<"请输入正确的数字！！"<<endl;
	   cout<<"0~9之间:";
       cin>>choice;
	 }
     else
	 {
	   switch(choice)
	 {
      case 1:                                                             //创建图书库
		  {
			  tem=new Function;
			  cout<<"成功创建图书库！！"<<endl;
			  Function::flag=1;
			  break;
		  }
      case 2:                                                             //新增
		  {
			  if(!Function::flag)
			  {
				  cout<<"Sorry，图书库没有创建成功!!!"<<endl;
				  break;
			  }
			  tem->Insert();
			  break;
		  }
      case 3:                                                              //删除
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry，图书库没有创建成功!!!"<<endl;
			  }
			  else
			  {
				  cout<<"请输入图书库中你想删除的书名:"<<endl;
				  cin>>BookName;
				  tem->Delete(BookName);
			  }
			  break;
		  }
	  case 4:                                                              //查找
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry，图书库没有创建成功!!!"<<endl;
			  }
			  else
			  {
				  cout<<"请输入图书库中你想查找的书名："<<endl;
				  cin>>BookName;
				  tem->Select(BookName);
			  }
			  break;
		  }
      case 5:                                                             //显示
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry，图书库没有创建成功!!!"<<endl;
			  }
			  else
			  {
				  tem->Display();
			  }
			  break;
		  }
	  case 6:                                                              //写入文件
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry，图书库没有创建成功!!!"<<endl;
			  }
			  else
			  {
				  tem->Write_file();
			  }
			  break;
		  }
	  case 7:                                                               //读出文件
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry，图书库没有创建成功!!!"<<endl;
				  tem=new Function;
				  Function::flag=1;
			  }
			  if(tem->head!=NULL)
			  {
				  cout<<"打开文件之前你想保留操作吗？(y/n):"<<endl;
				  char x;
				  cin>>x;
				  if(x=='y')
				  {
					  tem->Write_file();
					  tem->head=NULL;
				  }
			  }
			  tem->Read_file();
			  break;
		  }
       default:break;                                             //保留操作并退出
	   }
	 }
	 
	 
	 main_interface();
  }

  
 }