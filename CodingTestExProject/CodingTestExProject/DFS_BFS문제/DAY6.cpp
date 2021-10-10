/*
DAY6 1697 ���ٲ���

�����̴� ������ ���ٲ����� �ϰ� �ִ�.
�����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�.
�����̴� �Ȱų� �����̵��� �� �� �ִ�. ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. �����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.

�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.

"���� ���� �ð�"�̹Ƿ� bfs�� �����Ͽ���.
�ܰ踦 ���ϴ� ����� visited�� int������ �����Ͽ� ���ϴ� ������� �Ͽ���. �׸��� ��½ÿ� ù ������� 1�� ���������Ƿ�
-1�� �� ���� ����Ѵ�.
*/
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int sec = 0;
bool isClear = false;
int visited[200001] = { 0, };

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int y = 0;
			if (i == 0)
			{
				y = x - 1;
			}
			else if (i == 1)
			{
				y = x + 1;
			}
			else
			{
				y = 2 * x;
			}
			if (y >= 0 && y <= 100000 && !visited[y])
			{
				q.push(y);
				visited[y] = 1 + visited[x];
				if (y == K)
					isClear = true;
			}
		}

		if (isClear)
			break;
	}
}

int main() {
	cin >> N >> K;
	bfs(N);
	cout << visited[K] - 1;
	return 0;
}