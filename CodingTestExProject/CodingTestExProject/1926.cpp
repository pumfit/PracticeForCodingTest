/*
1926 그림

https://www.acmicpc.net/problem/1926

정석적인 BFS문제 영역내 크기와 영역의 개수 구하기

*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[501][501] = { 0, };
int visited[501][501] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0, maxSize = 0;

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ x,y });
	int bfsSize = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (map[ny][nx] == 1)
			{
				visited[ny][nx] = 1;
				q.push({ nx,ny });
				bfsSize++;
			}
		}
	}
	return bfsSize;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && map[i][j] == 1)
			{
				int s = bfs(j, i);
				maxSize = max(s, maxSize);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	cout << maxSize;
	return 0;
}