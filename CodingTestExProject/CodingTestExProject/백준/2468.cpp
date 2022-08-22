/*
2468 안전 영역

https://www.acmicpc.net/problem/2468
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited[nx][ny])
				continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	int D = 0;
	int maxArea = 0;
	while (true)
	{

		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] <= D)
				{
					visited[i][j] = 1;
				}
			}
		}
		int cntArea = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					bfs(i, j);
					cntArea++;
				}
			}
		}
		if (cntArea == 0)
			break;
		D++;
		maxArea = max(maxArea, cntArea);
	}
	cout << maxArea;
	return 0;
}