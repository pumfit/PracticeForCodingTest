/*
12761 돌다리

https://www.acmicpc.net/problem/12761

이후 다른 풀이보고 깨달았지만 dx자체를 bfs에 넣으면 초기화를 저렇게 하나씩 안해줘도 된다..
왜 저렇게 했을까 
1차원이라 더 쉬웠던 bfs문제
*/
#include <iostream>
#include <queue>
using namespace std;

int A, B, N, M;
int visited[100001] = { 0, };
int dx[8] = { 0, };

void bfs()
{
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = 0;
			if (i > 5)
				nx = x * dx[i];
			else
				nx = x + dx[i];
			if (nx == M)
			{
				cout << visited[x];
				return;
			}
			if (nx < 0 || nx >= 100000)
				continue;
			if (visited[nx])
				continue;
			visited[nx] = visited[x] + 1;
			q.push(nx);
		}
	}
}

int main() {
	cin >> A >> B >> N >> M;
	dx[0] = -1; dx[1] = 1; dx[2] = A; dx[3] = B; dx[4] = -A; dx[5] = -B; dx[6] = A; dx[7] = B;
	bfs();
	return 0;
}