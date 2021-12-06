/*
2210 숫자판 점프

5x5 판이 고정되어 있어 dfs로 전체 경우의 수를 구하면 되는 문제
6자리수가 중복이 되는지 는 num배열을 통해 중복 체크를 진행했다.
x,y 좌표값 ,6자리수가 될 합,자리수 4가지 매개변수로 dfs를 구성해 cnt를 구했다.
*/
#include <iostream>
using namespace std;

int cnt = 0;
int map[5][5] = { 0, };
int num[1000000] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y, int x, int sum, int idx)
{
	if (idx == 5)
	{
		if (num[sum] == 0)
		{
			num[sum]++;
			cnt++;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
		{
			dfs(ny, nx, sum * 10 + map[ny][nx], idx + 1);
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int sum = map[i][j];
			dfs(i, j, sum, 0);
		}
	}
	cout << cnt;
	return 0;
}