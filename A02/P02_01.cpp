#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>

static bool spinning = true;
static const int FPS = 60;
static GLfloat currentAngleOfRotation = 0.0;

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        glOrtho(-50.0, 50.0, -50.0 / aspect, 50.0 / aspect, -50.0, 50.0);
    }
    else {
        glOrtho(-50.0 * aspect, 50.0 * aspect, -50.0, 50.0, -50.0, 50.0);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(currentAngleOfRotation, 0.0, 0.0, 1.0);

    // make tetrahedron
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f); // color : red

    glVertex3f(0.0f, 20.0f, 0.0f); // point #01
    glVertex3f(-15.0f, -10.0f, 10.0f); // point #02
    glVertex3f(10.0f, -10.0f, 15.0f); // point #03

    glColor3f(1.0f, 1.0f, 0.0f); // color : yellow

    glVertex3f(15.0f, 5.0f, 40.0f); // point #04

    glColor3f(0.0f, 0.0f, 1.0f); // color : blue

    glVertex3f(-15.0f, -10.0f, 10.0f); // point #02

    glColor3f(0.0f, 1.0f, 0.0f); // color : green

    glVertex3f(0.0f, 20.0f, 0.0f); // point #01

    glEnd();

    glFlush();
    glutSwapBuffers();
}

void timer(int v) {
    if (spinning) {
        currentAngleOfRotation += 1.0;
        if (currentAngleOfRotation > 360.0) {
            currentAngleOfRotation -= 360.0;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(1000 / FPS, timer, v);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        spinning = true;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        spinning = false;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Spinning Triangle");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0);
    glutMouseFunc(mouse);
    glutMainLoop();
}