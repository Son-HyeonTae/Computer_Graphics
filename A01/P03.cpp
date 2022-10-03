#include <GL/glut.h>

GLvoid drawScene(GLvoid);

int main(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정 (단일 창 | RGBA 모드)
	glutInitWindowPosition(100, 100); // 윈도우의 위치 지정
	glutInitWindowSize(250, 250); // 윈도우의 크기 지정
	glutInit(&argc, argv); // GLUT 라이브러리 초기화
	glutCreateWindow("컴퓨터과학과 손현태"); // 윈도우 생성 (윈도우 이름)
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutMainLoop(); // 이벤트 처리 루프
}

GLvoid drawScene(GLvoid) {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // 바탕색을 'yellow' 로 지정
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // 현재 색상을 'red' 로 지정
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); // 좌표로 사각형 그리기
	glFlush(); // 화면에 출력하기
}
