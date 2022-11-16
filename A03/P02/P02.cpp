#include <iostream>
#include <GL/glut.h>

GLfloat ctrlPoints[10][3] = {
    {-20, -6, 0}, {-13, 8, 0}, {-7, -12, 0},
    {-4.0, -4.0, 0.0}, {-2.0, 9.0, 0.0},
    {2.0, -14.0, 0.0}, {4.0, 0.0, 0.0},
    {6, 3, 0}, {8, 6, 0}, {10, -6, 0}
};

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30.0, 30.0, -30.0, 30.0, -30, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPointSize(5.0);
    glColor3f(0.8, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 10; i++) {
        glVertex3fv(&ctrlPoints[i][0]);
    }
    glEnd();

    for (int i = 0; i <= 6; i = i + 3) {
        glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlPoints[i][0]);
        glEnable(GL_MAP1_VERTEX_3);

        glColor3f(0.0, 0.8, 0.0);
        glBegin(GL_LINE_STRIP);

        for (int j = 0; j <= 30; j++) {
            glEvalCoord1f((GLfloat)j / 30.0);
        }
        glEnd();
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(500, 300);
    glutCreateWindow("Bezier Curve");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}