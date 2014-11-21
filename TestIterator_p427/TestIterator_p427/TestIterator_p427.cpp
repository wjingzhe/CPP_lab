// TestIterator_p427.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iterator>
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <fstream>
#include <cassert>

template<typename IN>
void display(const IN &t_deque,std::ostream_iterator<int> &out_it)
{
	std::copy(t_deque.begin(),t_deque.end(),out_it);//ʹ��copyʵ�������3th parameter ���

	//*out_it = 3;
	std::cout<<std::endl;//ˢ��һ�����������
}

//Ϊʲô�Ҳ�std�����������Ϊÿ����������ڵ�ͷ�ļ��ұ���Ҫ�ر����������������ϵͳ�ļ����书��,ȷ�ϵ�ʱ������ų�ƴд����
int _tmain(int argc, _TCHAR* argv[])
{
	std::ostream_iterator<int> out_it(std::cout," ");//" "����ո��׺����������int������

	int ia[] = {0,1,2,3,4,5,6,7};

	std::deque<int> t_deque(ia,ia+8);

	display(t_deque,out_it);


	std::copy(ia+1,ia+2,std::front_inserter(t_deque));//��������������ķ�Χ������1��������t_deque��ǰ��,ע�⣬ֻ��sequence container����push_front������Ҫȷ�ϴ�����ȷ��

	display(t_deque,out_it);


	//��ʱ���Ǳ������Ƿ��ڱ���������������ͣ�������һ��
	//std::map<int,int> t_a();��̬���Ͳ�ͨ�������ܸ�effective stl 6 ���ᵽ�ķ��������йأ�����
	std::map<int,int> t_a;

	for (int i = 0; i < 5; ++i)
	{
		t_a.insert(std::pair<int,int>(i,i));
	};

	std::map<int,int>t_b;//��������ɾ���C4930,Ȼ���޷�ʹ�ö�̬��ʾ

	//std::copy(t_a.begin(),t_a.end(),std::front_inserter(t_b)); ��Ȼ���������error C2039: ��push_front��: ���ǡ�std::map<_Kty,_Ty>���ĳ�Ա


	std::copy(ia+4,ia+5,std::back_inserter(t_deque));//����������4�� 
	display(t_deque,out_it);


	{	
		auto it = std::find(t_deque.begin(),t_deque.end(),5);

		if (it==t_deque.end())
		{
			assert("the num isn't in !! why?");
		}


		std::copy(ia+0,ia+3,std::inserter(t_deque,it));//��5֮ǰ����0,1,2.֮��it�����ã�ʹ�������ռ䣬�����Ӳ������Ұָ��
	}

	display(t_deque,out_it);

	std::copy(t_deque.rbegin(),t_deque.rend(),out_it);//rbegin��end()-1,rend()����begin()-1��stl����תʱ��������˼ά����ת
	std::cout<<std::endl;

	std::fstream in_file("data.txt");
	if (in_file.bad())
	{
		assert("cann't open data.txt");
	}

	/*int temp ;
	in_file>>temp;

	std::cout<<temp<<std::endl;*/

	std::istream_iterator<int> in_it(in_file),eos;  // ����istream_iteratorʱ��Ϊ��ָ��istream��������������end-of-file(�ļ�β)��

	std::copy(in_it,eos,std::inserter(t_deque,t_deque.begin()));

	display(t_deque,out_it);

	in_file.close();

	return 0;
}

