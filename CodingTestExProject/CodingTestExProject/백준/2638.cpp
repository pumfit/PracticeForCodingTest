/*
2638 ġ��

������ �ϳ� �� �߰����־ �ذ��Ͽ���. �ٱ� ������ 3���� �����ϰ� �ٱ� ������ ���ѵ� ���ϴ� �κ��� ���ϰ� ��ȯ�ϴ� �� �� ����Ŭ�� �����ߴ�.

�ϸ鼭 Ʋ�� �κе��� ��κ��ִµ�
1. ���ϴ� �κ��� �ٷ� �ٱ� �������� �ٲٴ� ��� �ٱ������� ��� �κ��� �ٲ� �� �־ ���ϴ� �κ��� �� ���ѵ� �ѹ��� �ٲ���Ѵ�.
2.�ٱ� �κ� ���ϴ� ������ �ѹ��� ������ȴ�. ���� �ٸ� Ǯ�� ó�� 0 �κκ� ã�Ƽ� �ٵ����� ������
�������� ���� ®���� �翬�ϰԵ� Ʋ�ȴ� . �̺κ� �����ϰ� ��� ���� ������ ��ΰ� 3�̵Ǵ� ���� �ƴ� 0�� ���Ե� ���� �����Ƿ�
1�� ���� ��찡 ��� ���� �ɷ� �Ǵ��ϰ� �����ߴ�.

¥�鼭 ����ؾ��ϴ� ���� �پ��ؼ� ���Ҵ� ���� �ٸ� ����� ����Ǯ���� ���� ������� Ʋ�� �� ���Ƽ�
���� Ǯ�� ���� ����غ��� �����ؾ��� �� ����.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool isCanMelt(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if (map[ny][nx] == 3)
			count++;
	}
	if (count > 1)
		return true;
	else
		return false;
}

void FillOutside(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = 1;
	map[y][x] = 3;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visited[ny][nx])
				continue;
			if (map[ny][nx] == 1)//ġ��� �ǳʶڴ�.
				continue;
			map[ny][nx] = 3;
			visited[ny][nx] = 1;
			q.push({ nx,ny });
		}
	}
}

void FindMeltArea(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	if (isCanMelt(x, y))
		map[y][x] = 2;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visited[ny][nx])
				continue;
			if (map[ny][nx] != 1)//ġ� �ƴ϶�� �ǳʶڴ�.
				continue;
			if (isCanMelt(nx, ny))
				map[ny][nx] = 2;
			visited[ny][nx] = 1;
			q.push({ nx,ny });
		}
	}
}

bool isAllMelt()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	while (!isAllMelt())
	{
		answer++;
		FillOutside(0, 0);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visited[i][j] && map[i][j] == 1)
				{
					FindMeltArea(j, i);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 2)
				{
					map[i][j] = 3;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
	}

	cout << answer;
	return 0;
}