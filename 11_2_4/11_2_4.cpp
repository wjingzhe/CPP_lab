#include<fstream>
using namespace std;
int array[2]={ 99, 10};
int main()
{
	ofstream os("test.dat",ios_base::out|ios_base::binary);
	os.write(reinterpret_cast<char*>(array),sizeof(array));
	return 0;
}