/*
2636 ġ��

�Ʒ� <�׸� 1>�� ���� ���簢�� ĭ��� �̷���� �簢�� ����� ���� �ְ�, �� ���� ���� ġ��(ȸ������ ǥ�õ� �κ�)�� ���� �ִ�. ���� �����ڸ�(<�׸� 1>���� �׸� ĭ�� Xģ �κ�)���� ġ� ���� ���� ������ ġ��� �ϳ� �̻��� ������ ���� �� �ִ�.

�� ġ� ���� �߿� ������ ��� �Ǵµ� ����� ���˵� ĭ�� �� �ð��� ������ ��� ��������. ġ���� ���� �ӿ��� ���Ⱑ ������ ������ �ѷ��� ġ� ��Ƽ� ������ ������ ���� ������ ���Ⱑ ���� �ȴ�. <�׸� 1>�� ���, ġ���� ������ �ѷ��� ġ��� ���� �ʰ� ��c���� ǥ�õ� �κи�
�� �ð� �Ŀ� ��� �������� <�׸� 2>�� ���� �ȴ�.

�Է����� �簢�� ����� ���� ũ��� �� ������ ġ� �� ���� �־����� ��, ���� �߿��� ġ� ��� ��� �������� �� �ɸ��� �ð��� 
��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

100�ۼ�Ʈ���� �ָ�Ʋ �̽��� �� �ð����� ����ߴ� �� ����..0���θ� �̷������ 0 0 �� ���;��ϴµ� ī��Ʈ�� ������ ������
���� �� ����ϴ� �� ó���� ���� �ʾ���. �� �� ����ϰ� Ǯ �� ���� �� ���Ƽ� �ƽ�
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int Y, X;
int map[101][101];
int visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0, remain = 0;

int CountRemain()
{
	int sum = 0;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (map[i][j] == 1)
				sum++;
		}
	}
	return sum;
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = 1;
	cnt++;
	while (!q.empty())
	{
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;
			if (visited[ny][nx] == 0 && map[ny][nx] == 0)
			{
				q.push(make_pair(nx, ny));

			}
			else
			{
				map[ny][nx] = 0;
			}
			visited[ny][nx] = 1;
		}
	}
}

int main()
{
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> map[i][j];
		}
	}
	while (true)
	{
		int count = 0;
		count = CountRemain();
		bfs(0, 0);
		if (count == 0)
			break;
		memset(visited, 0, sizeof(visited));
		remain = count;
	}

	cout << cnt - 1 << endl;
	cout << remain;
	return 0;
}