#define NUM_SUBJECT 3 //科目数
#define INITIAL_SIZE 100 //初始数组大小
#define INCR_SIZE 50   //数组每次增加大小

typedef struct
{
	char Number[20]; //学号
	char Name[20];  //姓名
	char Sex[4];   //性别
	char Class[10];  //班级
	double Score[NUM_SUBJECT]; //成绩
	double Sum;  //总分
	double Average;  //平均分
}StudentInfo;

