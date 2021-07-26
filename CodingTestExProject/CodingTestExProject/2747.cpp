/*
2747 피보나치 수

기존에 시간 초과로 틀린 문제
피보나치 알고리즘으로 문제를 풀면 1초가 초과한다. 해당 풀이는 재귀를 두번 호출하므로 O(n^2)의 시간 복잡도를 가진다.
따라서, 동적 계획법을 통해 문제를 풀어나가야한다.

동적 계획법은 "복잡한 문제를 간단한 여러 개의 문제로 나누어 푸는 방법"이다.즉, 이전 풀이를 기억해두었다가 풀이를 하는 방식이다.

아직 코테를 준비하면서 동적 계획법을 접해보지 못했는데 해당 문제를 풀면서 왜 동적 계획법을 생각해냈는 지에 대해 쉽게 이해할 수 있었다.
(top-down방식으로 풀이하였다.)
*/
#include <iostream>
using namespace std;

int Fidata[50] = { 0, };

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (Fidata[n] == 0)
		Fidata[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
	return Fidata[n];
}
int main()
{
	int N = 0;
	cin >> N;
	cout << Fibonacci(N);
	return 0;
}