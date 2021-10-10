/*
DAY 2 바이러스
*/
#include<iostream>
#include<vector>
using namespace std;

bool visited[101];
vector<int> v[101];
int N, M,ans = 0;;

void dfs(int x)
{
	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (!visited[y])
		{
			ans++;
			dfs(y);
		}
	}
}

int main()
{
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << ans;
}