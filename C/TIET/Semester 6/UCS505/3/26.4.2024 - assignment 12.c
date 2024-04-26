#include <GL/glut.h>
#include <cmath>

// Function to draw a circle
void drawCircle(float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to display content on the window
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f); // Move the circle away from the viewer
    drawCircle(0.5f, 100); // Draw a circle with radius 0.5 and 100 segments
    glutSwapBuffers();
}

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("Circle Drawing"); // Set window title
    init();
    glutDisplayFunc(display); // Register display function
    glutMainLoop();
    return 0;
}