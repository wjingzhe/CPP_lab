// TestTrangle.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"

#include <iostream>
#include <GL/vgl.h>
#include <GL/LoadShaders.h>
using namespace std;

enum VAO_IDs { Triangles=0, NumVAOs};
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint NumVertices = 6;
//---------------------------------------------------------------------Your First Look at an OpenGL Program 5
//
// init
//

void init(void)
{
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);
	GLfloat vertices[NumVertices][2] = {
	{ -0.90, -0.90 }, // Triangle 1
	{ 0.85, -0.90 },
	{ -0.90, 0.85 },
	{ 0.90, -0.85 }, // Triangle 2
	{ 0.90, 0.90 },
	{ -0.85, 0.90 }
	};
	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
	vertices, GL_STATIC_DRAW);
	ShaderInfo shaders[] = {
	{ GL_VERTEX_SHADER, "triangles.vert" },
	{ GL_FRAGMENT_SHADER, "triangles.frag" },
	{ GL_NONE, NULL }
	};
	GLuint program = LoadShaders(shaders);
	glUseProgram(program);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
	GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
}
//---------------------------------------------------------------------
//
// display
//
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	glFlush();
}
//---------------------------------------------------------------------6 Chapter 1: Introduction to OpenGL
//
// main
//
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutInitContextVersion(3,1);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);
	if (glewInit()) 
	{
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(EXIT_FAILURE);
	}
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}


