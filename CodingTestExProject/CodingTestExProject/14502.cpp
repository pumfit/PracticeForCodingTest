/*
14502 ���̷���

��Ʈ��ŷ + BFS

������ Ǯ���� ��Ʈ��ŷ ���Ⱝȭó�� x+1�� ��� x,y���� ���� Ž���Ϸ��� �ߴµ� �ش� �����
��Ʈ��ŷ �κп��� ��ü Ž���� �����ʴ� �κ��� �־����� �ִ밪�� �������ʾҰ� �̿� ���� ����� �ٸ� Ǯ�̸� ���� �˰ԵǾ���.
���� �� �κ��� �����Ͽ� ���� ��Ʈ��ŷ�ϴ� ������� Ǯ�̸� �����ϰ� �ȴ�.
���� �ش�Ǵ� �� 3���� ���� bfs�� ������ ���̷����� ��Ʈ���� ������� ������ ���� ���ϸ� �ȴ�.

Ǯ�� ��ü�� �����ε� �� �κи� �����ϸ� ������� ���� ������ ����� ���� ������ ���� Ǯ��� �ͼ������°� �߿��� �� ����.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[9][9];
int tempMap[9][9];
int visited[9][9];
vector<pair<int, int>> v;
int answer = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int sum = 0;

void copyMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tempMap[i][j] = map[i][j];
		}
	}
}

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
			if (!visited[ny][nx] && nx >= 0 && ny >= 0 && nx < M&&ny < N&&tempMap[ny][nx] == 0)
			{
				visited[ny][nx] = 1;
				tempMap[ny][nx] = 2;
				bfs(ny, nx);
			}
		}
	}

}

void spread()
{
	memset(visited, 0, sizeof(visited));
	copyMap();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tempMap[i][j] == 2 && !visited[i][j])
				bfs(i, j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tempMap[i][j] == 0)
				sum++;
		}
	}
	answer = max(sum, answer);
	sum = 0;
}

void dfs(int idx, int cnt)
{
	if (cnt == 3)
	{
		spread();
		return;
	}
	for (int i = idx; i < v.size(); i++)
	{
		int x = v[i].second;
		int y = v[i].first;

		map[y][x] = 1;
		dfs(i + 1, cnt + 1);
		map[y][x] = 0;

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	cout << answer;
	return 0;
}