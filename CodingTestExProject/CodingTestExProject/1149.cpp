/*
1149 RGB거리

RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

처음에 dfs로 풀다가 n=1000인 경우라 시간초과가 날 것 같아서 다른 방법을 생각해보았고 배낭문제 배낭문제,퇴사문제가 생각났다. 
dp 로 풀었고 선택할 수 있는경우의 수를 두가지씩 나눠서 dp를 전체 계산하도록 하였다.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int m = 1001 * 1001;
int arr[1001][3];
int minArr[1001][3];

int dp(int n, int i)
{
	if (minArr[n][i] != 0)
		return minArr[n][i];
	if (i == 0)
	{
		return minArr[n][0] = min(dp(n - 1, 1), dp(n - 1, 2)) + arr[n][i];
	}
	else if (i == 1)
	{
		return minArr[n][1] = min(dp(n - 1, 0), dp(n - 1, 2)) + arr[n][i];
	}
	else if (i == 2)
	{
		return minArr[n][2] = min(dp(n - 1, 0), dp(n - 1, 1)) + arr[n][i];
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	minArr[0][0] = arr[0][0]; minArr[0][1] = arr[0][1]; minArr[0][2] = arr[0][2];
	cout << min(dp(N, 0), min(dp(N, 1), dp(N, 2))) << endl;

	return 0;
}