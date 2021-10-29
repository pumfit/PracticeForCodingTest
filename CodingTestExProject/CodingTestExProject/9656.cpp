/*
9656 돌 게임2


시뮬레이션문제는 꼭 몇가지 예제를 풀어보자

이상한데 꽂혀가지고 예제를 틀렸더니 빙 돌아갔다 이해하기만 한다면 아주 쉬운 문제

*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 2 == 0)
		cout << "SK";
	else
		cout << "CY";
	return 0;
}