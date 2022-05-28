/*
1629 곱셈

나머지의 특성과 재귀함수에 대한 문제
지수가 짝수의 경우 지수의 곱셈법칙을 통해 쉽게 답이 나오는 것 까지는 이해했지만
지수가 홀수인 경우에는 어떻게 처리를 해주어야 하는 지 감을 못 잡았는데 기존 계산 값에 a값을 곱해 다시 나눠주면 되는 것 이 신기했고
재귀로 리턴을 받고 해당 값을 판단하는 것을 배울 수 있었다.

강의 내용:
https://youtu.be/8vDDJm5EewM
*/

#include <iostream>
using namespace std;

int Pow(long long a, long long b, long long c)
{
	if (b == 1)//지수가 1인 경우
		return a % c;

	long long value = Pow(a, b / 2, c);
	value = value * value % c; //배수가 짝수인 경우의 나머지 값이 계산 된다.

	if (b % 2 == 0)//지수가 2의 배수인 경우
		return value;
	else
		return value * a % c;//지수가 1이 아니며 2의 배수가 아닌경우
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << Pow(a, b, c);
	return 0;
}