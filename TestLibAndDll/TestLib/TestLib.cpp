// jingzGLDemo.cpp : 定义控制台应用程序的入口点。
//
//在敬哲的C盘中有该路径。
#pragma comment(lib,"freeglut/freeglut.lib")
#include<GL/freeglut.h>


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);

	glBegin(GL_POLYGON);
		glVertex3f(0.25,0.25,0.0);
		glVertex3f(0.75,0.25,0.0);
		glVertex3f(0.75,0.75,0.0);
		glVertex3f(0.25,0.75,0.0);
	glEnd();
	glFlush();
}


void init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//投影
	glMatrixMode(GL_PROJECTION);
	//初始化为标准矩阵
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);

}



int main(int argc, char* argv[])
{
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(250,250);

	glutInitWindowPosition(100,100);

	glutCreateWindow("Hello GL");

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;

}

