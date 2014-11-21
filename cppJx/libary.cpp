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
   cout<<" ������";
   cin>>BookName;
   cout<<" ���";
   cin>>BookClass;
   cout<<" ͼ���ţ�";
   cin>>BookID;
   cout<<" ͼ��۸�";
   cin>>BookPrice;
   cout<<" ��������";
   cin>>BookPublishdate;
   cout<<" �Ƿ�������1Ϊ�����0Ϊδ�裩";
   cin>>Lending;
   next=NULL;
}
void Book::show()
{
   cout<<setw(10)<<"����"<< setw(10)<<"���"<< setw(10)<< "���"<< setw(10)<<"�۸�" << setw(15)<< "��������" << setw(15)<< " �Ƿ�����"<<endl;
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
	cout<<"�ɹ�����ͼ����Ϣ!"<<endl;
}
void Function::Delete(string BookName)
{
	if(head==NULL)
	{
		cout<<"ͼ�����û����!";
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
		cout<<"�ɹ�ɾ��ͼ����Ϣ!";
	}
}
void Function::Select(string BookName)
{
	if(head==NULL)
	{
		cout<<"ͼ�����û����!";
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
			cout<<"�������!";
		}
	}
}
void Function::Display()
{
	if(head==NULL)
	{
		cout<<"ͼ�����û����!";
	}
	else
	{
	    cout<<std::left<< setw(10)<<"����"<< setw(10)<< "���"<< setw(10)<< "���"<< setw(10)<< "�۸�" << setw(15)<< "��������" << setw(15)<< "�Ƿ�����"<<endl;
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
	cout<<"�������ļ�����:"<<endl;
	cin>>filename;
	file.open(filename,ios::out);
	if(!file)
	{
		cout<<"sorry���޷����ļ�!"<<endl;
		abort();
	}
	Book *p;
	file<<std::right<<setw(50)<<"lib systerm!"<<endl;
	file<<std::left<< setw(10)<<"����"<< setw(10)<< "���"<< setw(10)<< "���"<< setw(10)<< "�۸�" << setw(15)<< "��������" << setw(15)<< " �Ƿ�����"<<endl;
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
	cout<<"����������򿪵��ļ���:"<<endl;
	cin>>filename;
	cout<<endl;
	file.open(filename,ios::in);
		if(!file)
		{
			cout<<"sorry���޷����ļ�!"<<endl;
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
   cout<<"************��ӭ��½ͼ�����ϵͳ************"<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"          ********  1:����ͼ���"<<endl;
   cout<<"          ********  2:����"<<endl;
   cout<<"          ********  3:ɾ��"<<endl;
   cout<<"          ********  4:����"<<endl;
   cout<<"          ********  5:��ʾ"<<endl;
   cout<<"          ********  6:д���ļ�"<<endl;
   cout<<"          ********  7:�����ļ�"<<endl;
   cout<<"          ********  8:������Ĳ��˳�"<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"************��ӭ��½ͼ�����ϵͳ************"<<endl;
   cout<<endl;
   cout<<"������1-8ѡ������Ҫ�Ĺ��ܣ�"<<endl;
}
void choice_control()
{
   int choice=9;
   string BookName;
   Function *tem=NULL;
   while(choice!=8)
   {
     cout<<"������1-8������:";
	 cin>>choice;
	 if(choice<0&&choice>9)
	 {
	   cout<<"��������ȷ�����֣���"<<endl;
	   cout<<"0~9֮��:";
       cin>>choice;
	 }
     else
	 {
	   switch(choice)
	 {
      case 1:                                                             //����ͼ���
		  {
			  tem=new Function;
			  cout<<"�ɹ�����ͼ��⣡��"<<endl;
			  Function::flag=1;
			  break;
		  }
      case 2:                                                             //����
		  {
			  if(!Function::flag)
			  {
				  cout<<"Sorry��ͼ���û�д����ɹ�!!!"<<endl;
				  break;
			  }
			  tem->Insert();
			  break;
		  }
      case 3:                                                              //ɾ��
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry��ͼ���û�д����ɹ�!!!"<<endl;
			  }
			  else
			  {
				  cout<<"������ͼ���������ɾ��������:"<<endl;
				  cin>>BookName;
				  tem->Delete(BookName);
			  }
			  break;
		  }
	  case 4:                                                              //����
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry��ͼ���û�д����ɹ�!!!"<<endl;
			  }
			  else
			  {
				  cout<<"������ͼ�����������ҵ�������"<<endl;
				  cin>>BookName;
				  tem->Select(BookName);
			  }
			  break;
		  }
      case 5:                                                             //��ʾ
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry��ͼ���û�д����ɹ�!!!"<<endl;
			  }
			  else
			  {
				  tem->Display();
			  }
			  break;
		  }
	  case 6:                                                              //д���ļ�
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry��ͼ���û�д����ɹ�!!!"<<endl;
			  }
			  else
			  {
				  tem->Write_file();
			  }
			  break;
		  }
	  case 7:                                                               //�����ļ�
		  {
			  if(!Function::flag)
			  {
				  cout<<" Sorry��ͼ���û�д����ɹ�!!!"<<endl;
				  tem=new Function;
				  Function::flag=1;
			  }
			  if(tem->head!=NULL)
			  {
				  cout<<"���ļ�֮ǰ���뱣��������(y/n):"<<endl;
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
       default:break;                                             //�����������˳�
	   }
	 }
	 
	 
	 main_interface();
  }

  
 }