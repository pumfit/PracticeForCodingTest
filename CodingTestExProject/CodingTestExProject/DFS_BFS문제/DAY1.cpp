/*
DAY1

1260 DFS�� BFS

�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, 
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. 
���� ��ȣ�� 1������ N�������̴�.

ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. 
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. 
� �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.

void dfs(int x)
{
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited[y])
			dfs(y);
	}
}

// BFS �Լ� ����
void bfs(int start) {
	queue<int> q;//ť ���⿡ ����
	q.push(start); // ù ��带 queue�� ����
	visited[start] = true; // ù ��带 �湮 ó��

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}
��ó:
https://better-tomorrow.tistory.com/entry/DFS-BFS-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0
https://hyunah-home.tistory.com/6
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool visited[1001];
vector<int> graph[1001];
int N, M, V;

void reset()
{
	for (int i = 0; i < N; i++)
		visited[i] = false;
}

void dfs(int x)
{
	visited[x] = true;
	std::cout << x << " ";

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited[y])
			dfs(y);
	}
}

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		std::cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main()
{
	int x, y;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)//�����
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {		//������ ���� �ͺ��� �湮�ϵ���
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	std::cout << endl;
	memset(visited, 0, sizeof(visited));
	//reset();
	bfs(V);
}