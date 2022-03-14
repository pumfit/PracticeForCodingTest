/*
1012 ����� ����
https://www.acmicpc.net/problem/1012

BFS ���� �˾Ƴ��� ����
�̹��� �������� �Ⱦ��� Ǯ��Ҵ�.

ùǮ�̿� �������� 4ms �ð��� �ɷȾ��µ� �Է°��� ���ٺ��� 4ms����.
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
�߰����ָ� 0ms��� ����� ������ �����̴�.
*/
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int answer = 0;
		int M, N, K;//���� ����
		int map[51][51] = { 0, };
		int visited[51][51] = { 0, };
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (map[j][k] == 1 && visited[j][k] == 0)
				{
					visited[j][k] = 1;
					queue<pair<int, int>> q;
					q.push({ k,j });//x,y
					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++)
						{
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (nx < 0 || ny < 0 || nx >= M || ny >= N)
								continue;
							if (map[ny][nx] != 1)
								continue;
							if (visited[ny][nx])
								continue;
							q.push({ nx,ny });
							visited[ny][nx] = 1;
						}
					}
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}
	return 0;
}