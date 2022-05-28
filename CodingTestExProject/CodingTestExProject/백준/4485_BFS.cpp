/*
4485 ��� �� ���� �ְ� ������?

������ ���� ���ӿ��� ȭ���� ������ ����(rupee)��. �׷��� ��Ȥ '���Ϸ���'�� �Ҹ��� ������ ���ǵ� �����ϴµ�, �̰� ȹ���ϸ� ������ ������ ���ǰ� �����ϰ� �ȴ�!
������ ���� �ø����� ���ΰ�, ��ũ�� ���� ���Ϸ��Ǹ� ������ N x N ũ���� ������ ���� ���� ���� �ִ�. [0][0]�� ĭ�̱⵵ �ϴ�. �� �̷� ���� ���Գİ� ���´ٸ� �ۿ��� ������� �ڲ� "������ ������ ������ ��� �ְ� ������?"��� ����ñ� �����̴�. ��ũ�� ��� ���� ���� ���ΰ��̰� ���ٴ� �׳� �����ִ� �����ε�, ���� Ÿ��Ʋ�� ���ٰ� �����ִٰ� �ڲ� ������� �̷��� �����ϴϱ� ���ź��� �ɸ� ���⿡ ���� ���̴�.
�Ͽ�ư ����...�ƴ� ��ũ�� �� ������ �ݴ��� �ⱸ, ���� ������ �Ʒ� ĭ�� [N-1][N-1]���� �̵��ؾ� �Ѵ�. ������ �� ĭ���� ���Ϸ��ǰ� �ִµ�, �� ĭ�� ������ �ش� ���Ϸ����� ũ�⸸ŭ �������� �Ұ� �ȴ�. ��ũ�� �Ҵ� �ݾ��� �ּҷ� �Ͽ� ���� �ǳ������ �̵��ؾ� �ϸ�, �� ���� �����¿� ������ ������ 1ĭ�� �̵��� �� �ִ�.
��ũ�� ���� ���ۿ� ���� �ּ� �ݾ��� ���ϱ�?

�����ϴ� �������Ӷ� ��հ� Ǯ����

bfsǮ��

bfs���� ��� �ּҰ��� �Ǵ��ϴ°�??�� �ֿ� ����Ʈ���� �����̴�.
visited Ǯ��ΰ� ��üŽ������ ����� visited ���������� �ּҰ� �Ǵ� ��쿡�� �̵��� �����ϵ��� �Ѵ�.
+)�� ������ �� ���Ŀ� ���ͽ�Ʈ�� �˰������� �ٽ� Ǯ���!
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
int map[126][126] = { 0, };
int visited[126][126] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool CheckInside(int x, int y)
{
	return (x < N&&y < N&&x >= 0 && y >= 0) ? true : false;
}

void bfs(int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (CheckInside(nx, ny))//��üŽ��
			{
				if (visited[nx][ny] > visited[x][y] + map[nx][ny])//�����ϰ� ��
				{
					visited[nx][ny] = visited[x][y] + map[nx][ny];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	int k = 0;
	while (true)
	{
		k++;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				visited[i][j] = 1250;
			}
		}
		if (N == 0)
			return 0;
		else
		{
			visited[0][0] = map[0][0];
			bfs(0, 0);
			cout << "Problem " << k << ": " << visited[N - 1][N - 1] << endl;
		}
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}