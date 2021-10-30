/*
1389 케빈 베이컨의 6단계 법칙

vector subscript out of range
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[101];
int visited[101] = { 0, };
int N, M;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty())
	{
		int nx = q.front();
		q.pop();
		for (int i = 0; graph[nx].size(); i++)
		{
			int y = graph[nx][i];
			if (visited[y] == 0)
			{
				visited[y] = visited[nx] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++)//양방향
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int min = 0, idx = 1;

	for (int i = 1; i < N; i++)
	{
		int sum = 0;
		bfs(i);
		for (int j = 0; j < N; j++)
		{
			if (i != j)
				sum += visited[j];
		}
		memset(visited, 0, sizeof(visited));
		if (sum < min)
		{
			sum = min;
			idx = i;
		}
	}
	cout << idx;
	return 0;
}