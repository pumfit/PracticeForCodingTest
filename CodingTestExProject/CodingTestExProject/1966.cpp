/*
1966 ������ ť

�켱���� ť�� �˰� �ְ� pair�� ���°ͱ��� ����������
���� value ó���� ��� �ؾ��ϴ��� ���� ������ �����ϱ� �������.

ť�� �� ���� �ְ� �켱���� ť������ �켱������ �ְ� value�� ������ �Ǵ��ϴ� �������� �����ϸ� �ȴ�.
+)
�켱���� ť�� ��������ʴ� Ǯ�̵� �˾ƺ���
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, M;
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		cin >> N >> M;
		int n;
		for (int j = 0; j < N; j++)
		{
			cin >> n;
			q.push(make_pair(j, n));
			pq.push(n);
		}
		int cnt = 0;
		while (!q.empty())
		{
			int idx = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value)
			{
				pq.pop();
				cnt++;
				if (M == idx)
				{
					cout << cnt;
					break;
				}
			}
			else
			{
				q.push(make_pair(idx, value));
			}
		}
		cout << endl;
	}
	return 0;
}