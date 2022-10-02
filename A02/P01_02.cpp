#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

// Clears the window and draws the torus.
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a white grid "floor" for the torus to sit on.
    // variable r and g is change each color step by step
    glBegin(GL_LINES);
    float r = 1.0f; float g = 0.0f;
    for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
        glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
        glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
        glColor3f(r, g, 1);
        r -= 0.045f;
        g += 0.045f;
    }
    glEnd();

    // Draw the torus which is orange.
    glColor3f(1, (float)165 / 255, 0);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.3f);
    glutWireTorus(0.3, 1, 15, 30);

    glFlush();
}

void init() {
    glClearColor(0.1, 0.39, 0.88, 1.0);
    glColor3f(1.0, 1.0, 1.0);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1.5, 1.5, 1, 40);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -3);
    glRotatef(50, 1, 0, 0);
    glRotatef(70, 0, 1, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("A Simple Torus");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}