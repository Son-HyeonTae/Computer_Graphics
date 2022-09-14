#include <GL/glut.h>

GLvoid drawScene(GLvoid);

int main(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ���� (���� â | RGBA ���)
	glutInitWindowPosition(100, 100); // �������� ��ġ ����
	glutInitWindowSize(250, 250); // �������� ũ�� ����
	glutInit(&argc, argv); // GLUT ���̺귯�� �ʱ�ȭ
	glutCreateWindow("��ǻ�Ͱ��а� ������"); // ������ ���� (������ �̸�)
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop(); // �̺�Ʈ ó�� ����
}

GLvoid drawScene(GLvoid) {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // �������� 'yellow' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // ���� ������ 'red' �� ����
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); // ��ǥ�� �簢�� �׸���
	glFlush(); // ȭ�鿡 ����ϱ�
}