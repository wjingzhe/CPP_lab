#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream file("intergers",ios_base::in|ios_base::binary);
	if(file)
	{
		while(file) 
		{
			streampos here=file.tellg();
			int v;
			file.read(reinterpret_cast<char*>(&v),sizeof(int));
			if(v==0&&file)
				cout<<"Position "<<here<<" is 0"<<endl;
		}

	}
	else
	{
		cout<<"ERROR:Cannot open the file."<<endl;
	}
	return 0;

}