/*
6593 �������

����� ��� ������ ������ ���Ҵ�. ���⼭ Ż���ϴ� ���� ���� ���� �����ϱ�? ��� ������ �� ���� ���̰� 1�� ������ü(���� ������ü)�� �̷�����ִ�. �� ������ü�� ������ �̷���� �־� ������ �� ���ų�, ����־ ������ �� �ְ� �Ǿ��ִ�. ����� �� ĭ���� ������ 6���� ĭ(��,��,��,��,��,��)���� 1���� �ð��� �鿩 �̵��� �� �ִ�. ��, �밢������ �̵��ϴ� ���� �Ұ����ϴ�. �׸��� ��� ������ �ٱ��鵵 ��� ������ �����־� �ⱸ�� ���ؼ��� Ż���� �� �ִ�.

����� ��� ������ Ż���� �� ������? ���� �׷��ٸ� �󸶳� �ɸ���?

3������ ���� Ư���� �����̴�. pairȰ���ؼ� Ǯ���� 3���� BFS ��ü�� ����� �ʾҴ�.
dx,dy,dz �ۼ����� �Ǽ��� �־��µ� ã�µ� ��û �ɷȾ��� �����̴�.
�ܷ̿� visited�� ���̽����� �ʱ�ȭ�ؾ��ϴ� ���� ������ ���ؼ� �ѹ� �����߾���.
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