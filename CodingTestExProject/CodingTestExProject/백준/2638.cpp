/*
2638 치즈

구간을 하나 더 추가해주어서 해결하였다. 바깥 구역을 3으로 지정하고 바깥 구역을 구한뒤 변하는 부분을 구하고 전환하는 걸 한 사이클로 진행했다.

하면서 틀린 부분들이 몇부분있는데
1. 변하는 부분을 바로 바깥 구역으로 바꾸는 경우 바깥구역과 닿는 부분이 바뀔 수 있어서 변하는 부분을 다 구한뒤 한번에 바꿔야한다.
2.바깥 부분 구하는 로직은 한번만 돌리면된다. 기존 다른 풀이 처럼 0 인부분 찾아서 다돌리는 식으로
생각없이 로직 짰더니 당연하게도 틀렸다 . 이부분 수정하고 모두 녹은 지점도 모두가 3이되는 때가 아닌 0이 포함될 수도 있으므로
1이 없는 경우가 모두 녹은 걸로 판단하게 수정했다.

짜면서 고려해야하는 점이 다양해서 좋았던 문제 다른 비슷한 문제풀때도 비스한 이유들로 틀릴 것 같아서
문제 풀때 직접 출력해보고 복습해야할 것 같다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool isCanMelt(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if (map[ny][nx] == 3)
			count++;
	}
	if (count > 1)
		return true;
	else
		return false;
}

void FillOutside(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = 1;
	map[y][x] = 3;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visited[ny][nx])
				continue;
			if (map[ny][nx] == 1)//치즈면 건너뛴다.
				continue;
			map[ny][nx] = 3;
			visited[ny][nx] = 1;
			q.push({ nx,ny });
		}
	}
}

void FindMeltArea(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	if (isCanMelt(x, y))
		map[y][x] = 2;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visited[ny][nx])
				continue;
			if (map[ny][nx] != 1)//치즈가 아니라면 건너뛴다.
				continue;
			if (isCanMelt(nx, ny))
				map[ny][nx] = 2;
			visited[ny][nx] = 1;
			q.push({ nx,ny });
		}
	}
}

bool isAllMelt()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	while (!isAllMelt())
	{
		answer++;
		FillOutside(0, 0);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visited[i][j] && map[i][j] == 1)
				{
					FindMeltArea(j, i);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 2)
				{
					map[i][j] = 3;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
	}

	cout << answer;
	return 0;
}