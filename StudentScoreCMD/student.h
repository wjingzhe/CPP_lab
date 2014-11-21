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

extern int count;//声明全局记录计数变量
extern int savedTag;//记录是否已保存过数据
static char cchar;//保存操作控制量
extern char tempStr[20];//姓名或学号
extern char fname[20];//文件名
extern char tempFile[20];//默认文件名

typedef struct studentscore{
	char number[20]; //学号
	char name[20];   //姓名
	char sex[4];     //性别
	int classno;  //班级
	double score[NUM_SUBJECT];  //成绩
	double sum; // 总分
	double average;  //平均分
	struct studentscore *next;
}STUD;

STUD *input(STUD *top);//插入新记录

void display(STUD *top);
/*
*显示信息函数
*参数top：当前班级记录链表的表头
*/
void save(STUD *top);
STUD *load();
int menu_select();
void handle_menu(STUD *top);
STUD *delete_record(STUD *top);
void free_nodes(STUD *top);
void find_record(STUD*top);

void swap_record(STUD*,STUD*t);/*交换两个记录*/

void sort_record(STUD*top);
/*
*记录的排序操作函数
*参数top：当前班级记录链表的表头
*/

STUD *new_addclass(STUD* top);
/************************************
*新建班级
*参数top：当前班级学生信息链表的表头
*返回新建班级的学生信息链表的表头
*************************************/
void quit(STUD *top);

#endif