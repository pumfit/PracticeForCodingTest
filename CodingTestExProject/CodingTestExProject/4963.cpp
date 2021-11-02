/*
4963 ���� ����

�� ���簢���� ����, ���� �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� �ɾ �� �ִ� �簢���̴�.
�� ���簢���� ���� ���� ��������, �� ���簢������ �ٸ� ���簢������ �ɾ �� �� �ִ� ��ΰ� �־�� �Ѵ�.
������ �ٴٷ� �ѷ��ο� ������, ���� ������ ���� �� ����.

bfs + �밢��

���ڸ��� bfs�� Ǯ�� �ǰڰ� bfs ȣ���� ������ ���� �����ڱ��� ����
��ǥ �߸����� �ų� bfs ���� ���� ���� �ѹ��� ������ ����! Ȯ���� ��� �����ϰ�
�������� üũ�ϴϱ� ���� Ǯ �� �ְ� �� �� ����.

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