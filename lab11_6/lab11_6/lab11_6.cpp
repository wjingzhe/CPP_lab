// lab11_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#include<fstream>
#include<iostream>
using namespace std;

class dog
{
public:
	dog(int weight,long days):itsWeight(weight),itsNumberAlive(days){};
	~dog(){};

	int getWeight()const{return itsWeight;}
	int setWeight(int weight){itsWeight=weight;}

	long getDaysAlive()const{return itsNumberAlive;}
	long setDaysAlive(long days){itsNumberAlive=days;}

private:
	long itsNumberAlive;
	int itsWeight;
};

int main()//returns 1 on error
{
	char fileName[80];

	cout<<"Please enter the filename:";
	cin>>fileName;
	ofstream fout(fileName);
	if(!fout)
	{
		cout<<"Unable to open "<<fileName<<" for writing.";
		return 1;
	}

	dog Dog1(5,10);
	fout.write((char *)&Dog1,sizeof(Dog1));
	fout.close();
	
	
	dog Dog2(2,2);

	cout<<"Dog2 weight: "<<Dog2.getWeight()<<endl;
	cout<<"Dog2 days: "<<Dog2.getDaysAlive()<<endl;

	ifstream fin(fileName);
	if(!fin)
	{
		cout<<"Unable to open "<<fileName<<" for reading.";
		return 1;
	}

	fin.read((char*)&Dog2,sizeof(Dog2));

	cout<<"Dog2 weight: "<<Dog2.getWeight()<<endl;
	cout<<"Dog2 days: "<<Dog2.getDaysAlive()<<endl;
	fin.close();

	
	return 0;

}
