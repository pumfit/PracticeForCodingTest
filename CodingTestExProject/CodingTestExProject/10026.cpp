/*
10026 ���ϻ���

���ϻ����� �������� �ʷϻ��� ���̸� ���� ������ ���Ѵ�. ����, ���ϻ����� ����� ���� �׸��� �ƴ� ����� ���� �׸����� �� �ٸ� �� �ִ�.
ũ�Ⱑ N��N�� �׸����� �� ĭ�� R(����), G(�ʷ�), B(�Ķ�) �� �ϳ��� ��ĥ�� �׸��� �ִ�. �׸��� �� ���� �������� �������� �ִµ�, ������ ���� ������ �̷���� �ִ�. 
��, ���� ������ �����¿�� ������ �ִ� ��쿡 �� ���ڴ� ���� ������ ���Ѵ�. (������ ���̸� ���� ������ ���ϴ� ��쵵 ���� �����̶� �Ѵ�)

ù° �ٿ� N�� �־�����. (1 �� N �� 100)
��° �ٺ��� N�� �ٿ��� �׸��� �־�����.

bfs�� �Ϲ����� ����� ������ ���ϰ� �ش� ������ ���� �ϵ� red,green�� blue�� ������ ��츦 �����ϴ� ���ο� bfs�� �������.

+
�̸� ���� ������� ����..
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
char map[101][101] = { 0, };
int visited[101][101] = { 0, };
int visitedRG[101][101] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int rgb = 0, b = 0;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = 1;
	while (!q.empty())
	{
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N&&ny < N&&visited[ny][nx] == 0 && map[sy][sx] == map[ny][nx])
			{
				visited[ny][nx] = 1;
				bfs(ny, nx);
			}
		}
	}
}

void bfsRG(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visitedRG[y][x] = 1;
	while (!q.empty())
	{
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N&&ny < N&&visitedRG[ny][nx] == 0)
			{
				if ((map[sy][sx] == 'B'&&map[ny][nx] == 'R') || (map[sy][sx] == 'R'&&map[ny][nx] == 'B'))
					continue;
				if ((map[sy][sx] == 'B'&&map[ny][nx] == 'G') || (map[sy][sx] == 'G'&&map[ny][nx] == 'B'))
					continue;
				visitedRG[ny][nx] = 1;
				bfsRG(ny, nx);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
		{
			map[i][j] = s[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(i, j);
				rgb++;
			}
			if (visitedRG[i][j] == 0)
			{
				bfsRG(i, j);
				b++;
			}
		}
	}
	cout << rgb << " " << b;
	return 0;
}