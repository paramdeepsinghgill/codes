#include<gl/glut.h>
#include<math.h>

float boncolor[] = { 0, 0, 0 };
float fillcol[] = { 0, 0, 1 };
//color of boundary
//color to be filled
void draw_poly() {
	glLineWidth(1);
	glPointSize(1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(boncolor);
	glBegin(GL_LINE_LOOP);
	glVertex2i(150, 100);
	glVertex2i(200, 100);
	glVertex2i(150, 150);
	glEnd();
	glFlush();
}
void boundaryfill(int x, int y, float* fillcol, float* boncolor) {
	float color[3];
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
	if ((color[0] != boncolor[0] || color[1] != boncolor[1] || color[2] != boncolor[2]) && (color[0] != fillcol[0] || color[1] != fillcol[1] || color[2] != fillcol[2])) {
		glColor3f(fillcol[0], fillcol[1], fillcol[2]);
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		glFlush();
		boundaryfill(x + 1, y, fillcol, boncolor);
		boundaryfill(x - 1, y, fillcol, boncolor);
		boundaryfill(x, y + 1, fillcol, boncolor);
		boundaryfill(x, y - 1, fillcol, boncolor);
	}
}
void init() {
	glClearColor(1, 1, 1, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 600, 0, 500);
}
void mouse(int btn, int state, int x, int y) {
	y = 500 - y;
	if (btn == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			boundaryfill(x, y, fillcol, boncolor);
		}
	}
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Boundary Fill 4 connected");
	glutDisplayFunc(draw_poly);
	glutDisplayFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}