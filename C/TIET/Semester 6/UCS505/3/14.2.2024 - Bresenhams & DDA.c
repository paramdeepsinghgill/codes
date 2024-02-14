#include<gl/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	float x1 = 20;
	float x2 = 120;
	float y1 = 30;
	float y2 = 50;
	float d1 = x2 - x1;
	float d2 = y2 - y1;
	
	glBegin(GL_POINTS);
	//breshnhamm
	float x = x1;
	float y = y1;
	float p = 2 * d2 - d1;
	while (x != x2) {
		if (p < 0) {
			x = x + 1;
			p = p + 2 * d2;
		}
		else {
			x = x + 1;
			y = y + 1;
			p = p + 2 * d2 - 2 * d1;
		}
		glVertex2f(x, y);
	}
	//dda
	float steps = 1;
	if (d1 > d2) {
		steps = d1;
	}
	else {
		steps = d2;
	}
	float xi = d1 / steps;
	float yi = d2 / steps;
	glColor3f(1, 0, 0);
	x1 = 43;
	x2 = 300;
	y1 = 30;
	y2 = 300;
	x = x1;
	y = y1;
	while (x < x2) {
		x = x + xi;
		y = y+yi;
		
		glVertex2f(x, y);
	}
	//glVertex2f(10.0, 10.0);
	//glVertex2f(150.0, 10.0);
	//glVertex2f(150.0, 10.0);
	//glVertex2f(150.0, 80.0);
	//glVertex2f(150.0, 80.0);
	///glVertex2f(10, 80);
	//glVertex2f(10, 80);
	//glVertex2f(10.0, 10.0);
	glEnd();
	glFlush();
	//glColor3f(0.0, 1.0, 0.0);
	//glBegin(GL_LINES);
	//glVertex2f(70.0, 70.0);
	//glVertex2f(100.0, 100.0);
	//glVertex2f(100.0, 100.0);
	//glVertex2f(150.0, 80.0);
	//glVertex2f(150.0, 80.0);
	//glVertex2f(70, 70);
	//glEnd();
	//glFlush();
}

void myinit() {
	glClearColor(255.0, 255.0, 255.0, 1.0); //red
	glColor3f(255.0, 255.0, 255.0);
	glPointSize(10.0);
	glLineWidth(5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}