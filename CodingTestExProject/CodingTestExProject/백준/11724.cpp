/*
11724 연결 요소의 개수

방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

기본적인 양방향 그래프 연결 개수 문제로 빠르게 bfs로 풀 수 있었다.
다만 처음에 하나 틀렸었는데 M범위를 1에서부터 M까지로 설정해야하는데 0에서 M-1이라 답이 차이가 난 것을
cnt -1로 제출해서 한번 틀렸었다. 입력값의 범위와 반복문을 잘 살펴보자

이후  dfs 풀이도 같이 제출하였다.

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