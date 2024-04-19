#include <gl/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(10);
	glBegin(GL_LINES);
	// First square.
	glVertex2f(10, 10);
	glVertex2f(10, 50);

	glVertex2f(10, 50);
	glVertex2f(50, 50);

	glVertex2f(50, 50);
	glVertex2f(50, 10);

	glVertex2f(50, 10);
	glVertex2f(10, 10);

	// Second square.
	glVertex2f(20, 20);
	glVertex2f(20, 60);

	glVertex2f(20, 60);
	glVertex2f(60, 60);

	glVertex2f(60, 60);
	glVertex2f(60, 20);

	glVertex2f(60, 20);
	glVertex2f(20, 20);

	// Edges.
	glVertex2f(10, 50);
	glVertex2f(20, 60);

	glVertex2f(60, 60);
	glVertex2f(50, 50);

	glVertex2f(50, 10);
	glVertex2f(60, 20);

	glVertex2f(10, 10);
	glVertex2f(20, 20);

	glEnd();
	glFlush();
}

void myinit() {
	glClearColor(1, 1, 1, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Points");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}