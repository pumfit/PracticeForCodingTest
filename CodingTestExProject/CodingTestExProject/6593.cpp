/*
6593 상범빌딩

당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.

당신은 상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까?

3차원인 것이 특이한 문제이다. pair활용해서 풀었고 3차원 BFS 자체는 어렵지 않았다.
dx,dy,dz 작성에서 실수가 있었는데 찾는데 엄청 걸렸었던 문제이다.
이외로 visited를 케이스마다 초기화해야하는 것을 깨닫지 못해서 한번 실패했었다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int  L, R, C;
char map[35][35][35] = { 0, };
int visited[35][35][35] = { 0, };
int sx, sy, sz, ex, ey, ez;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

void bfs(int x, int y, int z)
{
	queue<pair<int, pair<int, int>>> q;
	q.push({ x,{y,z} });
	visited[z][y][x] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L)
				continue;
			if (visited[nz][ny][nx])
				continue;
			if (map[nz][ny][nx] == '#')
				continue;
			if (map[nz][ny][nx] == 'E')
			{
				cout << "Escaped in " << visited[z][y][x] << " minute(s)." << '\n';
				return;
			}
			visited[nz][ny][nx] = visited[z][y][x] + 1;
			q.push({ nx,{ny,nz} });
		}
	}
	cout << "Trapped!" << '\n';
}

int main() {

	while (true)
	{
		cin >> L >> R >> C;
		memset(visited, 0, sizeof(visited));
		if (L == 0 && R == 0 && C == 0)
			return 0;
		string s;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				cin >> s;
				for (int k = 0; k < C; k++)
				{
					map[i][j][k] = s[k];
					if (s[k] == 'S')
					{
						sx = k; sy = j; sz = i;
					}
					if (s[k] == 'E')
					{
						ex = k; ey = j; ez = i;
					}
				}
			}
		}
		bfs(sx, sy, sz);

	}
	return 0;
}