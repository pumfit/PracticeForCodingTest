/*
DAY1

1260 DFS와 BFS

그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
정점 번호는 1번부터 N번까지이다.

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

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

// BFS 함수 정의
void bfs(int start) {
	queue<int> q;//큐 여기에 만듬
	q.push(start); // 첫 노드를 queue에 삽입
	visited[start] = true; // 첫 노드를 방문 처리

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
출처:
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

	for (int i = 0; i < M; i++)//양방향
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {		//정점이 작은 것부터 방문하도록
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	std::cout << endl;
	memset(visited, 0, sizeof(visited));
	//reset();
	bfs(V);
}