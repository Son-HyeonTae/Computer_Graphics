#include <GL/glut.h>
#include <iostream>
#include <windows.h>
#include <math.h>

GLfloat ctrlpoints[4][4][3] = {
    { {0,0 ,-1 }, {-0.5,0.24 ,-0.87 }, {-0.87,0.24 , -0.5}, {-1, 0, 0}},
    { {0.5,0.24 ,-0.87 },{0,0.33 ,-0.19 },{-0.19,0.33 ,0 }, {-0.87, 0.24, 0.5}},
    { {0.87,0.24 ,-0.5 }, {0.19, 0.33, 0},{0, 0.33,0.19 }, {-0.5,0.24 ,0.87 }},
    { {1,0 ,0 }, {0.87, 0.24,0.5 },{0.5, 0.24,0.87}, {0,0 ,1 }}
};

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(30, 1.0, 0.0, 0.0);
    glRotatef(-7, 0.0, 1.0, 0.0);
    glEvalMesh2(GL_LINE, 0, 3, 0, 3);
    glPopMatrix();
    glFlush();
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(500, 300);
    glutCreateWindow("Bezier Surface");
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glMapGrid2f(3.0, 0.0, 1.1, 3.0, 0.0, 1.1);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
}