/*
4963 섬의 개수

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.
두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다.
지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.

bfs + 대각선

보자마자 bfs로 풀면 되겠고 bfs 호출한 개수가 섬의 개수겠구나 생각
좌표 잘못보는 거나 bfs 구현 오류 없이 한번에 성공한 문제! 확실히 계속 복습하고
주의할점 체크하니까 쉽게 풀 수 있게 된 것 같다.

*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[51][51] = { 0, };
int visited[51][51] = { 0, };

int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,0,-1,1,1,0,-1 };

void bfs(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visited[sy][sx] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visited[ny][nx] == 0 && map[ny][nx])
			{
				visited[ny][nx] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main() {
	int w = -1, h = -1;
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
}