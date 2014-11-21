#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int value[]={ 3, 7, 0, 5, 4 };
	ofstream os("intergers",ios_base::out|ios_base::binary);
	os.write(reinterpret_cast<char*>(&value),sizeof(value));
	os.close();

	ifstream is("intergers",ios_base::in|ios_base::binary);
	if(is)
	{
		is.seekg(3*sizeof(int));
		int v;
		is.read(reinterpret_cast<char*>(&v),sizeof(int));
		cout<<"The 4th integer in the file 'intergers' is "<<v<<endl;
	}
	else
	{
		cout<<"ERROR:Cancot open the file."<<endl;
	}
	return 0;
}