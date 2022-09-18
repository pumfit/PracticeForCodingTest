/*
1240 �������� �Ÿ�

https://www.acmicpc.net/problem/1240

����� visited�� ���� ����Ͽ��� ó�� �湮 ǥ�⸦ ���� ù �湮���� ����� 1�� �ϰ�
��ȯ������ 1���� ������ �Ÿ� ����� �����Ͽ���.
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