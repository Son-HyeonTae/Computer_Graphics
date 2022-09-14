#include <GL/glut.h>

GLvoid drawScene(GLvoid);

int main(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ���� (���� â | RGBA ���)
	glutInitWindowPosition(150, 150); // �������� ��ġ ����
	glutInitWindowSize(500, 500); // �������� ũ�� ����
	glutInit(&argc, argv); // GLUT ���̺귯�� �ʱ�ȭ
	glutCreateWindow("��ǻ�Ͱ��а� ������"); // ������ ���� (������ �̸�)
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop(); // �̺�Ʈ ó�� ����
}

GLvoid drawScene(GLvoid) {
	glColor4f(58.8f / 255.0f, 29.4f / 255.0f, 0.0f, 1.0f); // ���� : ����
	glTranslatef(0.5f, 0.0f, 0.0f); // ��ġ ����
	glRotatef(60.0f, 0.0f, 1.0f, 0.0f); // ȸ�� : Y��
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // ȸ�� : Z��
	glutWireTorus(0.1, 0.3, 30, 30); // ��ν� ����

	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // ���� : �����
	glTranslatef(-0.3f, 1.0f, 0.0f); // ��ġ ����
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // ȸ�� : Y��
	glRotatef(10.0f, 0.0f, 0.0f, 1.0f); // ȸ�� : Z��
	glutWireTeapot(0.25); // ������ ����

	glColor4f(128.0f / 255.0f, 0.0f / 255.0f, 32.0f / 255.0f, 1.0f); // ���� : ���ǵ�
	glTranslatef(0.5f, -1.0f, 0.0f); // ��ġ ����
	glutWireSphere(0.25, 20, 20); // �� ����

	glColor4f(155.0f / 255.0f, 228.0f / 255.0f, 102.0f / 255.0f, 1.0f); // ���� : �丮��Ʈ �׸�
	glTranslatef(0.3f, 0.7f, 0.0f); // ��ġ ����
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f); //ȸ�� : Y��
	glutWireCone(0.3, 0.5, 15, 15); // ���� ����

	glFlush(); // ȭ�鿡 ����ϱ�
}