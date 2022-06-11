/*
N과 M(11)
https://www.acmicpc.net/problem/15665

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

같은 수를 여러 번 골라도 된다.
-> 배열을 0부터 시작한다.
-> 이전에 고른 수가 아니게 처리한다.(prevNum)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10001];
int ans[10001];
int visited[10001] = { 0, };

void bf(int idx, int num)
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
			bf(idx + 1, i);
			visited[i] = 0;
		}

	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	bf(0, 0);
	return 0;
}