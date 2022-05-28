/*
15650
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 
M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 "중복 없이" M개를 고른 수열
고른 수열은 오름차순이어야 한다.

15649 문제에서 중복이 제외되는 문제이다.
중복을 제외하기 위해서 조건으로 for문에 들어갈 인덱스의 범위를 넘겨주어야 한다.
조합
*/
#include <iostream>
using namespace std;

int N, M;
int visited[9] = { 0, };
int arr[9] = { 0, };

void dfs(int idx, int num)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}
	for (int i = num; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			arr[idx] = i;
			dfs(idx + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(0, 1);
	return 0;
}