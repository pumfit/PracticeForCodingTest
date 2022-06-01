/*
파도반 수열

DP문제
초기값 dp[1] dp[2] dp[3] = 1
점화식 dp[i] = dp[i-2]+dp[i-3];

한번 틀렸던 이유
int로 배열 선언해두었는데 dp문제의 경우 N값이 커질 수록 그 값이 엄청 커져서 long long형이어야한다.
100넣어보고 오버플로 나는거 보고 바로 수정
*/
#include <iostream>
using namespace std;

int main() {
	int T, N;
	long long dp[101] = { 0, };
	cin >> T;
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	for (int i = 4; i <= 100; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	while (T--)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}