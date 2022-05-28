/*

2583 ���� ���ϱ�

dfs

�ʹ� �ʰ� Ǭ ����..������ ������ ���� ���ڸ��� dfs�� Ǯ��ǰڴ� �����߰� ���� �κ��� �Ʒ���

1.ä���� ����

(0,0)��ǥ���� �������� �ִ� ����ε� �̴� ������ ���ϴ� ���̴� ������� ��縸 ������ �ȴ�.
�׷��� ó���� �ԷµǴ� ��ǥ�� ���ظ� ���ؼ� �ι�°������ ���� ���ϰ� ������ ������. ����غ��� ���ذ��鼭 �ܿ� ã�Ҵ�.

2.dfs�� ���������� ��� ������..?

������ �ߴ� �ǵ� ��Ծ������ �ظ̴� �κ� bfs ���ϰ��� int�� �ؼ� bfs���� 1�� ���� ���� �����ϵ��� �ߴ��� �ܰ躰�� ���� ���ͼ�
���� �ߴ�. �Լ��� �θ������� ��������ϴ� �Լ� �ʹݿ� ���� ���ؼ� �����ָ� �ȴ�. �� �����Ѱ� �Ź� ������ �ȳ��� ���� �𸣰ڴ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, N;
int c = 0;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsInside(int x, int y)
{
	return (x < N&&x >= 0 && y < M&&y >= 0);
}

void dfs(int x, int y)
{
	c++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsInside(nx, ny) && visited[ny][nx] == 0)
		{
			visited[ny][nx] = 1;
			dfs(nx, ny);
		}
	}
}

void print()
{
	for (int i = 0; i < M; i++)//y
	{
		for (int j = 0; j < N; j++)//x
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int K;
	vector<int> v;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		for (int j = x; j < nx; j++)
		{
			for (int k = y; k < ny; k++)
			{
				visited[k][j] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++)//y
	{
		for (int j = 0; j < N; j++)//x
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;
				dfs(j, i);
				v.push_back(c);
				c = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}