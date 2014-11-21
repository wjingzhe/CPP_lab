// lab11_9_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include<iostream>
#include<fstream>
using namespace std;

void main() {
	ofstream file;
	file.open("input.txt");
	file<<"aaaaaaaa\nbbbbbbbb\ncccccccc";
	file.close();

	ifstream filei("input.txt");
	ofstream fileo;
	fileo.open("output.txt");

	char c;
	filei>>noskipws;
	int i=1;
	fileo<<i<<".";
	cout<<i<<".";
	while(filei>>c) {
		if(c=='\n') {
			i++;
			fileo<<"\n";
			cout<<"\n";
			fileo<<i<<".";
			cout<<i<<".";
		} else {
			fileo<<c;
			cout<<c;
		}
	}
	filei.close();
	fileo.close();
}