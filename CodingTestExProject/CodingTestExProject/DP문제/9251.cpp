/*
LCS
https://www.acmicpc.net/problem/9251

LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

문자열이 1000이라 1001x1001 2차원 배열로 이중for문을 실행해도 시간초과가 나지 않을 문제였다.

2차원 배열로 각 문자열을 이중 for문을 돌면서 비교한다. 만약 값이 같다면 해당되는 인덱스에서 1더한 값이 현재 최장길이가 된다.

이때 맨처음 값도 비교를 해야하므로 0번 인덱스는 모두 0으로 초기화하여 1부터 진행하도록한다.
*/
#include <iostream>
using namespace std;

int main() {
	int dp[1001][1001] = { 0, };
	string A, B;
	cin >> A >> B;
	for (int i = 1; i <= A.size(); i++)
	{
		for (int j = 1; j <= B.size(); j++)
		{
			if (A[i - 1] == B[j - 1])//두 값이 같다면
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;//1을 더한다.
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);//같지 않은 경우 이전 값중 더 큰 값을 선택한다.
			}
		}
	}
	cout << dp[A.size()][B.size()];
	return 0;
}