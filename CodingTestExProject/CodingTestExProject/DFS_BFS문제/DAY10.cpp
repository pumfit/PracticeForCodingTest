/*
2468 ���� ����

���� ����� �ʴ� ������ �����̶� ���� ���� ����� �ʴ� �������� ��, �Ʒ�, ������ Ȥ�� �������� ������ ������ �� ũ�Ⱑ �ִ��� ������ ���Ѵ�.

*/
#include<iostream>
using namespace std;

int N;
int map[101][101] = {0,};
int visited[101][101] = {0,};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool isAvailable(int x,int y)
{
	return (x >= 0 && y >= 0 && x < N&&y < N) ? true : false;
}

int check(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isAvailable(nx, ny) && !(map[x][y] >= map[nx][ny]))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	cin >> N;
	int height = 0;
	int cnt = 0, maxHeight =0, maxArea=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (maxHeight < map[i][j])
				maxHeight = map[i][j];
		}
	}

	for (int h = 0; h < maxHeight; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > h)
				{
					cnt += check(i, j);
				}
			}
		}
		cout << cnt<<endl;
		if (cnt > maxArea)
			maxArea = cnt;
		cnt = 0;
	}
	cout << maxArea;
}