// SGI_STL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include<iostream>
#include <iterator>
#include <deque>
#include <set>
#include <vector>
#include <list>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::flush;

int main(int argc, char* argv[])
{
	std::ostream_iterator<int> out_it(std::cout," ");

	int ia[6] = {0,1,2,3,4,5};

	std::deque<int> id(ia,ia+6);
	std::multiset<int> is(id.begin(),id.end());
	std::vector<int> iv(is.begin(),is.end());
	std::list<int> il(iv.begin(),iv.end());

	std::copy(id.begin(),id.end(),out_it);//�����õ��Ǻ����ĸ�ֵ��������Ҳ����˵���е����������������ʹ�á�
	cout<<endl;

	std::insert_iterator<std::multiset<int> > is_it(is,is.begin());//C++11��׼�ı���������ȷʶ�𣬶������ǽ���Ϊ��λ������
	//std::insert_iterator<std::multiset<int>> is_it(is,is.end()); ����ʲôλ�ã�setϵ�е�������ʹ�ú����ʵ�֣���������ġ�����ֻҪ��insert����������������

	//ǰ�����
	std::copy(id.begin(),id.end(),is_it);
	std::copy(is.begin(),is.end(),out_it);//�����õ��Ǻ����ĸ�ֵ��������Ҳ����˵���е����������������ʹ�á�
	cout<<endl;
	
	is.insert(10);
	std::insert_iterator<std::vector<int> > iv_it(iv,iv.begin());//��Զ��vector���Ԫ��0��ǰ��������ݣ���Ϊ��һ������ֱ�߸տ�ʼ��ֵ��begin�������Ƕ�̬begin���ڲ���֮��insert_iterator��ִ��++����ִ��0��
	std::copy(is.begin(),is.end(),iv_it);//copy��ʼ���ø�ֵ����
	std::copy(iv.begin(),iv.end(),out_it);
	cout<<endl;
	
#ifdef WIN32
	std::front_insert_iterator<decltype(il)> il_it(il); //��Զ����push_frontȥִ�в��룬û��λ�����ƣ��γ��˵������
#else
	std::front_insert_iterator<std::list<int> > il_it(il); //��Զ����push_frontȥִ�в��룬û��λ�����ƣ��γ��˵������
#endif
	std::copy(is.begin(),is.end(),il_it);
	std::copy(il.begin(),il.end(),out_it);
	cout<<endl;
	
	//����ʽ. 5 = 0+6-1,4,3,2,1,0.���������ĵ�������Ч������ǰ��һ�����Ǵ�id.end-1��ʼ�ݼ�ֵbegin�����ݶ�ȥ����iv.offet-1��iv.begin�����ݶ�
	//�����������һ���������ݵĸ��ǣ�����ʹ��reserve_iterator��
	//std::copy_backward(id.rbegin(),id.rend(),iv.begin()+id.size());//copy_backwardָ����target iteratorʹ��backward,����insert reserved.��Ӧ����Ҫ����һ�¡�
	std::copy(id.rbegin(),id.rend(),iv.begin());//++��--,����iv�ǲ��仯��
	std::copy(iv.begin(),iv.end(),out_it);
	cout<<endl;

	std::istream_iterator<int> in_it(cin),eos;//�����и�bug������Ҫ�ö��߳̽�����������߳�������д���ȴ���������ж���λ��vs_stl���ṩ�л�������MS��STL��insert_iterator����������ȡ���ݵĲ��������߳̽��ж϶�ȡ�����С���ᵼ��һ�����ص�bug��������ĳ��IO����ʱ��ǰ��������ݲ�����������ܲ������������ġ�


	cout<<"less(3,13):"<<std::less<int>()(3,13)<<endl;//�����������󼴳�ʼ�����ٵ���

	while (!(in_it==eos))
	{
		cout<<*in_it;
		cout<<endl;
		++in_it;
	}


	return 0;
}

