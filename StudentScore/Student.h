#define NUM_SUBJECT 3 //��Ŀ��
#define INITIAL_SIZE 100 //��ʼ�����С
#define INCR_SIZE 50   //����ÿ�����Ӵ�С

typedef struct
{
	char Number[20]; //ѧ��
	char Name[20];  //����
	char Sex[4];   //�Ա�
	char Class[10];  //�༶
	double Score[NUM_SUBJECT]; //�ɼ�
	double Sum;  //�ܷ�
	double Average;  //ƽ����
}StudentInfo;

