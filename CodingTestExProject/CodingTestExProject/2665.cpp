/*
2665 �̷θ���� 
https://www.acmicpc.net/problem/2665

�������� BFS����
�ش� ������ ������ �������� ��ġ���� ��� ���� ���� �����°� �̴�.
����� ��� ���� �ʾҴ� ���̰ų� ������ ��κ��� Ƚ���� ������ ���� ������ �����ϸ� �ǰ�
���� ���� ��쵵 ���� ������ ���� ���� �������Ƿ� ���� ������ 1 �����Ѵ�.

�ٸ� �ش� ����Ǯ�鼭 cnt[0][0] = 0;���� �����ϰ� Ǯ� ��� Ʋ�Ⱦ��µ� 1�� �ٲٰ� Ǭ ���Ŀ� ����� 
Ǯ�̰� �Ǿ���. ������ ��� 0001�̸� �ٽ� �����ؼ� ���ư��� ��찡 ����ٴ� ���� �������� ���ϰ� �Ǽ��ؼ�
ó������ 1�� �����ϰ� ��������������� -1 �ϴ� ������� �����־���.

+)
���ͽ�Ʈ�� �˰������ε� Ǯ���
*/
#include <iostream>
#include <queue>
using namespace std;

int N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int map[51][51] = { 0, };
int cnt[51][51] = { 0, };

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	cnt[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (map[ny][nx] == 1)//���
			{
				if (cnt[ny][nx] == 0 || cnt[ny][nx] > cnt[y][x])//�湮�� ���߰ų� �� ª�� ���
				{
					q.push({ nx,ny });
					cnt[ny][nx] = cnt[y][x];
				}

			}
			else {//������
				if (cnt[ny][nx] == 0 || cnt[ny][nx] > cnt[y][x] + 1)
				{
					q.push({ nx,ny });
					cnt[ny][nx] = cnt[y][x] + 1;
				}
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
			map[i][j] = s[j] - '0';
		}
	}
	BFS();
	cout << cnt[N - 1][N - 1] - 1;
	return 0;
}
}