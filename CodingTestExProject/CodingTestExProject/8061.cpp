/*
8061 Bitmap

There is given a rectangular bitmap of size n x m. Each pixel of the bitmap is either white or black,
but at least one is white. The pixel in i-th line and j-th column is called the pixel (i,j).
The distance between two pixels p1=(i1,j1) and p2=(i2,j2) is defined as:d(p1,p2)=|i1-i2|+|j1-j2|.


dfs�� Ǯ�̸� ������ ���� ó���� ������ Ǯ�̶� ���� �ٸ��� �������� �̻��� ������ �ڲ� �Ǽ��ؼ� �ð��� �� �ɷȴ�.

1.�Է�
�Է¿� ��ĭ�� ��� string ���·� �ް� �ٽ� int����ȯ�ؼ� �־��ִ� ������ �ʿ��ѵ� �ش� �������� cin���� �ٷ� �Է¹޾Ƽ�
11111000...�� ���� map�� �Է��� ������ ���簡 ��������. ���� ���� �Է� ���ǵ� Ȯ���ϰ� Ȯ���� ��
2.���
���� Ǯ�� �� �����ߴµ� 5�۴뿡�� Ʋ���� �ָ�Ʋ �ϸ鼭 ���� �� �־�� �־��µ�...����� ���� ����� �� ������ ������ �־��ش�.
�̸� �߰��ϴ� ����ߴ�. ���� ���� ���� ��� ���ǵ� Ȯ���� Ȯ���� ��

*/
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[183][183] = { 0, };
int visited[183][183] = { 0, };
int Y, X;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < X&&ny < Y&&map[ny][nx] != 1)
			{
				if (visited[ny][nx] == 0)
				{
					visited[ny][nx] = visited[y][x] + 1;
					q.push(make_pair(nx, ny));
				}
				else if (visited[ny][nx] > visited[y][x] + 1)
				{
					visited[ny][nx] = visited[y][x] + 1;
					q.push(make_pair(nx, ny));
				}

			}
		}
	}
	return;
}

int main() {
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < X; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (map[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}