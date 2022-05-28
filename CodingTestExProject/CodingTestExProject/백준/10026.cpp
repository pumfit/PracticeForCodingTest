/*
10026 적록색약

적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
둘째 줄부터 N개 줄에는 그림이 주어진다.

bfs로 일반적인 경우의 구역을 구하고 해당 구현과 같게 하되 red,green이 blue와 만나는 경우를 제외하는 새로운 bfs를 만들었다.

+
이름 짓기 어려웠던 문제..
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
char map[101][101] = { 0, };
int visited[101][101] = { 0, };
int visitedRG[101][101] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int rgb = 0, b = 0;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = 1;
	while (!q.empty())
	{
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N&&ny < N&&visited[ny][nx] == 0 && map[sy][sx] == map[ny][nx])
			{
				visited[ny][nx] = 1;
				bfs(ny, nx);
			}
		}
	}
}

void bfsRG(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visitedRG[y][x] = 1;
	while (!q.empty())
	{
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N&&ny < N&&visitedRG[ny][nx] == 0)
			{
				if ((map[sy][sx] == 'B'&&map[ny][nx] == 'R') || (map[sy][sx] == 'R'&&map[ny][nx] == 'B'))
					continue;
				if ((map[sy][sx] == 'B'&&map[ny][nx] == 'G') || (map[sy][sx] == 'G'&&map[ny][nx] == 'B'))
					continue;
				visitedRG[ny][nx] = 1;
				bfsRG(ny, nx);
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
			map[i][j] = s[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(i, j);
				rgb++;
			}
			if (visitedRG[i][j] == 0)
			{
				bfsRG(i, j);
				b++;
			}
		}
	}
	cout << rgb << " " << b;
	return 0;
}