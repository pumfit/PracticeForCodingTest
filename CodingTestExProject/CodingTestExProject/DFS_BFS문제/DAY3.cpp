/*
2644 �̼����

ù ������ ������ �������� ������ ������ �ʾҴ�.
"�ִ� ��θ� ã�ƾ��ϴ� ����"�� dfs,bfs�� ��� �ִܰ�θ� ���� �� �ִ��� �˾ƺ��Ҵ�.

���� dfs�� �����ߴ� �κ��� �����ϰ� bfs�� �ٽ� �����غ��Ҵ�.

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
��� �ִ� ��θ� ����ؾ��ϴ°�?�� ���� �ش��� ã�� �������.
Ǯ�� ���� : https://kiung9085.tistory.com/9
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