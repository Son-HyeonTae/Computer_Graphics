#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <cmath>

void myWireSphere(GLfloat radius, int slices, int stacks) {
    glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glutSolidSphere(radius, slices, stacks);
    glPopMatrix();
}

static int year = 0, day = 0;

void drawPlanet(float distance, float size, int speed) {
    glPushMatrix();
    glRotatef((GLfloat)year * speed, 0.0, 1.0, 0.0);
    glTranslatef(distance, 0.0, 0.0);
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    myWireSphere(size, 15, 15);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0, -(size + 0.1), 0);
    glVertex3f(0,   size + 0.1, 0);
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    // Draw the Sun
    glColor3f(1.0, 1.0, 0.0);
    myWireSphere(1.0, 15, 15);

    // Draw planet : Mercury
    glColor3f(0.2, 0.2, 0.2);
    drawPlanet(1.5, 0.07, 4.2);

    // Draw planet : Venus
    glColor3f(0.7, 0.3, 0.1);
    drawPlanet(2.0, 0.2, 3.0);

    // Draw planet : Earth
    glColor3f(0, 0, 1);
    drawPlanet(4.0, 0.2, 2.7);

    // Draw planet : Mars
    glColor3f(1.0, 1.0, 0.0);
    drawPlanet(9.0, 0.1, 1.8);
     
    // Draw planet : Jupiter
    glColor3f(6.0, 0.4, 0.0);
    drawPlanet(13.0, 3.0, 3.8);
     
    // Draw planet : Saturn
    glColor3f(1.0, 0.7, 0.0);
    glPushMatrix();
    glRotatef((GLfloat)year * 2.5, 0.0, 1.0, 0.0);
    glTranslatef(18, 0.0, 0.0);
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    myWireSphere(2.5, 15, 15);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0, -(2.8 + 0.1), 0);
    glVertex3f(0,   2.8 + 0.1, 0);
    glEnd();
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.7, 0.0);
    glutWireTorus(0.2, 4, 60, 60);
    glPopMatrix();
    
    // Draw planet : Uranus
    glColor3f(0.0, 0.0, 0.8);
    drawPlanet(22.0, 0.8, 3.0);
     
    // Draw planet : Neptune
    glColor3f(0.0, 0.0, 1.0);
    drawPlanet(25.0, 1.0, 1);
    
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

static GLfloat u = 0.0;
static GLfloat du = 0.1;

void timer(int v) {
    u += du;
    day = (day + 1) % 360;
    year = (year + 2) % 360;
    glLoadIdentity();
    gluLookAt(20 * cos(u / 8.0) + 12, 5 * sin(u / 8.0) + 1, 10 * cos(u / 8.0) + 2, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, v);
}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 80.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("On a Comet");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(100, timer, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}