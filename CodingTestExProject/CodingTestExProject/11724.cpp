/*
11724 ���� ����� ����

���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�⺻���� ����� �׷��� ���� ���� ������ ������ bfs�� Ǯ �� �־���.
�ٸ� ó���� �ϳ� Ʋ�Ⱦ��µ� M������ 1�������� M������ �����ؾ��ϴµ� 0���� M-1�̶� ���� ���̰� �� ����
cnt -1�� �����ؼ� �ѹ� Ʋ�Ⱦ���. �Է°��� ������ �ݺ����� �� ���캸��

����  dfs Ǯ�̵� ���� �����Ͽ���.

*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[1001];
int visited[1001] = { 0, };

void dfs(int n)
{
	visited[n] = 1;
	for (int i = 0; i < graph[n].size(); i++)
	{
		int x = graph[n][i];
		if (visited[x] == 0)
			dfs(x);
	}
}

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (visited[y] == 0)
			{
				visited[y] = 1;
				q.push(y);
			}
		}
	}
}

int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);//bfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}