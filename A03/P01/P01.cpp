#include <iostream>
#include <GL/glut.h>

GLfloat ctrlPoints[10][3] = {
    {-20, 3, 0}, {-13, -2, 0}, {-7, -12, 0},
    {-4.0, -4.0, 0.0}, {-2.0, 9.0, 0.0},
    {2.0, -14.0, 0.0}, {4.0, 0.0, 0.0},
    {6, 10, 0}, {8, 6, 0}, {10, -6, 0}
};

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30.0, 30.0, -30.0, 30.0, -30, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

float poly(float points[][3], float x, int n) {
    float y;
    float num = 1.0, d = 1.0;
    float sum = 0.0;

    for (int i = 0; i < n; ++i) {
        num = d = 1.0;

        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }

            num = num * (x - points[j][0]);
        }

        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }

            d = d * (points[i][0] - points[j][0]);
        }
        sum += num / d * points[i][1];
    }

    y = sum;

    return y;
}

void display(void) {
    int i;
    float x, y;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);

    for (i = -200; i <= -40; i++) {
        x = (float)i / 10.0;
        y = poly(ctrlPoints, x, 4);
        glVertex2f(x, y);
    }

    for (i = -40; i <= 40; i++) {
        x = (float)i / 10.0;
        y = poly(ctrlPoints, x, 7);
        glVertex2f(x, y);
    }

    for (i = 40; i <= 100; i++) {
        x = (float)i / 10.0;
        y = poly(ctrlPoints, x, 10);
        glVertex2f(x, y);
    }

    glEnd();
    glBegin(GL_LINE_STRIP);

    glEnd();
    glPointSize(5.0);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);

    for (i = 0; i < 10; i++) {
        glVertex3fv(&ctrlPoints[i][0]);
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(500, 300);
    glutCreateWindow("Cubic Spline Curve");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}