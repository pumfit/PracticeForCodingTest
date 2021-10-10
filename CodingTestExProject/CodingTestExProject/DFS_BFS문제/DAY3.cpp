/*
2644 촌수계산

첫 구현후 예제는 맞췄지만 정답이 나오진 않았다.
"최단 경로를 찾아야하는 문제"로 dfs,bfs로 어떻게 최단경로를 구할 수 있는지 알아보았다.

먼저 dfs로 구현했던 부분을 제외하고 bfs로 다시 구현해보았다.

void dfs(int x)
{
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited[y]&&!visited[B])
		{
			cnt++;
			dfs(y);
		}
	}
}
어떻게 최단 경로를 계산해야하는가?에 대한 해답을 찾기 어려웠다.
풀이 참고 : https://kiung9085.tistory.com/9
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M;
int A, B;
vector<int> graph[101];
int cnt [101];
bool visited[101];

void bfs(int s)
{
	visited[s] = true;
	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
				cnt[y] = cnt[x] + 1;
			}
		}

	}

}

int main()
{
	cin >> N >> A >> B >> M;
	cnt[0] = 0;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(A);
	if (!visited[B])
	{
		cout << -1;
	}
	else
	{
		cout << cnt[B];
	}
}