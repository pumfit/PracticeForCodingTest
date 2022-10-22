/*
11403 ��� ã��

https://www.acmicpc.net/problem/11403

����ġ ���� ���� �׷��� G�� �־����� ��, ��� ���� (i, j)�� ���ؼ�, 
i���� j�� ���� ��ΰ� �ִ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

��θ� ã�� ������ bfs�� ���� Ǯ�̸� �����ߴ�.
�̶�, �ڱ� �ڽŵ� ��ΰ� �־�� ���q�ϴ�. ���� bfsó�� ó�� �湮�� ������ �湮ǥ���ϸ�
����ϴ� ������ ��� �湮ǥ�ð� �ǹǷ� visited[n] = 1�� �����ϰ� Ǯ�̸� �����ϸ� �ȴ�.


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