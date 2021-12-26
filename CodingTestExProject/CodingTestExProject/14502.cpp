/*
14502 바이러스

백트래킹 + BFS

이전에 풀었던 백트래킹 무기강화처럼 x+1로 모든 x,y범위 내를 탐색하려고 했는데 해당 방법이
백트래킹 부분에서 전체 탐색이 되지않는 부분이 있었는지 최대값이 나오지않았고 이에 대한 방법을 다른 풀이를 보며 알게되었다.
벽이 들어갈 부분을 저장하여 꺼내 백트래킹하는 방식으로 풀이를 진행하게 된다.
이후 해당되는 벽 3개에 대해 bfs를 진행해 바이러스를 퍼트리고 빈공간의 개수를 세어 비교하면 된다.

풀이 자체는 긴편인데 위 부분만 제외하면 어렵지는 않은 문제라 비슷한 문제 유형을 많이 풀어보고 익숙해지는게 중요한 것 같다.
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