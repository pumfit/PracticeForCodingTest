/*
1240 노드사이의 거리

https://www.acmicpc.net/problem/1240

비용을 visited와 같이 계산하였고 처음 방문 표기를 위해 첫 방문지점 비용을 1로 하고
반환값에서 1빼는 식으로 거리 계산을 진행하였다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> v[1001];
int visited[1001] = { 0, };

int BFS(int A, int B)
{
	queue<int> q;
	q.push(A);
	visited[A] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == B)
			break;
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int cost = v[cur][i].second;
			if (visited[next])
				continue;
			q.push(next);
			visited[next] = visited[cur] + cost;
		}
	}
	return visited[B];
}

int main() {
	int N, M;
	cin >> N >> M;
	int A, B, H;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B >> H;
		v[A].push_back({ B,H });
		v[B].push_back({ A,H });
	}
	while (M--)
	{
		cin >> A >> B;
		cout << BFS(A, B) - 1 << endl;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}