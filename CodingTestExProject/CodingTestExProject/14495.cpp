/*
14495 피보나치 비스무리한 수열

구현은 나온대로 하면되는데 116까지 즉 세자리 넘는 피보나치라서
int형이 아닌 long으로 바꿔줘야한다.
피보나치 수열은 N범위에 따라 자료형 조심하기
*/
#include <iostream>
using namespace std;
int N;
long long dp[117];
int main() {
	cin >> N;
	dp[1] = dp[2] = dp[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[N];
	return 0;
}