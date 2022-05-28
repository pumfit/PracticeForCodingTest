/*

5567 ��ȥ��

����̴� �ڽ��� ��ȥ�Ŀ� �б� ���� �� �ڽ��� ģ���� ģ���� ģ���� �ʴ��ϱ�� �ߴ�. ������� ����� ��� N���̰�,

�� �л����� �й��� ��� 1���� N�����̴�. ������� �й��� 1�̴�.

����̴� ������� ģ�� ���踦 ��� ������ ����Ʈ�� ������ �ִ�.

�� ����Ʈ�� �������� ��ȥ�Ŀ� �ʴ��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



ó�����ڸ��� ���� ���߿��Ḯ��Ʈ bfs ����

�����ߴ��� 3�ܰ����ϱ��� �������� �ʾƵ� �Ǵ� ���ǹ��� if(visitList[y]==0&&visitList[x]<3)�� �Ͽ� bfs�� �����ߴ�.

�����ϱ��� ���ɰ� ���� 3�ε� 4�� ���Դµ� ������ 1(�ڽ�)�� �����ؼ� ����.

�ٸ� ������ ó�� �信�� -1���ָ� �ι�° ���ɰ� ������� �����Ƿ� �ݺ������� i�� 2���� ���۵Ǿ�� �Ѵ�.



https://www.acmicpc.net/source/35222975

���� ���Ҷ� bfs���ͼ� �ݺ��� ���� ���� bfs���ο��� ���ؼ� �ð� �����ϱ�

*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[501];
int visitList[501];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (visitList[y] == 0 && visitList[x] < 3)
			{
				visitList[y] = visitList[x] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	bfs(1);
	for (int i = 2; i < N + 1; i++)
	{
		if (visitList[i] > 0 && visitList[i] < 3)
		{
			cnt++;
		}

	}
	cout << cnt;
	return 0;
}