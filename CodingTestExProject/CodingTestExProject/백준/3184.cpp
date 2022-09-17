/*
3184 양
https://www.acmicpc.net/problem/3184

BFS문제 - ideone에서 결과 나오는데 5초씩은 걸린 것 같은데 백준 채점은 1초도 안걸린 것 같은 문제
x,y 순서를 문제풀면서 자꾸 바꿔서 잘못 넣었다가 값이 안나왔다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

string map[251] = { "", };
int visited[251][251] = { 0, };
int R, C;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int sheep = 0, wolf = 0;

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (map[cy][cx] == 'v')
			wolf++;
		if (map[cy][cx] == 'o')
			sheep++;
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= C || ny >= R)
				continue;
			if (visited[ny][nx])
				continue;
			if (map[ny][nx] == '#')
				continue;

			q.push({ nx,ny });
			visited[ny][nx] = 1;
		}
	}
	return;
}

int main() {
	string s;
	cin >> R >> C;
	int A = 0, B = 0;
	for (int i = 0; i < R; i++)
	{
		cin >> map[i];
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!visited[i][j] && map[i][j] != '#')
			{
				BFS(j, i);
				if (sheep > wolf)
					A += sheep;
				else
					B += wolf;
				sheep = 0, wolf = 0;
			}

		}

	}
	cout << A << " " << B;
	return 0;
}