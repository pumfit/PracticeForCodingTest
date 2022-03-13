/*
5427 ��!

https://www.acmicpc.net/problem/5427

������� �ٸ� �� BFS�� ����ϴ� ������ �̹��� ó�� Ǯ��Ҵµ�
�̹����� �庮�� 25�ۼ�Ʈ���� ��� �ɷȴ�.
������ ���� �������� ��Ʈ�� ���� ���� ���� �� �־��µ�
1. ť �ʱ�ȭ
	���������� ����ϴ� ť�� �ʱ�ȭ���� �ʾ� ť�� �� ���� �ʰ� ���ϵɶ� ���� ���� ������ �ش�.
2. visited[ny][nx] != 0 && (0�� ������ ������ �� ����)
	�ܼ��� ���� ������ ������ ���ϴ� ���� �ƴ� ���� ���� ������ ������ �� ������ �����ؾ��Ѵ�.
�� ���� �ذ����� ���ؼ� ������� �����̴�.
�̿ܿ��� string���� ���������ʰ� int�� �����ͼ� �ظ� ���̳� queue������ �򰥸� �� �� ���� �ð��� ���� �ɸ� �������� �־��µ�
�̷� �Ǽ�����  BFS ������ ��� Ǯ�鼭 ���� �������� �� ����.
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char map[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };
int exitVisited[1001][1001] = { 0, };
int W, H;
queue<pair<int, int>> q;
queue<pair<int, int>> exitQueue;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void exitBfs() {
	while (!exitQueue.empty())
	{
		int y = exitQueue.front().first;
		int x = exitQueue.front().second;
		exitQueue.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= W || ny >= H)
			{
				cout << exitVisited[y][x] << '\n';
				return;
			}
			if (map[ny][nx] == '#')
				continue;
			if (visited[ny][nx] != 0 && visited[ny][nx] <= exitVisited[y][x] + 1)
				continue;
			if (exitVisited[ny][nx] == 0)
			{
				exitVisited[ny][nx] = exitVisited[y][x] + 1;
				exitQueue.push({ ny,nx });
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}

void bfs() {
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= W || ny >= H)
				continue;
			if (map[ny][nx] == '#')
				continue;
			if (visited[ny][nx] == 0)
			{
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		memset(exitVisited, 0, sizeof(visited));
		while (!q.empty())
			q.pop();
		while (!exitQueue.empty())
			exitQueue.pop();
		int w, h;
		cin >> w >> h;
		string s;
		W = w; H = h;
		for (int j = 0; j < h; j++)
		{
			cin >> s;
			for (int k = 0; k < w; k++)
			{
				map[j][k] = s[k];
				if ('*' == map[j][k])
				{
					visited[j][k] = 1;
					q.push({ j,k });
				}
				else if ('@' == map[j][k])
				{
					exitVisited[j][k] = 1;
					exitQueue.push({ j,k });
				}

			}
		}

		bfs();
		exitBfs();
	}
	return 0;
}