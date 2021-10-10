/*
9095 1, 2, 3 더하기

정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

DP문제, memoization 사용
메모제이션 구현 복습 필수!!

0이 아닌 경우 : 해당 배열 값을 리턴한다.
0인 경우 : 해당 배열값을 찾기위해 재귀를 실행한 후
			배열 값을 리턴한다.

처음엔 완전탐색 생각했다가 말도 안된다는걸 알았고 이후 더 생각하다 모르겠어서 포기
이 문제가 DP문제라는 걸 전혀 깨닫지 못했다..규칙 찾기 -> 점화식 변경 중요함
*/
#include <iostream>
using namespace std;

int arr[12];

int func(int n)
{
	if (arr[n] != 0)
	{
		return arr[n];
	}
	else
	{
		arr[n] = func(n - 1) + func(n - 2) + func(n - 3);
		return arr[n];
	}
}

int main() {
	int T, n;
	arr[1] = 1; arr[2] = 2; arr[3] = 4;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cout << func(n) << endl;
	}

	ret