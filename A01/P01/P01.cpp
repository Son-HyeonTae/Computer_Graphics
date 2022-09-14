#include <GL/glut.h>

void Display() {
	glClear(GL_COLOR_BUFFER_BIT); // ���ۿ� ������ ������ ��ü�� ĥ�ϱ� (�ʱⰪ : Black)
	glBegin(GL_POLYGON); // ������ ����(Vertex) ���� ����
	// �Ű����� : ��� ��
	//           �� GL_POLYGON : ����� ��� �ٰ���
	glVertex3f(-0.5, -0.5, 0.0); // ��ǥ ���� 0
	glVertex3f(0.5, -0.5, 0.0); // ��ǥ ���� 1
	glVertex3f(0.5, 0.5, 0.0); // ��ǥ ���� 2
	glVertex3f(-0.5, 0.5, 0.0); // ��ǥ ���� 3
	glEnd(); // ������ ���� ���� ����
	glFlush(); // ������ ���ۿ� ������ ����
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv); // GLUT ���̺귯�� �ʱ�ȭ
	glutCreateWindow("Hello World!"); // ������ ���� (������ �̸� : Hello World!)
	glutDisplayFunc(Display); // ��� �Լ��� ����
	glutMainLoop(); // �̺�Ʈ ó�� ����
	return 0; // main �Լ� return
}
