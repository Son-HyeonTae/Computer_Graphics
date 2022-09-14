#include <GL/glut.h>

GLvoid drawScene(GLvoid);

int main(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정 (단일 창 | RGBA 모드)
	glutInitWindowPosition(150, 150); // 윈도우의 위치 지정
	glutInitWindowSize(500, 500); // 윈도우의 크기 지정
	glutInit(&argc, argv); // GLUT 라이브러리 초기화
	glutCreateWindow("컴퓨터과학과 손현태"); // 윈도우 생성 (윈도우 이름)
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutMainLoop(); // 이벤트 처리 루프
}

GLvoid drawScene(GLvoid) {
	glColor4f(58.8f / 255.0f, 29.4f / 255.0f, 0.0f, 1.0f); // 색상 : 갈색
	glTranslatef(0.5f, 0.0f, 0.0f); // 위치 조정
	glRotatef(60.0f, 0.0f, 1.0f, 0.0f); // 회전 : Y축
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // 회전 : Z축
	glutWireTorus(0.1, 0.3, 30, 30); // 토로스 생성

	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // 색상 : 노란색
	glTranslatef(-0.3f, 1.0f, 0.0f); // 위치 조정
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // 회전 : Y축
	glRotatef(10.0f, 0.0f, 0.0f, 1.0f); // 회전 : Z축
	glutWireTeapot(0.25); // 주전자 생성

	glColor4f(128.0f / 255.0f, 0.0f / 255.0f, 32.0f / 255.0f, 1.0f); // 색상 : 버건디
	glTranslatef(0.5f, -1.0f, 0.0f); // 위치 조정
	glutWireSphere(0.25, 20, 20); // 구 생성

	glColor4f(155.0f / 255.0f, 228.0f / 255.0f, 102.0f / 255.0f, 1.0f); // 색상 : 페리도트 그린
	glTranslatef(0.3f, 0.7f, 0.0f); // 위치 조정
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f); //회전 : Y축
	glutWireCone(0.3, 0.5, 15, 15); // 원뿔 생성

	glFlush(); // 화면에 출력하기
}