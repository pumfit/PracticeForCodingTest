/*
11403 경로 찾기

https://www.acmicpc.net/problem/11403

가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, 
i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

경로를 찾는 문제로 bfs를 통해 풀이를 진행했다.
이때, 자기 자신도 경로가 있어야 가늫하다. 기존 bfs처럼 처음 방문한 정점을 방문표시하면
출발하는 정점은 모두 방문표시가 되므로 visited[n] = 1을 제외하고 풀이를 진행하면 된다.


*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int graph[101][101] = { 0, };
int visited[101] = { 0, };
int N;

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++)
		{
			if (visited[i])
				continue;
			if (!graph[cur][i])
				continue;
			q.push(i);
			visited[i] = 1;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		bfs(i);
		for (int j = 0; j < N; j++)
			cout << visited[j] << " ";
		cout << '\n';
		memset(visited, 0, sizeof(visited));

	}
	return 0;
}