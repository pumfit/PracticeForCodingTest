/*
공기청정기 시계방향 반시계방향 구현 방식이 어려운 문제
https://kibbomi.tistory.com/69
*/

#include <iostream>
using namespace std;

int R, C, T;
int up_y = 0, down_y = 0;
int map[51][51] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int diffuse(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < C && ny < R && map[ny][nx] != -1)
		{
			map[ny][nx] += map[y][x] / 5;
			cnt++;
		}
	}

	return cnt;
}
void cleanDown()
{
	for (int i = down_y + 1; i < R - 1; i++)
		map[i][0] = map[i + 1][0];
	for (int j = 0; j < C - 1; j++)
		map[R - 1][j] = map[R - 1][j + 1];
	for (int i = R - 1; i > down_y; i--)
		map[i][C - 1] = map[i - 1][C - 1];
	for (int j = C - 1; j > 1; j--)
		map[down_y][j] = map[down_y][j - 1];
	map[down_y][1] = 0;
}
void cleanUp()
{
	for (int i = up_y - 1; i > 0; i--)
		map[i][0] = map[i - 1][0];
	for (int j = 0; j < C - 1; j++)
		map[0][j] = map[0][j + 1];
	for (int i = 0; i < up_y; i++)
		map[i][C - 1] = map[i + 1][C - 1];
	for (int j = C - 1; j > 1; j--)
		map[up_y][j] = map[up_y][j - 1];
	map[up_y][1] = 0;
}

int main() {
	int sum = 0;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				up_y = i; down_y = i - 1;
			}
		}
	}
	for (int k = 0; k < T; k++)//초마다
	{
		for (int i = 0; i < R; i++)//미세먼지 확산
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] > 0)
				{
					int cnt = diffuse(i, j);
					map[i][j] -= (map[i][j] / 5)*cnt;
				}
			}
		}

		cleanUp();
		cleanDown();

	}

	map[down_y][0] = -1;
	map[up_y][0] = -1;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != -1)
			{
				sum += map[i][j];
			}
		}
	}
	cout << sum;
	return 0;
}