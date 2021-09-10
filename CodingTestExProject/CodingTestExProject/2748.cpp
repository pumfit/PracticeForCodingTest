/*
2748 피보나치 수2

첫째 줄에 n이 주어진다. n은 90보다 작거나 같은 자연수이다.
기존 피보나치 수 문제의 메모제이션을 복습하면서 정답 값이 커 int에서 long 으로 타입을 변환해주었다.
이때 19번 라인을 else if로 쓰는 실수를 하였는데 else if가 아닌 if로 써야 0,1모두 지나 내려와 계산이 가능해진다. 주의하자
*/
#include <iostream>
using namespace std;

long long Fidata[90] = { 0, };

long long Fibonacci(int n)
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