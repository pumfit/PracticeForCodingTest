/*
2660 »∏¿ÂªÃ±‚

https://www.acmicpc.net/problem/2660
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
vector<int> v[51];
int visited[51] = { 0, };

int BFS(int n)
{
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	int score = 0;

	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		for (int i = 0; i < v[s].size(); i++)
		{
			if (visited[v[s][i]])
				continue;
			q.push(v[s][i]);
			visited[v[s][i]] = visited[s] + 1;
			score = max(score, visited[s] + 1);
		}
	}
	return score;
}

bool isAllFriend()
{
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
			return false;
	}
	return true;
}

int main() {
	int A, B;
	cin >> N;

	while (true)
	{
		cin >> A >> B;
		if (A == -1 && B == -1)
			break;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	vector<int> minScore[51];
	for (int i = 1; i <= N; i++)
	{
		int score = BFS(i) - 1;
		if (isAllFriend())
		{
			minScore[score].push_back(i);
		}
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 0; i < 51; i++)
	{
		if (minScore[i].size() > 0)
		{
			cout << i << " " << minScore[i].size() << '\n';
			for (int j = 0; j < minScore[i].size(); j++)
			{
				cout << minScore[i][j] << " ";
			}
			break;
		}
	}
	return 0;
}