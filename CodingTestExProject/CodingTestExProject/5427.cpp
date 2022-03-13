/*
5427 불!

https://www.acmicpc.net/problem/5427

출발점이 다른 두 BFS를 사용하는 문제는 이번에 처음 풀어보았는데
이문제의 장벽인 25퍼센트에서 계속 걸렸다.
문제에 대한 질문에서 힌트를 보고 답을 맞출 수 있었는데
1. 큐 초기화
	전역변수로 사용하는 큐를 초기화하지 않아 큐가 다 돌지 않고 리턴될때 이후 값에 영향을 준다.
2. visited[ny][nx] != 0 && (0인 구간은 지나갈 수 있음)
	단순히 불이 지나간 구간만 비교하는 것이 아닌 불이 없는 구간도 지나갈 수 있음을 생각해야한다.
이 둘을 해결하지 못해서 어려웠던 문제이다.
이외에도 string으로 가져오지않고 int로 가져와서 해맨 점이나 queue종류를 헷갈린 점 등 여러 시간이 오래 걸린 문제점이 있었는데
이런 실수들을  BFS 문제를 계속 풀면서 고쳐 나가야할 것 같다.
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