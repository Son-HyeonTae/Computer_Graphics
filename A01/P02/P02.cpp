#include <GL/glut.h> /* includes gl.h glu.h */

GLvoid drawScene(GLvoid); // �Լ� ����

int main(int argc, char* argv[]) {
	// �ʱ�ȭ �Լ���
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ���� (���� â | RGBA ���)
	glutInitWindowPosition(100, 100); // �������� ��ġ ����
	glutInitWindowSize(250, 250); // �������� ũ�� ����
	glutInit(&argc, argv); // GLUT ���̺귯�� �ʱ�ȭ
	glutCreateWindow("��ǻ�Ͱ��а� ������"); // ������ ���� (������ �̸�)
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop(); // �̺�Ʈ ó�� ����
}

GLvoid drawScene(GLvoid) {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glFlush(); // ������ ���ۿ� ������ ����
}