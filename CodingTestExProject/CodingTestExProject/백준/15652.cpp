/*
15651 N과 M(4)

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

N과 M중 가장 어려웠고 해당 문제에 대한 이해는 중복과 비내림차순이다. visted x
num값이 현재 i값이 되도록 해줘야 (3)과 달리 중복되는 수열을 여러 번 출력하지 않는다.
*/
#include<iostream>
using namespace std;

int arr[8] = { 0, };
int visited[8] = { 0, };
int N, M;

void dfs(int idx,int num)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++)
	{
		arr[idx] = i;
		dfs(idx+1, i);
	}
}

int main()
{
	cin >> N >> M;
	dfs(0,1);
	return 0;
}