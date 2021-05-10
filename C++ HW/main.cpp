/********************************
과제명 : #1 기본 프로그래밍        *
작성자 : 20181397 유찬영          *
과목 : C++ 프로그래밍(김용호 교수님)*
********************************/
#include <iostream>

void PrintChars(char ch, int num); // 지정한 문자(ch)를 지정한 수(num)만큼 출력하는 함수 

int main() {
	int num;
	char ch; 
	

	std::cout << "문자<char>와 숫자<int> 입력 : ";
	std::cin >> ch >> num;

	if ((num < 1 || num > 10) || num % 2 == 0) { // 문제 1. B. 조건에서 정수는 1이상 10 이하의 '홀수'를 검사하는 조건문
		std::cout << "숫자가 범위를 벗어나 종료함";
		return 0;
	}
	else { // 문제 1. B.의 조건에 해당되는 숫자이면 PrintChars 함수를 호출한다.
		PrintChars(ch, num);
	}
	return 0;
}
void PrintChars(char ch, int num) {
	int cnt = -1; // 문자로 이루어진 삼각형 밖의 숫자를 처리해 주기 위한 카운트, 0부터 시작하므로 -1로 초기화

	for (int i = 0; i < num; i++) {
		cnt++; // -1로 초기화했으므로 다음 첫번째 줄에는 0부터 입력되며, 개행이 되고 나면 cnt 값을 1씩 증가시킨다.

		for (int j = num - 1; j > i; j--) {     // 문자 이전의 숫자를 처리해준다.
			std::cout << cnt;
		}

		for (int j = 0; j < (i * 2) + 1; j++) { // 0번째 줄 = 1개, 1번째 줄 = 3개, 2번째 줄 = 5개, 3번째 줄 = 7개
			std::cout << ch;                    // 위 규칙대로 (줄 수 * 2) + 1을 하게되면 각 줄이 늘어날때마다 문자를
		}										// 2개씩 추가해서 찍는다.
												
		for (int k = num - 1; k > i; k--) {     // 문자 이후의 숫자를 처리해 준다.
			std::cout << cnt;
		}
		if (i == num - 1) break; // 마지막 줄이 끝나면 개행문자 \n을 실행시키지 않고 반복문을 탈출한다. 
		std::cout << "\n";

	}
}