/*
12865 평범한 배낭
https://www.acmicpc.net/problem/12865

dp[i][j] 안에는 만족도가 최대가 되는 
배낭의 물건 개수와 최대 무게 만큼 배열을 잡아두고 넣을 수 있는 지 없는 지를 판단 한 후에 
- 배낭에 넣을 수 있는가?
	- 배낭에 물건을 넣은 경우 / 넣지 않은 경우 둘 중 더 큰 경우를 넣는다.
- 넣을 수 없는 경우에는 이전 값을 가지게된다.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101] = { 0, };
int V[101] = { 0, };
int dp[101][100001] = { 0, };

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= N; i++)// 배낭에 넣을 수 있는 물건 개수만큼
	{
		for (int j = 1; j <= K; j++)// 배낭의 최대 무게까지
		{
			if (j - W[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);//물건 넣을 때와 안 넣을 때
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
	return 0;
}