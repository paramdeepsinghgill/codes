#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>

typedef float Matrix4[4][4];
Matrix4 theMatrix;

static GLfloat input[8][3] =
{
   {40,40,-50 }, { 90,40,-50 }, { 90,90,-50 }, { 40,90,-50 }, { 30,30,0 }, { 80,30,0 }, { 80,80,0 }, { 30,80,0 }
};

float output[8][3];
void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);

	glEnable(GL_DEPTH_TEST);

}

void setIdentityM(Matrix4 m)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m[i][j] = (i == j);
}

void Axes(void)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2s(-1000, 0);
	glVertex2s(1000, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2s(0, -1000);
	glVertex2s(0, 1000);
	glEnd();
}


void draw(float a[8][3]) {
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3fv(a[0]);
	glVertex3fv(a[1]);
	glVertex3fv(a[2]);
	glVertex3fv(a[3]);
	glColor3f(1, 0, 0);
	glVertex3fv(a[0]);
	glVertex3fv(a[1]);
	glVertex3fv(a[5]);
	glVertex3fv(a[4]);
	glColor3f(1, 0, 0);
	glVertex3fv(a[0]);
	glVertex3fv(a[4]);
	glVertex3fv(a[7]);
	glVertex3fv(a[3]);
	glColor3f(1, 0, 0);
	glVertex3fv(a[1]);
	glVertex3fv(a[2]);
	glVertex3fv(a[6]);
	glVertex3fv(a[5]);
	glColor3f(1, 0, 0);
	glVertex3fv(a[2]);
	glVertex3fv(a[3]);
	glVertex3fv(a[7]);
	glVertex3fv(a[6]);
	glColor3f(1, 0, 0);
	glVertex3fv(a[4]);
	glVertex3fv(a[5]);
	glVertex3fv(a[6]);
	glVertex3fv(a[7]);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(a[0]);
	glVertex3fv(a[1]);
	glVertex3fv(a[1]);
	glVertex3fv(a[2]);
	glVertex3fv(a[2]);
	glVertex3fv(a[3]);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex3fv(a[0]);
	glVertex3fv(a[1]);
	glVertex3fv(a[5]);
	glVertex3fv(a[4]);
	glVertex3fv(a[0]);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex3fv(a[0]);
	glVertex3fv(a[4]);
	glVertex3fv(a[7]);
	glVertex3fv(a[3]);
	glVertex3fv(a[0]);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex3fv(a[1]);
	glVertex3fv(a[2]);
	glVertex3fv(a[6]);
	glVertex3fv(a[5]);
	glVertex3fv(a[1]);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex3fv(a[2]);
	glVertex3fv(a[3]);
	glVertex3fv(a[7]);
	glVertex3fv(a[6]);
	glVertex3fv(a[2]);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex3fv(a[4]);
	glVertex3fv(a[5]);
	glVertex3fv(a[6]);
	glVertex3fv(a[7]);
	glVertex3fv(a[4]);
	glEnd();
}

void RotateX(float angle) //Parallel to x
{
	angle = angle * 3.142 / 180;
	theMatrix[1][1] = cos(angle);
	theMatrix[1][2] = sin(angle); 
	theMatrix[2][1] = sin(angle);
	theMatrix[2][2] = cos(angle);
}

void scale(int sx, int sy, int sz)
{
	theMatrix[0][0] = sx;
	theMatrix[1][1] = sy;
	theMatrix[2][2] = sz;
}

void multiplyM()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				output[i][j] = output[i][j] + input[i][k] * theMatrix[k][j];
			}
		}
	}
}
void trans(int tx, int ty, int tz)
{
	for (int i = 0; i < 8; i++)
	{
		output[i][0] = input[i][0] + tx;
		output[i][1] = input[i][1] + ty;
		output[i][2] = input[i][2] + tz;
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Axes();
	glColor3f(1.0, 0.0, 0.0);
	draw(input);
	trans(50, 50, 50);
	scale(1.5, 1.5, 1.5);
	multiplyM();
	draw(output);
	trans(200, 0, 0);
	RotateX(60);
	multiplyM();
	draw(output);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 600); glutInitWindowPosition(0, 0);
	glutCreateWindow("3-D");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	glutInit(&argc, argv);
}