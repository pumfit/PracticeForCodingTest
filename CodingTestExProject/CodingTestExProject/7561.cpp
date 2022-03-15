/*
7561 ����Ʈ�� �̵�
https://www.acmicpc.net/problem/7562

�̵� ȸ�� = �湮 �ܰ�

	if (x == ex && y == ey)
		return 0;
ó���� �����ָ� �̻��ϰ� 3�� ���ɿ��� ���� 2�� ���´� ����...�ʹ� �и� ù �湮�� visited ó�����ߴµ�
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
int sx, sy;
int ex, ey;
int visited[301][301] = { 0, };

int dx[8] = { -1,-1,1,1,-2,-2,2,2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };


int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = 1;
	int cnt = 0;
	if (x == ex && y == ey)
		return 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == ex && ny == ey)
				return visited[y][x];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited[ny][nx])
				continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ nx,ny });
		}
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(visited, 0, sizeof(visited));
		cin >> N >> sx >> sy >> ex >> ey;
		cout << bfs(sx, sy) << '\n';
	}
	return 0;
}