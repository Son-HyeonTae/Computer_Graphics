#include <GL/glut.h>

void Display() {
	glClear(GL_COLOR_BUFFER_BIT); // 버퍼에 설정된 색으로 전체를 칠하기 (초기값 : Black)
	glBegin(GL_POLYGON); // 도형의 정점(Vertex) 지정 시작
	// 매개변수 : 모드 값
	//           ㄴ GL_POLYGON : 연결된 블록 다각형
	glVertex3f(-0.5, -0.5, 0.0); // 좌표 지정 0
	glVertex3f(0.5, -0.5, 0.0); // 좌표 지정 1
	glVertex3f(0.5, 0.5, 0.0); // 좌표 지정 2
	glVertex3f(-0.5, 0.5, 0.0); // 좌표 지정 3
	glEnd(); // 도형의 정점 지정 종료
	glFlush(); // 프레임 버퍼에 렌더링 전달
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv); // GLUT 라이브러리 초기화
	glutCreateWindow("Hello World!"); // 윈도우 생성 (이름 : Hello World!)
	glutDisplayFunc(Display); // 출력 함수의 지정
	glutMainLoop(); // 이벤트 처리 루프
	return 0; // main 함수 return
}
