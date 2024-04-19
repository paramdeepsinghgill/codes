#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
typedef float Matrix4[4][4];
Matrix4 theMatrix;
static GLfloat input[8][3] =
{
    {40, 40, -50}, {90,40,-50}, {90,90,-50},{40,90,-50}, {30,30,0}, {80,30,0}, {80,80,0}, {30,80,0}
};
float output[8][3];
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
    glEnable(GL_DEPTH_TEST);
}
void setIdentity(MAtrix4 m)
{
    for (int i = 0; i<4; i++)
    for (int j = 0;j<4;j++)
    m[i][j] = (i==j);
}
void Axes(void){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2s(-1000, 0);
    glVertex2s(1000,0);
    glEnd();
    glBegin(GL_LINES);
    glVErtex2x(0, -1000);
    glVertex2s(0, 1000);
    glEnd();
}
void draw(float a[8][3])
{
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    flVertex3fv(a[0]);
    flVertex3fv(a[1]);
    flVertex3fv(a[2]);
    flVertex3fv(a[3]);
    glColor3f(1,0,0);
    flVertex3fv(a[0]);
    flVertex3fv(a[1]);
    flVertex3fv(a[5]);
    flVertex3fv(a[4]);
    glColor3f(1,0,0);
    flVertex3fv(a[0]);
    flVertex3fv(a[4]);
    flVertex3fv(a[7]);
    flVertex3fv(a[3]);
    glColor3f(1,0,0);
    flVertex3fv(a[1]);
}