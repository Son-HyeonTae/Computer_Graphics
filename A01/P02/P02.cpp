#include <GL/glut.h> /* includes gl.h glu.h */

GLvoid drawScene(GLvoid); // 함수 선언

int main(int argc, char* argv[]) {
	// 초기화 함수들
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정 (단일 창 | RGBA 모드)
	glutInitWindowPosition(100, 100); // 윈도우의 위치 지정
	glutInitWindowSize(250, 250); // 윈도우의 크기 지정
	glutInit(&argc, argv); // GLUT 라이브러리 초기화
	glutCreateWindow("컴퓨터과학과 손현태"); // 윈도우 생성 (윈도우 이름)
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutMainLoop(); // 이벤트 처리 루프
}

GLvoid drawScene(GLvoid) {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	glFlush(); // 프레임 버퍼에 렌더링 전달
}