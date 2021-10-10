#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int A, B;
vector<int> graph[101];
int cnt[101];
bool visited[101];

void dfs(int x)
{
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited[y] && !visited[B])
		{
			cnt[y] = cnt[x] + 1;
			dfs(y);
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
	dfs(A);
	if (!visited[B])
	{
		cout << -1;
	}
	else
	{
		cout << cnt[B];
	}
}