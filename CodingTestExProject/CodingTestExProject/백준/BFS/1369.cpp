/*
https://www.acmicpc.net/problem/1389
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[101];
int visited[101] = { 0, };
int N, M;

int bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty())
	{
		int nx = q.front();
		q.pop();
		for (int i = 0; i < graph[nx].size(); i++)
		{
			int y = graph[nx][i];
			if (visited[y] == 0 && x != y)
			{
				visited[y] = visited[nx] + 1;
				q.push(y);
			}
		}
	}

    int num = 0;
    for (int i = 1; i <= N; ++i) {
        num += visited[i];
    }
    
    return num;
}

int main() {
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int m = 2e9, idx = -1;

	for (int i = 1; i <= N; i++)
	{
		int sum = bfs(i);
		if (sum < m)
		{
			m = sum;
			idx = i;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << idx;
	return 0;
}