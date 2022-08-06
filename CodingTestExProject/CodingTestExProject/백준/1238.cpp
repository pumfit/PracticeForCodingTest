/*
1238 ��Ƽ

�պ� �ִ� �Ÿ��� ���ϰ� ���� �ִ븦 ã�� �������� ��ü �л� �迭 ���鼭 �ִܰŸ� ���ϰ� 
�ܹ����̰� �պ��� �޶��� �� �־ ���ͽ�Ʈ��� ��� ã�� �� �ι� �����ϸ� �ȴ�.

�׷��� �ѹ� �ð��ʰ��� Ʋ���� �ٸ� �˰����� �ֳ� �;� ã�ƺôµ� ����� �ӵ� �����̾���.
ios::sync_with_stdio(false); ���� cin,cout ������ ���� �� ������

+)
��ǥ�� �ڱ⸶���� ���� ������� ������ �� ���� �� ���Ƽ� if(i+1==X) continue; �߰��ؼ� �����ߴµ�
�ð������� ���ǹ� ���� �� �� �ð��� �����ɷȴ�. 1�� �ǳʶٴ� �Ŷ� ũ�� ���̰� ������ �� ����
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int N, M, X;//�л� �ܹ��⵵�� ����
vector<pair<int, int>> v[1001];
int d[1001];
int maxDist = 0;

void BFS(int s)
{
	priority_queue<pair<int, int>> q;
	q.push({ s,0 });
	d[s] = 0;
	while (!q.empty())
	{
		int now = q.top().first;
		int dist = -q.top().second;
		q.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0; i < v[now].size(); i++)
		{
			int cost = dist + v[now][i].second;
			if (cost < d[v[now][i].first])
			{
				d[v[now][i].first] = cost;
				q.push({ v[now][i].first,-cost });
			}
		}
	}

}

int FindMinPath(int start, int end)
{
	fill(d, d + 1001, INF);
	BFS(start);
	return d[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;
	int A, B, C;
	while (M--)
	{
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
	}
	for (int i = 0; i < N; i++)
	{
		if (i + 1 == X)
			continue;
		int dist = 0;
		dist += FindMinPath(i + 1, X);
		dist += FindMinPath(X, i + 1);
		maxDist = max(maxDist, dist);
	}
	cout << maxDist;
	return 0;
}