/*
16928 뱀과 사다리 게임

*/
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[101] = { 0, };
int visited[101] = { 0, };
int cnt = 0;
queue<int> q;

void bfs()
{
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		if (i == 100)
			return;
		for (int k = 1; k <= 6; k++)
		{
			int ni = i + k;
			if (map[ni] > 0)
				ni = map[ni];
			if (ni <= 100 && visited[ni] == 0)
			{
				visited[ni] = visited[i] + 1;
				q.push(ni);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a] = b;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a] = b;
	}
	visited[1] = 1; q.push(1);
	bfs();
	cout << visited[100] - 1;
	return 0;
}