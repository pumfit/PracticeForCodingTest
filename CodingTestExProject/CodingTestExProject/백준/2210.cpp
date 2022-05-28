/*
2210 ������ ����

5x5 ���� �����Ǿ� �־� dfs�� ��ü ����� ���� ���ϸ� �Ǵ� ����
6�ڸ����� �ߺ��� �Ǵ��� �� num�迭�� ���� �ߺ� üũ�� �����ߴ�.
x,y ��ǥ�� ,6�ڸ����� �� ��,�ڸ��� 4���� �Ű������� dfs�� ������ cnt�� ���ߴ�.
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