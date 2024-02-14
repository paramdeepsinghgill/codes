#include<gl/glut.h>
#include<math.h>
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.2, 0.3, 0.0);
	float x1 = 20;
	float x2 = 120;
	float y1 = 30;
	float y2 = 50;

	float dx = x2 - x1;
	float dy = y2 - y1;

	float p = (2 * dy) - dx;
	glBegin(GL_POINTS);
	float x = x1;
	float y = y1;
	int i = 0;
	while (x < x2) {
		glVertex2f(x, y);
		if (p < 0) {
			x = x + 1;
			p = p + 2 * dy;
		}
		else {
			x = x + 1;
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
	}
	glEnd();
	glFlush();
}
void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("bresenhams");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}