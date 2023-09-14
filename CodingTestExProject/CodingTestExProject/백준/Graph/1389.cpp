/*
1389 케빈 베이컨의 6단계 법칙

vector subscript out of range

진짜 약간 이상해지면 아무것도 안보이나보다..
29번 라인에서 두번째 조건식 i< 없이 graph[nx].size()만 써서 vector subscript out of range 나고
왜지?? 뭐가 문제지 삽질 하루동안 했음 진짜.....역대급...정신차리자
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[101];
int visited[101] = { 0, };
int N, M;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty())
	{
		int nx = q.front();
		q.pop();
		for (int i = 0; i < graph[nx].size(); i++)
		{
			int y = graph[nx][i];
			if (visited[y] == 0)
			{
				visited[y] = visited[nx] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++)//양방향
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int m = 999, idx = 1;

	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		bfs(i);
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
			{
				sum += visited[j]-1;
			}
		}
		if (sum < m)
		{
			m = sum;
			idx = i;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << idx;
	return 0;
}