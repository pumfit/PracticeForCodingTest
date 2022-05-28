/*
1966 프린터 큐

우선순위 큐를 알고 있고 pair를 쓰는것까지 생각했지만
같은 value 처리를 어떻게 해야하는지 까지 생각을 도출하기 어려웠다.

큐에 두 쌍을 넣고 우선순위 큐에서는 우선순위만 넣고 value가 같은지 판단하는 형식으로 구현하면 된다.
+)
우선순위 큐를 사용하지않는 풀이도 알아보기
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