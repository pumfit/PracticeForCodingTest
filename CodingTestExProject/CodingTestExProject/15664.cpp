/*
15664 N과 M(10)

#https://www.acmicpc.net/problem/15664
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

백트래킹문제

이번 문제에서 가장 어려웠던 부분은 "중복되는 수열을 여러 번 출력하면 안되며," 이부분이였다.
중복까지는 출력했는데 이후 처리가 어려웠다. dfs 단계에서 선택되는 수를 저장하고 이 숫자가 다음수와 같은지만 판단하면 된다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10001];
int ans[10001];
int visited[10001] = { 0, };

void dfs(int idx, int num)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << endl;
		return;
	}
	int preNum = -1;
	for (int i = num; i < N; i++)
	{
		if (!visited[i] && preNum != arr[i])
		{
			visited[i] = 1;
			ans[idx] = arr[i];
			preNum = arr[i];
			dfs(idx + 1, i);
			visited[i] = 0;
		}

	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	dfs(0, 0);
	return 0;
}