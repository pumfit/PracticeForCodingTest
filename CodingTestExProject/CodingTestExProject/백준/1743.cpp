/*
1743 음식물 피하기 DFS
https://www.acmicpc.net/problem/1743
*/
#include <iostream>
using namespace std;

int map[101][101] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N, M, K;
int visited[101][101] = { 0, };
int mapSize = 0;

void DFS(int x, int y)
{
	visited[y][x] = 1;
	mapSize++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > M || ny > N)
			continue;
		if (visited[ny][nx] == 1)
			continue;
		if (map[ny][nx] == 0)
			continue;
		DFS(nx, ny);
	}
}

int main() {
	int answer = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> y >> x;
		map[y][x] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				DFS(j, i);
				answer = max(answer, mapSize);
				mapSize = 0;
			}
		}
	}
	cout << answer;
	return 0;
}