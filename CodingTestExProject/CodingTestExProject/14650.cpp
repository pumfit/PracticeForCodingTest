/*
14650 걷다보니 신천역 삼

0, 1, 2만 가지고 만들 수 있는 N자리 3의 배수의 개수를 출력하삼.

각자리수의 합이 3으로 나눠지는 경우 3의 배수이고 N이 최대값인 9일때도 3^9 이므로 전체탐색이 가능하다고 생각되었다.
dfs로 풀이를 진행하였고 쉽게 통과했다. 다른 풀이들을 보던 중 dp풀이도 가능함을 알 수 있었다.
테케를 몇가지 입력해보면 1 - 0 ,2 - 2, 3 - 6, 4 - 18 ,5 - 54 로 dp[i] = dp[i-1]*3인 dp문제인 걸 알 수 있다.
dp란 걸 알고 보니 신기했던 문제이다.
*/
#include <iostream>
using namespace std;

int N;
int num[10] = { 0, };
int cnt = 0;

void dfs(int idx)
{
	int sum = 0;
	if (idx == N)
	{
		for (int i = 0; i < N; i++)
			sum += num[i];
		if (sum % 3 == 0)
			cnt++;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (idx != 0)
			num[idx] = i;
		else
		{
			if (i == 0)
				continue;
			num[idx] = i;
		}
		dfs(idx + 1);
	}
}

int main() {
	cin >> N;
	dfs(0);
	cout << cnt;
	return 0;
}