/*
9084 동전

우리나라 화폐단위, 특히 동전에는 1원, 5원, 10원, 50원, 100원, 500원이 있다. 
이 동전들로는 정수의 금액을 만들 수 있으며 그 방법도 여러 가지가 있을 수 있다. 
예를 들어, 30원을 만들기 위해서는 1원짜리 30개 또는 10원짜리 2개와 5원짜리 2개 등의 방법이 가능하다.

동전의 종류가 주어질 때에 주어진 금액을 만드는 모든 방법을 세는 프로그램을 작성하시오.

정말 오랫만에 dp 문제풀어서 dp 접근법에 대해 어려웠던 문제이고
1. 주어진 금액을 만드는 모든 방법
2. 동전의 가지수
3. 어떻게 M까지 합을 만들지
를 고민하면 되는 문제였던 것 같다. 이후 dp 복습과 자세한 풀이는 아래로 
https://maybemine.tistory.com/entry/dp-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4-%EB%8F%99%EC%A0%84-9084-%EC%99%B8
*/
#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int coins[21];
int dp[10001] = { 0, };

void check()
{
	dp[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = coins[i]; j <= M; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}
	cout << dp[M] << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		memset(dp, 0, sizeof(dp));
		memset(coins, 0, sizeof(coins));
		for (int j = 1; j <= N; j++)
			cin >> coins[j];
		cin >> M;
		check();
	}

	return 0;
}