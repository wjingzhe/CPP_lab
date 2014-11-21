#ifndef _H_LETTER_H_A
#define _H_LETTER_H_A

#include<iostream>
using namespace std;
#include<stdlib.h>
#include<ctype.h>
#include<string>
#include<iomanip>

#define ASK(p) do{\
	p = (STUD *)malloc(sizeof(STUD));\
	if(p==NULL) {cout<<"memory fail";exit(-1);}\
}while(0);

#define LEN sizeof(STUD)
#define NUM_SUBJECT 3

extern int count;//����ȫ�ּ�¼��������
extern int savedTag;//��¼�Ƿ��ѱ��������
static char cchar;//�������������
extern char tempStr[20];//������ѧ��
extern char fname[20];//�ļ���
extern char tempFile[20];//Ĭ���ļ���

typedef struct studentscore{
	char number[20]; //ѧ��
	char name[20];   //����
	char sex[4];     //�Ա�
	int classno;  //�༶
	double score[NUM_SUBJECT];  //�ɼ�
	double sum; // �ܷ�
	double average;  //ƽ����
	struct studentscore *next;
}STUD;

STUD *input(STUD *top);//�����¼�¼

void display(STUD *top);
/*
*��ʾ��Ϣ����
*����top����ǰ�༶��¼����ı�ͷ
*/
void save(STUD *top);
STUD *load();
int menu_select();
void handle_menu(STUD *top);
STUD *delete_record(STUD *top);
void free_nodes(STUD *top);
void find_record(STUD*top);

void swap_record(STUD*,STUD*t);/*����������¼*/

void sort_record(STUD*top);
/*
*��¼�������������
*����top����ǰ�༶��¼����ı�ͷ
*/

STUD *new_addclass(STUD* top);
/************************************
*�½��༶
*����top����ǰ�༶ѧ����Ϣ����ı�ͷ
*�����½��༶��ѧ����Ϣ����ı�ͷ
*************************************/
void quit(STUD *top);

#endif