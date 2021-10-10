/*
2525 오븐 시계

시간 문제 쉽게 푸는 방법은 최소 단위로 만들고 나머지 연산 쓰는 것이 가장 쉬운 방법같다.
역 방향으로 풀려고 하면 더 어려워 진다.
*/
#include<iostream>
using namespace std;

int main()
{
	int A, B;
	int C;
	int M = 0 ;

	cin >> A >> B >> C;

	M = (A * 60 + B + C) % (24 *60);

	cout << M / 60 <<" "<< M % 60;
}