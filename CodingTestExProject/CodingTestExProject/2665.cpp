/*
2665 미로만들기 
https://www.acmicpc.net/problem/2665

오랫만에 BFS문제
해당 문제의 메인은 지나가는 위치까지 몇개의 검은 방을 지났는가 이다.
흰방의 경우 가지 않았던 곳이거나 지나간 경로보다 횟수가 적으면 이전 값으로 갱신하면 되고
검은 방의 경우도 위와 같지만 검은 방을 지나가므로 이전 값보다 1 증가한다.

다만 해당 문제풀면서 cnt[0][0] = 0;으로 설정하고 풀어서 계속 틀렸었는데 1로 바꾸고 푼 이후에 제대로 
풀이가 되었다. 전자의 경우 0001이면 다시 역행해서 돌아가는 경우가 생긴다는 것을 인지하지 못하고 실수해서
처음부터 1로 시작하고 마지막결과값에서 -1 하는 방식으로 고쳐주었다.

+)
다익스트라 알고리즘으로도 풀어보기
*/
#include <iostream>
#include <queue>
using namespace std;

int N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int map[51][51] = { 0, };
int cnt[51][51] = { 0, };

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	cnt[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (map[ny][nx] == 1)//흰방
			{
				if (cnt[ny][nx] == 0 || cnt[ny][nx] > cnt[y][x])//방문을 안했거나 더 짧은 경우
				{
					q.push({ nx,ny });
					cnt[ny][nx] = cnt[y][x];
				}

			}
			else {//검은방
				if (cnt[ny][nx] == 0 || cnt[ny][nx] > cnt[y][x] + 1)
				{
					q.push({ nx,ny });
					cnt[ny][nx] = cnt[y][x] + 1;
				}
			}

		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	BFS();
	cout << cnt[N - 1][N - 1] - 1;
	return 0;
}
}